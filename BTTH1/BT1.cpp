#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

    int UCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

public:
    void nhap() {
        while (true) {
            cout << "Nhap tu so: ";
            cin >> tu;

            if (cin.fail()) {
                cout << "Loi: Vui long nhap so nguyen!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else break;
        }

        while (true) {
            cout << "Nhap mau so: ";
            cin >> mau;

            if (cin.fail()) {
                cout << "Loi: Vui long nhap so nguyen!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else if (mau == 0) {
                cout << "Loi: Mau so phai khac 0!\n";
            } else break;
        }
    }

    void rutgon() {
        int ucln = UCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;

        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    void xuat() {
        cout << tu << "/" << mau;
    }
};

int main() {
    PhanSo ps;

    ps.nhap();
    ps.rutgon();

    cout << "Phan so sau khi rut gon: ";
    ps.xuat();

    return 0;
}
