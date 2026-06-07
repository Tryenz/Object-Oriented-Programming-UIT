#include <bits/stdc++.h>
#include "KhachHang.h"

using namespace std;

int main() {
    ifstream inFile("XYZ.INP");
    if (!inFile) {
        cerr << "[Loi] Khong the mo file XYZ.INP!\n";
        return 1;
    }

    int x, y, z;
    if (!(inFile >> x >> y >> z)) {
        cerr << "[Loi] File dinh dang khong hop le.\n";
        return 1;
    }

    vector<KhachHang*> DanhSachKhachHang;

    for (int i = 0; i < x; ++i) {
        KhachHang* kh = new KhachHangA();
        kh->docFile(inFile);
        DanhSachKhachHang.push_back(kh);
    }

    for (int i = 0; i < y; ++i) {
        KhachHang* kh = new KhachHangB();
        kh->docFile(inFile);
        DanhSachKhachHang.push_back(kh);
    }

    for (int i = 0; i < z; ++i) {
        KhachHang* kh = new KhachHangC();
        kh->docFile(inFile);
        DanhSachKhachHang.push_back(kh);
    }
    inFile.close();

    double TongTienCongTy = 0;
    for (const auto& kh : DanhSachKhachHang) {
        TongTienCongTy += kh->TinhTien();
    }

    ofstream outFile("XYZ.OUT");
    if (!outFile) {
        cerr << "[Loi] Khong the tạo file XYZ.OUT!\n";
        for (auto kh : DanhSachKhachHang) delete kh;
        return 1;
    }

    outFile << x << " " << y << " " << z << "\n";

    for (const auto& kh : DanhSachKhachHang) {
        kh->ghiFile(outFile);
    }

    outFile << (long long)TongTienCongTy << "\n";
    outFile.close();

    cout << "Xu ly file thanh cong! Vui long kiem tra ket qua tai file XYZ.OUT.\n";

    for (auto kh : DanhSachKhachHang) {
        delete kh;
    }
    DanhSachKhachHang.clear();

    return 0;
}
