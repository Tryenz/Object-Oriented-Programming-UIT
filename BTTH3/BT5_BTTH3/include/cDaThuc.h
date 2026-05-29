#pragma once
#include<iostream>
#include<vector>
using namespace std;
class cDaThuc
{
private:
	int n;
	vector<double> he_so;
public:
	cDaThuc();
	cDaThuc(const vector<double>);
	void nhap();
	void xuat();
	long long tinhX(int x);
	cDaThuc cong(cDaThuc);
	cDaThuc tru(cDaThuc);
	int getN();
};
