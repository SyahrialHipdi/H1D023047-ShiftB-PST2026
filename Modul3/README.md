## Pertanyaan Praktikum iv

1. terdapat logika pada program. Pertama program akan mengecek apakah ada jalur komunikasi dengan komputer? Jika ada, maka ambil data yang diinput oleh komputer lalu lakukan pengecekan. if data == 1, maka LED nyala dan Serial monitor akan menampilkan "LED On". Jika input yang dimasukan 0, maka LED mati. Dan jika selain input 1/0 maka perintah tidak dikenal dan LED akan berada pada kondisi sebelumnya

2. Berfungsi untuk mengecek apakah ada data yang masuk dari komputer. Hasilnya akan 0 jika tidak ada data dan > 0 jika ada data masuk. Jika baris itu dihapus, program tetap berjalan tapi tidak sesuai harapan. Karena tidak ada pengecekan data yang masuk, maka program akan terus menerima input Sehingga akan spam "Perintah tidak dikenal" walaupun kita tidak menginput apapun. akan tetapi tidak akan menerima pesan error jika seandainya komputer tidak terhubung dengan Arduino sehingga menyulitkan proses debugging.

3. ada di folder Source Code > iv

4. milis(). Jika menggunakan delay tetap bisa, tapi hanya bisa sekali, karena ketika menggunakan delay artinya mematikan program sementara, sehingga program tidak bisa menerima input lain. Jika menggunakan milis dilakukan perhitungan matematika. Program terus berjalan tanpa mati sehingga tetap bisa menerima input.
