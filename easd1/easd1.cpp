#include <iostream>
using namespace std;

const int MAX_Data = 118; // 98 +20 - 2 * 15 + 10 + 20 (nim 98)

void merge(int Rama[], int low, int mid, int high) {       //arr diganti dengan nama panggilan 
    int i = low, RR = mid + 1, k = low;                     //j diganti dengan inisial nama awal dan terahir nama Rama Ramdani
    int b[MAX_Data];
    while (i <= mid && RR <= high) {
        if (Rama[i] <= Rama[RR]) {
            b[k] = Rama[i];
            i++;
        }
        else {
            b[k] = Rama[RR];
            RR++;
        }
        k++;
    }
    while (RR <= high) {
        b[k] = Rama[RR];
        RR++;
        k++;
    }
    while (i <= mid) {
        b[k] = Rama[RR];
        i++;
        k++;
    }
    for (k = low; k <= high; k++) {
        Rama[k] = b[k];
    }
}

void mergeSort(int Rama[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(Rama, low, mid);
    mergeSort(Rama, mid + 1, high);
    merge(Rama, low, mid, high);
}

void input(int Rama[], int& n) {
    cout << "masukkan jumlah elemen (maximum " << MAX_Data << "): ";
    cin >> n;
    if (n > MAX_Data) {
        cout << "jumlah elemen maksumum yang dizinkan!" << endl;
        exit(1);
    }
    cout << "masukkan elemen:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> Rama[i];
    }
}

void display(int Rama[], int n) {
    cout << "sorted elements : " << endl;
    for (int i = 0; i < n; i++) {
        cout << Rama[i] << "";
    }
    cout << endl;
}

int main() {
    int Rama[MAX_Data];
    int n;
    input(Rama, n);
    mergeSort(Rama, 0, n - 1);
    display(Rama, n);
    return 0;
}

// 1. Karena Algoritma merupakan urutan langkah-langlkah yang sistematis dan terstruktur untuk menyelesaikan suatu masalah dengan efisien
// 2. Array dan Linked list
// 3. Faktor yang mempengaruhi waktu ekseskusi suatu program yaitu ukuran input, algoritma yang digunakan, kompleksitas algoritma, struktur data
// 4. Merge sort, karena lebih stabil dan konsisten dalam waktu eksekusinya, tetapi alokasi memori tambahan
// 5. Algoritma yang termasuk ke dalam quadratic adalah Bubblesort, Selection Sort, Insertion Sort, sedangkan yang termasuk dalam longlinear adalah Quick sort, Merge sort