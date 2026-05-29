#include "cArray.h"
#include <algorithm>
#include <ctime>

using namespace std;

cArray::cArray() {
    n = 0;
    a = nullptr;
}

cArray::cArray(const cArray& m) {
    n = m.n;

    if (n == 0) {
        a = nullptr;
    } else {
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = m.a[i];
        }
    }
}

cArray::~cArray() {
    delete[] a;
}

int cArray::getN() {
    return n;
}

void cArray::tao_mang() {
    cout << "Nhap so phan tu: ";
    cin >> n;

    while (cin.fail() || n <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai n hop le: ";
        cin >> n;
    }

    delete[] a;
    a = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void cArray::xuat() const {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int cArray::so_lan_xuat_hien(int x) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) dem++;
    }
    return dem;
}

bool cArray::ktra_tang_dan() {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

bool cArray::laSNT(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int cArray::tim_le_nho_nhat() {
    int min = 101;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            if (!found || a[i] < min) {
                min = a[i];
                found = true;
            }
        }
    }

    return found ? min : -1;
}

int cArray::tim_snt_max() {
    int max = -1;

    for (int i = 0; i < n; i++) {
        if (laSNT(a[i]) && a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

void heapify_max(int* a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify_max(a, n, largest);
    }
}

void heap_sort_tang(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_max(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify_max(a, i, 0);
    }
}

void heapify_min(int* a, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapify_min(a, n, smallest);
    }
}

void heap_sort_giam(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_min(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify_min(a, i, 0);
    }
}

void cArray::sap_xep_tang_dan() {
    heap_sort_tang(a, n);
}

void cArray::sap_xep_giam_dan() {
    heap_sort_giam(a, n);
}
