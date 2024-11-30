void sortMenu(vector<Menu>& daftarMenu) {
    sort(daftarMenu.begin(), daftarMenu.end(), [](const Menu& a, const Menu& b) {
        return a.kategori < b.kategori;
    });
    cout << "Menu Sudah Diurutkan Berdasarkan Kategori!" << endl;
}