#include <iostream>
#include "NgayThangNam.h"
using namespace std;

bool LaNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int SoNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return LaNamNhuan(nam) ? 29 : 28;
        default:
            return 0;
    }
}

void NgayThangNam::Nhap() {
    cout << "Nhap ngay: ";
    cin >> iNgay;
    cout << "Nhap thang: ";
    cin >> iThang;
    cout << "Nhap nam: ";
    cin >> iNam;
}

void NgayThangNam::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam;
}

NgayThangNam NgayThangNam::NgayThangNamTiepTheo() {
    NgayThangNam kq = *this;

    int maxNgay = SoNgayTrongThang(iThang, iNam);

    kq.iNgay++;

    if (kq.iNgay > maxNgay) {
        kq.iNgay = 1;
        kq.iThang++;

        if (kq.iThang > 12) {
            kq.iThang = 1;
            kq.iNam++;
        }
    }

    return kq;
}
