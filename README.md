# ゼノファジのパズルを解くやつ

## パズルの答え

盤面を左上から見て

||||
|-|-|-|
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |


とした場合、

| セクター | 押す順番 |
| ---- | ---- |
| K1コミュニオン | 2279 |
| K1ロジスティクス | 1567 |
| K1リベレーション | 24455568 |
| K1クルー企画 | 3458889 |


の順番で押すと解けます。

## プログラムの使い方
1. `puzzle.txt`(盤面)を以下のルールに従って編集
1. 実行！

### 記号への変換表

| 文字 | マーク |
| ---- | ---- |
| * | ![ast](https://user-images.githubusercontent.com/20632567/79740926-64763900-833b-11ea-8378-06b496d42d70.png) |
| = | ![eq](https://user-images.githubusercontent.com/20632567/79740951-6f30ce00-833b-11ea-93d1-e5b167554141.png) |
| V | ![V](https://user-images.githubusercontent.com/20632567/79740964-71932800-833b-11ea-9dd2-229a5c2d4d14.png) |
| A | ![A](https://user-images.githubusercontent.com/20632567/79740970-735ceb80-833b-11ea-98ae-1f44e4df07c4.png) |
