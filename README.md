*This project has been created as part of the 42 curriculum by yohsawa, msumiji.*

# push_swap

## Description

`push_swap` は、2つのスタック `a` / `b` と限られた操作だけを使い、整数列を昇順へ並べ替える操作列を出力する 42 curriculum の課題です。

この実装では、入力を検証したあと座標圧縮を行い、入力サイズや disorder に応じてソート戦略を切り替えます。通常の操作列は標準出力へ出し、`--bench` 指定時の統計情報は標準エラー出力へ出します。

使用する操作:

sa　スタックaの先頭の２つを入れ替える。要素数が１以下のときは何もしない。
sb　スタックbの先頭の２つを入れ替える。要素数が１以下のときは何もしない。
ss　saとsbを同時に行う。
pa　スタックbの最初の要素をスタックaの先頭に持っていく。スタックbが空のときは何もしない。
pb　スタックaの最初の要素をスタックbの先頭に持っていく。スタックaが空のときは何もしない。
ra　スタックaの要素を全て１つずつ上げる。先頭の要素は一番下に行く。
rb　スタックbの要素を全て１つずつ上げる。先頭の要素は一番下に行く。
rr　raとrbを同時に行う。
rra　スタックaの要素を全て１つずつ下げる。最後尾の要素は一番上に行く。
rrb　スタックbの要素を全て１つずつ下げる。最後尾の要素は一番上に行く。
rrr　rraとrrbを同時に行う。

## Build

```sh
cd push_swap
make
```

生成される実行ファイルは `push_swap` です。

```sh
./push_swap 2 1 3
```

出力例:

```txt
sa
```

## Options

先頭に `--bench` を付けると、操作数の合計と各操作の回数を標準エラー出力へ表示します。

```sh
./push_swap --bench 3 2 1
```

ソート戦略は selector で指定できます。

```sh
./push_swap --simple 4 1 3 2
./push_swap --medium 4 1 3 2
./push_swap --complex 4 1 3 2
./push_swap --adaptive 4 1 3 2
```

- `--simple`: `selection_sort`
- `--medium`: `chunk_sort`
- `--complex`: `radix_sort`
- `--adaptive`: disorder を見て自動選択

selector を省略した場合も adaptive として動きます。要素数が `5` 以下の場合は、selector に関係なく `selection_sort` の小さい入力向け処理を優先します。

`--bench` と selector は組み合わせられます。

```sh
./push_swap --bench --medium 5 1 4 2 3
```

## Error Handling

以下の場合は `Error` を標準エラー出力へ表示して終了します。

- 数字として解釈できない値
- `int` 範囲外の値
- 重複した整数
- option のあとに数値がない場合

```sh
./push_swap 1 2 2
```

## Algorithms

### 課題要件と選定理由

この課題では、以下の3つの計算量クラスから少なくとも1つずつアルゴリズムを実装することが求められています。この実装では、それぞれのクラスに対して `selection_sort`, `chunk_sort`, `radix_sort` を選びました。

| 要件 | この実装で選んだ方法 | 理由 |
| --- | --- | --- |
| Simple algorithm / `O(n^2)` | `selection_sort` | 最小値を探して別スタックへ送る処理が `push_swap` の操作に素直に対応し、実装と検証がしやすいためです。小さい入力やほぼ整列済みの入力では余分な分割やビット走査を避けられ、操作列も読みやすくなります。 |
| Medium algorithm / `O(n√n)` | `chunk_sort` | 値域を `√n` 個程度の chunk に分けることで、単純な全探索より操作数を抑えられます。`push_swap` では配列のようにランダムアクセスできないため、範囲ごとに `pb`, `ra`, `rb` で仕分ける chunk-based sorting は2スタック構造と相性がよいです。 |
| Complex algorithm / `O(n log n)` | `radix_sort` | 座標圧縮後の値をビットごとに処理でき、比較や再帰を使わずに `pb`, `pa`, `ra` だけで安定して実装できます。入力が大きい場合でも必要な走査回数が `log2(n)` 程度に収まるため、最悪ケースの見通しがよいです。 |

この3つを用意することで、入力サイズや乱れ具合に応じて、単純で低コストな方法、中間的な chunk-based strategy、大きな入力でも安定する radix strategy を切り替えられるようにしています。

### 値を順位に変換

ソート前に入力値を順位へ変換します。

```txt
input:      42 -10 7
compressed: 2   0 1
```

`push_swap` では値そのものではなく大小関係だけが必要です。`0..n-1` に圧縮すると、負数や大きな整数を気にせず扱え、radix sort で必要なビット数も `log2(n)` 程度に抑えられます。

### 戦略の決定
　引数に--simpleなどの指定があるときは優先的にその戦略にします。指定がないとき、あるいは引数に--adaptiveという指定があるときは、以下の手順で戦略を決定します。
　まずdisorder metricを計算します。これは要素の中から２つの要素を取り出して、それが昇順になっているか調べます。disorder metricは昇順になっている組み合わせを全ての組み合わせで割ったものです。
　引数が--simpleのとき、あるいはdisorder metricが0.2未満のときはselection sortで処理を行います。引数が--mediumのとき、あるいはdisorder metricが0.2以上0.5未満のときはchunk sortで処理を行います。引数が--complexのとき、あるいはdisorder metricが0.5以上のときは、radix sortで処理を行います。

### selection_sort / O(n^2)

座標圧縮後の値が `0..n-1` であることを利用し、`0`, `1`, `2` ... の順に探して `b` へ送り、最後に `a` へ戻します。

計算量の見積もり:

- 各 target について `find_pos` が最大 `O(n)`
- それを `n` 回行うため探索だけで `O(n^2)`
- 回転も各 target で最大 `O(n)` なので、操作数の上限も `O(n^2)`
- 追加メモリは stack `b` を除けば `O(1)`

### chunk_sort / O(n√n)

座標圧縮後の値が `0..n-1` であることを利用し、値域を chunk に分けて処理します。各 chunk の範囲 `[start, end)` に入る値を `a` の先頭から回しながら `b` へ送り、chunk の前半側の値は `rb` で下側へ回して、あとで大きい値から `a` に戻しやすくしています。

現在の chunk 幅は `sqrt(n)` に近い値です。

計算量の見積もり:

- chunk 幅を `√n` とすると、chunk 数もおよそ `√n`
- 1 chunk では、範囲内の値を拾うために残りの `a` を最大 `O(n)` 回見る
- それを `√n` chunk 分行うため、`O(n√n)`
- `b` から `a` に戻す処理も値を探して回すため、操作数の目安は同じく `O(n√n)` に収まります
- `chunk_sort` 自体の追加メモリは stack `b` を除けば `O(1)`

### radix_sort / O(n log n)

座標圧縮後の値に対して、下位ビットから順に処理します。現在のビットが `0` なら `pb`、`1` なら `ra`、1ビット分の走査後に `pa` で `b` を戻します。

計算量の見積もり:

- 最大値は `n - 1` なので、必要なビット数は `k = ceil(log2(n))`
- 各ビットで全要素 `n` 個を1回ずつ見るため `O(n * k)`
- つまり `O(n log n)`
- 各ビットごとに `pb` / `ra` と `pa` が発生するため、操作数も `O(n log n)`
- 追加メモリは stack `b` を除けば `O(1)`

## Project Structure

```txt
push_swap/
├── Makefile
├── README.md
├── include/
│   └── push_swap.h
└── src/
    ├── main.c
    ├── ft_printf_err/
    │   ├── ft_printf_err.c
    │   └── ft_printf_err_utils.c
    ├── libft/
    │   ├── ft_atoi.c
    │   ├── ft_putnbr.c
    │   ├── ft_split.c
    │   ├── ft_strdup.c
    │   ├── ft_strlen.c
    │   └── ft_strncmp.c
    ├── operations/
    │   ├── push.c
    │   ├── rotate.c
    │   ├── reverse_rotate.c
    │   ├── rotate_and_push.c
    │   └── swap.c
    ├── others/
    │   ├── compress.c
    │   ├── print_bench.c
    │   └── utils.c
    ├── sort/
    │   ├── sort.c
    │   ├── selection_sort.c
    │   ├── chunk_sort.c
    │   └── radix_sort.c
    └── stack_utils/
        ├── stack_init.c
        ├── stack_check.c
        └── stack_validate.c
```

## Notes

- `ft_printf_err` は bench と error 表示用の最小 printf です。標準エラー出力へ出します。
- `t_stack` 内のカウンタで各操作の回数を数え、`--bench` で表示します。

## checker_linux

subject に添付されている `checker_linux` を使うと、`push_swap` が出力した操作列を検証できます。

### 準備

`checker_linux` をダウンロードし、`push_swap` と同じディレクトリにコピーします。その後、実行権限を付与します。

```sh
chmod +x checker_linux
```

### push_swap の出力を検証する

`push_swap` の出力を `checker_linux` に渡します。

```sh


```

操作後のスタックが正しくソートされていれば `OK`、ソートされていなければ `KO` が表示されます。

### 操作を手動で入力する

`checker_linux` の実行後に操作を1行ずつ入力し、最後に `Ctrl+D` で入力を終了します。

`OK` になる例:

```txt
$ ./checker_linux 3 2 1
sa
rra
Ctrl+D
OK
```

`KO` になる例:

```txt
$ ./checker_linux 3 2 1
pb
pa
Ctrl+D
KO
```

## Resources

- 42 subject: push_swap
- Qiita: [push_swap で使われる Radix sort の解説](https://qiita.com/tommyecguitar/items/3c1897bceda4a06beef2)
- GeeksforGeeks: [Selection Sort Algorithm](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)

## AI Usage

AI は README の構成整理、説明文の更新、計算量の説明補助、コード変更後の整合性確認に使用しました。
