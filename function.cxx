#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <cctype>
#include <functional>
#include <queue>
using namespace std;

struct Menu {
    string kategori;
    string nama;
    int harga;
};

// Inisialisasi daftar menu
vector<Menu> daftarMenu = {
        {"Makanan", "Nasi Goreng", 10000},
        {"Makanan", "Ikan Bakar", 20000},
        {"Minuman", "Teh Manis", 5000},
        {"Makanan", "Nasi Goreng", 10000},
        {"Makanan", "Ikan Bakar", 20000},
        {"Minuman", "Jus Buah", 5000}
};

void showDaftarMenu(const vector<Menu>& daftarMenu) {
    string pemisahKategori = "";
    
        for (const auto& menu : daftarMenu) {
            /* Untuk Memisahkan Antar Kategori */
            if(pemisahKategori.empty() || pemisahKategori != menu.kategori){
                cout << endl << menu.kategori << endl;
            }
            cout << "  Nama: " << menu.nama << ", Harga: " << menu.harga << endl;
            pemisahKategori = menu.kategori;        
        }
        cout << endl;
}

#include "hashTable.cxx"
#include "Queue.cpp"
#include "sort.cpp"

// Fungsi untuk menampilkan menu utama
void showMenuPelanggan() {
    cout << "====================================\n";
    cout << "     SELAMAT DATANG DI RESTORAN\n";
    cout << "  \"MAKANAN LEZAT, PELAYANAN CEPAT\"\n";
    cout << "====================================\n";
    cout << "\nKami siap melayani kebutuhan Anda!\n";
    cout << "Silahkan pilih menu dari sistem kami:\n\n";
    cout << "====================================\n";
    cout << "   SISTEM PEMESANAN MAKANAN ONLINE\n";
    cout << "====================================\n";
    cout << "1. Lihat Daftar Menu\n"; 
    cout << "2. Urutkan Menu\n"; 
    cout << "3. Cari Menu atau Pesanan (Belum) \n";
    cout << "4. Buat Pesanan\n";
    cout << "5. Proses Pesanan\n"; 
    cout << "6. Lihat Antrian Pesanan\n";
    cout << "7. Hapus Pesanan (Belum) \n";
    cout << "8. Lihat Riwayat Pesanan (Belum) \n";
    cout << "9. Kembali Ke Menu Awal\n";
    cout << "====================================\n";
    cout << "Pilih opsi (1-9): ";
}

void showMenuPemilik() {
    cout << "====================================\n";
    cout << "  \"RUANG ADMIN\"\n";
    cout << "====================================\n";
    cout << "1. Lihat Daftar Pelanggan\n"; 
    cout << "2. Cari Data Pelanggan\n";
    cout << "3. Hapus Data Pelanggan\n";
    cout << "4. Kembali Ke Menu Awal\n"; 
    cout << "====================================\n";
    cout << "Pilih opsi (1-4): ";
}