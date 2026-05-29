#include <iostream>
#include "CMatrix.h"
#include "CVector.h"

int main() {
    cout << "===== TICH HAI MA TRAN =====\n";
    CMatrix A, B;
    cout << "--- Nhap Ma Tran A ---\n";
    cin >> A;
    cout << "\n--- Nhap Ma Tran B ---\n";
    cin >> B;

    cout << "\nMa tran A:\n" << A;
    cout << "Ma tran B:\n" << B;

    CMatrix C = A * B;
    cout << "Tich A * B =\n" << C << "\n";

    cout << "===== TICH MA TRAN VOI VECTOR =====\n";
    CMatrix M;
    cout << "--- Nhap Ma Tran M ---\n";
    cin >> M;

    CVector V;
    cout << "\n--- Nhap Vector V ---\n";
    cin >> V;

    cout << "\nMa tran M:\n" << M;
    cout << "Vector V: " << V << "\n";

    CVector resultV = M * V;
    cout << "Tich M * V = " << resultV << "\n";

    return 0;
}
