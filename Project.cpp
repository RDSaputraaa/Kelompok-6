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
