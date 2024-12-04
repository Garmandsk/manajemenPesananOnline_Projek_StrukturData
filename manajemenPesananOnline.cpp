#include "function.cxx"
    
// Fungsi utama
int main() {
    int role;
    
    menuAwal:
    system("cls");
    cout << "1. Pelanggan" << endl;
    cout << "2. Pemilik" << endl;
    cout << "3. Keluar Program" << endl << endl;
    
    cout << "Role Anda(1-2): "; cin >> role;
    
    while(true){
        if (role == 1){
            
            system("cls");
           
            cout << "Masukkan Nama Anda: "; 
            cin.ignore(); 
            getline(cin, namaPelanggan); 
            
            system("cls");
            
            int pilihan;
            
            do {
                system("cls");
                showMenuPelanggan();
                cin >> pilihan;
        
                switch (pilihan) {
                    case 1:
                        sortMenu(daftarMenu, 1);
                        tambahPesanan(antrianPesanan, daftarMenu);
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 2:
                        system("cls");

                        showAntrian(antrianPesanan, riwayat);
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 3:
                        system("cls");
                        konfirmasiRiwayatPesanan(riwayat);
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 4:
                        goto menuAwal;
                        break;
                    default:
                        system("cls");
                        cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                }
            } while (pilihan != 4);
        }else if(role == 2){
            string kataSandi;
            
            cout << "Kata Sandi: "; cin >> kataSandi;
            
            if(kataSandi == "lupaaku"){
                int pilihan;                
                
                system("cls");
                
                do {
                    system("cls");
                    system("color 2");
                    showMenuPemilik();
                    cin >> pilihan;
            
                    switch (pilihan) {
                        case 1: {
                            system("cls");
                            system("color 6"); tampilDataPelanggan(daftarPelanggan);
                            simpanDataPelanggan(daftarPelanggan, maxPelanggan);
                            cout << endl << "Enter Untuk Kembali";
                            cin.ignore();
                            cin.get();  
                            break;
                        }
                        case 2: {
                            system("cls");
                            system("color 3");
                            string pilihKeyDicari;
                            
                            headerCariDataPelanggan();
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
                            cout << endl << "Enter Untuk Kembali";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                        case 3: {
                            system("cls");
                            system("color D");
                            string pilihKeyDihapus;
                            
                            headerHapusDataPelanggan();
                            cout << "Masukkan Data Yang Ingin Dihapus Berdasarkan Key-nya: ";
                            cin >> pilihKeyDihapus;
                            hapusDataPelanggan(pilihKeyDihapus);
                            cout << endl << "Enter Untuk Kembali";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                        case 4: {
                            tambahMenu();  // Panggil fungsi untuk menambah menu baru
                            break;
                        }
                        case 5: {
                            cout << "Kembali ke menu awal.\n";
                            goto menuAwal;
                            break;
                        }
                        default: {
                            cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    }        
                } while (pilihan != 5);
            }else{
                goto menuAwal;
            }
        }else if(role == 3){
            keluarProgram();
            cin.ignore();
            cin.get();
            return 0;
        }else{
            cout << "Masukkan Ulang!" << endl;
            goto menuAwal;
        }
    }
    
    return 0;
}