#include <iostream>
using namespace std;

class PhanSo {
private:
    long long tu;
    long long mau;

    long long UCLN(long long a, long long b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            long long r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    long long nhapSo() {
        long long x;
        while (true) {
            cin >> x;
            if (cin.fail()) {
                cout << "Loi: Vui long nhap so nguyen!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                return x;
            }
        }
    }

public:
    void nhap() {
        cout << "Nhap tu so: ";
        tu = nhapSo();

        cout << "Nhap mau so: ";
        while (true) {
            mau = nhapSo();
            if (mau == 0) {
                cout << "Mau so phai khac 0! Nhap lai: ";
            } else break;
        }
    }

    void rutgon() {
        if (tu == 0) {
            mau = 1;
            return;
        }

        long long ucln = UCLN(tu, mau);
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

    // Cộng
    PhanSo cong(PhanSo b) {
        PhanSo kq;
        kq.tu = tu * b.mau + b.tu * mau;
        kq.mau = mau * b.mau;
        kq.rutgon();
        return kq;
    }

    // Trừ
    PhanSo tru(PhanSo b) {
        PhanSo kq;
        kq.tu = tu * b.mau - b.tu * mau;
        kq.mau = mau * b.mau;
        kq.rutgon();
        return kq;
    }

    // Nhân
    PhanSo nhan(PhanSo b) {
        PhanSo kq;
        kq.tu = tu * b.tu;
        kq.mau = mau * b.mau;
        kq.rutgon();
        return kq;
    }

    // Chia
    PhanSo chia(PhanSo b) {
        PhanSo kq;

        if (b.tu == 0) {
            cout << "\nKhong the chia cho phan so bang 0!\n";
            kq.tu = 0;
            kq.mau = 1;
            return kq;
        }

        kq.tu = tu * b.mau;
        kq.mau = mau * b.tu;
        kq.rutgon();
        return kq;
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

    PhanSo tong = ps1.cong(ps2);
    PhanSo hieu = ps1.tru(ps2);
    PhanSo tich = ps1.nhan(ps2);
    PhanSo thuong = ps1.chia(ps2);

    cout << "\nTong = "; tong.xuat();
    cout << "\nHieu = "; hieu.xuat();
    cout << "\nTich = "; tich.xuat();
    cout << "\nThuong = "; thuong.xuat();

    return 0;
}
