#include "function.cxx"

int main (){
        
    vector<string> pesanan2 = {"Bakso", "Mie Ayam", "Ayam Goreng", "Es Teh", "Jus Jeruk"};
    
    tambahDataPelanggan(generateKey(), "Audi", "10000", pesanan2);
    
    tambahDataPelanggan(generateKey(), "Budi", "30000", pesanan2);
    
    int pilihan;

    do {
        system("cls"); 
        tampilDataPelanggan();

        cout << "Menu:\n";
        cout << "1. Cari Data Pelanggan\n";
        cout << "2. Hapus Data Pelanggan\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string pilihKeyDicari;
                cout << "Masukkan Data Yang Ingin Dicari Berdasarkan Key-nya: ";
                cin >> pilihKeyDicari;

                vector<string> dataHasilPencarian = cariDataPelanggan(pilihKeyDicari);
                try {
                    if (!dataHasilPencarian.empty()) {
                        cout << "Data Ditemukan:\n";
                        for (const auto& item : dataHasilPencarian) {
                            cout << item << " ";
                        }
                        cout << "\n";
                    } else {
                        throw runtime_error("Data tidak ditemukan.");
                    }
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                getchar(); getchar();
                break;
            }

            case 2: {
                string pilihKeyDihapus;
                cout << "Masukkan Data Yang Ingin Dihapus Berdasarkan Key-nya: ";
                cin >> pilihKeyDihapus;
                hapusDataPelanggan(pilihKeyDihapus);
                break;
            }

            case 3:
                cout << "Keluar dari program.\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

        cout << "Tekan enter untuk melanjutkan...";
        getchar();
    } while (pilihan != 3);

    return 0;
}