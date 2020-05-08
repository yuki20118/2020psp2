# 課題1 レポート

aa83988848 薗田光太郎

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

あいうえお

## 入出力結果

```
input the filename of sample:../sample/heights_male.csv
the filename of sample: ../sample/heights_male.csv
sample mean：
sample variance：
population mean (estimated)：
population variance (estimated)：
```

## 修正履歴

説明は「かきくけこ」だ！
