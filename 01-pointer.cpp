#include <iostream>

int main() {
    // 1. Deklarasi dan penggunaan pointer sederhana
    int num = 10;
    int *ptr = &num; // Pointer ptr menyimpan alamat memori dari variabel num
    
    // Menampilkan nilai num melalui pointer
    std:cout << "Nilai num: " << num << std::endl; // Output: 10
    std::cout << "Alamat memori num: " << &num << std::endl;
    std::cout << "Alamat memori melalui pointer: " << ptr << std::endl; // Output: alamat memori
    std::cout << "Nilai melalui pointer: " << *ptr << std::endl; // Output: 10 (Dereferencing pointer)

    // 2. Mengubah nilai variabel melalui pointer
    *ptr = 20; // Mengubah nilai num melalui pointer
    std::cout << "Nilai num setelah perubahan: " << num << std::endl; // Output: 20

    // 3. Pointer Null
    int *ptrNull = nullptr; // Pointer null
    if (ptrNull == nullptr) {
        std::cout << "Pointer tidak menunjuk ke alamat memori manapun." << std::endl; // Output: Pointer tidak menunjuk ke alamat memori manapun.
    }

    // 4. Pointer ke Pointer
    int **ptr2 = &ptr; // Pointer ptr2 menunjuk ke pointer ptr
    std::cout << "Nilai yang ditunjuk oleh ptr2: " << **ptr2 << std::endl; // Output: 20 (Dereference dua kali)

    // 5. Pointer dengan Array
    int arr[] = {10, 20, 30, 40};
    int *ptrArr = arr; // Pointer menunjuk ke elemen pertama array
    
    std::cout << "Elemen pertama array: " << *ptrArr << std::endl; // Output: 10
    std::cout << "Elemen kedua array: " << *(ptrArr + 1) << std::endl; // Output: 20 (Pointer arithmetic)

    // 6. Menggunakan Pointer dalam Fungsi
    void changeValue(int *ptr);
    int num1 = 30;
    std::cout << "Nilai num1 sebelum perubahan: " << num1 << std::endl; // Output: 30
    changeValue(&num1); // Mengirimkan alamat memori num1
    std::cout << "Nilai num1 setelah perubahan: " << num1 << std::endl; // Output: 50

    // 7. Alokasi Memori Dinamis
    int *ptrDynamic = new int; // Alokasi memori dinamis
    *ptrDynamic = 100;         // Menyimpan nilai 100 di alamat memori dinamis
    
    std::cout << "Nilai ptrDynamic: " << *ptrDynamic << std::endl; // Output: 100

    delete ptrDynamic; // Membebaskan memori yang dialokasikan

    return 0;
}

// Fungsi untuk mengubah nilai menggunakan pointer
void changeValue(int *ptr) {
    *ptr = 50; // Mengubah nilai yang ditunjuk oleh pointer
}
