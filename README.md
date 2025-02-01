# Konsep-CPP
Disini adalah repo untuk menjelaskan konsep konsep dasar c+++ yang sulit dipahami pemula atau bahkan yang sudah lupa karena sudah lama tidak di implementasikan (misalnya sedang nyasar ke web prog)

# 1. Pointer di C++

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Pointer memungkinkan kita untuk bekerja langsung dengan alamat memori, memberikan fleksibilitas dan efisiensi dalam pemrograman, terutama ketika berhubungan dengan alokasi memori dinamis atau manipulasi data besar.
Deklarasi Pointer

Pointer dideklarasikan dengan menambahkan tanda * di depan nama variabel. Berikut adalah cara mendeklarasikan pointer:

```cpp
tipe_data *nama_pointer;
```

Di sini, tipe_data adalah tipe data yang akan ditunjuk oleh pointer, dan nama_pointer adalah nama variabel pointer.
Contoh Sederhana Penggunaan Pointer

Berikut adalah contoh penggunaan pointer untuk menyimpan alamat memori variabel:


```cpp
int num = 10;  // Variabel biasa
int *ptr = &num;  // Pointer yang menyimpan alamat memori variabel num
    
// Menampilkan nilai variabel dan alamat memori
cout << "Nilai num: " << num << endl;          // Output: 10
cout << "Alamat memori num: " << &num << endl;  // Menampilkan alamat memori num
cout << "Alamat memori melalui pointer: " << ptr << endl;  // Menampilkan alamat memori melalui pointer
cout << "Nilai melalui pointer: " << *ptr << endl;  // Output: 10 (Dereferencing pointer)
```

Penjelasan:

    int *ptr mendeklarasikan pointer ptr yang menyimpan alamat memori variabel num.
    &num adalah operator alamat yang mengembalikan alamat memori dari variabel num.
    *ptr digunakan untuk mengakses nilai yang ditunjuk oleh pointer (dereferencing).

Mengubah Nilai Variabel Melalui Pointer

Dengan menggunakan pointer, kita bisa mengubah nilai variabel yang ditunjuk oleh pointer:


```cpp
int num = 10;  // Variabel biasa
int *ptr = &num;  // Pointer yang menyimpan alamat memori variabel num
    
cout << "Nilai num sebelum perubahan: " << num << endl;  // Output: 10
    
*ptr = 20;  // Mengubah nilai num melalui pointer
    
cout << "Nilai num setelah perubahan: " << num << endl;  // Output: 20
```

Penjelasan:

    *ptr = 20; mengubah nilai variabel num menjadi 20 dengan menggunakan pointer.

Pointer Null

Pointer yang tidak menunjuk ke alamat memori yang valid disebut pointer null. Pointer null sering digunakan untuk menandakan bahwa pointer belum mengarah ke memori yang valid.

```cpp
int *ptr = nullptr;  // Pointer null
    
if (ptr == nullptr) {
    cout << "Pointer tidak menunjuk ke alamat memori manapun." << endl;  // Output: Pointer tidak menunjuk ke alamat memori manapun.
}
```

Penjelasan:

    nullptr adalah nilai yang menunjukkan bahwa pointer tidak menunjuk ke alamat memori manapun.

Pointer ke Pointer (Pointer of Pointer)

Pointer juga bisa menunjuk ke pointer lain, yang sering disebut sebagai pointer ke pointer.


```cpp
int num = 10;
int *ptr = &num;    // Pointer pertama
int **ptr2 = &ptr;   // Pointer kedua yang menunjuk ke pointer pertama
    
cout << "Nilai melalui ptr2: " << **ptr2 << endl;  // Output: 10 (Dereference dua kali)
```

Penjelasan:

    ptr2 adalah pointer yang menyimpan alamat memori dari pointer ptr.
    **ptr2 adalah cara untuk mengakses nilai yang ditunjuk oleh pointer yang ditunjuk oleh ptr2.

Pointer dan Array

Pointer dapat digunakan untuk mengakses elemen-elemen dalam array. Array di C++ adalah sekumpulan elemen yang tersimpan secara berurutan di memori, dan pointer sangat berguna untuk mengakses elemen-elemen array ini.

```cpp
int arr[] = {1, 2, 3};   // Array dengan 3 elemen
int *ptr = arr;          // Pointer yang menunjuk ke array
    
// Menampilkan elemen array menggunakan pointer
cout << "Elemen pertama: " << *ptr << endl;  // Output: 1
cout << "Elemen kedua: " << *(ptr + 1) << endl;  // Output: 2
cout << "Elemen ketiga: " << *(ptr + 2) << endl;  // Output: 3
```

Penjelasan:

    ptr menunjuk ke elemen pertama array.
    Dengan menggunakan pointer arithmetic (ptr + 1), kita dapat mengakses elemen berikutnya.

Alokasi Memori Dinamis dengan Pointer

Dengan menggunakan operator new, kita bisa mengalokasikan memori secara dinamis untuk variabel atau array. Setelah memori selesai digunakan, kita harus membebaskannya dengan delete.

```cpp
// Alokasi memori dinamis untuk sebuah integer
int *ptr = new int;  
*ptr = 100;  // Menyimpan nilai 100 di memori yang dialokasikan
    
cout << "Nilai yang disimpan di memori dinamis: " << *ptr << endl;  // Output: 100
    
delete ptr;  // Membebaskan memori yang dialokasikan
```

Penjelasan:

    new int mengalokasikan memori untuk satu integer.
    delete ptr membebaskan memori yang dialokasikan untuk menghindari kebocoran memori.

Kesimpulan:

    Pointer memungkinkan kita untuk mengakses dan memanipulasi memori secara langsung.
    Pointer memberikan fleksibilitas dalam penggunaan alokasi memori dinamis dan pengelolaan data besar.
    Konsep seperti pointer ke pointer, pointer null, dan pointer dengan array sangat penting untuk dikuasai.


# 2. 📌 Pointer vs Reference di C++
Dengan melihat alamat memori dan nilainya, kita bisa memahami bagaimana data diproses saat dilewatkan ke fungsi.
```cpp
#include <iostream>
using namespace std;

void fungsi(int nilaiBiasa, int *nilaiPointer, int &nilaiReference) {
    cout << "Nilai biasa      : " << nilaiBiasa << endl;
    cout << "&Nilai biasa     : " << &nilaiBiasa << endl << endl;

    cout << "Nilai pointer    : " << nilaiPointer << endl;
    cout << "&Nilai pointer   : " << &nilaiPointer << endl;
    cout << "*Nilai pointer   : " << *nilaiPointer << endl << endl;

    cout << "Nilai reference  : " << nilaiReference << endl;
    cout << "&Nilai reference : " << &nilaiReference << endl;
    cout << "*Nilai reference : " << *nilaiPointer << endl << endl;
}

int main() {
    int nilai = 5;

    cout << "Nilai      : " << nilai << endl;
    cout << "&Nilai     : " << &nilai << endl << endl;

    fungsi(nilai, &nilai, nilai);

    return 0;
}
```

🔍 Penjelasan

1️⃣ Nilai Biasa (pass by value)<br>
-Saat kita memanggil fungsi dengan nilai biasa, C++ membuat salinan baru dari variabel.<br>
-Perubahan dalam fungsi tidak akan mempengaruhi nilai asli di luar fungsi.<br>
-Oleh karena itu, alamat memori berbeda dari variabel aslinya.<br>

2️⃣ Pointer (pass by pointer)<br>
-Pointer menyimpan alamat memori variabel yang dilewatkan.<br>
-Dengan menggunakan *namaPointer, kita bisa mengakses nilai dari alamat tersebut.<br>
-Perubahan pada *nilaiPointer akan mempengaruhi nilai asli.<br>
-Namun, &nilaiPointer dalam fungsi akan berbeda dari &nilai di main() karena pointer itu sendiri juga merupakan variabel baru yang menyimpan alamat.<br>

3️⃣ Reference (pass by reference)<br>
-Reference adalah alias dari variabel asli.<br>
-Tidak seperti pointer, reference tidak memiliki alamat sendiri; referensi menggunakan alamat yang sama dengan variabel asli.<br>
-Perubahan pada nilaiReference langsung mengubah nilai asli.<br>

📊 Output Program (Contoh)
```cpp
Nilai      : 5
&Nilai     : 0x61ff08


Nilai biasa      : 5
&Nilai biasa     : 0x61fef4  <-- Alamatnya berbeda dari variabel asli karena salinan baru

Nilai pointer    : 0x61ff08  <-- Menunjuk ke alamat variabel asli
&Nilai pointer   : 0x61fef0  <-- Alamat dari pointer itu sendiri
*Nilai pointer   : 5         <-- Mengambil nilai dari alamat yang ditunjuk

Nilai reference  : 5
&Nilai reference : 0x61ff08  <-- Sama dengan alamat variabel asli
*Nilai reference : 5
```

🚀 Catatan Tambahan
Gunakan reference (&) jika ingin mengubah nilai tanpa menyalin data.<br>
Gunakan pointer (*) jika butuh fleksibilitas dalam manajemen memori.<br>
