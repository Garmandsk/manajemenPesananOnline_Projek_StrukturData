#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <cctype>
#include <functional>
#include <queue>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map> // Tambahkan untuk menggunakan map
#include <map> // Tambahkan untuk menggunakan map
using namespace std;

struct Menu {
    string kategori;
    string nama;
    int harga;
};

struct RiwayatPesanan {
    Menu menu;
    RiwayatPesanan* next;
};

vector<Menu> daftarMenu = {
        {"Minuman", "Teh Manis", 5000},
        {"Makanan", "Nasi Goreng", 10000},
        {"Makanan", "Ikan Bakar", 20000},
        {"Minuman", "Jus Buah", 5000}
};

bool isDataSaved = true;
string namaPelanggan; 

/* Variabel Global Queue dan Linked List */
queue<Menu> antrianPesanan; 
RiwayatPesanan* riwayat = nullptr;

/* Variabel Global HashTable */
int ukuranHashTable = 10;
const int maxPelanggan = 100;
string daftarPelanggan[maxPelanggan];
vector<list<pair<string, vector<string>>>> dataPelanggan(ukuranHashTable);

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

#include "sort.cpp"
#include "hashTable.cxx"
#include "Queue.cpp"

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
    cout << "1. Buat Pesanan\n";
    cout << "2. Lihat Antrian Pesanan\n";
    cout << "3. Lihat Riwayat Pesanan\n";
    cout << "4. Kembali Ke Menu Awal\n";
    cout << "====================================\n";
    cout << "Pilih opsi (1-9): ";
}

void showMenuPemilik() {
    cout << "====================================\n";
    cout << "  \"RUANG ADMIN\"\n";
    cout << "====================================\n";
    cout << "1. Lihat dan Simpan Daftar Pelanggan\n"; 
    cout << "2. Cari Data Pelanggan\n";
    cout << "3. Hapus Data Pelanggan\n";
    cout << "4. Kembali Ke Menu Awal\n"; 
    cout << "====================================\n";
    cout << "Pilih opsi (1-4): ";
}

void keluarProgram() {
    if (!isDataSaved) {
        simpanData:
        cout << endl << "Anda BELUM menyimpan perubahan data pelanggan.\n";
        cout << "Apakah Anda ingin menyimpan sekarang? (y/n): ";
        string pilihan;
        cin >> pilihan;
        if (pilihan == "y" || pilihan == "Y") {
            // Simpan data sebelum keluar
            simpanDataPelanggan(daftarPelanggan, maxPelanggan);
        } else if (pilihan == "n" || pilihan == "N"){
            cout << endl << "Perubahan data tidak disimpan. Keluar program...\n";
        } else {
            cout << endl << "Masukkan Ulang!" << endl << endl;     
            cin.ignore();
            cin.get();  
            goto simpanData;
        }
    } else {
        cout << endl << "Data sudah tersimpan. Keluar program...\n";
    }
}