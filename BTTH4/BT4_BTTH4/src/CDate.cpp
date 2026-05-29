#include "CDate.h"

bool CDate::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int CDate::daysInMonth(int m, int y) const {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m];
}

int CDate::daysFromEpoch() const {
    int y = year - 1;
    int totalDays = y * 365 + y / 4 - y / 100 + y / 400;

    for (int i = 1; i < month; ++i) {
        totalDays += daysInMonth(i, year);
    }

    totalDays += day;
    return totalDays;
}

CDate::CDate(int d, int m, int y) : day(d), month(m), year(y) {
    if (year < 1) year = 1;
    if (month < 1 || month > 12) month = 1;
    if (day < 1 || day > daysInMonth(month, year)) day = 1;
}

CDate CDate::operator+(int d) const {
    CDate result = *this;
    result.day += d;
    while (result.day > result.daysInMonth(result.month, result.year)) {
        result.day -= result.daysInMonth(result.month, result.year);
        result.month++;
        if (result.month > 12) {
            result.month = 1;
            result.year++;
        }
    }
    return result;
}

CDate CDate::operator-(int d) const {
    CDate result = *this;
    result.day -= d;
    while (result.day <= 0) {
        result.month--;
        if (result.month < 1) {
            result.month = 12;
            result.year--;
        }
        result.day += result.daysInMonth(result.month, result.year);
    }
    return result;
}

CDate& CDate::operator++() {
    *this = *this + 1;
    return *this;
}

CDate& CDate::operator--() {
    *this = *this - 1;
    return *this;
}

int CDate::operator-(const CDate& other) const {
    return this->daysFromEpoch() - other.daysFromEpoch();
}

ostream& operator<<(ostream& os, const CDate& dt) {
    os << (dt.day < 10 ? "0" : "") << dt.day << "/"
       << (dt.month < 10 ? "0" : "") << dt.month << "/"
       << dt.year;
    return os;
}

istream& operator>>(istream& is, CDate& dt) {
    cout << "Nhap ngay: "; is >> dt.day;
    cout << "Nhap thang: "; is >> dt.month;
    cout << "Nhap nam: "; is >> dt.year;

    if (dt.year < 1) dt.year = 1;
    if (dt.month < 1 || dt.month > 12) dt.month = 1;
    if (dt.day < 1 || dt.day > dt.daysInMonth(dt.month, dt.year)) {
        cout << "Ngay khong hop le! Tu dong dua ve ngay 1.\n";
        dt.day = 1;
    }
    return is;
}
