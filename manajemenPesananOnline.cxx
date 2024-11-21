#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Menu {
    string kategori;
    string nama;
    string harga;
};

int main() {
    vector<Menu> daftarMenu = {
        {"Makanan", "Nasi Goreng", "10000"},
        {"Makanan", "Ikan Bakar", "20000"},
        {"Minuman", "Teh Manis", "5000"},
        {"Minuman", "Jus Buah", "5000"}
    };

    string pemisahKategori = "";

    for (const auto& menu : daftarMenu) {
        
        /* Untuk Memisahkan Antar Kategori */
        if(pemisahKategori.empty() || pemisahKategori != menu.kategori){
            cout << endl << menu.kategori << endl;
        }

        cout << "  Nama: " << menu.nama << ", Harga: " << menu.harga << endl;

        pemisahKategori = menu.kategori;        
    }

    return 0;
}