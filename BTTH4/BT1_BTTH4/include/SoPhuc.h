#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    SoPhuc(double t = 0.0, double a = 0.0);

    SoPhuc operator+(const SoPhuc& other) const;
    SoPhuc operator-(const SoPhuc& other) const;
    SoPhuc operator*(const SoPhuc& other) const;
    SoPhuc operator/(const SoPhuc& other) const;

    bool operator==(const SoPhuc& other) const;
    bool operator!=(const SoPhuc& other) const;

    friend ostream& operator<<(ostream& os, const SoPhuc& sp);
    friend istream& operator>>(istream& is, SoPhuc& sp);
};

#endif
