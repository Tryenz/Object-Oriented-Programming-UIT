#include <iostream>
#include "PhanSo.h"

int main() {

    PhanSo ps1, ps2;
    cout << "--- Nhap phan so 1 ---\n";
    cin >> ps1;
    cout << "--- Nhap phan so 2 ---\n";
    cin >> ps2;

    cout << "\n--- Ket qua cac phep toan ---\n";
    cout << "Tong:   " << (ps1 + ps2) << "\n";
    cout << "Hieu:   " << (ps1 - ps2) << "\n";
    cout << "Tich:   " << (ps1 * ps2) << "\n";
    cout << "Thuong: " << (ps1 / ps2) << "\n";

    cout << "\n--- Ket qua so sanh ---\n";
    cout << ps1 << " == " << ps2 << " : " << ((ps1 == ps2) ? "Dung" : "Sai") << "\n";
    cout << ps1 << " > " << ps2 << "  : " << ((ps1 > ps2) ? "Dung" : "Sai") << "\n";
    cout << ps1 << " < " << ps2 << "  : " << ((ps1 < ps2) ? "Dung" : "Sai") << "\n";

    return 0;
}
