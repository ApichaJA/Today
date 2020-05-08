Communication Binary

นาย อภิชา จรรยาธนากร 62070216

นาย ธัชนิน มูลผล 62070089

นาย โชติชัน วิจิตรแก้ว 62070049

นางสาว ลลิตวดี สิงห์สูตร 62070160

หลักการทำงาน

ขั้นตอนที่ 1

ESP8266 ตัวที่1 ที่เป็นตัวส่ง จะมี module

GY-21P เป็นตัวรับ ค่าความกดอากาศ อุณหภูมิ ความชื้น
MQ-2 Gas sensor เป็นตัวรับ ค่าแก้
Transmitter เป็นตัวส่งข้อมูลโดยใช้คลื่น 433 Mhz

เมื่อModule Transmitter ได้รับข้อมูลครบแล้วจะทำการส่งไปที่ตัว รับ Receiver(ESP8266 Board ตัวที่ 2)


ขั้นตอนที่ 2 

เมื่อ Module Receiver ได้รับข้อมูล ก็จะทำการส่งไปใน ESP8266 เพื่อทำการแปลงข้อมูลต่างๆ
เมื่อทำการแปลงเสร็จแล้วก็จะทำขั้นตอนต่อไป


ขั้นตอนที่ 3

เป็นขั้นตอนที่ นำค่าต่างๆที่ได้รับมาจาก Board ตัวแรกขึ้นไปบน Realtime database (ใช้Firebase)
เมื่อข้อมูลถูกPushขึ้นไปทั้งหมด ก็จะทำการกลับไปที่ ESP8266 ตัวแรก และเป็น Loop แบบนี้ไปเรื่อยๆ


ขั้นตอนที่ 4

แสดงข้อมูลต่างๆที่ได้รับมา ขึ้นบนเว็บโดยดึงข้อมูลต่างๆ มาจาก Realtime database โดยการสร้างเว็บนี้เขียนด้วย Framework vue

# howabout-today

Link Youtube: https://www.youtube.com/watch?v=rWjcxBk0uIw&fbclid=IwAR1g5hAVuq3_I8zYc8Z2tPXgNf2YN4YXQBLNrhe3ywLT1mVb-Ad-QQNotMM

## Project setup
```
npm install
```

### Compiles and hot-reloads for development
```
npm run serve
```

### Compiles and minifies for production
```
npm run build
```

### Lints and fixes files
```
npm run lint
```

### Customize configuration
See [Configuration Reference](https://cli.vuejs.org/config/).
