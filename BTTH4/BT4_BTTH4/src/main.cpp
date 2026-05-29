#include <iostream>
#include <iomanip>
#include "CDate.h"

int main() {
    cout << "===== CHUONG TRINH TINH LAI SUAT TIEN GUI NGAN HANG =====\n\n";

    CDate ngayGui, ngayRut;
    cout << "--- Thong tin Ngay Gui ---\n";
    cin >> ngayGui;

    cout << "\n--- Thong tin Ngay Rut ---\n";
    cin >> ngayRut;

    double tienGoc, laiSuatNam;
    cout << "\nNhap so tien gui (VND): ";
    cin >> tienGoc;
    cout << "Nhap lai suat nam (%): ";
    cin >> laiSuatNam;

    int soNgayGui = ngayRut - ngayGui;

    if (soNgayGui < 0) {
        cout << "\n[Loi] Ngay rut tien khong the xay ra truoc ngay gui!\n";
        return 1;
    }

    double tienLai = tienGoc * (laiSuatNam / 100.0) * ((double)soNgayGui / 365.0);
    double tongTien = tienGoc + tienLai;

    cout << "\n===== BIEN LAI RUT TIEN =====\n";
    cout << "Ngay gui:           " << ngayGui << "\n";
    cout << "Ngay rut:           " << ngayRut << "\n";
    cout << "Thoi gian thuc gui: " << soNgayGui << " ngay\n";

    cout << fixed << setprecision(2);
    cout << "Tien goc:           " << tienGoc << " VND\n";
    cout << "Tien lai nhan duoc: " << tienLai << " VND\n";
    cout << "Tong tien sau cung: " << tongTien << " VND\n";
    cout << "\n";


    cout << "===== KIEM TRA THEM BOT NGAY =====\n";
    int x;
    cout << "Nhap so ngay muon cong/tru: ";
    cin >> x;

    cout << "Ngay gui " << ngayGui << " sau khi cong " << x << " ngay: " << (ngayGui + x) << "\n";
    cout << "Ngay gui " << ngayGui << " sau khi tru " << x << " ngay: " << (ngayGui - x) << "\n\n";

    CDate temp = ngayGui;
    ++temp;
    cout << "Ngay tiep theo cua ngay gui (++): " << temp << "\n";

    --temp; --temp;
    cout << "Ngay truoc do cua ngay gui  (--): " << temp << "\n";
    cout << "\n";

    return 0;
}
