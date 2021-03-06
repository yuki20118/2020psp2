# 課題1 レポート

bb35319042 藤田佑樹

## 課題

標本男性の平均と分散を求めよ．また，「適当に選んだ」と言っても所詮聞く相手は周辺の同年代の同じ学部の友達に限定されそうである．周辺に住んでる同年代の工学部の男性の平均と分散を推定せよ．また，この推定される平均値は標本のとるたびに異なるので確率変数であり，今回推定した平均には誤差がある．その誤差（標準誤差）を求めよ．
   
標本平均$\bar{x}$は$\bar{x}=\dfrac{1}{N}\sum_{i=1}^{N}x_{i}$で求められる．また，標本分散$s^2$は$s^2=\dfrac{1}{N}\sum_{i=1}^{N}\left(x_{i}-\bar{x}\right)^2$もしくは，$s^2=\bar{x^2}-\left(\bar{x}\right)^2$で求められるのも有名な事実である．

しかし，プログラムでこれを計算する際に少し問題が出てくる可能性がある．実は上述の相加平均というのは先ず総和を計算してみる必要がある．最終的な相加平均はデータと同じくらいに小さく収まるが，総和はバカデカくなる可能性がある．バカデカいと計算機で扱えない数値になる可能性があるのだ．そこでデータを増やすたびに平均を更新していくという方法を取る．つまり今，$N$個のデータがあるわけだが，$N-1$個目までの平均$\bar{x}_{N-1}$を使って$\bar{x}_{N}$を作る関数 `double ave_online(double val,double ave)` を作ってみよう．また分散についても `var_online`を作ってみよう．
   
$$ \bar{x}_{N} = \frac{1}{N}\sum_{i=1}^{N} x_{i} = \frac{1}{N} \left\{\sum_{i=1}^{N-1}x_{i} + x_{N}\right\} = \frac{1}{N}\left\{(N-1)\bar{x}_{N-1} + x_{N}\right\}$$
   
つまり，$\bar{x}_{N} = \dfrac{N-1}{N} \bar{x}_{N-1} + \dfrac{1}{N} x_{N}$．この場合はバカデカい数値が計算に現れなくなる．
   
分散のほうはどうであろうか．$N-1$個目までの分散$s^2_{N-1}$を使って$s^2_{N}$を作れるだろうか．
   
$$ s^2_{N} = \frac{N-1}{N} s^2_{N-1} + \frac{1}{N} (x_{N}-\bar{x}_{N})^2$$
と考えたら大きな間違いである．
   
$$ s^2_{N} = \frac{1}{N}\sum_{i=1}^{N}\left(x_{i}-\bar{x}_{N}\right)^2 = \frac{1}{N}\left\{\sum_{i=1}^{N-1}(x_{i}-\bar{x}_{N})^2 + (x_{N}-\bar{x}_N)^2\right\} = \frac{1}{N}\sum_{i=1}^{N-1}(x_{i}-\bar{x}_{N})^2 + \frac{1}{N}(x_{N}-\bar{x}_N)^2$$
だが，$\sum_{i=1}^{N-1}(x_{i}-\bar{x}_{N})^2$は$(N-1)s^2_{N-1}$ではない．$(N-1)s^2_{N-1}=\sum_{i=1}^{N-1}(x_{i}-\bar{x}_{N-1})^2$なのだ．

そこで，もう一つの分散の計算方法で考えてみる．
$$ s^2_{N} = \bar{x^2}_{N}-\left(\bar{x}_{N}\right)^2 = \left\{\dfrac{N-1}{N}\bar{x^2}_{N-1} + \dfrac{1}{N} x^2_{N} \right\}-\left(\dfrac{N-1}{N} \bar{x}_{N-1} + \dfrac{1}{N} x_{N}\right)^2 $$
つまり，$\bar{x^2}_{N-1}$と$\bar{x}_{N-1}$と$x_{N}$があれば，$s^2_{N}$を求める関数ができる．`double var_online(double val, double ave, double square_ave)`

また，母集団の分散$u^$は標本の分散$s^2$と標本サイズ$N$から「推定」できる．所謂，不偏分散である．
$$u^2=\dfrac{1}{N-1}\sum_{i=1}^{N}\left(x_{i}-\bar{x}\right)^2=\dfrac{N}{N-1}s^2$$
一方，母集団の平均の推定値は，標本の平均$\bar{x}$が最良である．

標準誤差（standard error）は，$\sqrt{\dfrac{u^2}{n}}$で求めることができる．

したがって，今回の課題について，

|統計量|値|
|---|---|
|標本平均|$173.89$|
|標本分散|$25.36$|
|母集団平均|$173.89\pm 1.90$|
|母集団分散|$28.98$|

## ソースコードの説明

l.15 繰り返し回数をnとする。

l.33 n回目の平均をave_nに代入
l.34 n回目の2乗の平均をsquare_aveに代入
l.35 n回目の分散をvar_nに代入

l.37,38 n回目の平均と2乗の平均をn-1回目として次回使うためにave_n1,square_ave_n1に代入

l.40 母集団の分散をu2に代入
l.41 標準誤差をgapに代入

l.66 n-1回目の平均とn回目の値を使ってn回目の平均をave_nに代入してave_nを返す。

l.75 n回目の値とn-1回目の平均、n-1回目の2乗の平均を使ってn回目の分散を求め、var_nに代入してvar_nを返す。

## 入出力結果

```
input the filename of sample:../sample/heights_male.csv
the filename of sample: ../sample/heights_male.csv
ave = 173.89
var = 25.36
ave_all = 173.89+-1.90
var_all = 28.98
```

## 修正履歴

[comment #20200508]
- [k01.c#L30] l.30 `n=n++;`という処理はできません．`n++;`だけで`n=n+1;`の意味です．
- [k01.c#L54][k01.c#L64] l.54とl.64にある `return(val,ave,n)`のような処理は`return`ではできません．`return`は数値一つだけを返せます．`return ave`みたいにします．関数ではないので丸カッコも使いません．
- 間違いではありませんが，`#include <stdio.h>`みたいなものが3回くらいあります．同じファイルには1回だけで十分です．

修正提案の通りに改正してみました.

[comment #20200514]
- コンパイルして実行してみましたか？
  ```
  cd k01
  gcc -o k01 k01.c -Wall -W
  ./k01
  ```
  でコンパイルと実行できますが，私の手元では期待される結果が得られません．
- [k01.c#L31] [k01.c#L32] で関数に値を入れて計算していますが，関数から得られた結果を誰も受け取っていません．
  計算結果をもし`foo`に受け取るならば，
  ```
  foo = ave_online(val,ave,n);
  ```
  のようにしないといけないです．
- [k01.c#L61] n回目のループでの`var_online`は，n個の標本の分散を求める関数ですよね．
  関数の中では分散を求める式になっているのに，変数名はsquare_aveという名前になっています．
- whileループの中は，n回目においてn個の平均とn個の分散を求めているはずです．やり方は，
  1. n個目の標本値 val[n]を読み取る
  2. n個の標本の平均 ave[n] は val[n]と (n-1)個の標本の平均 ave[n-1]を使って計算
  3. ...
  4. n個の標本の分散 var[n] は，n個の標本の平均ave[n]と，n個の「標本の2乗」の平均 square_ave[n]を使って計算．
   　もしくは，
     n個の標本の分散 var[n] は，val[n]と，(n-1)個の標本の平均 ave[n-1]と n個の「標本の2乗」の平均 square_ave[n]を使って計算
  です．
  なので，4の処理を行う前に，n個の「標本の2乗」の平均 square_ave[n]を求める必要があります．
- 今回の課題は，
  - 標本平均
  - 標本分散
  - 母集団平均の推定値
  - 母集団分散の推定値
  の4つを求めます．ソースコードを見ると出力表示をするprintfが2つしかありません．残りの2つも表示させてください．

[comment #20200617宮下]
課題修正お疲れさまでした。
前回までの修正点の中で未修正点について補足です。
- L31 
関数ave_onlineは「n番目までの平均」を求める関数です。
（n番目までの平均を表す配列）＝　ave_online(val,ave,n)という風に書いてみましょう。

今回もいくつか修正点があります。
- L57 関数ave_online
  ave_onlineという関数はwhile文がn回目の時に
  ave「n-1番目までの平均」とval「n番目の要素」を入力すると
  新しい値「n番目までの平均」を返す関数です。
  １、新しい変数の定義
  ２、（新変数）＝（n番目までの平均の計算）
  ３、return （新変数）
  のような3行で書いてみましょう。
  また平均の計算についてですが（変数）[n]　は配列の書き方です。
  すでに関数内のaveは「n-1番目までの平均」、valは「n番目の要素」
  という意味を持っているので[]は不要です。

- L65 #include <math.h> はL4で書いているので不要です。　

[comment0708宮下]

課題提出お疲れさまでした！修正点はありません。k01完了です。

[comment #20200716 sonoda]
- 課題1完了確認
