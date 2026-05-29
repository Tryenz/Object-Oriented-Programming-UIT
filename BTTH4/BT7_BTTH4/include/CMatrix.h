#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <iomanip>
#include "CVector.h"
using namespace std;

class CMatrix {
private:
    int rows;
    int cols;
    double** data;

    void allocateMemory();
    void freeMemory();

public:
    CMatrix(int r = 2, int c = 2);

    ~CMatrix();
    CMatrix(const CMatrix& other);
    CMatrix& operator=(const CMatrix& other);

    double& operator()(int r, int c);
    double operator()(int r, int c) const;

    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;

    CMatrix operator*(const CMatrix& other) const;

    CVector operator*(const CVector& v) const;

    friend ostream& operator<<(ostream& os, const CMatrix& m);
    friend istream& operator>>(istream& is, CMatrix& m);
};

#endif
