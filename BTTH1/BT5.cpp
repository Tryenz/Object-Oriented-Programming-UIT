#include <iostream>
#include <string>
using namespace std;

class HocSinh {
private:
    string hoten;
    float toan, van, dtb;

    bool tenhople(string s) {
        if (s.empty()) return false;

        bool cochu = false;
        for (char c : s) {
            if (isdigit(c)) return false;
            if (isalpha(c)) cochu = true;
        }
        return cochu;
    }

    float nhapdiem() {
        float x;
        while (true) {
            cin >> x;

            if (cin.fail()) {
                cout << "Loi: Vui long nhap so!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (x < 0 || x > 10) {
                cout << "Diem phai tu 0 den 10! Nhap lai: ";
            }
            else {
                cin.ignore(1000, '\n');
                return x;
            }
        }
    }

public:
    void nhap() {
        while (true) {
            cout << "Nhap ho ten: ";
            getline(cin, hoten);

            if (!tenhople(hoten)) {
                cout << "Ten khong hop le!\n";
            } else break;
        }

        cout << "Nhap diem Toan: ";
        toan = nhapdiem();

        cout << "Nhap diem Van: ";
        van = nhapdiem();
    }

    void tinhdtb() {
        dtb = (toan + van) / 2;
    }

    void xuat() {
        cout << "\nTHONG TIN HOC SINH\n";
        cout << "Ho ten: " << hoten << endl;
        cout << "Diem Toan: " << toan << endl;
        cout << "Diem Van: " << van << endl;
        cout << "Diem trung binh: " << dtb << endl;
    }
};

int main() {
    HocSinh hs;

    hs.nhap();
    hs.tinhdtb();
    hs.xuat();

    return 0;
}
