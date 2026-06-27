*This project has been created as part of the 42 curriculum by yohsawa, msumiji.*

# push_swap

## Description

`push_swap` は、42 curriculum のアルゴリズム課題です。
2つのスタック `a` と `b`、および限られた操作だけを使って、整数列を昇順に並べ替えるための最短に近い操作列を標準出力へ出力します。

このプロジェクトの目的は、単にソートを実装することではなく、制約のある環境でデータ構造・アルゴリズム・入力検証・メモリ管理を組み合わせ、効率的な解法を設計することです。

プログラムは以下を行います。

- コマンドライン引数から整数列を受け取る
- 不正な入力、`int` 範囲外の値、重複値を検出する
- すでに整列済みの場合は何も出力しない
- 必要な場合のみ、指定された操作名を1行ずつ出力する

使用できる主な操作は、`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr` です。

## Instructions

### コンパイル

`push_swap` ディレクトリへ移動して `make` を実行します。

```sh
cd push_swap
make
```

生成される実行ファイルは `push_swap` です。

### 実行

整数を引数として渡します。

```sh
./push_swap 2 1 3 6 5 8
```

出力例:

```txt
sa
pb
ra
pa
```

出力される各行は、スタックに対して実行すべき操作を表します。

### Strategy selector

先頭の引数に selector を指定すると、使用するソート方針を切り替えられます。

```sh
./push_swap --simple 4 1 3 2
./push_swap --complex 4 1 3 2
./push_swap --adaptive 4 1 3 2
```

- `--simple`: `selection_sort` を使用する
- `--complex`: `radix_sort` を使用する
- `--adaptive`: 入力の disorder を計算し、状態に応じて内部手法を選ぶ

selector を指定しない場合も、現在の実装では adaptive sort を使います。
ただし、要素数が `5` 以下の場合は selector に関係なく小規模入力用の個別ソートを優先します。

### エラー処理

以下のような入力では `Error` を標準エラー出力へ表示し、終了します。

- 数字として解釈できない値
- `int` の範囲を超える値
- 重複した整数

例:

```sh
./push_swap 1 2 2
```

### Makefile のターゲット

- `make`: `push_swap` をビルドする
- `make clean`: オブジェクトファイルを削除する
- `make fclean`: オブジェクトファイルと実行ファイルを削除する
- `make re`: クリーン後に再ビルドする

## Algorithm

この実装では、入力サイズに応じてアルゴリズムを切り替えています。

### 1. 座標圧縮

ソート処理の前に、入力値を相対的な順位へ変換します。

例:

```txt
入力:       42 -10 7
圧縮後:     2 0 1
```

`push_swap` では値そのものの大小関係だけが重要です。
そのため、元の整数を `0` から `n - 1` の連続したインデックスに置き換えても、ソート結果の正しさは変わりません。

座標圧縮を使う理由は以下です。

- 負数や大きな整数を扱いやすくする
- Radix sort でビット演算を単純にする
- 最大値を `n - 1` に抑え、必要なビット数を減らす

### 2. 小規模入力用の個別ソート

要素数が `2` から `5` の場合は、専用の処理を使います。

- `2` 個: 必要なら `sa`
- `3` 個: 値の並びに応じて `sa`, `ra`, `rra` を組み合わせる
- `4` または `5` 個: 最小値を `b` に退避し、残り3個を整列してから `a` に戻す

小さい入力では、汎用アルゴリズムよりも分岐を用いた専用処理の方が操作数を抑えやすいため、この方法を選択しています。

### 3. 6個以上の入力に対する Radix sort

要素数が `6` 個以上の場合は、座標圧縮後の値に対して Radix sort を使用します。
最下位ビットから順に確認し、ビットが `0` の要素を `b` に送り、ビットが `1` の要素は `a` 内で回転させます。
各ビットの処理後、`b` にある要素をすべて `a` に戻します。

処理の流れは以下です。

1. 最大値 `n - 1` に必要なビット数を求める
2. 下位ビットから順番に見る
3. 現在のビットが `0` なら `pb`
4. 現在のビットが `1` なら `ra`
5. 1ビット分の走査後、`pa` で `b` から `a` に戻す
6. すべてのビットを処理すると昇順になる

Radix sort を選んだ理由は以下です。

- 実装が比較的単純で、操作の正しさを追いやすい
- 座標圧縮と相性がよく、負数や大きな値を気にせず処理できる
- 計算量が `O(n log n)` 相当ではなく、ビット数を `k` とした `O(n * k)` で安定している
- `push_swap` の基本操作である `pb`, `pa`, `ra` を中心に構成できる
- 入力数が増えても、極端に複雑な分岐を増やさずに対応できる

この課題では絶対的な最短手順を常に求めることよりも、制約内で安定して正しい操作列を出すことが重要です。
そのため、本実装では小規模入力では操作数を抑える専用処理を使い、大きな入力では予測しやすく堅牢な Radix sort を使う方針にしています。

### 4. Disorder による Adaptive sort

`--adaptive` が指定された場合、または selector が指定されていない場合は、ソート前の `stack a` から disorder を計算して内部手法を切り替えます。
disorder は、すべての組 `(i, j)` について `i < j` かつ `a[i] > a[j]` となる inversion の割合です。
完全に整列済みなら `0`、逆順に近いほど `1` に近づきます。

disorder は move を出す前、かつ座標圧縮の前に測定します。
大小関係だけを見るため、圧縮前でも圧縮後でも値は同じになりますが、subject の要件に合わせて初期 stack に対して計算しています。

Adaptive sort の閾値は subject の regime に合わせ、以下のようにしています。

- Low disorder: `disorder < 0.2`
- Medium disorder: `0.2 <= disorder < 0.5`
- High disorder: `disorder >= 0.5`

Low disorder では `selection_sort` を使います。
圧縮後の値が `0..n-1` になることを利用し、`0`, `1`, `2` ... を順番に探して上へ回し、`b` に送ります。
各 target について位置探索と回転が最大 `O(n)`、それを `n` 回行うため、Push_swap 操作モデルでの上限は `O(n^2)` です。
追加メモリは stack `b` を除けば `O(1)` です。
`--simple` selector は、この `selection_sort` を明示的に選択するためのオプションです。

Medium disorder では、最終的には `chunk_sort` を使う予定です。
`sqrt(n)` 個程度の chunk に分け、各 chunk の値を `b` に送りながら整列しやすい位置へ回す設計にします。
chunk 数と chunk 幅をどちらも `sqrt(n)` 程度に抑えることで、探索と回転の合計上限を `O(n sqrt(n))` にする方針です。
現在の実装では `chunk_sort(a, b);` の呼び出しをコメントアウトし、完成までの fallback として `radix_sort` を呼んでいます。

High disorder では `radix_sort` を使います。
座標圧縮後の最大値は `n - 1` なので、必要なビット数は `log n` です。
各ビットごとに全要素を一度ずつ処理するため、Push_swap 操作モデルでの上限は `O(n log n)` です。
追加メモリは stack `b` を除けば `O(1)` です。
`--complex` selector は、この `radix_sort` を明示的に選択するためのオプションです。

## Project Structure

```txt
push_swap/
├── Makefile
├── include/
│   └── push_swap.h
├── src/
│   ├── main.c
│   ├── compress.c
│   ├── sort.c
│   ├── sort_small.c
│   ├── utils.c
│   └── operations/
└── stack_utils/
```

## Resources

### 参考資料

- 42 subject: push_swap
- Qiita: [push_swap で使われる Radix sort の解説](https://qiita.com/tommyecguitar/items/3c1897bceda4a06beef2)
- GeeksforGeeks: [Selection Sort Algorithm](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)

### AI の使用について

AI は、README の文章構成、説明の明確化、アルゴリズム説明の整理に使用しました。
具体的には、プロジェクトの目的、実行方法、エラー処理、座標圧縮および Radix sort の説明を、第三者が読みやすい日本語に整えるために利用しています。

ソート処理、スタック操作、入力検証などの実装コードそのものは、この README 作成時点では AI によって変更していません。
