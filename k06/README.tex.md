# 課題6 レポート

bb35319042 藤田佑樹

## 課題

[sample/heights.csv]は標本全体のデータをまとめたものである．
今回の標本14人では，男性8人，女性6人であるが，同年代の工学部学生全体でも男性のほうが多いのだろうか．男性の割合$r$の推定範囲を求めよ．

[母比率の信頼区間][1]

[1]:../Reference/PopulationRatio.md

## ソースコードの説明
l.6~7 母比率を求めるget_bound,組み合わせの数を求めるchooseを定義

l.19~28 heights.csvを読み込む

l.33 heights.csvの性別、身長のデータをそれぞれgender,valに代入

l.34~43 genderの値によって性別ごとの人数をそれぞれnum_male,num_female,num_unknownに代入

l.44 全体の人数num_wholeに上記の3つの関数の和を代入

l.46~49 num_male,num_femaleに加え標本中の男性の割合を出力

l.56 get_boundに飛ぶ。

l.58 男性の割合rの推定範囲を出力


l.65 get_bound関数について

l.72~77 下側2.5％の点を求める。

l.79~86 上側2.5％の点を求める。


l.89 choose関数について

l.93~96 それぞれ分母n,分子rがr,0になるまでそれぞれをかけていき、分子/分母を返す。






## 入出力結果
```
input the filename of sample:../sample/heights.csv
the filename of sample: ../sample/heights.csv
================================
Number of male sample : 8
Number of female sample : 6
Male Ratio : 0.533333
0.000000
0.000000
0.000030
0.000461
0.002806
0.009978
0.024728
0.046926
0.000000
0.000003
0.000194
0.001921
0.008369
0.022714
0.044839
Population Male Ratio (estimated) : 0.466667--0.600000
============================
```
## 修正履歴

