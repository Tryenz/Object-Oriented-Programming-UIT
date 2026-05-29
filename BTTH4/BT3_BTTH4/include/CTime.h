#ifndef CTIME_H
#define CTIME_H

#include <iostream>
#include <iomanip>
using namespace std;

class CTime {
private:
    int hour;
    int minute;
    int second;

    void chuanhoa();

public:
    CTime(int h = 0, int m = 0, int s = 0);

    CTime operator+(int s) const;
    CTime operator-(int s) const;

    CTime& operator++();
    CTime& operator--();

    friend ostream& operator<<(ostream& os, const CTime& t);
    friend istream& operator>>(istream& is, CTime& t);
};

#endif
