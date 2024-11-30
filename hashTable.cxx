/* Pembentukan Hash Table */
int ukuranHashTable = 10;
vector<list<pair<string, vector<string>>>> dataPelanggan(ukuranHashTable);

/* Generate Key Versi 1 
string generateKey() {
    string input = to_string(rand()); 
    hash<string> hash_fn;
    size_t hash = hash_fn(input);  
    return to_string(hash);  
}
*/

/* Generate Key Versi 2 */
string generateKey() {
    static int counter = 1;
    return "KEY" + to_string(counter++);
}

/* Hash Function */
int hashFunction(string key) {
    int hashValue = 0;
    for (char ch : key) {
        hashValue += ch;
        cout<<"ch: "<<ch<<endl;
    }
    return hashValue % ukuranHashTable;
}

/* Function Tambah Data */
void tambahDataPelanggan(string key, string namaPelanggan, string totalBayarPelanggan, const vector<string>& pesanan) {
    int index = hashFunction(key);

    for (auto& item : dataPelanggan[index]) {
        if (item.first == key) {
            item.second.push_back(namaPelanggan);
            item.second.push_back(totalBayarPelanggan);
            item.second.insert(item.second.end(), pesanan.begin(), pesanan.end());
            return;
        }
    }

    vector<string> dataPelangganBaru = {namaPelanggan, totalBayarPelanggan};
    dataPelangganBaru.insert(dataPelangganBaru.end(), pesanan.begin(), pesanan.end());
    dataPelanggan[index].push_back({key, dataPelangganBaru});
    cout<<"Data Dimasukkan Dengan Key: "<<key<<endl;
}

/* Function Hapus Data */
void hapusDataPelanggan(string key) {
    int index = hashFunction(key);
    auto& list_at_index = dataPelanggan[index];

    for (auto it = list_at_index.begin(); it != list_at_index.end(); ++it) {
        if (it->first == key) {
            list_at_index.erase(it);
            cout << "Data Dengan Key: '" << key << "' Berhasil Dihapus" << endl;
            return;
        }
    }
    cout << "Data Tidak Ditemukan" << endl;
}

/* Function Cari Data */
vector<string> cariDataPelanggan(string key) {
    int index = hashFunction(key);
    for (auto& item : dataPelanggan[index]) {
        if (item.first == key) {
            vector<string> dataS;
            for (const auto& val : item.second) {
                dataS.push_back(val);
            }
            cout << endl;          
            return dataS; 
        }
    }
    
    return {}; 
}

/* Function Tampilkan Semua Data */
void tampilDataPelanggan() {
    for (int i = 0; i < ukuranHashTable; ++i) {
        cout << "Index " << i << ": ";
        if (dataPelanggan[i].empty()) {
            cout << "Data Pelanggan Kosong" << endl;
        } else {
            for (const auto& item : dataPelanggan[i]) {
                cout << "(" << item.first << ": [";
                for (const auto& val : item.second) {
                    cout << val << ", ";
                }
                cout << "]) ";
            }
            cout << endl;
        }
    }
}