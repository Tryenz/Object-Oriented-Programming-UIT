#include "cArray.h"
using namespace std;

int main() {
    cArray x;

    x.tao_mang();

    if (x.getN() == 0) {
        cout << "Mang rong!";
        return 0;
    }

    cout << "Mang: ";
    x.xuat();
    cout << endl;

    int k;
    cout << "Nhap so muon dem so lan xuat hien: ";
    cin >> k;
    cout << "So lan xuat hien: " << x.so_lan_xuat_hien(k) << endl;

    cout << (x.ktra_tang_dan() ? "Mang tang dan" : "Mang khong tang dan") << endl;

    int lemin = x.tim_le_nho_nhat();
    if (lemin == -1)
        cout << "Khong co phan tu le nao trong mang\n";
    else
        cout << "Phan tu le nho nhat trong mang: " << lemin << endl;

    int sntmax = x.tim_snt_max();
    if (sntmax == -1)
        cout << "Khong co so nguyen to nao trong mang\n";
    else
        cout << "So nguyen to lon nhat co trong mang: " << sntmax << endl;

    x.sap_xep_tang_dan();
    cout << "Mang sau khi sap xep tang dan: ";
    x.xuat();
    cout << endl;

    x.sap_xep_giam_dan();
    cout << "Mang sau khi sap xep giam dan: ";
    x.xuat();
}
