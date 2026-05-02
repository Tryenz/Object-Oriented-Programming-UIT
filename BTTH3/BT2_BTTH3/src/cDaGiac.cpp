#include "cDaGiac.h"
#include <iostream>
#include <cmath>
using namespace std;

cDaGiac::cDaGiac() {
    n = 0;
}

cDaGiac::~cDaGiac() {}

double cDaGiac::dodai(cDiem A, cDiem B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

void cDaGiac::nhap() {
    cout << "Nhap so dinh: ";
    cin >> n;

    dsDiem.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap diem " << i + 1 << ": ";
        dsDiem[i].nhap();
    }
}

void cDaGiac::xuat() {
    cout << "Da giac: ";
    for (int i = 0; i < n; i++) {
        dsDiem[i].xuat();
        cout << " ";
    }
    cout << endl;
}

double cDaGiac::chuvi() {
    double cv = 0;
    for (int i = 0; i < n; i++) {
        cv += dodai(dsDiem[i], dsDiem[(i + 1) % n]);
    }
    return cv;
}

// Công thức Shoelace
double cDaGiac::dientich() {
    double s = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += dsDiem[i].x * dsDiem[j].y;
        s -= dsDiem[j].x * dsDiem[i].y;
    }
    return fabs(s) / 2;
}

void cDaGiac::tinhtien(double dx, double dy) {
    for (int i = 0; i < n; i++)
        dsDiem[i].tinhtien(dx, dy);
}

void cDaGiac::phongto(double k) {
    for (int i = 0; i < n; i++)
        dsDiem[i].phongto(k);
}

void cDaGiac::thunho(double k) {
    for (int i = 0; i < n; i++)
        dsDiem[i].thunho(k);
}

void cDaGiac::quay(double goc) {
    for (int i = 0; i < n; i++)
        dsDiem[i].quay(goc);
}
