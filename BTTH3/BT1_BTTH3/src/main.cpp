#include <iostream>
#include "cTamGiac.h"
using namespace std;

int main() {
    cTamGiac tg;
    tg.nhap();

    cout << "\nTAM GIAC BAN DAU\n";
    tg.xuat();
    cout << "Chu vi: " << tg.chuvi() << endl;
    cout << "Dien tich: " << tg.dientich() << endl;
    tg.loaitamgiac();

    cTamGiac tg1 = tg;
    tg1.tinhtien(1, 1);
    cout << "\nTINH TIEN (1,1)\n";
    tg1.xuat();

    cTamGiac tg2 = tg;
    tg2.phongto(2);
    cout << "\nPHONG TO x2\n";
    tg2.xuat();

    cTamGiac tg3 = tg;
    tg3.thunho(2);
    cout << "\nTHU NHO x2\n";
    tg3.xuat();

    cTamGiac tg4 = tg;
    tg4.quay(90);
    cout << "\nQUAY 90 DO\n";
    tg4.xuat();

    return 0;
}
