#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main() {
    NgayThangNam a;

    cout << "Nhap ngay thang nam:\n";
    a.Nhap();

    cout << "\nNgay vua nhap: ";
    a.Xuat();

    NgayThangNam next = a.NgayThangNamTiepTheo();

    cout << "\nNgay tiep theo: ";
    next.Xuat();

    return 0;
}

