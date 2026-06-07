#include <iostream>
#include <vector>
#include "NhanVien.h"

using namespace std;

int main() {
    vector<NhanVien*> DanhSachNhanVien;
    int LuaChon;

    do {
        cout << "\n===== CONG TY PHAN MEM HOAN CAU =====\n";
        cout << "1. Nhap Lap trinh vien\n";
        cout << "2. Nhap Kiem chung vien\n";
        cout << "0. Ket thuc nhap va thong ke\n";

        LuaChon = NhapSoNguyen("Moi ban chon (0-2): ", 0);
        if (LuaChon > 2) {
            cout << "[Loi] Lua chon khong hop le!\n";
            continue;
        }

        NhanVien* nv = nullptr;
        if (LuaChon == 1) {
            cout << "\n--- Nhap Lap Trinh Vien ---\n";
            nv = new LapTrinhVien();
        } else if (LuaChon == 2) {
            cout << "\n--- Nhap Kiem Chung Vien ---\n";
            nv = new KiemChungVien();
        }

        if (nv != nullptr) {
            nv->nhap();
            DanhSachNhanVien.push_back(nv);
        }
    } while (LuaChon != 0);

    if (DanhSachNhanVien.empty()) {
        cout << "Danh sach nhan vien hien dang trong!\n";
        return 0;
    }

    cout << "\n======================================================\n";
    cout << "DANH SACH NHAN VIEN CONG TY:\n";
    for (const auto& nv : DanhSachNhanVien) {
        nv->xuat();
    }

    double TongLuong = 0;
    double LuongMaxTong = DanhSachNhanVien[0]->TinhLuong();
    double LuongMinhTong = DanhSachNhanVien[0]->TinhLuong();

    LapTrinhVien* ltvMax = nullptr;
    KiemChungVien* kcvMin = nullptr;

    for (const auto& nv : DanhSachNhanVien) {
        double Luong = nv->TinhLuong();
        TongLuong += Luong;

        if (Luong > LuongMaxTong) LuongMaxTong = Luong;
        if (Luong < LuongMinhTong) LuongMinhTong = Luong;

        if (LapTrinhVien* ltv = dynamic_cast<LapTrinhVien*>(nv)) {
            if (ltvMax == nullptr || ltv->TinhLuong() > ltvMax->TinhLuong()) {
                ltvMax = ltv;
            }
        }
        else if (KiemChungVien* kcv = dynamic_cast<KiemChungVien*>(nv)) {
            if (kcvMin == nullptr || kcv->TinhLuong() < kcvMin->TinhLuong()) {
                kcvMin = kcv;
            }
        }
    }

    double LuongTrungBinh = TongLuong / DanhSachNhanVien.size();

    cout << "\n======================================================\n";
    cout << "DANH SACH NHAN VIEN CO LUONG THAP HON LUONG TRUNG BINH CUA CAC NHAN VIEN TRONG CONG TY ("
         << (long long)LuongTrungBinh << " VND):\n";
    bool ThapHonTB = false;
    for (const auto& nv : DanhSachNhanVien) {
        if (nv->TinhLuong() < LuongTrungBinh) {
            nv->xuat();
            ThapHonTB = true;
        }
    }
    if (!ThapHonTB) cout << "=> Khong co ai!\n";

    cout << "\n======================================================\n";
    cout << "THONG TIN NHAN VIEN CO LUONG CAO NHAT CONG TY ("
         << (long long)LuongMaxTong << " VND):\n";
    for (const auto& nv : DanhSachNhanVien) {
        if (nv->TinhLuong() == LuongMaxTong) nv->xuat();
    }

    cout << "\n======================================================\n";
    cout << "THONG TIN NHAN VIEN CO LUONG THAP NHAT CONG TY ("
         << (long long)LuongMinhTong << " VND):\n";
    for (const auto& nv : DanhSachNhanVien) {
        if (nv->TinhLuong() == LuongMinhTong) nv->xuat();
    }

    cout << "\n======================================================\n";
    cout << "THONG TIN LAP TRINH VIEN CO LUONG CAO NHAT:\n";
    if (ltvMax != nullptr) {
        ltvMax->xuat();
    } else {
        cout << "=> Khong co lap trinh vien nao trong danh sach.\n";
    }

    cout << "\n======================================================\n";
    cout << "THONG TIN KIEM CHUNG VIEN CO LUONG THAP NHAT:\n";
    if (kcvMin != nullptr) {
        kcvMin->xuat();
    } else {
        cout << "=> Khong co kiem chung vien nao trong danh sach.\n";
    }

    for (auto nv : DanhSachNhanVien) {
        delete nv;
    }
    DanhSachNhanVien.clear();

    return 0;
}
