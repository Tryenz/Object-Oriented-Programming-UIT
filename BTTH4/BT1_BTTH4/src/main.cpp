#include <iostream>
#include "SoPhuc.h"

int main() {;

    SoPhuc sp1, sp2;
    cout << "--- Nhap so phuc 1 ---\n";
    cin >> sp1;
    cout << "--- Nhap so phuc 2 ---\n";
    cin >> sp2;

    cout << "\n--- Cac so phuc ---\n";
    cout << "So phuc 1: " << sp1 << "\n";
    cout << "So phuc 2: " << sp2 << "\n";

    cout << "\n--- Ket qua cac phep toan ---\n";
    cout << "Tong:   " << (sp1 + sp2) << "\n";
    cout << "Hieu:   " << (sp1 - sp2) << "\n";
    cout << "Tich:   " << (sp1 * sp2) << "\n";
    cout << "Thuong: " << (sp1 / sp2) << "\n";

    cout << "\n--- Ket qua so sanh ---\n";
    cout << "So phuc 1 == So phuc 2: " << ((sp1 == sp2) ? "Dung" : "Sai") << "\n";
    cout << "So phuc 1 != So phuc 2: " << ((sp1 != sp2) ? "Dung" : "Sai") << "\n";

    return 0;
}
