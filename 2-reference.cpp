#include <iostream>
using namespace std;

void fungsi(int nilaiBiasa, int *nilaiPointer, int &nilaiReference){
    cout << "Nilai biasa      : " << nilaiBiasa << endl;
    cout << "&Nilai biasa     : " << &nilaiBiasa << endl << endl;
    
    cout << "Nilai pointer    : " << nilaiPointer << endl;
    cout << "&Nilai pointer   : " << &nilaiPointer << endl;
    cout << "*Nilai pointer   : " << *nilaiPointer << endl << endl;

    cout << "Nilai reference  : " << nilaiReference << endl;
    cout << "&Nilai reference : " << &nilaiReference << endl;
    cout << "*Nilai reference : " << *nilaiPointer << endl << endl;
}

int main(int argc, const char *argv[]){

    int nilai = 5;
    cout << "Nilai      : " << nilai << endl;
    cout << "&Nilai     : " << &nilai << endl << endl;
    fungsi(nilai, &nilai, nilai);

    // kalau pakai pointer, ada 2 variabel, *nama untuk nilai, dan nama untuk mentyimpan alamat.
    // Tapi si nama juga punya alamat sendiri jika digunakan &a.
    // Jadi konsepnya, 
    // si nama terletak di alamat xxxx, 
    // nama nilainya  alamat yyy, 
    // *nama nilainya isi si alat yg ditunjuk

    // kalau pakai reference, hany ada 2, yaitu nama, &nama, sedangkan nilai *nama nya == nama
    // jadi :
    // &nama addressnya sama dengan address si nilai yg disimpan, jadi si &nama ini bukan variabel baru
    // tapi hanya nama lain

    return 0;
}
