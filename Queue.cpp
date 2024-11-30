#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

// Struktur untuk menu
struct Menu {
    string kategori;
    string nama;
    int harga;
};

// Fungsi untuk menampilkan sambutan
void pesanSambutan() {
    cout << "Selamat datang di sistem manajemen restoran!\n";
}

// Fungsi untuk menampilkan menu utama
void showMenu() {
    cout << "\nMenu Utama:\n";
    cout << "1. Tampilkan daftar menu\n";
    cout << "2. Tambah pesanan ke antrian\n";
    cout << "3. Proses pesanan dalam antrian\n";
    cout << "4. Tampilkan antrian pesanan\n";
    cout << "9. Keluar\n";
    cout << "Pilihan Anda: ";
}

// Fungsi untuk menampilkan daftar menu
void showDaftarMenu(const vector<Menu>& daftarMenu) {
    cout << "\nDaftar Menu:\n";
    for (size_t i = 0; i < daftarMenu.size(); ++i) {
        cout << i + 1 << ". [" << daftarMenu[i].kategori << "] " 
             << daftarMenu[i].nama << " - Rp" << daftarMenu[i].harga << endl;
    }
}

// Fungsi untuk menampilkan antrian
void showAntrian(queue<Menu> antrian) {
    if (antrian.empty()) {
        cout << "\nAntrian kosong.\n";
        return;
    }
    cout << "\nAntrian Pesanan:\n";
    int nomor = 1;
    while (!antrian.empty()) {
        Menu menu = antrian.front();
        cout << nomor << ". [" << menu.kategori << "] " << menu.nama 
             << " - Rp" << menu.harga << endl;
        antrian.pop();
        nomor++;
    }
}

// Fungsi untuk menambah pesanan ke antrian
void tambahPesanan(queue<Menu>& antrian, const vector<Menu>& daftarMenu) {
    cout << "\nPilih nomor menu yang ingin ditambahkan ke antrian: ";
    int pilihan;
    cin >> pilihan;

    if (pilihan < 1 || pilihan > daftarMenu.size()) {
        cout << "\nPilihan tidak valid.\n";
        return;
    }

    antrian.push(daftarMenu[pilihan - 1]);
    cout << daftarMenu[pilihan - 1].nama << " telah ditambahkan ke antrian.\n";
}

// Fungsi untuk memproses pesanan dari antrian
void prosesPesanan(queue<Menu>& antrian) {
    if (antrian.empty()) {
        cout << "\nAntrian kosong. Tidak ada pesanan untuk diproses.\n";
        return;
    }

    Menu menu = antrian.front();
    antrian.pop();
    cout << "\nMemproses pesanan: [" << menu.kategori << "] " 
         << menu.nama << " - Rp" << menu.harga << endl;
}

// Fungsi utama
int main() {
    system("cls");

    // Inisialisasi daftar menu
    vector<Menu> daftarMenu = {
        {"Makanan", "Nasi Goreng", 10000},
        {"Makanan", "Ikan Bakar", 20000},
        {"Minuman", "Teh Manis", 5000},
        {"Makanan", "Nasi Goreng", 10000},
        {"Makanan", "Ikan Bakar", 20000},
        {"Minuman", "Jus Buah", 5000}
    };

    // Inisialisasi queue untuk antrian pesanan
    queue<Menu> antrianPesanan;

    int pilihan;
    pesanSambutan();

    do {
        showMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                showDaftarMenu(daftarMenu);
                break;
            case 2:
                tambahPesanan(antrianPesanan, daftarMenu);
                break;
            case 3:
                prosesPesanan(antrianPesanan);
                break;
            case 4:
                showAntrian(antrianPesanan);
                break;
            case 9:
                cout << "Terima kasih telah menggunakan sistem ini!\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 9);

    return 0;
}
