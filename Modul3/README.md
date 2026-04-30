## Pertanyaan Praktikum iv

1. terdapat logika pada program. Pertama program akan mengecek apakah ada jalur komunikasi dengan komputer? Jika ada, maka ambil data yang diinput oleh komputer lalu lakukan pengecekan. if data == 1, maka LED nyala dan Serial monitor akan menampilkan "LED On". Jika input yang dimasukan 0, maka LED mati. Dan jika selain input 1/0 maka perintah tidak dikenal dan LED akan berada pada kondisi sebelumnya

2. Berfungsi untuk mengecek apakah ada data yang masuk dari komputer. Hasilnya akan 0 jika tidak ada data dan > 0 jika ada data masuk. Jika baris itu dihapus, program tetap berjalan tapi tidak sesuai harapan. Karena tidak ada pengecekan data yang masuk, maka program akan terus menerima input Sehingga akan spam "Perintah tidak dikenal" walaupun kita tidak menginput apapun. akan tetapi tidak akan menerima pesan error jika seandainya komputer tidak terhubung dengan Arduino sehingga menyulitkan proses debugging.

3. ada di folder Source Code > iv

4. milis(). Jika menggunakan delay tetap bisa, tapi hanya bisa sekali, karena ketika menggunakan delay artinya mematikan program sementara, sehingga program tidak bisa menerima input lain. Jika menggunakan milis dilakukan perhitungan matematika. Program terus berjalan tanpa mati sehingga tetap bisa menerima input.

## Pertanyaan Praktikum 3.6.4
1. pada LCD yang menggunakan modul I2C, komunikasi menggunakan dua jalur: SDA dan SCL. Arduino akan mengirim sinyalmulai dan mengirim alamat (0x27). Jika cocok, LCD dan Arduino dapat bertukar data. Semisal Arduino mengirim data untuk mengcetak "Hallo World", data akan diterima LCD lalu ditampilkan.

2. Tidak harus seperti itu, tapi alangkah baiknya begitu karena sesuai panduan. Jika dipasang terbalik tidak mengapa, program masih bisa berjalan.

3. ada di folder Source Code > 3.6.4

4. 1, 0.0048, 0.0977
	21, 0.1026, 2.0527
	49, 0.2394, 4.7898
	74, 0.3616, 7.2336
	96, 0.4692, 9.3841


## Pertanyaan Praktikum 3.7

1. Kelebihan dan Keuntungan UART dan I2C
Keuntungan UART:
Sederhana dan mudah digunakana
Stabil untuk komunikasi point-to-point
Cepat untuk komunikasi jarak pendek

Kerugian UART:
Tidak mendukung banyak perangkat
Tidak ada metode addressing
Sinkronisasi bergantung pada baud rate


Keuntungan I2C
Mendukung banyak perangkat
Hemat Pin
Mendukung Komunikasi kompleks

Kerugian I2C
Lebih kompleks dibanding UART
lebih lambat dari UART
Rentan terhadap noise

2. Alamat pada metode komunikasi I2C berfungsi sebagai identitas unik. pad I2C semua device terhubung pada satu bus yang sama. oleh karena itu, setiap device diberi alamat unik. Dalam penerapan LCD, Jika data dikirim pada alamat yang salah, LCD tidak akan merespon. Alamat pada device sendiri sudah ditentukan oleh hardware, tidak random

3. Pertama data akan masuk ke Komputer melalui Serial Monitor. Lalu data diteruskan ke Arduino, lalu Arduino akan mengirim datanya ke LCD via I2C. Arduino tidak menjalankan keduanya secara parallel tapi bergantian dengan sangat cepat.
