<<<<<<< HEAD
void sortMenu(vector<Menu>& daftarMenu, int urutanPilihan) {
    if (urutanPilihan == 1) {
        // Urutkan berdasarkan abjad
        sort(daftarMenu.begin(), daftarMenu.end(), [](const Menu& a, const Menu& b) {
            return a.nama < b.nama; // Mengurutkan berdasarkan nama
        });
    } else if (urutanPilihan == 2) {
=======
void sortMenu(vector<Menu>& daftarMenu) {
   
>>>>>>> d0f59d1ba3b30230da7cc49873c78c0b2041748b
        // Urutkan berdasarkan harga
        sort(daftarMenu.begin(), daftarMenu.end(), [](const Menu& a, const Menu& b) {
            return a.harga < b.harga; // Mengurutkan berdasarkan harga
        });
<<<<<<< HEAD
    } else {
        cout << "Pilihan tidak valid. Tidak ada pengurutan dilakukan.\n";
    }
=======
>>>>>>> d0f59d1ba3b30230da7cc49873c78c0b2041748b
}