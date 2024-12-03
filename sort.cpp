void sortMenu(vector<Menu>& daftarMenu) {
   
        // Urutkan berdasarkan harga
        sort(daftarMenu.begin(), daftarMenu.end(), [](const Menu& a, const Menu& b) {
            return a.harga < b.harga; // Mengurutkan berdasarkan harga
        });
}