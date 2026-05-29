#include "cTamGiac.h"
#include <iostream>
#include <cmath>
using namespace std;

cTamGiac::cTamGiac() {}
cTamGiac::~cTamGiac() {}

double cTamGiac::dodai(cDiem P, cDiem Q) {
    return sqrt(pow(P.x - Q.x, 2) + pow(P.y - Q.y, 2));
}

void cTamGiac::nhap() {
    cout << "Nhap diem A: "; A.nhap();
    cout << "Nhap diem B: "; B.nhap();
    cout << "Nhap diem C: "; C.nhap();
}

void cTamGiac::xuat() {
    cout << "Tam giac: ";
    A.xuat(); cout << " ";
    B.xuat(); cout << " ";
    C.xuat(); cout << endl;
}

double cTamGiac::chuvi() {
    return dodai(A, B) + dodai(B, C) + dodai(C, A);
}

double cTamGiac::dientich() {
    double a = dodai(A, B);
    double b = dodai(B, C);
    double c = dodai(C, A);
    double p = chuvi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void cTamGiac::loaitamgiac() {
    double a = dodai(A, B);
    double b = dodai(B, C);
    double c = dodai(C, A);

    if (a == b && b == c)
        cout << "Tam giac deu\n";
    else if (a == b || b == c || a == c)
        cout << "Tam giac can\n";
    else if (fabs(a*a + b*b - c*c) < 1e-6 ||
             fabs(a*a + c*c - b*b) < 1e-6 ||
             fabs(b*b + c*c - a*a) < 1e-6)
        cout << "Tam giac vuong\n";
    else
        cout << "Tam giac thuong\n";
}

void cTamGiac::tinhtien(double dx, double dy) {
    A.tinhtien(dx, dy);
    B.tinhtien(dx, dy);
    C.tinhtien(dx, dy);
}

void cTamGiac::phongto(double k) {
    A.phongto(k);
    B.phongto(k);
    C.phongto(k);
}

void cTamGiac::thunho(double k) {
    A.thunho(k);
    B.thunho(k);
    C.thunho(k);
}

void cTamGiac::quay(double goc) {
    A.quay(goc);
    B.quay(goc);
    C.quay(goc);
}
