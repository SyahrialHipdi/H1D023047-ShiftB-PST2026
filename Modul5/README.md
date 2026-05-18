# Percobaan 1

## Deskripsi
Program ini merupakan implementasi multitasking menggunakan FreeRTOS pada Arduino.  
Program memiliki 3 task:

1. TaskBlink1  
   Mengontrol LED pada pin 8.

2. TaskBlink2  
   Mengontrol LED pada pin 9.

3. TaskPrint  
   Membaca nilai potensiometer dan menampilkan data ke Serial Monitor.

---

## Komponen
- Arduino Uno
- 2 LED
- 2 Resistor 220Ω
- Potensiometer
- Breadboard
- Kabel jumper

---

## Koneksi
### LED 1
- Anoda → Pin 8
- Katoda → Resistor → GND

### LED 2
- Anoda → Pin 9
- Katoda → Resistor → GND

### Potensiometer
- VCC → 5V
- GND → GND
- Output tengah → A0


# Percobaan 2

## Deskripsi
Program ini menggunakan FreeRTOS pada Arduino untuk melakukan multitasking dalam membaca sensor DHT dan menampilkan data secara realtime menggunakan Queue.

Sensor DHT digunakan untuk membaca:
- Suhu (Temperature)
- Kelembapan (Humidity)

Data sensor dikirim dari task pembacaan sensor ke task display menggunakan Queue FreeRTOS.

---

## Komponen
- Arduino Uno
- Sensor DHT11 / DHT22
- Resistor 10KΩ (pull-up)
- Breadboard
- Kabel jumper

---

## Library
Program membutuhkan library:
- Arduino_FreeRTOS
- DHT sensor library by Adafruit
- Adafruit Unified Sensor

---

## Koneksi Sensor DHT11

| Pin DHT11 | Arduino |
|----------|----------|
| VCC      | 5V       |
| DATA     | Pin 2    |
| GND      | GND      |
