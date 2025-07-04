﻿# TugasDataStructure

✈️ Sistem Manajemen Penumpang Pesawat (C++)
Proyek ini merupakan aplikasi berbasis C++ yang berjalan di terminal/console dan menyediakan fitur CRUD (Create, Read, Update, Delete), Hashing, dan Sorting untuk pengelolaan data penumpang pesawat. Cocok untuk pembelajaran dasar pemrograman struktural dan logika sistem manajemen data.

🛠️ Fitur Utama
✅ Tambah Penumpang (Create): Menambahkan data penumpang baru ke sistem.

📄 Lihat Semua Penumpang (Read): Menampilkan daftar seluruh penumpang yang sudah diurutkan berdasarkan nama.

✏️ Edit Data Penumpang (Update): Mengubah informasi penumpang yang sudah ada berdasarkan ID.

❌ Hapus Penumpang (Delete): Menghapus data penumpang dari sistem berdasarkan ID.

🔍 Cari Penumpang berdasarkan ID (Hashing): Mempercepat pencarian penumpang menggunakan fungsi hash.

🧮 Sorting berdasarkan Nama (Bubble Sort): Mengurutkan daftar penumpang secara alfabetis berdasarkan nama.

🧠 Struktur Data: Menggunakan vector untuk menyimpan data dan unordered_map untuk implementasi hashing.

📂 Struktur Proyek
passenger-management-system/
├── src/
│   └── main.cpp ← Kode utama program
├── README.md    ← Dokumentasi proyek
├── .gitignore   ← File ignore (opsional)
└── LICENSE      ← Lisensi (MIT)

🧪 Cara Menjalankan Program
🔁 Clone Repositori
Pertama, clone repositori ini ke komputer Anda:

git clone https://github.com/username/passenger-management-system.git
cd passenger-management-system

Catatan: Ganti username dengan nama pengguna GitHub Anda dan passenger-management-system dengan nama repositori Anda jika Anda mengunggahnya ke GitHub.

⚙️ Kompilasi Program
Pastikan Anda sudah menginstal compiler C++ (misalnya, g++ melalui MinGW di Windows, atau sudah terinstal secara default di lingkungan Linux/macOS).

Buka terminal atau command prompt di direktori proyek (passenger-management-system/) dan jalankan perintah kompilasi:

g++ src/main.cpp -o passenger_system

Perintah ini akan membuat file executable bernama passenger_system (atau passenger_system.exe di Windows).

▶️ Jalankan Program
Setelah berhasil dikompilasi, Anda dapat menjalankan program dengan perintah berikut:

./passenger_system

Di Windows, Anda mungkin perlu menjalankan:

.\passenger_system.exe

🧩 Struktur Data Internal
Sistem ini menggunakan kombinasi dua struktur data utama untuk efisiensi:

vector<Passenger>: Ini adalah kontainer dinamis yang menyimpan semua objek Passenger. Setiap kali penumpang ditambahkan, dihapus, atau diedit, operasi utamanya dilakukan pada vector ini.

unordered_map<int, vector<int>>: Struktur data ini digunakan untuk mempercepat operasi pencarian (searchPassenger) menggunakan teknik hashing.

Key: Hasil dari hashFunction(ID_penumpang) (yaitu ID_penumpang % 10).

Value: Sebuah vector yang berisi indeks-indeks (int) dari objek Passenger di vector<Passenger> yang memiliki hash key yang sama. Ini menangani potensi kolisi hash.

💡 Contoh Tampilan Program
Saat program dijalankan, Anda akan melihat menu interaktif di terminal seperti ini:

==================================================
      SISTEM MANAJEMEN PENUMPANG PESAWAT
==================================================
1. Tambah Penumpang
2. Lihat Semua Penumpang
3. Edit Data Penumpang
4. Hapus Penumpang
5. Cari Penumpang
6. Keluar
==================================================
Pilihan Anda:

🔍 Penjelasan Hashing dan Sorting
Hashing
Fitur hashing diterapkan untuk mempercepat proses pencarian penumpang berdasarkan ID. Ketika Anda mencari penumpang dengan ID tertentu, sistem tidak perlu memindai seluruh daftar penumpang. Sebaliknya, ia langsung menghitung hash dari ID tersebut untuk menemukan lokasi potensial penumpang di unordered_map, yang secara signifikan mengurangi waktu pencarian.

Fungsi hash yang digunakan sangat sederhana:

int hashFunction(int id) {
    return id % 10;
}

Ini berarti penumpang akan dikelompokkan ke dalam "bucket" berdasarkan digit terakhir dari ID mereka.

Sorting
Proyek ini menggunakan algoritma Bubble Sort untuk mengurutkan daftar penumpang secara alfabetis berdasarkan nama mereka sebelum ditampilkan. Meskipun Bubble Sort bukan algoritma pengurutan yang paling efisien untuk kumpulan data besar, ia mudah dipahami dan diimplementasikan, sehingga cocok untuk tujuan pembelajaran dalam proyek ini.

Fungsi pengurutan yang digunakan adalah:

void sortByName() {
    for (int i = 0; i < passengers.size() - 1; i++) {
        for (int j = 0; j < passengers.size() - i - 1; j++) {
            if (passengers[j].name > passengers[j + 1].name) {
                std::swap(passengers[j], passengers[j + 1]);
            }
        }
    }
}

⚙️ Teknologi yang Digunakan
Bahasa: C++

Compiler: GCC / MinGW / Clang (atau compiler C++ standar lainnya)

Library Standar C++:

<iostream>: Untuk operasi input/output dasar.

<vector>: Untuk penggunaan array dinamis.

<string>: Untuk manipulasi string.

<algorithm>: Menyediakan fungsi std::swap.

<iomanip>: Untuk memformat output (misalnya, setw untuk lebar kolom).

<unordered_map>: Untuk implementasi hash table.
