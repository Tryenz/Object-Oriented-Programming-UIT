#ifndef CDAGIAC_H
#define CDAGIAC_H

#include <vector>
#include "cDiem.h"
using namespace std;

class cDaGiac {
private:
    int n;
    vector<cDiem> dsDiem;

    double dodai(cDiem A, cDiem B);

public:
    cDaGiac();
    ~cDaGiac();

    void nhap();
    void xuat();

    double chuvi();
    double dientich();

    void tinhtien(double dx, double dy);
    void phongto(double k);
    void thunho(double k);
    void quay(double goc);
};

#endif
