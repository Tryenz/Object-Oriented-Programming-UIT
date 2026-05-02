#ifndef CTAMGIAC_H
#define CTAMGIAC_H

#include "cDiem.h"

class cTamGiac {
private:
    cDiem A, B, C;

    double dodai(cDiem P, cDiem Q);

public:
    cTamGiac();
    ~cTamGiac();

    void nhap();
    void xuat();

    double chuvi();
    double dientich();
    void loaitamgiac();

    void tinhtien(double dx, double dy);
    void phongto(double k);
    void thunho(double k);
    void quay(double goc);
};

#endif
