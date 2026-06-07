#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <bits/stdc++.h>
using namespace std;

int NhapSoNguyen(const string& ThongBao, int MinVal);
double NhapSoThuc(const string& ThongBao, double MinVal);
void XoaBoDem();

class NhanVien {
protected:
    string MaNhanVien;
    string HoTen;
    int Tuoi;
    string SDT;
    string Email;
    double LuongCoBan;

public:
    virtual ~NhanVien() {}

    virtual void nhap();
    virtual void xuat() const;
    virtual double TinhLuong() const = 0;

    string getHoTen() const;
};

class LapTrinhVien : public NhanVien {
private:
    int Overtime;

public:
    void nhap() override;
    void xuat() const override;
    double TinhLuong() const override;
};

class KiemChungVien : public NhanVien {
private:
    int SoLoi;

public:
    void nhap() override;
    void xuat() const override;
    double TinhLuong() const override;
};

#endif // NHANVIEN_H
