#include <iostream>
#include <vector>
#include "GiaoDich.h"

using namespace std;

int main() {
    vector<GiaoDich*> DanhSachGiaoDich;
    int LuaChon;

    do {
        cout << "\n===== CONG TY BAT DONG SAN VAKALAND =====\n";
        cout << "1. Giao Dich Dat\n";
        cout << "2. Giao Dich Nha Pho\n";
        cout << "3. Giao Dich Chung Cu\n";
        cout << "0. Ket thuc nhap va thuc hien tinh toan\n";

        LuaChon = NhapSoNguyen("Moi ban chon (0-3): ", 0, 3);

        GiaoDich* gd = nullptr;
        if (LuaChon == 1) {
            gd = new GiaoDichDat();
        } else if (LuaChon == 2) {
            gd = new GiaoDichNhaPho();
        } else if (LuaChon == 3) {
            gd = new GiaoDichChungCu();
        }

        if (gd != nullptr) {
            cout << "\n--- NHAP THONG TIN GIAO DICH ---\n";
            gd->nhap();
            DanhSachGiaoDich.push_back(gd);
        }
    } while (LuaChon != 0);

    cout << "\n============================================\n";
    cout << "\nDANH SACH CAC GIAO DICH BAT DONG SAN:\n";
    for (const auto& gd : DanhSachGiaoDich) {
        gd->xuat();
    }

    int SoLuongDat = 0, SoLuongNhaPho = 0, SoLuongChungCu = 0;
    double TongTienChungCu = 0;
    GiaoDichNhaPho* NhaPhoMax = nullptr;

    for (const auto& gd : DanhSachGiaoDich) {
        if (dynamic_cast<GiaoDichDat*>(gd)) {
            SoLuongDat++;
        }
        else if (GiaoDichNhaPho* np = dynamic_cast<GiaoDichNhaPho*>(gd)) {
            SoLuongNhaPho++;
            if (NhaPhoMax == nullptr || np->ThanhTien() > NhaPhoMax->ThanhTien()) {
                NhaPhoMax = np;
            }
        }
        else if (GiaoDichChungCu* cc = dynamic_cast<GiaoDichChungCu*>(gd)) {
            SoLuongChungCu++;
            TongTienChungCu += cc->ThanhTien();
        }
    }

    cout << "\n--- THONG KE SO LUONG ---\n";
    cout << "+ Giao dich Dat: " << SoLuongDat << "\n";
    cout << "+ Giao dich Nha pho: " << SoLuongNhaPho << "\n";
    cout << "+ Giao dich Chung cu: " << SoLuongChungCu << "\n";

    if (SoLuongChungCu > 0) {
        cout << "\n=> Trung binh thanh tien chung cu: "
             << (long long)(TongTienChungCu / SoLuongChungCu) << " VND\n";
    } else {
        cout << "\n=> Khong co giao dich chung cu nao.\n";
    }

    if (NhaPhoMax != nullptr) {
        cout << "=> Giao dich nha pho co tri gia cao nhat:\n   ";
        NhaPhoMax->xuat();
    } else {
        cout << "=> Khong co giao dich nha pho nao.\n";
    }

    cout << "\n--- DANH SACH GIAO DICH THANG 12/2024 ---\n";
    bool GiaoDichThang12 = false;
    for (const auto& gd : DanhSachGiaoDich) {
        if (gd->getThang() == 12 && gd->getNam() == 2024) {
            gd->xuat();
            GiaoDichThang12 = true;
        }
    }
    if (!GiaoDichThang12) {
        cout << "(Khong co giao dich nao thoa dieu kien)\n";
    }

    for (auto gd : DanhSachGiaoDich) {
        delete gd;
    }
    DanhSachGiaoDich.clear();

    return 0;
}
