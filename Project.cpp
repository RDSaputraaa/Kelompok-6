#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Mahasiswa {
public:
    char nama[100];
    char nim[20];
    float ipk;

    Mahasiswa(const char* namaInput, const char* nimInput, float ipkInput) {
        strcpy(nama, namaInput);
        strcpy(nim, nimInput);
        ipk = ipkInput;
    }

    void tampilkanInfoKasual() {
        cout << "> " << nama << " (NIM: " << nim << ") - IPK: " << ipk << endl;
    }
};

void quickSort(vector<Mahasiswa*>& data, int low, int high) {
    if (low >= high) return;

    float pivot = data[high]->ipk;
    int left = low, right = high - 1;

    while (left <= right) {
        while (left <= right && data[left]->ipk > pivot) left++;
        while (left <= right && data[right]->ipk <= pivot) right--;
        if (left < right) swap(data[left], data[right]);
    }

    swap(data[left], data[high]);

    quickSort(data, low, left - 1);
    quickSort(data, left + 1, high);
}

float hitungTotalBiayaBeasiswa(const vector<Mahasiswa*>& beasiswa, float nominalPerOrang) {
    return beasiswa.size() * nominalPerOrang;
}

string formatRupiah(float angka) {
    int nilai = static_cast<int>(angka);
    string hasil;
    string str = to_string(nilai);
    int len = str.length();
    int hitung = 0;

    for (int i = len - 1; i >= 0; --i) {
        hasil.insert(0, 1, str[i]);
        hitung++;
        if (hitung % 3 == 0 && i != 0) {
            hasil.insert(0, 1, '.');
        }
    }
    return "Rp" + hasil + ",00";
}

void distribusiMahasiswa(vector<Mahasiswa*>& data,
                         vector<Mahasiswa*>& beasiswa,
                         vector<Mahasiswa*>& pertimbangan,
                         vector<Mahasiswa*>& tidakLolos) {
    cout << "\nLangkah-langkah pembagian beasiswa:\n";
    for (size_t i = 0; i < data.size(); ++i) {
        Mahasiswa* mhs = data[i];
        cout << "Memproses: " << mhs->nama << " (IPK: " << mhs->ipk << ")\n";
        if (mhs->ipk >= 3.75) {
            beasiswa.push_back(mhs);
            cout << "-> Dimasukkan ke kategori LOLOS BEASISWA\n";
        } else if (mhs->ipk >= 2.5) {
            pertimbangan.push_back(mhs);
            cout << "-> Dimasukkan ke kategori DALAM PERTIMBANGAN\n";
        } else {
            tidakLolos.push_back(mhs);
            cout << "-> Dimasukkan ke kategori TIDAK LOLOS\n";
        }
    }
    cout << endl;
}

void tampilkanKelompokKasual(const char* namaKelompok, const vector<Mahasiswa*>& kelompok) {
    cout << namaKelompok << endl;
    if (kelompok.empty()) {
        cout << "(Tidak ada mahasiswa di kategori ini.)\n";
    } else {
        for (size_t i = 0; i < kelompok.size(); ++i) {
            kelompok[i]->tampilkanInfoKasual();
        }
    }
    cout << endl;
}

int main() {
    vector<Mahasiswa*> semuaMahasiswa;
    int jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; ++i) {
        char nama[100], nim[20];
        float ipk;

        cout << "\nData Mahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        cin.getline(nama, sizeof(nama));
        cout << "NIM: ";
        cin.getline(nim, sizeof(nim));
        cout << "IPK: ";
        cin >> ipk;
        cin.ignore();

        semuaMahasiswa.push_back(new Mahasiswa(nama, nim, ipk));
    }

    quickSort(semuaMahasiswa, 0, semuaMahasiswa.size() - 1);

    return 0;
}
