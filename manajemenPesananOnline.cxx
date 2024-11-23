#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Menu {
    string kategori;
    string nama;
    string harga;
};

// Fungsi untuk menampilkan pesan sambutan
void pesanSambutan() {
    cout << "====================================\n";
    cout << "     SELAMAT DATANG DI RESTORAN\n";
    cout << "  \"MAKANAN LEZAT, PELAYANAN CEPAT\"\n";
    cout << "====================================\n";
    cout << "\nKami siap melayani kebutuhan Anda!\n";
    cout << "Silahkan pilih menu dari sistem kami:\n\n";
}

// Fungsi untuk menampilkan menu utama
void showMenu() {
    cout << "====================================\n";
    cout << "   SISTEM PEMESANAN MAKANAN ONLINE\n";
    cout << "====================================\n";
    cout << "1. Lihat Daftar Menu\n"; 
    cout << "2. Urutkan Menu\n"; 
    cout << "3. Cari Menu atau Pesanan\n";
    cout << "4. Buat Pesanan\n";
    cout << "5. Proses Pesanan\n"; 
    cout << "6. Lihat Antrian Pesanan\n";
    cout << "7. Hapus Pesanan\n";
    cout << "8. Lihat Riwayat Pesanan\n";
    cout << "9. Keluar\n";
    cout << "====================================\n";
    cout << "Pilih opsi (1-9): ";
}

// Fungsi untuk menampilkan daftar menu
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

int main() {
    system("cls");
    // Inisialisasi daftar menu
    vector<Menu> daftarMenu = {
        {"Makanan", "Nasi Goreng", "10000"},
        {"Makanan", "Ikan Bakar", "20000"},
        {"Minuman", "Teh Manis", "5000"},
        {"Minuman", "Jus Buah", "5000"}
    };

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
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
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