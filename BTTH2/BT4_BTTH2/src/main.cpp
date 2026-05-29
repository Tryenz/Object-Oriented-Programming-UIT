#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

int main() {
    GioPhutGiay t;

    cout << "Nhap gio phut giay:\n";
    t.Nhap();

    cout << "\nThoi gian ban dau: ";
    t.Xuat();

    GioPhutGiay next = t.TinhCongThemMotGiay();

    cout << "\nSau khi cong 1 giay: ";
    next.Xuat();

    return 0;
}

