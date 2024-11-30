#include "function.cxx"

// Fungsi utama
int main() {
    system("cls");
    
    int role;
    
    cout << "1. Pelanggan" << endl;
    cout << "2. Pemilik" << endl;
    cout << "Role Anda: "; cin >> role;
    
    if (role == 1){
        system("cls");
        string nama; 
       
        cout << "Masukkan Nama Anda: "; 
        cin >> nama;
        
        system("cls");
        
        int pilihan;
        
        do {
            showMenu();
            cin >> pilihan;
    
            switch (pilihan) {
                case 1:
                    system("cls");
                    showDaftarMenu(daftarMenu);
                    cout << endl << "Enter Untuk Kembali";
                    getchar(); getchar();
                    break;
                case 2:
                    system("cls");
                    sortMenu(daftarMenu);
                    cout << endl << "Enter Untuk Kembali";
                    getchar(); getchar();
                    break;
                case 3:
                    system("cls");
                    prosesPesanan(antrianPesanan);
                    cout << endl << "Enter Untuk Kembali";
                    getchar(); getchar();
                    break;
                case 4:
                    system("cls");
                    tambahPesanan(antrianPesanan, daftarMenu);
                    cout << endl << "Enter Untuk Kembali";
                    getchar(); getchar();
                    break;
                case 5:
                    system("cls");
                    prosesPesanan(antrianPesanan);
                    cout << endl << "Enter Untuk Kembali";
                    getchar(); getchar();
                    break;
                case 6:
                    system("cls");
                    showAntrian(antrianPesanan);
                    cout << endl << "Enter Untuk Kembali";
                    getchar(); getchar();
                    break;
                case 7:
                 
                     break;
                 case 8:
                  
                     break;
                 case 9:
                    cout << endl << "Terima kasih telah menggunakan sistem ini!\n";
                    break;
                 default:
                     system("cls");
                    cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
            }
        } while (pilihan != 9);
    }else if(role == 2){
        cout << "Halo Pemilik" << endl;
    }
    
    return 0;
}