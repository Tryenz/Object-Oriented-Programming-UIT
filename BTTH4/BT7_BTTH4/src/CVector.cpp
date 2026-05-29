#include "CVector.h"

CVector::CVector(int dim) : n(dim) {
    if (n < 1) n = 1;
    mangdong = new double[n];
    for (int i = 0; i < n; ++i) mangdong[i] = 0.0;
}

CVector::~CVector() { delete[] mangdong; }

CVector::CVector(const CVector& other) : n(other.n) {
    mangdong = new double[n];
    for (int i = 0; i < n; ++i) mangdong[i] = other.mangdong[i];
}

CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        delete[] mangdong;
        n = other.n;
        mangdong = new double[n];
        for (int i = 0; i < n; ++i) mangdong[i] = other.mangdong[i];
    }
    return *this;
}

double& CVector::operator[](int index) { return mangdong[index]; }
double CVector::operator[](int index) const { return mangdong[index]; }

CVector CVector::operator+(const CVector& other) const {
    if (n != other.n) return CVector(n);
    CVector result(n);
    for (int i = 0; i < n; ++i) result.mangdong[i] = mangdong[i] + other.mangdong[i];
    return result;
}

CVector CVector::operator-(const CVector& other) const {
    if (n != other.n) return CVector(n);
    CVector result(n);
    for (int i = 0; i < n; ++i) result.mangdong[i] = mangdong[i] - other.mangdong[i];
    return result;
}

double CVector::operator*(const CVector& other) const {
    if (n != other.n) return 0;
    double result = 0;
    for (int i = 0; i < n; ++i) result += mangdong[i] * other.mangdong[i];
    return result;
}

CVector CVector::operator*(double k) const {
    CVector result(n);
    for (int i = 0; i < n; ++i) result.mangdong[i] = mangdong[i] * k;
    return result;
}

CVector operator*(double k, const CVector& v) { return v * k; }

double CVector::length() const {
    double sum = 0;
    for (int i = 0; i < n; ++i) sum += mangdong[i] * mangdong[i];
    return sqrt(sum);
}

bool CVector::operator==(const CVector& other) const {
    if (n != other.n) return false;
    for (int i = 0; i < n; ++i) {
        if (mangdong[i] != other.mangdong[i]) return false;
    }
    return true;
}

bool CVector::operator!=(const CVector& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const CVector& v) {
    os << "(";
    for (int i = 0; i < v.n; ++i) {
        os << v.mangdong[i];
        if (i < v.n - 1) os << ", ";
    }
    os << ")";
    return os;
}

istream& operator>>(istream& is, CVector& v) {
    int dim;
    cout << "Nhap so chieu cua vector: "; is >> dim;
    delete[] v.mangdong;
    v.n = dim;
    v.mangdong = new double[v.n];
    for (int i = 0; i < v.n; ++i) {
        cout << "Nhap toa do thu " << i + 1 << ": ";
        is >> v.mangdong[i];
    }
    return is;
}
