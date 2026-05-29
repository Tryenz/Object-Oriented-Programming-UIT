#include "PhanSo.h"

int PhanSo::UCLN(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return (a == 0) ? 1 : a;
}

void PhanSo::rutGon() {
    if (mau == 0) return;
    int ucln = UCLN(tu, mau);
    tu /= ucln;
    mau /= ucln;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

PhanSo::PhanSo(int t, int m) : tu(t), mau(m) {
    if (mau == 0) {
        cout << "Loi: Mau so khong the bang 0. Tu dong gan mau so = 1.\n";
        mau = 1;
    }
    rutGon();
}

PhanSo PhanSo::operator+(const PhanSo& other) const {
    return PhanSo(tu * other.mau + other.tu * mau, mau * other.mau);
}

PhanSo PhanSo::operator-(const PhanSo& other) const {
    return PhanSo(tu * other.mau - other.tu * mau, mau * other.mau);
}

PhanSo PhanSo::operator*(const PhanSo& other) const {
    return PhanSo(tu * other.tu, mau * other.mau);
}

PhanSo PhanSo::operator/(const PhanSo& other) const {
    return PhanSo(tu * other.mau, mau * other.tu);
}

bool PhanSo::operator==(const PhanSo& other) const {
    return (tu == other.tu && mau == other.mau);
}

bool PhanSo::operator>(const PhanSo& other) const {
    return (long long)tu * other.mau > (long long)other.tu * mau;
}

bool PhanSo::operator<(const PhanSo& other) const {
    return (long long)tu * other.mau < (long long)other.tu * mau;
}

ostream& operator<<(ostream& os, const PhanSo& ps) {
    if (ps.mau == 1) {
        os << ps.tu;
    } else if (ps.tu == 0) {
        os << 0;
    } else {
        os << ps.tu << "/" << ps.mau;
    }
    return os;
}

istream& operator>>(istream& is, PhanSo& ps) {
    cout << "Nhap tu so: ";
    is >> ps.tu;
    cout << "Nhap mau so: ";
    is >> ps.mau;

    while (ps.mau == 0) {
        cout << "Loi! Mau so phai khac 0. Vui long nhap lai mau so: ";
        is >> ps.mau;
    }

    ps.rutGon();
    return is;
}
