#ifndef header_h
#define header_h

#include <vector>
#include <string>
using namespace std;

struct Menu {
    string kategori;
    string nama;
    int harga;
};

void pesanSambutan();
void showMenu();
void showDaftarMenu(const vector<Menu>& daftarMenu);

#endif