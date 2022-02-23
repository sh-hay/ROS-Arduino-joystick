# ROS-Arduino-joystick

## 使用機器
- Arduino Mega
- Docker
- ROS serial
- PS4 コントローラー  

## Run Docker container
```bash
$ cd
$ docker build -t shhay/ros-joy .
$ docker run -it --rm --name ros-joy shhay/ros-joy
```

### ino [使い方](https://qiita.com/RyodoTanaka/items/9480fbe4999dbf8cc25e)
```bash
# プロジェクトの生成
$ ino init
# ビルド
$ ino build
# 書き込み
$ ino upload
# シリアル通信
$ ino serial
# 尚、他にもコマンドあがるので、
$ ino -h
で確認しておきましょう。
```


## 参考
[ROSのrosserialを使ってArduinoでLチカをする](https://qiita.com/nnn112358/items/059487952eb3f9a5489b)  
[コマンドラインからArduinoの書き込みなどを行う (ino を使う 編)](https://qiita.com/RyodoTanaka/items/9480fbe4999dbf8cc25e)  