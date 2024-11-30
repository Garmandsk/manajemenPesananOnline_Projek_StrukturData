queue<Menu> antrianPesanan;
    
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