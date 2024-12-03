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
            string nama; 
            
            system("cls");
           
            cout << "Masukkan Nama Anda: "; 
            cin.ignore(); 
            getline(cin, nama); 
            
            system("cls");
            
            int pilihan;
            
            do {
                system("cls");
                showMenuPelanggan();
                cin >> pilihan;
        
                switch (pilihan) {
                    case 1:
                        system("cls");
                        showDaftarMenu(daftarMenu);
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get(); 
                        break;
                    case 2:
                        system("cls");
                        sortMenu(daftarMenu);
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 3:
                        system("cls");
                        /* Belum */
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 4:
                        system("cls");
                        tambahPesanan(antrianPesanan, daftarMenu);
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 5:
                        system("cls");
                        prosesPesanan(antrianPesanan);
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 6:
                        system("cls");
                        showAntrian(antrianPesanan);
                        cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                        break;
                    case 7:
                         system("cls");
                         /* Belum */
                         cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                         break;
                     case 8:
                          system("cls");
                          /* Belum */
                          cout << endl << "Enter Untuk Kembali";
                        cin.ignore();
                        cin.get();  
                         break;
                     case 9:
                        goto menuAwal;
                        break;
                     default:
                         system("cls");
                        cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                }
            } while (pilihan != 9);
        }else if(role == 2){
            string kataSandi;
            
            cout << "Kata Sandi: "; cin >> kataSandi;
            
            if(kataSandi == "a"){
                int pilihan;                
                
                vector<string> pesanan2 = {"Bakso", "Mie Ayam", "Ayam Goreng", "Es Teh", "Jus Jeruk"};
    
                tambahDataPelanggan(generateKey(), "Audi", "10000", pesanan2);
                system("cls");
                
                do {
                    system("cls");
                    showMenuPemilik();
                    cin >> pilihan;
            
                    switch (pilihan) {
                        case 1: {
                            system("cls");
                            tampilDataPelanggan(daftarPelanggan);
                            simpanDataPelanggan(daftarPelanggan, maxPelanggan);
                            cout << endl << "Enter Untuk Kembali";
                            cin.ignore();
                            cin.get();  
                            break;
                        }
                        case 2: {
                            system("cls");
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
                            cout << endl << "Enter Untuk Kembali";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                        case 3: {
                            system("cls");
                            string pilihKeyDihapus;
                            
                            cout << "Masukkan Data Yang Ingin Dihapus Berdasarkan Key-nya: ";
                            cin >> pilihKeyDihapus;
                            hapusDataPelanggan(pilihKeyDihapus);
                            cout << endl << "Enter Untuk Kembali";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                        case 4: {
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
                } while (pilihan != 4);
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