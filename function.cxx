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

bool isDataSaved = true;
const int maxPelanggan = 100;
string daftarPelanggan[maxPelanggan];

void showDaftarMenu(const vector<Menu>& daftarMenu) {
    map<string, vector<Menu>> daftarMenuTerurut;
    for (const auto& menu : daftarMenu) {
        daftarMenuTerurut[menu.kategori].push_back(menu);
    }
    for (const auto& pair : daftarMenuTerurut) {
        cout << endl << "Kategori: " << pair.first << endl;
        cout << "-----------------------------------------------" << endl;
        
        cout << "| No. | Nama "<< pair.first <<"              |  Harga |" << endl;
        cout << "-----------------------------------------------" << endl;
        int no = 1;
        for (const auto& menu : pair.second) {
            cout << "| " << setw(3) << left << no << " | " << setw(25) << left << menu.nama << " | " << setw(6) << right << menu.harga << " |" << endl;
            no++;
        }
        cout << "-----------------------------------------------" << endl;
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
    cout << "7. Hapus Pesanan\n";
    cout << "8. Lihat Riwayat Pesanan\n";
    cout << "9. Kembali Ke Menu Awal\n";
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