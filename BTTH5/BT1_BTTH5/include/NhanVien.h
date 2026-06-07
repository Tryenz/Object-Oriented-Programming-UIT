#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <bits/stdc++.h>
using namespace std;

int NhapSoNguyen(const string& ThongBao, int MinVal);
double NhapSoThuc(const string& ThongBao, double MinVal);

class NhanVien {
protected:
    string HoTen;
    int Ngay, Thang, Nam;

public:
    virtual ~NhanVien() {}

    virtual void nhap();
    virtual void xuat() const;
    virtual double TinhLuong() const = 0;

    int getNgay() const;
    int getThang() const;
    int getNam() const;

    string getHoTen() const;
};

class NVSanXuat : public NhanVien {
private:
    double LuongCanBan;
    int SoSanPham;

public:
    void nhap() override;
    void xuat() const override;
    double TinhLuong() const override;
};

class NVVanPhong : public NhanVien {
private:
    int SoNgayLamViec;

public:
    void nhap() override;
    void xuat() const override;
    double TinhLuong() const override;
};

#endif // NHANVIEN_H
