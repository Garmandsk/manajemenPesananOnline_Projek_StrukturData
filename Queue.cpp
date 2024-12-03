struct RiwayatPesanan {
    Menu menu;
    RiwayatPesanan* next;
};

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

void showRiwayatPesanan(RiwayatPesanan* riwayat) {
    if (!riwayat) {
        cout << "\nRiwayat pesanan kosong.\n";
        return;
    }
    cout << "\nRiwayat Pesanan:\n";
    int nomor = 1;
    while (riwayat) {
        cout << nomor << ". [" << riwayat->menu.kategori << "] " 
             << riwayat->menu.nama << " - Rp" << riwayat->menu.harga << endl;
        riwayat = riwayat->next;
        nomor++;
    }
}

void hapusPesanan(queue<Menu>& antrian) {
    if (antrian.empty()) {
        cout << "\nAntrian kosong. Tidak ada pesanan untuk dihapus.\n";
        return;
    }

    cout << "\nPesanan dalam antrian: \n";
    queue<Menu> tempQueue = antrian;
    int index = 1;
    while (!tempQueue.empty()) {
        Menu menu = tempQueue.front();
        cout << index++ << ". " << menu.nama << " - Rp" << menu.harga << endl;
        tempQueue.pop();
    }

    cout << "\nPilih opsi:\n";
    cout << "1. Hapus satu pesanan\n";
    cout << "2. Hapus semua pesanan\n";
    cout << "Masukkan pilihan: ";
    int pilihan;
    cin >> pilihan;
    
    if (pilihan == 1) {
        cout << "\nMasukkan nomor pesanan yang ingin dihapus: ";
        int nomor;
        cin >> nomor;
        if (nomor < 1 || nomor > antrian.size()) {
            cout << "\nPilihan tidak valid.\n";
            return;
        }
        queue<Menu> antrianTemp;
        int counter = 1;
        while (!antrian.empty()) {
            Menu menu = antrian.front();
            if (counter != nomor) {
                antrianTemp.push(menu);
            }
            antrian.pop();
            counter++;
        }
        antrian = antrianTemp;
        cout << "Pesanan nomor " << nomor << " berhasil dihapus.\n";
    } else if (pilihan == 2) {
        while (!antrian.empty()) {
            antrian.pop(); 
        }
        cout << "Semua pesanan telah dihapus.\n";
    } else {
        cout << "\nPilihan tidak valid.\n";
    }
}

queue<Menu> antrianPesanan; 

RiwayatPesanan* riwayatPesanan = nullptr;

void tambahPesanan(queue<Menu>& antrian, const vector<Menu>& daftarMenu) {
    showDaftarMenu(daftarMenu);
    
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

void prosesPesanan(queue<Menu>& antrian, RiwayatPesanan*& riwayat) {
    if (antrian.empty()) {
        cout << "\nAntrian kosong. Tidak ada pesanan untuk diproses.\n";
        return;
    }

    Menu menu = antrian.front();
    antrian.pop();
    cout << "\nMemproses pesanan: [" << menu.kategori << "] " 
         << menu.nama << " - Rp" << menu.harga << endl;
    
    tambahRiwayatPesanan(riwayat, menu);
}

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