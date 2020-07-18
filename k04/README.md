# 課題4 レポート

bb35319042 藤田佑樹

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
l.6~11: 構造体student_dataを定義

l.22: student_dataを使用することを定義。

l.25~33: heights.csvのデータを取り込む

l.36~44: heights.csvのデータをそれぞれdetail[i].gender,detail[i].heightに代入

l.54~61: IDs.csvのデータを取り込む

l.66~76: IDs.csvのデータをdetail[i].IDに代入

l.79~82: どのIDについて検索するか確認する

l.84~105: 入力されたIDについて該当するものがある場合にはそれぞれのデータを表示し、無い場合にはNo dataと出力する。



## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

