 void tambahRiwayatPesanan(RiwayatPesanan*& riwayat, const Menu& menu) {
    RiwayatPesanan* baru = new RiwayatPesanan{menu, nullptr};
    if (!riwayat) {
        riwayat = baru;
    } else {
        RiwayatPesanan* temp = riwayat;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

/* Generate Key Versi 2 */
string generateKey() {
    static int counter = 1;
    return "KEY" + to_string(counter++);
}

void konfirmasiRiwayatPesanan(RiwayatPesanan*& riwayat) {
    
    cout << "=== Konfirmasi Riwayat Pesanan ===\n";
    if (!riwayat) {
        cout << "\nRiwayat pesanan kosong.\n";
        return;
    }

    vector<string> daftarPesanan;
    int totalBayar = 0;

    RiwayatPesanan* current = riwayat;
    while (current) {
        cout << "- [" << current->menu.kategori << "] " 
             << current->menu.nama << " - Rp" << current->menu.harga << endl;
        daftarPesanan.push_back(current->menu.nama + " - Rp" + to_string(current->menu.harga));
        totalBayar += current->menu.harga;
        current = current->next;
    }

    cout << "\nTotal Bayar: Rp" << totalBayar << endl;
    cout << "Apakah Anda ingin mengonfirmasi dan menyimpan data pelanggan? (Y/T): ";
    char konfirmasi;
    cin >> konfirmasi;

    if (tolower(konfirmasi) == 'y') {
        
        
        tambahDataPelanggan(generateKey(), namaPelanggan, to_string(totalBayar), daftarPesanan);

        // Menghapus riwayat setelah disimpan
        while (riwayat) {
            RiwayatPesanan* temp = riwayat;
            riwayat = riwayat->next;
            delete temp;
        }
        cout << "Data pelanggan berhasil disimpan ke dalam daftar pelanggan.\n";
    } else if(tolower(konfirmasi) == 't'){
        cout << "\nData riwayat pesanan tidak disimpan.\n";
    } else {
        cout << "Masukkan Tidak Valid!" << endl;
        cin.ignore();
        cin.get();
    }
}

void tambahPesanan(queue<Menu>& antrian, vector<Menu> daftarMenu) {
    string pilihan;
    char pilihanPesanan;
    int jumlahPesanan;

    do {
        system("cls"); // Bersihkan layar (Windows)
        showDaftarMenu(daftarMenu);

        cout << "Tekan 'h' untuk mengurutkan berdasarkan harga" << endl;
        cout << "Tekan 'c' untuk mencari menu" << endl;
        cout << "Tekan 'k' untuk keluar" << endl << endl;
        
        cout << "Catatan: Pilih Menu Sesuai ID!" << endl << endl;
        
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        // Perintah berdasarkan input
        if (pilihan == "h" || pilihan == "H") {
            sortMenu(daftarMenu, 2);
            continue; // Kembali ke awal loop untuk menampilkan daftar terurut
        } else if (pilihan == "c" || pilihan == "C") {
            pencarianMenu(daftarMenu);
            cout << endl << "Enter Untuk Kembali";
            cin.ignore();
            cin.get();
            continue;
        } else if (pilihan == "k" || pilihan == "K") {
            return; // Keluar dari fungsi
        } else {
            // Konversi pilihan menjadi indeks
            int indeksPilihan;
            try {
                indeksPilihan = stoi(pilihan);
            } catch (invalid_argument& e) {
                cout << "\nMasukkan tidak valid (harus angka)." << endl;
                cin.ignore();
                cin.get();
                continue;
            }

            if (indeksPilihan < 0 || indeksPilihan > daftarMenu.size()) {
                cout << "\nMasukkan tidak valid (indeks di luar jangkauan)." << endl;
                cin.ignore();
                cin.get();
                continue;
            }

            // Pesan jumlah
            cout << "Jumlah yang ingin dipesan: ";
            cin >> jumlahPesanan;

            if (jumlahPesanan <= 0) {
                cout << "\nJumlah harus lebih dari 0." << endl;
                cin.ignore();
                cin.get();
                continue;
            }

            // Tambahkan ke antrian
            Menu menuDipilih;
            for (auto& menu : daftarMenu) {
                if (menu.id == indeksPilihan) {
                    menuDipilih = menu;
                    break;
                }
            }
            for (int i = 0; i < jumlahPesanan; i++) {
                antrian.push(menuDipilih);
            }
            
            cout << jumlahPesanan << " " << menuDipilih.nama << " telah ditambahkan ke antrian.\n";
            cout << "Pesan lagi (Y/T)? ";
            cin >> pilihanPesanan;

            if (pilihanPesanan == 't' || pilihanPesanan == 'T') {
                return; // Keluar dari fungsi
            }
        }
    } while (true);
}

void prosesPesanan(queue<Menu>& antrian, RiwayatPesanan*& riwayat) {
    if (antrian.empty()) {
        cout << "\nAntrian kosong. Tidak ada pesanan untuk diproses.\n";
        cin.ignore();
        cin.get();
        return;
    }

    int pilihan;
    do {
        system("cls");
        cout << "=== Proses Pesanan ===\n";
        cout << "\nPesanan dalam antrian:\n";
         if (antrian.empty()) {
            cout << "\nAntrian kosong.\n";
        }
        queue<Menu> tempQueue = antrian; // Salinan antrian untuk ditampilkan
        int index = 1;
        while (!tempQueue.empty()) {
            Menu menu = tempQueue.front();
            cout << index++ << ". [" << menu.kategori << "] " 
                 << menu.nama << " - Rp" << menu.harga << endl;
            tempQueue.pop();
        }
        cout << endl << "Opsi Proses Pesanan:" << endl;
        cout << "1. Proses satu pesanan\n";
        cout << "2. Proses semua pesanan\n";
        cout << "3. Kembali\n";
        cout << endl << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Proses satu pesanan
            if (!antrian.empty()) {
                Menu menu = antrian.front();
                antrian.pop();

                cout << "\nMemproses pesanan: [" << menu.kategori << "] " 
                     << menu.nama << " - Rp" << menu.harga << endl;

                tambahRiwayatPesanan(riwayat, menu);
                cout << "Pesanan berhasil ditambahkan ke riwayat.\n";
            } else {
                cout << "\nAntrian kosong. Tidak ada pesanan untuk diproses.\n";
            }
        } else if (pilihan == 2) {
            // Proses semua pesanan
            while (!antrian.empty()) {
                Menu menu = antrian.front();
                antrian.pop();

                cout << "\nMemproses pesanan: [" << menu.kategori << "] " 
                     << menu.nama << " - Rp" << menu.harga << endl;

                tambahRiwayatPesanan(riwayat, menu);
            }
            cout << "\nSemua pesanan telah diproses dan ditambahkan ke riwayat.\n";
        } else if (pilihan == 3) {
            // Kembali ke menu sebelumnya
            cout << "\nKembali ke menu sebelumnya.\n";
            return;
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }

        cin.ignore();
        cin.get();
    } while (pilihan != 3);
}

void hapusPesanan(queue<Menu>& antrian) {
    if (antrian.empty()) {
        cout << "\nAntrian kosong. Tidak ada pesanan untuk dihapus.\n";
        cin.ignore();
        cin.get();
        return;
    }

    int pilihan;
    do {
        system("cls");
        cout << "=== Hapus Pesanan ===\n";
        cout << "\nPesanan dalam antrian:\n";

        if (antrian.empty()) {
            cout << "\nAntrian kosong.\n";
            return;
        }

        queue<Menu> tempQueue = antrian; // Salinan antrian untuk ditampilkan
        int index = 1;
        while (!tempQueue.empty()) {
            Menu menu = tempQueue.front();
            cout << index++ << ". [" << menu.kategori << "] " 
                 << menu.nama << " - Rp" << menu.harga << endl;
            tempQueue.pop();
        }

        cout << "\nOpsi Hapus Pesanan:\n";
        cout << "1. Hapus satu pesanan\n";
        cout << "2. Hapus semua pesanan\n";
        cout << "3. Kembali\n";
        cout << endl << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Hapus satu pesanan
            cout << "\nMasukkan nomor pesanan yang ingin dihapus: ";
            int nomor;
            cin >> nomor;

            if (nomor < 1 || nomor > antrian.size()) {
                cout << "\nNomor pesanan tidak valid. Silakan coba lagi.\n";
            } else {
                queue<Menu> antrianTemp;
                int counter = 1;

                while (!antrian.empty()) {
                    Menu menu = antrian.front();
                    antrian.pop();
                    if (counter != nomor) {
                        antrianTemp.push(menu);
                    }
                    counter++;
                }

                antrian = antrianTemp; // Update antrian dengan elemen baru
                cout << "Pesanan nomor " << nomor << " berhasil dihapus.\n";
            }
        } else if (pilihan == 2) {
            // Hapus semua pesanan
            while (!antrian.empty()) {
                antrian.pop();
            }
            cout << "Semua pesanan telah dihapus.\n";
        } else if (pilihan == 3) {
            // Kembali ke menu sebelumnya
            cout << "\nKembali ke menu sebelumnya.\n";
            return;
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }

        cin.ignore();
        cin.get();
    } while (pilihan != 3);
}

void showAntrian(queue<Menu>& antrian, RiwayatPesanan*& riwayat) {
    string pilihan;
    
    do {
        system("cls"); // Membersihkan layar (opsional untuk Windows)
        
        cout << "==== Antrian Pesanan ====" << endl;

        if (antrian.empty()) {
            cout << "\nAntrian kosong.\n";
            return;
        }

        // Tampilkan semua pesanan dalam antrian
        queue<Menu> tempQueue = antrian;
        int nomor = 1;
        cout << "Ukuran Antrian: " << antrian.size() << endl;
        cout << "\nAntrian Pesanan:\n";
        while (!tempQueue.empty()) {
            Menu menu = tempQueue.front();
            cout << nomor << ". [" << menu.kategori << "] " << menu.nama 
                 << " - Rp" << menu.harga << endl;
            tempQueue.pop();
            nomor++;
        }

        // Opsi untuk pengguna
        cout << "\nPilihan:\n";
        cout << "1. Proses pesanan\n";
        cout << "2. Hapus pesanan\n";
        cout << "3. Kembali\n";
        cout << endl << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == "1") {
            prosesPesanan(antrian, riwayat);
        } else if (pilihan == "2") {
            hapusPesanan(antrian);
        } else if (pilihan == "3") {
            return; // Keluar dari fungsi
        } else {
            cout << "\nPilihan tidak valid. Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
    } while (true);
}