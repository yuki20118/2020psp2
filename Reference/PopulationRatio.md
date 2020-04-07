# 母比率の信頼区間

母比率（工学部全体における男性の割合）が<img src="/Reference/tex/2ec6e630f199f589a2402fdf3e0289d5.svg?invert_in_darkmode&sanitize=true" align=middle width=8.270567249999992pt height=14.15524440000002pt/>のとき，無作為に選んだ14人のうち8人が男性である確率は，
<p align="center"><img src="/Reference/tex/792eaaf36915a3388886f1ab991b36dc.svg?invert_in_darkmode&sanitize=true" align=middle width=162.7478028pt height=18.312383099999998pt/></p>
である．

よって下側2.5%の点のp_lは
```
z=0;
n=0;
while(z < 0.025){
   z += choose(14,8) * pow(n/14.0, 8) * pow((14-n)/14.0, 14-8); 
   n ++; 
}
p_l = (n-1)/14.0;
```
同様に上側2.5%の点のp_uは
```
z=0;
n=14;
while(z< 0.025){
    z += choose(14,8) * pow(n/14.0, 8) * pow((14-n)/14.0, 14-8);
    n --;
}
p_u = (n+1)/14.0;
```
で求められる．

ここで，`pow(x,n)`は標準数学関数で`math.h`に定義されている．`choose(n,x)`は<img src="/Reference/tex/f95e46cc118874781786429e748bf959.svg?invert_in_darkmode&sanitize=true" align=middle width=28.15115984999999pt height=22.465723500000017pt/>を計算する関数で自作する必要がある．



