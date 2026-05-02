#include <iostream>
#include "cDaGiac.h"
using namespace std;

int main() {
    cDaGiac dg;
    dg.nhap();

    cout << "\nDA GIAC BAN DAU\n";
    dg.xuat();
    cout << "Chu vi: " << dg.chuvi() << endl;
    cout << "Dien tich: " << dg.dientich() << endl;

    cDaGiac dg1 = dg;
    dg1.tinhtien(1, 1);
    cout << "\nTINH TIEN (1,1)\n";
    dg1.xuat();

    cDaGiac dg2 = dg;
    dg2.phongto(2);
    cout << "\nPHONG TO x2\n";
    dg2.xuat();

    cDaGiac dg3 = dg;
    dg3.thunho(2);
    cout << "\nTHU NHO x2\n";
    dg3.xuat();

    cDaGiac dg4 = dg;
    dg4.quay(90);
    cout << "\nQUAY 90 DO\n";
    dg4.xuat();

    return 0;
}
