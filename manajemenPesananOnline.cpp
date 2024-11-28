#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "header.h"
using namespace std;

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