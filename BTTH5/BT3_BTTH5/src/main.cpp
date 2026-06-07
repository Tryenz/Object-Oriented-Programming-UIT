#include <iostream>
#include <vector>
#include "SinhVien.h"

using namespace std;

int main() {
    vector<SinhVien*> DanhSachSinhVien;
    int LuaChon;

    do {
        cout << "\n===== CHUONG TRINH QUAN LY SINH VIEN =====\n";
        cout << "1. Nhap thong tin sinh vien cao dang\n";
        cout << "2. Nhap thong tin sinh vien dai hoc\n";
        cout << "0. Ket thuc nhap va thuc hien thong ke\n";

        LuaChon = NhapSoNguyen("Moi ban chon (0-2): ", 0);
        if (LuaChon > 2) {
            cout << "[Loi] Lua chon khong hop le!\n";
            continue;
        }

        SinhVien* sv = nullptr;
        if (LuaChon == 1) {
            cout << "\n--- Nhap sinh vien cao dang ---\n";
            sv = new SVCaoDang();
        } else if (LuaChon == 2) {
            cout << "\n--- Nhap sinh vien dai hoc ---\n";
            sv = new SVDaiHoc();
        }

        if (sv != nullptr) {
            sv->nhap();
            DanhSachSinhVien.push_back(sv);
        }
    } while (LuaChon != 0);

    cout << "\n============================================\n";
    cout << "DANH SACH CAC SINH VIEN:\n";
    for (const auto& sv : DanhSachSinhVien) {
        sv->xuat();
    }

    cout << "\n============================================\n";
    cout << "DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP:\n";
    for (const auto& sv : DanhSachSinhVien) {
        if (sv->XetTotNghiep()) sv->xuat();
    }

    cout << "\n============================================\n";
    cout << "DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP:\n";
    for (const auto& sv : DanhSachSinhVien) {
        if (!sv->XetTotNghiep()) sv->xuat();
    }

    SVDaiHoc* dhMax = nullptr;
    SVCaoDang* cdMax = nullptr;
    int CaoDangKoDat = 0;
    int DaiHocKoDat = 0;

    for (const auto& sv : DanhSachSinhVien) {
        if (SVCaoDang* cd = dynamic_cast<SVCaoDang*>(sv)) {
            if (cdMax == nullptr || cd->getDiemTrungBinh() > cdMax->getDiemTrungBinh()) {
                cdMax = cd;
            }
            if (!cd->XetTotNghiep()) CaoDangKoDat++;
        }
        else if (SVDaiHoc* dh = dynamic_cast<SVDaiHoc*>(sv)) {
            if (dhMax == nullptr || dh->getDiemTrungBinh() > dhMax->getDiemTrungBinh()) {
                dhMax = dh;
            }
            if (!dh->XetTotNghiep()) DaiHocKoDat++;
        }
    }

    cout << "\n============================================\n";
    cout << "SINH VIEN DAI HOC CO DIEM TRUNG BINH CAO NHAT:\n";
    if (dhMax != nullptr) {
        dhMax->xuat();
    } else {
        cout << "=> Khong co sinh vien dai hoc nao trong danh sach.\n";
    }

    cout << "\n============================================\n";
    cout << "SINH VIEN CAO DANG CO DIEM TRUNG BINH CAO NHAT:\n";
    if (cdMax != nullptr) {
        cdMax->xuat();
    } else {
        cout << "=> Khong co sinh vien cao dang nao trong danh sach.\n";
    }

    cout << "\n============================================\n";
    cout << "THONG KE SO SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP:\n";
    cout << "=> He cao dang: " << CaoDangKoDat << " sinh vien.\n";
    cout << "=> He dai hoc: " << DaiHocKoDat << " sinh vien.\n";

    for (auto sv : DanhSachSinhVien) {
        delete sv;
    }
    DanhSachSinhVien.clear();

    return 0;
}
