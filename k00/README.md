# 課題0 レポート

aa83988848 薗田光太郎

## 課題

N人の身長の分布の四分位，外れ値を表示せよ．また，続いて男女別々に四分位と外れ値を表示し，男女の分布に差があるか考察せよ．

出力イメージは，

```
==Whole== 
1Q: 155.0
median: 164.5
3Q: 167.2
outlier: 190.6

==Male==
1Q: 155.0
median: 164.5
3Q: 167.2
outlier: 190.6

==Female==
1Q: 155.0
median: 164.5
3Q: 167.2
outlier: 190.6

==Result==
d = 1.5
Height of Male is higher than Female
```

以下の12人の標本を与えた場合に上に示した出力を得る．

| gender | height (cm) |
| ------ | ----------- |
|   male |       190.6 |
|   male |       164.5 |
|   male |       153.6 |
|   male |       158.7 |
|   male |       168.0 |
|   male |       159.7 |
| female |       165.7 |
| female |       155.0 |
| female |       165.6 |
| female |       167.2 |
| female |       146.5 |

## ソースコードの説明

## 修正履歴
