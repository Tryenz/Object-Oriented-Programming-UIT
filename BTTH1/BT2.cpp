#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

    int UCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

public:
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;

        while (mau == 0) {
            cout << "Mau so khong hop le! Nhap lai: ";
            cin >> mau;
        }
    }

    void rutgon() {
        int ucln = UCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;

        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    void xuat() {
        cout << tu << "/" << mau;
    }

    bool lonhon(PhanSo other) {
        return tu * other.mau > other.tu * mau;
    }
};

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu 1:\n";
    ps1.nhap();

    cout << "\nNhap phan so thu 2:\n";
    ps2.nhap();

    ps1.rutgon();
    ps2.rutgon();

    cout << "\nPhan so lon nhat la: ";

    if (ps1.lonhon(ps2)) {
        ps1.xuat();
    } else if (ps2.lonhon(ps1)) {
        ps2.xuat();
    } else {
        cout << "Hai phan so bang nhau";
    }

    return 0;
}
