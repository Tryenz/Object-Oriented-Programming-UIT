#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
private:
    int bac;
    double* heso;

public:
    DaThuc(int n = 0);

    ~DaThuc();
    DaThuc(const DaThuc& other);
    DaThuc& operator=(const DaThuc& other);

    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;

    double operator()(double x) const;

    friend ostream& operator<<(ostream& os, const DaThuc& dt);
    friend istream& operator>>(istream& is, DaThuc& dt);
};

#endif
