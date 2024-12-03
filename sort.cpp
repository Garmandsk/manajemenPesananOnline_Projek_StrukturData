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