# 四分位，外れ値について

## 四分位(Quantile)とは

<img src="/Reference/tex/f9c4988898e7f532b9f826a75014ed3c.svg?invert_in_darkmode&sanitize=true" align=middle width=14.99998994999999pt height=22.465723500000017pt/>個のデータを標本化（抽出）したとき，その<img src="/Reference/tex/f9c4988898e7f532b9f826a75014ed3c.svg?invert_in_darkmode&sanitize=true" align=middle width=14.99998994999999pt height=22.465723500000017pt/>個はそれぞれ数値を持っていて，その数値で昇順に並びかえる．

並べたデータの<img src="/Reference/tex/a660ebd4058ad581c863efb20fd855a5.svg?invert_in_darkmode&sanitize=true" align=middle width=54.35832929999999pt height=44.70706679999999pt/>番目の数値を第<img src="/Reference/tex/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode&sanitize=true" align=middle width=9.075367949999992pt height=22.831056599999986pt/>四分位(k-th quantile;<img src="/Reference/tex/433644e6bfec246b88fde3ebfacee0cb.svg?invert_in_darkmode&sanitize=true" align=middle width=21.860802149999987pt height=22.831056599999986pt/>)という．

- 特に，第2四分位は別名「中央値（メジアン;median）」とも言う．
- もし上記の「?番目」の「?」が2.5など非整数の場合は，2番目の値と 3番目の値の平均（足して2で割る）とする．

例えば，

|subject|value|
|---|---|
|1|3|
|2|5|
|3|5|
|4|6|
|5|1|
|6|3|
|7|0|
|8|9|
|9|2|
|10|20|
|11|10|

のような<img src="/Reference/tex/08e0cb96365499c929c416d5510b7832.svg?invert_in_darkmode&sanitize=true" align=middle width=53.35601864999999pt height=22.465723500000017pt/>の標本を得たとき，valueを昇順に並び変えると

|#|subject|value|
|---|---|---|
|1|7|0|
|2|5|1|
|3|9|2|
|4|1, 6|3|
|6|2, 3|5|
|8|4|6|
|9|8|9|
|10|11|10|
|11|10|20|

N=11なので，Q1は(11+1)/4=3番目，Q2は6番目，Q3は9番目の値である．すなわち，

- Q1 : 2
- Q2 (median) : 5
- Q3 : 9

となる．

ところで，メジアン（中央値）は，標本の分布の中心を表す代表値であるが，似たような代表値で頻出するのは平均値（ミーン;mean）である．

<p align="center"><img src="/Reference/tex/096a284940ff10e0bf3ee9c4b1276b18.svg?invert_in_darkmode&sanitize=true" align=middle width=163.87775085pt height=47.806078649999996pt/></p>

今回の標本であれば，meanはおおよそ<img src="/Reference/tex/5f2663d2d774207be54e387f608b40df.svg?invert_in_darkmode&sanitize=true" align=middle width=21.00464354999999pt height=21.18721440000001pt/>である．今回はmedianとmeanのどちらか標本の分布の中心を表す代表値としてふさわしいだろうか．
ふさわしさは，標本の抽出元の母集団の分布の中心（期待値;Expectation）への近さで表される．

では，今回の標本の抽出元の母集団の分布はどんな分布しているんでしょう？

- 今回の標本には現れなかったが，母集団には負の値も含まれるのでしょうか
- 今回の標本には現れなかったが，母集団には小数も現れるのでしょうか
- 今回の標本は，0から20の間にありますが，母集団の範囲も同じでしょうか？
- 11個抽出した場合にいつでも上のメンバーになるような分布でしょうか

「わからない」が正直なところだが，ここで大きな妄想が入ります．「自然現象は正規分布する！」本当かどうかは怪しいが，わりと当たっている．
すなわち，どこかの値の周りにデータが集まりやすく，上側・下側に対称的にデータが広がって分布している．

では今回の標本はどうか．さきほどの表は，昇順にvalueの階級値ごとにデータの個数を並べると

|value|freq|*|
|---|---|---|
|0|1|*|
|1|1|*|
|2|1|*|
|3|2|**|
|4|0||
|5|2|**|
|6|1|*|
|7|0||
|8|0||
|9|1|*|
|10|1|*|
|11|0||
|12|0||
|13|0||
|14|0||
|15|0||
|16|0||
|17|0||
|18|0||
|19|0||
|20|1|*|

3列目は個数を*の数で表していて，横向きの棒グラフ（ヒストグラム）と思えばいい．正規分布から標本化したと考えると，3から5あたりに中心があって，分布の幅（標準誤差；標本の標準偏差）は，．．．

ここで第1四分位(Q1)以下の値をもつデータは，全体の<img src="/Reference/tex/ab5f479524db84a7ebea3a1b0caaf369.svg?invert_in_darkmode&sanitize=true" align=middle width=62.24652224999999pt height=43.42856099999997pt/>以下であり，同様に，Q2以下の値をもつのは<img src="/Reference/tex/34cae016d8e4805f60faa6d65887e976.svg?invert_in_darkmode&sanitize=true" align=middle width=30.137091599999987pt height=24.65753399999998pt/>以下，Q3以下の値をもつのは<img src="/Reference/tex/a765222b07b056dfefcae3aee67fd0e3.svg?invert_in_darkmode&sanitize=true" align=middle width=30.137091599999987pt height=24.65753399999998pt/>以下と言えるので，Q1とQ2（中央値）の間には<img src="/Reference/tex/cf66a3c436986d634c0bd87326cecdb9.svg?invert_in_darkmode&sanitize=true" align=middle width=30.137091599999987pt height=24.65753399999998pt/>，Q2とQ3の間にも<img src="/Reference/tex/cf66a3c436986d634c0bd87326cecdb9.svg?invert_in_darkmode&sanitize=true" align=middle width=30.137091599999987pt height=24.65753399999998pt/>，すなわちQ2を含むQ1からQ2までの範囲の値をもつデータが全体の中心的な<img src="/Reference/tex/34cae016d8e4805f60faa6d65887e976.svg?invert_in_darkmode&sanitize=true" align=middle width=30.137091599999987pt height=24.65753399999998pt/>といえる．

実は，標準偏差<img src="/Reference/tex/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode&sanitize=true" align=middle width=7.7054801999999905pt height=14.15524440000002pt/>というのは 平均を<img src="/Reference/tex/0e51a2dede42189d77627c4d742822c3.svg?invert_in_darkmode&sanitize=true" align=middle width=14.433101099999991pt height=14.15524440000002pt/>としたとき，<img src="/Reference/tex/de2f65f5494f60bf14939679ec55192f.svg?invert_in_darkmode&sanitize=true" align=middle width=42.22977164999999pt height=19.1781018pt/>から<img src="/Reference/tex/c38efb8bcf79ce0f720f7dfe54d44dc9.svg?invert_in_darkmode&sanitize=true" align=middle width=42.22977164999999pt height=19.1781018pt/>にデータの約<img src="/Reference/tex/4b566aa9c3a655c8a1d696ca22c6294e.svg?invert_in_darkmode&sanitize=true" align=middle width=30.137091599999987pt height=24.65753399999998pt/>が含まれるような値だ（本当に正規分布から標本化したら）．

今回は正規分布してそうだけどわからないので，データの<img src="/Reference/tex/34cae016d8e4805f60faa6d65887e976.svg?invert_in_darkmode&sanitize=true" align=middle width=30.137091599999987pt height=24.65753399999998pt/>を含む下限と上限をQ1とQ2として，標準偏差的なものを<img src="/Reference/tex/2e0b31d43ce6db6e61f197c50e09d104.svg?invert_in_darkmode&sanitize=true" align=middle width=43.5618513pt height=30.392597399999985pt/>と考えればよい．この分子<img src="/Reference/tex/62fc927b4112466a23f3448698eb352d.svg?invert_in_darkmode&sanitize=true" align=middle width=62.10046424999999pt height=22.465723500000017pt/>を「四分位範囲」(Interval of Quantile Range)と呼ぶ．

今回の標本では，

<p align="center"><img src="/Reference/tex/c8edea83c26d7205278cd4fbc1164832.svg?invert_in_darkmode&sanitize=true" align=middle width=207.14203125pt height=14.42921205pt/></p> 

## 外れ値

さらに，正規分布では，平均から標準偏差の3倍以上離れるとほとんどデータが存在しないはず(0.005%)で，そこにあらわれるデータは外れ値（アウトライアー;Outlier）といって同じ母集団から標本化したと言えない，もしくはノイズと考えられる．今回の場合は，その「平均から標準偏差の3倍離れた値」を「中央値から四分位範囲の2倍離れた値」や「1Qや3Qから1.5 IQR離れた値」と考える．

その値は，今回の標本から求めると，

<p align="center"><img src="/Reference/tex/45d9210a7bb74ed10ed488bdac259e19.svg?invert_in_darkmode&sanitize=true" align=middle width=498.7959966pt height=14.42921205pt/></p>

となり，subject 10 の value 20　という値は外れ値となる．

## 箱ひげ図(boxcar graph)

これら四分位で分布を表す図が箱ひげ図(boxcar graph)である．

上フタをQ3，中央をQ2，下フタをQ1の位置とした箱を書き，それに加えて
上ヒゲとして，外れ値を除いた最大値，
下ヒゲとして，外れ値を除いた最小値の位置に書いたものである．

## 2つの標本に差があるかどうか

2つの標本に差があるかどうかは，良く知られた「2群の平均値の差の検定」（ウェルチのt検定）で検定できます．
ただし，それぞれの標本の母集団が正規分布していなければいけません．また，それぞれの標本のサイズが小さいと検定に信頼がもてません．

今回は，男女合わせて12人のデータであり，性別ごとに分けた2つの標本のサイズはとても小さいです．母集団（日本人や長崎県や長崎大の男全体や女全体）は正規分布していると想定できますが，今回の数人の標本では，標本の分布と考えにくいので，標本平均や分散を母集団の平均や分散の推定値にはできません．

標本のサイズが小さいとき，分布をあらわすのが四分位です．第2四分位（中央値）は平均値のような代表値，四分位範囲は分散のような分布の幅をあらわす代表値です．第1四分位から第3四分位の範囲に標本の半分が入ります．なので，それぞれの標本のこの範囲が重ならないほど標本に差があるといえます．

つまり，女性の第3四分位<img src="/Reference/tex/1af349dd66f00fff01c6e9defe5d33a8.svg?invert_in_darkmode&sanitize=true" align=middle width=28.91450099999999pt height=22.465723500000017pt/>が男性の第1四分位<img src="/Reference/tex/03437b2883230d2658cf05a9c5a15707.svg?invert_in_darkmode&sanitize=true" align=middle width=32.87948399999999pt height=22.465723500000017pt/>より下であれば，男性と女性で差があるといっていいでしょう．また，その差の大きさは，
<img src="/Reference/tex/529f9a8aceac82728fa3261e1d83ffc5.svg?invert_in_darkmode&sanitize=true" align=middle width=82.70709149999998pt height=22.465723500000017pt/>で表されますが，この値だけ見ても大きいと考えるべきか小さいと考えるべきかわからないので，この差が四分位範囲の何倍か考えるとおおよそ0~1の間になって，判断しやすくなります．

<p align="center"><img src="/Reference/tex/0e042c06e35b4b6792507a97c54bf0fd.svg?invert_in_darkmode&sanitize=true" align=middle width=124.2742578pt height=42.5151012pt/></p>

ちなみにこの<img src="/Reference/tex/78ec2b7008296ce0561cf83393cb746d.svg?invert_in_darkmode&sanitize=true" align=middle width=14.06623184999999pt height=22.465723500000017pt/>は，勝手に私が考えてみたものですので「例えばのはなし」と思ってください．

