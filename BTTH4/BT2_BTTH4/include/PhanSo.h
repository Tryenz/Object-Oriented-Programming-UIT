#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
#include <cmath>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

    int UCLN(int a, int b) const;

    void rutGon();

public:
    PhanSo(int t = 0, int m = 1);

    PhanSo operator+(const PhanSo& other) const;
    PhanSo operator-(const PhanSo& other) const;
    PhanSo operator*(const PhanSo& other) const;
    PhanSo operator/(const PhanSo& other) const;

    bool operator==(const PhanSo& other) const;
    bool operator>(const PhanSo& other) const;
    bool operator<(const PhanSo& other) const;

    friend ostream& operator<<(ostream& os, const PhanSo& ps);
    friend istream& operator>>(istream& is, PhanSo& ps);
};

#endif
