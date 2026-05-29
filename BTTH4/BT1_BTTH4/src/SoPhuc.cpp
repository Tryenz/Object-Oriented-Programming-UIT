#include "SoPhuc.h"

SoPhuc::SoPhuc(double t, double a) : thuc(t), ao(a) {}

SoPhuc SoPhuc::operator+(const SoPhuc& other) const {
    return SoPhuc(thuc + other.thuc, ao + other.ao);
}

SoPhuc SoPhuc::operator-(const SoPhuc& other) const {
    return SoPhuc(thuc - other.thuc, ao - other.ao);
}

SoPhuc SoPhuc::operator*(const SoPhuc& other) const {
    double r = thuc * other.thuc - ao * other.ao;
    double i = thuc * other.ao + ao * other.thuc;
    return SoPhuc(r, i);
}

SoPhuc SoPhuc::operator/(const SoPhuc& other) const {
    double mau = other.thuc * other.thuc + other.ao * other.ao;
    double r = (thuc * other.thuc + ao * other.ao) / mau;
    double i = (ao * other.thuc - thuc * other.ao) / mau;
    return SoPhuc(r, i);
}

bool SoPhuc::operator==(const SoPhuc& other) const {
    return (thuc == other.thuc && ao == other.ao);
}

bool SoPhuc::operator!=(const SoPhuc& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const SoPhuc& sp) {
    if (sp.ao >= 0) {
        os << sp.thuc << " + " << sp.ao << "i";
    } else {
        os << sp.thuc << " - " << -sp.ao << "i";
    }
    return os;
}

istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.thuc;
    cout << "Nhap phan ao: ";
    is >> sp.ao;
    return is;
}
