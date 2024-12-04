void sortMenu(vector<Menu>& daftarMenu, int urutanPilihan) {
    if (urutanPilihan == 1) {
        // Urutkan berdasarkan abjad
        sort(daftarMenu.begin(), daftarMenu.end(), [](const Menu& a, const Menu& b) {
            return a.nama < b.nama; // Mengurutkan berdasarkan nama
        });
    } else if (urutanPilihan == 2) {
        // Urutkan berdasarkan harga
        sort(daftarMenu.begin(), daftarMenu.end(), [](const Menu& a, const Menu& b) {
            return a.harga < b.harga; // Mengurutkan berdasarkan harga
        });
    } else {
        cout << "Pilihan tidak valid. Tidak ada pengurutan dilakukan.\n";
    }
}

// ... existing code ...
void searchMenu(const vector<Menu>& daftarMenu, string nama, int id, string hargaCondition, double harga) {
    // Pencarian berdasarkan nama atau ID
    if (!nama.empty()) {
        auto it = find_if(daftarMenu.begin(), daftarMenu.end(), [&](const Menu& menu) {
            return menu.nama == nama; // Mencari menu berdasarkan nama
        });

        if (it != daftarMenu.end()) {
            vector<Menu> daftarMenuTersaring = {*it};
            showDaftarMenu(daftarMenuTersaring);

        } else {
            cout << "Menu dengan nama '" << nama << "' tidak ditemukan.\n";
        }
    } else if (id >= 0 && id < daftarMenu.size()) {
        vector<Menu> daftarMenuTersaring = {daftarMenu[id]};
        showDaftarMenu(daftarMenuTersaring);

    } else {
        cout << "Menu tidak ditemukan.\n";
    }

    // Pencarian berdasarkan harga
    vector<Menu> daftarMenuTersaringHarga;
    if (hargaCondition == "<") {
        cout << "Menu dengan harga kurang dari " << harga << ":\n";
        for (const auto& menu : daftarMenu) {
            if (menu.harga < harga) {
                daftarMenuTersaringHarga.push_back(menu);
            }
        }
        showDaftarMenu(daftarMenuTersaringHarga);
    } else if (hargaCondition == ">") {
        cout << "Menu dengan harga lebih dari " << harga << ":\n";
        for (const auto& menu : daftarMenu) {
            if (menu.harga > harga) {
                daftarMenuTersaringHarga.push_back(menu);
            }
        }
        showDaftarMenu(daftarMenuTersaringHarga);
    }
}

void pencarianMenu(const vector<Menu>& daftarMenu) {
    int pilihan;
    cout << "Pilih metode pencarian:\n";
    cout << "1. Berdasarkan nama/id\n";
    cout << "2. Berdasarkan harga\n";
    cout << "Pilih opsi (1-3): ";
    cin >> pilihan;

    if (pilihan == 1) {
        string nama;
        cout << "Masukkan nama menu: ";
        cin.ignore();
        getline(cin, nama);
        bool isNama = true;
        int id;
        try {
            id = stoi(nama);
            isNama = false;
        } catch (invalid_argument& e) {
            isNama = true;
        }

        if (isNama) {
            searchMenu(daftarMenu, nama, -1, "", 0.0);
        } else {
            searchMenu(daftarMenu, "", id, "", 0.0);
        }
    } else if (pilihan == 2) {
        char simbol;
        double harga;
        cout << "Masukkan simbol kondisi harga (< atau >) dan harga: ";
        cin >> simbol >> harga;
        string hargaCondition = simbol == '<' ? "<" : simbol == '>' ? ">" : "";
        if (hargaCondition.empty()) {
            cout << "Simbol tidak valid. Silakan masukkan '<' atau '>'." << endl;
            return;
        }
        searchMenu(daftarMenu, "", -1, hargaCondition, harga);
    }
}