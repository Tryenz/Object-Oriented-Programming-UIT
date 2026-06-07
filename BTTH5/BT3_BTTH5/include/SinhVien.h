#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <bits/stdc++.h>
using namespace std;

int NhapSoNguyen(const string& ThongBao, int MinVal);
double NhapDiem(const string& ThongBao);
void XoaBoDem();

class SinhVien {
protected:
    string MaSinhVien;
    string HoTen;
    string DiaChi;
    int TongTinChi;
    double DiemTrungBinh;

public:
    virtual ~SinhVien() {}

    virtual void nhap();
    virtual void xuat() const;
    virtual bool XetTotNghiep() const = 0;

    double getDiemTrungBinh() const;
    string getHoTen() const;
};

class SVCaoDang : public SinhVien {
private:
    double DiemThiTN;

public:
    void nhap() override;
    void xuat() const override;
    bool XetTotNghiep() const override;
};

class SVDaiHoc : public SinhVien {
private:
    string TenLuanVan;
    double DiemLuanVan;

public:
    void nhap() override;
    void xuat() const override;
    bool XetTotNghiep() const override;
};

#endif // SINHVIEN_H
