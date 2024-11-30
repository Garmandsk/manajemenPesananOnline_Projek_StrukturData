#include "function.cxx"

int main (){
    
    string key1 = generateKey();
    vector<string> pesanan1 = {"Bakso", "Mie Ayam", "Ayam Goreng", "Es Teh", "Jus Mangga"};
    
    string key2 = generateKey();
    vector<string> pesanan2 = {"Bakso", "Mie Ayam", "Ayam Goreng", "Es Teh", "Jus Jeruk"};

    tambahDataPelanggan(key1, "Audi", "10000", pesanan1);
    tambahDataPelanggan(key2, "Budi", "30000", pesanan2);
    
    tampilDataPelanggan();
    
    hapusDataPelanggan(key1);
    tampilDataPelanggan();
    
    vector<string> dataHasilPencarian = cariDataPelanggan(key1);  

    try {
        if(dataHasilPencarian.size() > 0){
            cout << "Data Ku: " << dataHasilPencarian[2] << endl;
        }else{
            throw runtime_error("Data Sudah Tidak Ada");
        }
    } catch (const runtime_error &e) {
        cout << "Error:  "<< e.what() << endl;
    }
    
    return 0;
}