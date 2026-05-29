#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

void GioPhutGiay::Nhap() {
    cout << "Nhap gio: ";
    cin >> iGio;
    cout << "Nhap phut: ";
    cin >> iPhut;
    cout << "Nhap giay: ";
    cin >> iGiay;
}

void GioPhutGiay::Xuat() {
    cout << iGio << ":" << iPhut << ":" << iGiay;
}

GioPhutGiay GioPhutGiay::TinhCongThemMotGiay() {
    GioPhutGiay kq = *this;

    kq.iGiay++;

    if (kq.iGiay >= 60) {
        kq.iGiay = 0;
        kq.iPhut++;

        if (kq.iPhut >= 60) {
            kq.iPhut = 0;
            kq.iGio++;

            if (kq.iGio >= 24) {
                kq.iGio = 0;
            }
        }
    }

    return kq;
}
