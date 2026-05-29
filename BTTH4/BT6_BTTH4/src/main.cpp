#include <iostream>
#include "CVector.h"

int main() {
    CVector v1, v2;

    cout << "--- NHAP VECTOR V1 ---\n";
    cin >> v1;
    cout << "v1 = " << v1 << "\n";
    cout << "Do dai |v1| = " << v1.length() << "\n\n";

    cout << "--- NHAP VECTOR V2 ---\n";
    cin >> v2;
    cout << "v2 = " << v2 << "\n";
    cout << "Do dai |v2| = " << v2.length() << "\n\n";

    cout << "--- KET QUA CAC PHEP TOAN ---\n";
    CVector tong = v1 + v2;
    cout << "v1 + v2 = " << tong << "\n";

    CVector hieu = v1 - v2;
    cout << "v1 - v2 = " << hieu << "\n";

    double tichvohuong = v1 * v2;
    cout << "Tich vo huong v1 * v2 = " << tichvohuong << "\n";

    double k;
    cout << "\nNhap so k de nhan: ";
    cin >> k;

    cout << "v1 * " << k << " = " << (v1 * k) << "\n";
    cout << k << " * v2 = " << (k * v2) << "\n";

    return 0;
}
