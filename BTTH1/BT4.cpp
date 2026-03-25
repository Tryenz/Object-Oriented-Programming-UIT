#include <iostream>
using namespace std;

class Date {
private:
    int ngay, thang, nam;

    bool namnhuan() {
        return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
    }

    int songaytrongthang() {
        if (thang == 1 || thang == 3 || thang == 5 || thang == 7 ||
            thang == 8 || thang == 10 || thang == 12)
            return 31;

        if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            return 30;

        if (thang == 2)
            return namnhuan() ? 29 : 28;

        return 0;
    }

public:
    void nhap() {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }

    bool hople() {
        if (nam < 1 || thang < 1 || thang > 12)
            return false;

        if (ngay < 1 || ngay > songaytrongthang())
            return false;

        return true;
    }

    void ngayketiep() {
        ngay++;

        if (ngay > songaytrongthang()) {
            ngay = 1;
            thang++;

            if (thang > 12) {
                thang = 1;
                nam++;
            }
        }
    }

    void xuat() {
        cout << ngay << "/" << thang << "/" << nam;
    }
};

int main() {
    Date d;

    d.nhap();

    if (!d.hople()) {
        cout << "Ngay khong hop le!";
        return 0;
    }

    d.ngayketiep();

    cout << "Ngay ke tiep la: ";
    d.xuat();

    return 0;
}
