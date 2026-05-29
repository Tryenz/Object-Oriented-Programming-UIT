#include <iostream>
#include "DaThuc.h"

int main() {
    DaThuc dt1, dt2;

    cout << "--- NHAP DA THUC 1 ---\n";
    cin >> dt1;
    cout << "P(x) = " << dt1 << "\n\n";

    cout << "--- NHAP DA THUC 2 ---\n";
    cin >> dt2;
    cout << "Q(x) = " << dt2 << "\n\n";

    cout << "--- KET QUA CAC PHEP TOAN ---\n";
    DaThuc tong = dt1 + dt2;
    cout << "P(x) + Q(x) = " << tong << "\n";

    DaThuc hieu = dt1 - dt2;
    cout << "P(x) - Q(x) = " << hieu << "\n";

    DaThuc tich = dt1 * dt2;
    cout << "P(x) * Q(x) = " << tich << "\n\n";

    double x;
    cout << "Nhap gia tri x can tinh: ";
    cin >> x;

    cout << "P(" << x << ") = " << dt1(x) << "\n";
    cout << "Q(" << x << ") = " << dt2(x) << "\n";

    return 0;
}
