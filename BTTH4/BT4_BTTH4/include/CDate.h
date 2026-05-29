#ifndef CDATE_H
#define CDATE_H

#include <iostream>
using namespace std;

class CDate {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;
    int daysFromEpoch() const;

public:
    CDate(int d = 1, int m = 1, int y = 2026);

    CDate operator+(int d) const;
    CDate operator-(int d) const;

    CDate& operator++();
    CDate& operator--();

    int operator-(const CDate& other) const;

    friend ostream& operator<<(ostream& os, const CDate& dt);
    friend istream& operator>>(istream& is, CDate& dt);
};

#endif
