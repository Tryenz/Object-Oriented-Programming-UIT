#ifndef GIAODICH_H
#define GIAODICH_H

#include <bits/stdc++.h>
using namespace std;

int NhapSoNguyen(const string& ThongBao, int MinVal, int MaxVal);
double NhapSoThuc(const string& ThongBao, double MinVal);
bool NgayHopLe(int Ngay, int Thang, int Nam);

class GiaoDich {
protected:
    string MaGiaoDich;
    int Ngay, Thang, Nam;
    double DonGia;
    double DienTich;

public:
    virtual ~GiaoDich() {}

    virtual void nhap();
    virtual void xuat() const;
    virtual double ThanhTien() const = 0;

    int getThang() const;
    int getNam() const;
};

class GiaoDichDat : public GiaoDich {
private:
    char LoaiDat;

public:
    void nhap() override;
    void xuat() const override;
    double ThanhTien() const override;
};

class GiaoDichNhaPho : public GiaoDich {
private:
    string LoaiNha;
    string DiaChi;

public:
    void nhap() override;
    void xuat() const override;
    double ThanhTien() const override;
};

class GiaoDichChungCu : public GiaoDich {
private:
    string MaCan;
    int ViTriTang;

public:
    void nhap() override;
    void xuat() const override;
    double ThanhTien() const override;
};

#endif // GIAODICH_H
