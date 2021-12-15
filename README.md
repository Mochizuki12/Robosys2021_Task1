# Robosys2021_Task1

---

# １．概要
2021年度ロボットシステム学7～8回にて作成したコードを改変し、

2～9までの任意の最大値を決め、その最大値までの1～9までの値をランダムに7セグメントLEDで表示するようにしたデバイスドライバです。

2～9個の中からどれでもいいけど、何かを選ぶときに決めきれず、困ったときに役立つと思います。

---

# ２．確認済み動作環境

- Raspberry Pi4 Model B 8GB OKdo版

- OS : Ubuntu 20.04

---

# ３．用意する物

- 1kΩ抵抗 × 7

- ジャンパー線（オス-メス）× 8

- ジャンパー線（オス-オス）× 13

- 7セグメントLED × 1

- ブレッドボード × 1

- Raspberry Pi4 Model B × 1

# ４．実体配線図

下の図のように配線してください

![7seg_ブレッドボード](https://user-images.githubusercontent.com/92071009/146275109-d0719f07-5a0c-4839-9b98-1e867ac421b9.png)

# ５．デバイスドライバの使用方法

#### １．インストール

以下のコマンドを上から順に実行してください。

```
$ git clone git@github.com:Mochizuki12/Robosys2021_Task1.git

$ cd Robosys2021_Task1

$ make

$ sudo insmod myled.ko

$ sudo chmod 666 /dev/myled0
```

#### ２．実行


##### 2.1．最大値が2でランダムな値を表示

```
$ echo 2 > /dev/myled0
```

##### 2.2．最大値が3でランダムな値を表示

```
$ echo 3 > /dev/myled0
```

##### 2.3．最大値が4でランダムな値を表示

```
$ echo 4 > /dev/myled0
```

##### 2.4．最大値が5でランダムな値を表示

```
$ echo 5 > /dev/myled0
```

##### 2.5．最大値が6でランダムな値を表示

```
$ echo 6 > /dev/myled0
```

##### 2.6．最大値が7でランダムな値を表示

```
$ echo 7 > /dev/myled0
```

##### 2.7．最大値が8でランダムな値を表示

```
$ echo 8 > /dev/myled0
```

##### 2.8．最大値が9でランダムな値を表示

```
$ echo 9 > /dev/myled0
```

#### ３．アンインストール

以下のコマンドを上から順に実行してください。

```
$ sudo rmmod myled

$ make clean
```

---

## ６．デモ動画
上記の手順を踏み実際に動作させた動画です

[セグメントLEDで1～９のランダムな数字を表示するデバイスドライバ](https://youtu.be/__I8KDhq_y0)

---

## ７．ライセンス

[GNU General Public License v3.0](https://github.com/Mochizuki12/Robosys2021_Task1/blob/main/COPYING)


