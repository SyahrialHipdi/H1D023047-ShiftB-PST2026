# Percobaan Satu_LED tidak langsung reset

## Deskripsi
Program ini akan membuat LED berkedip dengan cepat lalu melambat sampai mati dan mengulanginya lagi dari lambat
Lambat -> sedang -> cepat -> sedang -> cepat -> mati -> ulang.
Pada program ini perlu tambahan variable agar program dapat menentukan kapan saatnya melambat dan kapan saatnya mempercepat. Disini, saya menggunakan variable "batas".
Ketika batas == false, delay akan terus berkurang.
Ketika batas == true, maka delay akan bertambah.
Untuk Codenya bisa dilihat di
Source Code/1.5.4/main.ino

# Percobaan Dua_Tiga LED menyala bergantian

## Deskripsi
Program ini akan membuat 6 LED (3 kanan dan 3 kiri) akan menyala secara bergantian. Ketika sisi kanan nyala, sisi kiri mati dan sebaliknya.
Codenya bisa dilihat di: 
Source Code/1.6.4/main.ino
