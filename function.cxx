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
#include <map> 
#include <windows.h> 
using namespace std;

struct Menu {
    string kategori;
    string nama;
    int harga;
    int id;
};

struct RiwayatPesanan {
    Menu menu;
    RiwayatPesanan* next;
};

vector<Menu> daftarMenu = {
        {"Minuman", "Teh Manis", 5000, 1}, // Tambahkan id untuk setiap menu
        {"Makanan", "Nasi Goreng", 10000, 2},
        {"Makanan", "Ikan Bakar", 20000, 3},
        {"Minuman", "Jus Buah", 5000, 4}
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
    map<string, vector<pair<int, Menu>>> daftarMenuTerurut;

    for (int i = 0; i < daftarMenu.size(); i++) {
        daftarMenuTerurut[daftarMenu[i].kategori].push_back({daftarMenu[i].id, daftarMenu[i]});
    int no = 1; 
    for (const auto& pair : daftarMenuTerurut) {
        cout << endl << "Kategori: " << pair.first << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "| No. | ID | Nama " << pair.first << "                     |  Harga |" << endl;
        cout << "---------------------------------------------------------" << endl;
        
        cout << "| NO  | ID  | Nama "<< pair.first <<"              |  Harga |" << endl;
        cout << "-----------------------------------------------" << endl;
        int no = 1;
        for (const auto& menu : pair.second) {
            cout << "| " << setw(3) << left << no << " | " << setw(3) << left << menu.first << " | " << setw(25) << left << menu.second.nama << " | " << setw(6) << right << menu.second.harga << " |" << endl;
            no++;
        }
        cout << "---------------------------------------------------------" << endl;
    }
    cout << endl;
}

#include "sort.cpp"
#include "hashTable.cxx"
#include "Queue.cpp"

// Fungsi untuk menambahkan menu baru
void tambahMenu() {
    string namaMenu, kategoriMenu;
    int hargaMenu;

    cout << "Masukkan Nama Menu: ";
    cin.ignore(); 
    getline(cin, namaMenu);
    
    cout << "Masukkan Kategori Menu (Makanan/Minuman/Snack): ";
    getline(cin, kategoriMenu);
    
    cout << "Masukkan Harga Menu: ";
    cin >> hargaMenu;

    // Menambahkan menu baru ke daftarMenu
    daftarMenu.push_back({kategoriMenu, namaMenu, hargaMenu});
    cout << "Menu " << namaMenu << " berhasil ditambahkan!\n";
}

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
    cout << "Pilih opsi (1-4): ";
}

void showMenuPemilik() {
    cout << "====================================\n";
    cout << "  \"RUANG ADMIN\"\n";
    cout << "====================================\n";
    cout << "1. Lihat dan Simpan Daftar Pelanggan\n"; 
    cout << "2. Cari Data Pelanggan\n";
    cout << "3. Hapus Data Pelanggan\n";
    cout << "4. Masukkan Menu Baru\n";
    cout << "5. Kembali Ke Menu Awal\n"; 
    cout << "====================================\n";
    cout << "Pilih opsi (1-6): ";
}

void keluarProgram() {
    if (!isDataSaved) {
        simpanData:
        cout << endl << "Anda BELUM menyimpan perubahan data pelanggan.\n";
        cout << "Apakah Anda ingin menyimpan sekarang? (Y/T): ";
        string pilihan;
        cin >> pilihan;
        if (pilihan == "y" || pilihan == "Y") {
            // Simpan data sebelum keluar
            simpanDataPelanggan(daftarPelanggan, maxPelanggan);
        } else if (pilihan == "t" || pilihan == "T"){
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