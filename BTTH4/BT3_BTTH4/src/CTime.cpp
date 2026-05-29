#include "CTime.h"

void CTime::chuanhoa() {
    long totalseconds = hour * 3600 + minute * 60 + second;

    totalseconds = (totalseconds % 86400 + 86400) % 86400;

    hour = totalseconds / 3600;
    minute = (totalseconds % 3600) / 60;
    second = totalseconds % 60;
}

CTime::CTime(int h, int m, int s) : hour(h), minute(m), second(s) {
    chuanhoa();
}

CTime CTime::operator+(int s) const {
    return CTime(hour, minute, second + s);
}

CTime CTime::operator-(int s) const {
    return CTime(hour, minute, second - s);
}

CTime& CTime::operator++() {
    second++;
    chuanhoa();
    return *this;
}

CTime& CTime::operator--() {
    second--;
    chuanhoa();
    return *this;
}

ostream& operator<<(ostream& os, const CTime& t) {
    os << setfill('0') << setw(2) << t.hour << ":"
       << setfill('0') << setw(2) << t.minute << ":"
       << setfill('0') << setw(2) << t.second;
    return os;
}

istream& operator>>(istream& is, CTime& t) {
    cout << "Nhap gio: "; is >> t.hour;
    cout << "Nhap phut: "; is >> t.minute;
    cout << "Nhap giay: "; is >> t.second;
    t.chuanhoa();
    return is;
}
