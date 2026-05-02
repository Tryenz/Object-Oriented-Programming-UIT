#include "cDiem.h"
#include <iostream>
#include <cmath>
using namespace std;

cDiem::cDiem() {
    x = y = 0;
}

cDiem::cDiem(double x, double y) {
    this->x = x;
    this->y = y;
}

cDiem::~cDiem() {}

void cDiem::nhap() {
    cin >> x >> y;
}

void cDiem::xuat() {
    cout << "(" << x << ", " << y << ")";
}

void cDiem::tinhtien(double dx, double dy) {
    x += dx;
    y += dy;
}

void cDiem::phongto(double k) {
    x *= k;
    y *= k;
}

void cDiem::thunho(double k) {
    x /= k;
    y /= k;
}

void cDiem::quay(double goc) {
    double rad = goc * M_PI / 180;
    double xMoi = x * cos(rad) - y * sin(rad);
    double yMoi = x * sin(rad) + y * cos(rad);
    x = xMoi;
    y = yMoi;
}
