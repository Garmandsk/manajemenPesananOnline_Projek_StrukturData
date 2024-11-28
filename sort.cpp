#include "header.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void sortMenu(vector<Menu>& daftarMenu) {
    sort(daftarMenu.begin(), daftarMenu.end(), [](const Menu& a, const Menu& b) {
        return a.kategori < b.kategori;
    });
}