#include "cDaThuc.h"

int main()
{
	cDaThuc x, y;
	cout << "Nhap da thuc 1: "<<endl;
	x.nhap();
	cout << "Nhap da thuc 2: "<<endl;
	y.nhap();
	if (x.getN() == 0 && y.getN() == 0)
	{
		cout << "Hai da thuc deu bang 0";
		return 0;
	}
	cout << "Da thuc 1: ";
	if (x.getN() == 0) cout << 0;
	else x.xuat();
	cout << endl;
	cout << "Da thuc 2: ";
	if (y.getN() == 0) cout << 0;
	else y.xuat();
	cout << endl;
	int k;
	cout << "Nhap x: ";
	cin >> k;
	cout << "Ket qua cua da thuc 1 khi thay x: " << x.tinhX(k) << endl;
	cout << "Ket qua cua da thuc 2 khi thay x: " << y.tinhX(k) << endl;
	cout << "Ket qua cong 2 da thuc: "; x.cong(y).xuat();
	cout << endl;
	cout << "Ket qua tru 2 da thuc: "; x.tru(y).xuat();
}
