#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <bits/stdc++.h>

using namespace std;

class KhachHang {
protected:
    string TenKhachHang;
    int SoLuongHang;
    double DonGiaHang;

public:
    virtual ~KhachHang() {}

    virtual void docFile(ifstream& in);
    virtual void ghiFile(ofstream& out) const;
    virtual double TinhTien() const = 0;
};

class KhachHangA : public KhachHang {
public:
    double TinhTien() const override;
};

class KhachHangB : public KhachHang {
private:
    int SoNamThanThiet;

public:
    void docFile(ifstream& in) override;
    double TinhTien() const override;
};

class KhachHangC : public KhachHang {
public:
    double TinhTien() const override;
};

#endif // KHACHHANG_H
