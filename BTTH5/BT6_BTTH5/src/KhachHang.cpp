#include "KhachHang.h"
#include <algorithm>

void KhachHang::docFile(ifstream& in) {
    in >> ws;
    getline(in, TenKhachHang);
    in >> SoLuongHang >> DonGiaHang;
}

void KhachHang::ghiFile(ofstream& out) const {
    out << TenKhachHang << "\n";
    out << (long long)TinhTien() << "\n";
}

double KhachHangA::TinhTien() const {
    return (SoLuongHang * DonGiaHang) * 1.1;
}

void KhachHangB::docFile(ifstream& in) {
    KhachHang::docFile(in);
    in >> SoNamThanThiet;
}

double KhachHangB::TinhTien() const {
    double PhanTramKhuyenMai = max(SoNamThanThiet * 0.05, 0.50);
    double TienSauKhiGiam = (SoLuongHang * DonGiaHang) * (1.0 - PhanTramKhuyenMai);
    return TienSauKhiGiam * 1.1;
}

double KhachHangC::TinhTien() const {
    return (SoLuongHang * DonGiaHang * 0.5) * 1.1;
}
