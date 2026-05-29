#include "DaThuc.h"

DaThuc::DaThuc(int n) : bac(n) {
    heso = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        heso[i] = 0.0;
    }
}

DaThuc::~DaThuc() {
    delete[] heso;
}

DaThuc::DaThuc(const DaThuc& other) : bac(other.bac) {
    heso = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        heso[i] = other.heso[i];
    }
}

DaThuc& DaThuc::operator=(const DaThuc& other) {
    if (this != &other) {
        delete[] heso;
        bac = other.bac;
        heso = new double[bac + 1];
        for (int i = 0; i <= bac; ++i) {
            heso[i] = other.heso[i];
        }
    }
    return *this;
}

DaThuc DaThuc::operator+(const DaThuc& other) const {
    int maxBac = max(bac, other.bac);
    DaThuc result(maxBac);

    for (int i = 0; i <= bac; ++i) result.heso[i] += heso[i];
    for (int i = 0; i <= other.bac; ++i) result.heso[i] += other.heso[i];

    return result;
}

DaThuc DaThuc::operator-(const DaThuc& other) const {
    int maxBac = max(bac, other.bac);
    DaThuc result(maxBac);

    for (int i = 0; i <= bac; ++i) result.heso[i] += heso[i];
    for (int i = 0; i <= other.bac; ++i) result.heso[i] -= other.heso[i];

    return result;
}

DaThuc DaThuc::operator*(const DaThuc& other) const {
    DaThuc result(bac + other.bac);

    for (int i = 0; i <= bac; ++i) {
        for (int j = 0; j <= other.bac; ++j) {
            result.heso[i + j] += heso[i] * other.heso[j];
        }
    }
    return result;
}

double DaThuc::operator()(double x) const {
    double result = heso[bac];
    for (int i = bac - 1; i >= 0; --i) {
        result = result * x + heso[i];
    }
    return result;
}

ostream& operator<<(ostream& os, const DaThuc& dt) {
    bool isZero = true;

    for (int i = dt.bac; i >= 0; --i) {
        if (dt.heso[i] == 0) continue;

        if (isZero) {
            if (dt.heso[i] < 0) os << "-";
            isZero = false;
        } else {
            os << (dt.heso[i] > 0 ? " + " : " - ");
        }

        double val = abs(dt.heso[i]);
        if (val != 1 || i == 0) {
            os << val;
        }

        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;
    }

    if (isZero) os << "0";
    return os;
}

istream& operator>>(istream& is, DaThuc& dt) {
    int b;
    cout << "Nhap bac cua da thuc: ";
    is >> b;

    delete[] dt.heso;
    dt.bac = b;
    dt.heso = new double[dt.bac + 1];

    for (int i = dt.bac; i >= 0; --i) {
        cout << "Nhap he so cua x^" << i << ": ";
        is >> dt.heso[i];
    }
    return is;
}
