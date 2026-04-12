#include <iostream>
#include "SoPhuc.h"
using namespace std;

void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}

void SoPhuc::Xuat() {
    cout << iThuc;
    if (iAo >= 0)
        cout << " + " << iAo << "i";
    else
        cout << " - " << -iAo << "i";
}

// Cộng
SoPhuc SoPhuc::Tong(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc + sp.iThuc;
    kq.iAo = iAo + sp.iAo;
    return kq;
}

// Trừ
SoPhuc SoPhuc::Hieu(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc - sp.iThuc;
    kq.iAo = iAo - sp.iAo;
    return kq;
}

// Nhân
SoPhuc SoPhuc::Tich(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    kq.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
    return kq;
}

// Chia
SoPhuc SoPhuc::Thuong(SoPhuc sp) {
    SoPhuc kq;
    float mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;

    kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mau;
    kq.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mau;

    return kq;
}
