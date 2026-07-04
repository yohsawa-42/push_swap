*This project has been created as part of the 42 curriculum by yohsawa, msumiji.*

# push_swap

## Description

`push_swap` は、2つのスタック `a` / `b` と限られた操作だけを使い、整数列を昇順へ並べ替える操作列を出力する 42 curriculum の課題です。

この実装では、入力を検証したあと座標圧縮を行い、入力サイズや disorder に応じてソート戦略を切り替えます。通常の操作列は標準出力へ出し、`--bench` 指定時の統計情報は標準エラー出力へ出します。

使用する操作:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

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

selector を省略した場合も adaptive として動きます。要素数が `5` 以下の場合は、selector に関係なく `sort_small` を優先します。

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

### 値を順位に変換

ソート前に入力値を順位へ変換します。

```txt
input:      42 -10 7
compressed: 2   0 1
```

`push_swap` では値そのものではなく大小関係だけが必要です。`0..n-1` に圧縮すると、負数や大きな整数を気にせず扱え、radix sort で必要なビット数も `log2(n)` 程度に抑えられます。

### sort_small / O(1)

要素数 `2..5` 用の専用処理です。

- `2`: 必要なら `sa`
- `3`: 並びに応じて `sa`, `ra`, `rra`
- `4..5`: 最小値を `b` に退避し、残り3個を整列して戻す

計算量の見積もり:

- 対象サイズが最大5なので、理論上は定数時間 `O(1)`
- `find_min_pos` は線形探索ですが、最大5個に限定されます
- 操作数も小さい定数個に収まります

### selection_sort / O(n^2)

座標圧縮後の値が `0..n-1` であることを利用し、`0`, `1`, `2` ... の順に探して `b` へ送り、最後に `a` へ戻します。

計算量の見積もり:

- 各 target について `find_pos` が最大 `O(n)`
- それを n 回行うため探索だけで `O(n^2)`
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

### adaptive_sort

selector がない場合、または `--adaptive` の場合は disorder を計算して戦略を選びます。

disorder は、全ての組 `(i, j)` について `i < j` かつ `a[i] > a[j]` となる inversion の割合です。

- `disorder < 0.2`: `selection_sort`
- `0.2 <= disorder < 0.5`: `chunk_sort`
- `0.5 <= disorder`: `radix_sort`

## Project Structure

```txt
push_swap/
├── Makefile
├── README.md
├── include/
│   └── push_swap.h
└── src/
    ├── main.c
    ├── compress.c
    ├── utils.c
    ├── print_bench.c
    ├── ft_printf_err/
    │   ├── ft_printf_err.c
    │   └── ft_printf_err_utils.c
    ├── operations/
    │   ├── push.c
    │   ├── rotate.c
    │   ├── reverse_rotate.c
    │   ├── rotate_and_push.c
    │   └── swap.c
    ├── sort/
    │   ├── sort.c
    │   ├── sort_small.c
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
- `t_operations` で各操作の回数を数え、`--bench` で表示します。
- `rotate_and_push.c` には、指定位置を最短方向で top に回してから push する補助関数を置いています。

## Resources

- 42 subject: push_swap
- Qiita: [push_swap で使われる Radix sort の解説](https://qiita.com/tommyecguitar/items/3c1897bceda4a06beef2)
- GeeksforGeeks: [Selection Sort Algorithm](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)

## AI Usage

AI は README の構成整理、説明文の更新、計算量の説明補助、コード変更後の整合性確認に使用しました。
