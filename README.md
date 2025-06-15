# Kelompok-6 -> Distribusi Beasiswa Berdasarkan Nilai dan Kebutuhan 🎓

📌 Deskripsi Project

Project ini adalah penggabungan hasil dari semua materi C++, yang dimana kami membuat sistem yang berfungsi untuk mengelompokkan mahasiswa ke dalam tiga kategori berdasarkan IPK-nya:
  1. Lolos Beasiswa –> IPK ≥ 3.75
  2. Dalam Pertimbangan –> IPK 2.5 ≤ IPK < 3.75
  3. Tidak Lolos –> IPK < 2.5
Lalu Project ini juga menghitung total biaya beasiswa yang dikeluarkan dan menyusun antrian wawancara untuk kategori Dalam Pertimbangan.

❤️Fungsi Program Utama ialah:

  📝 Input data mahasiswa (nama, NIM, IPK)
  
  ⚡ Penyusunan mahasiswa berdasarkan IPK tertinggi menggunakan Quick Sort
  
  🎯 Pembagian kategori beasiswa otomatis
  
  💰 Perhitungan total dana beasiswa dengan format Rupiah
  
  ⏳ Penyusunan antrian wawancara berbasis struktur data Queue
  
  🧹 Manajemen memori dinamis dengan new dan delete

🛠️ Struktur dan Penjelasan Kode
1. Membuat class Mahasiswa
   
    Lalu Menampung data dasar mahasiswa Seperti:
   
    ~ char nama[100]
   
    ~ char nim[20]
   
    ~ float ipk
   
Metode tampilkanInfoKasual() digunakan untuk mencetak info singkat mahasiswa secara rapi.

2. Membuat fungsi quickSort
   
    Untuk mengurutkan mahasiswa berdasarkan IPK secara descending. Digunakan untuk memprioritaskan mahasiswa dengan IPK tertinggi saat         proses klasifikasi.

3. Membuat fungsi distribusiMahasiswa
   
    Lalu Memproses data mahasiswa dan mendistribusikan ke 3 kategori:
   
    ~ beasiswa
   
    ~ pertimbangan
   
    ~ tidakLolos
   
Serta menampilkan proses klasifikasinya secara real-time.

4. Membuat fungsi tampilkanKelompokKasual
   
    Mencetak semua mahasiswa dalam satu kategori ke konsol dengan tampilan yang mudah dibaca.

5. Membuat fungsi hitungTotalBiayaBeasiswa
   
    Menghitung total dana beasiswa yang dikeluarkan berdasarkan nominal tetap per mahasiswa.

6. Membuat fungsi formatRupiah
   
    Untuk konversi angka menjadi format rupiah seperti:
   
      Rp1.500.000,00

7. main()
   
   Fungsi utama yang dilakukan di main() ialah:
   
     ~ Menerima input jumlah mahasiswa

     ~ Memasukkan data mahasiswa
   
     ~ Melakukan penyortiran
   
     ~ Membagi kategori
   
     ~ Menghitung dana beasiswa
   
     ~ Menyusun antrian wawancara berdasarkan NIM
   
     ~ Membersihkan memori dinamis

Anggota Kelompok 👥

    ~ Arkhan Al Hakim Larabe 	2417053002
    ~ Alfin Lambok Kristiano Silitonga 	2417053001
    ~ Rizky Dwi Saputra	2417051009
    ~ Althaf Zabran Ismail	2417053003
