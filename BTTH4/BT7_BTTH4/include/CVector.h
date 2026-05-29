#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <cmath>
using namespace std;

class CVector {
private:
    int n;
    double* mangdong;

public:
    CVector(int dim = 2);

    ~CVector();
    CVector(const CVector& other);
    CVector& operator=(const CVector& other);

    int getSize() const { return n; }

    double& operator[](int index);
    double operator[](int index) const;

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;
    double operator*(const CVector& other) const;
    CVector operator*(double k) const;

    double length() const;

    bool operator==(const CVector& other) const;
    bool operator!=(const CVector& other) const;

    friend ostream& operator<<(ostream& os, const CVector& v);
    friend istream& operator>>(istream& is, CVector& v);
    friend CVector operator*(double k, const CVector& v);
};

#endif
