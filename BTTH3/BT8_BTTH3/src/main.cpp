#include <iostream>
#include "cNhanVienSX.h"

int main()
{
    cListNhanVien ds;

    ds.Nhap();

    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    ds.Xuat();

    cout << "\nNHAN VIEN LUONG THAP NHAT:\n";
    ds.luong_thap_nhat().Xuat();
    cout << endl;

    cout << "\nTONG LUONG TRA CHO CAC NHAN VIEN LA: " << ds.tong_luong() << endl;

    cout << "\nNHAN VIEN CAO TUOI NHAT:\n";
    ds.nv_cao_tuoi_nhat().Xuat();
    cout << endl;

    cout << "\nDANH SACH NHAN VIEN VOI MUC LUONG TANG DAN:\n";
    ds.sap_xep();
    ds.Xuat();

    return 0;
}
