#ifndef CDIEM_H
#define CDIEM_H

class cDiem {
public:
    double x, y;

    cDiem();
    cDiem(double x, double y);
    ~cDiem();

    void nhap();
    void xuat();

    void tinhtien(double dx, double dy);
    void phongto(double k);
    void thunho(double k);
    void quay(double goc);
};

#endif
