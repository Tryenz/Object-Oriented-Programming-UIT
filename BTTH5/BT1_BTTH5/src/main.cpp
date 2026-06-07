#include <iostream>
#include <vector>
#include "NhanVien.h"

using namespace std;

int main() {
    vector<NhanVien*> DanhSachNV;

    cout << "===== CHUONG TRINH QUAN LY NHAN VIEN =====\n\n";

    int SoLuongSX = NhapSoNguyen("Nhap so luong nhan vien san xuat: ", 0);
    for (int i = 0; i < SoLuongSX; ++i) {
        cout << "\n--- Nhap thong tin nhan vien san xuat thu " << i + 1 << " ---\n";
        NhanVien* nv = new NVSanXuat();
        nv->nhap();
        DanhSachNV.push_back(nv);
    }

    cout << "\n------------------------------------------\n";

    int SoLuongVP = NhapSoNguyen("\nNhap so luong nhan vien van phong: ", 0);
    for (int i = 0; i < SoLuongVP; ++i) {
        cout << "\n--- Nhap thong tin nhan vien van phong thu " << i + 1 << " ---\n";
        NhanVien* nv = new NVVanPhong();
        nv->nhap();
        DanhSachNV.push_back(nv);
    }

    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    for (const auto& nv : DanhSachNV) {
        nv->xuat();
    }

    double TongLuong = 0;
    for (const auto& nv : DanhSachNV) {
        TongLuong += nv->TinhLuong();
    }
    cout << "\nTong luong ma cong ty phai tra cho cac nhan vien: " << (long long)TongLuong << " VND\n";

    NVSanXuat* nvsxMin = nullptr;
    for (const auto& nv : DanhSachNV) {
        if (NVSanXuat* sx = dynamic_cast<NVSanXuat*>(nv)) {
            if (nvsxMin == nullptr || sx->TinhLuong() < nvsxMin->TinhLuong()) {
                nvsxMin = sx;
            }
        }
    }

    if (nvsxMin != nullptr) {
        cout << "Nhan vien san xuat co luong thap nhat: "
             << nvsxMin->getHoTen() << " (" << (long long)nvsxMin->TinhLuong() << " VND)\n";
    }

    NVVanPhong* nvvpOldest = nullptr;
    for (const auto& nv : DanhSachNV) {
        if (NVVanPhong* vp = dynamic_cast<NVVanPhong*>(nv)) {
            if (nvvpOldest == nullptr || vp->getNam() < nvvpOldest->getNam()) {
                nvvpOldest = vp;
            }
        }
    }

    if (nvvpOldest != nullptr) {
        cout << "Nhan vien van phong co tuoi cao nhat: "
             << nvvpOldest->getHoTen() << " ("
             << right << setfill('0') << setw(2) << nvvpOldest->getNgay() << "/"
             << setw(2) << nvvpOldest->getThang() << "/"
             << nvvpOldest->getNam() << ")\n";
    }

    for (auto nv : DanhSachNV) {
        delete nv;
    }
    DanhSachNV.clear();

    return 0;
}
