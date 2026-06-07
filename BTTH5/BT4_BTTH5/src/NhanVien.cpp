#include "NhanVien.h"
#include <iomanip>

void XoaBoDem() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int NhapSoNguyen(const string& ThongBao, int MinVal) {
    int GiaTri;
    while (true) {
        cout << ThongBao;
        if (cin >> GiaTri && GiaTri >= MinVal) {
            XoaBoDem();
            return GiaTri;
        }
        cout << "[Loi] Vui long nhap so nguyen (>= " << MinVal << ")!\n";
        XoaBoDem();
    }
}

double NhapSoThuc(const string& ThongBao, double MinVal) {
    double GiaTri;
    while (true) {
        cout << ThongBao;
        if (cin >> GiaTri && GiaTri >= MinVal) {
            XoaBoDem();
            return GiaTri;
        }
        cout << "[Loi] Vui long nhap so lon hon hoac bang " << MinVal << "!\n";
        XoaBoDem();
    }
}

void NhanVien::nhap() {
    cout << "Nhap ma nhan vien: ";
    getline(cin, MaNhanVien);
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);

    Tuoi = NhapSoNguyen("Nhap tuoi: ", 18);

    cout << "Nhap so dien thoai: ";
    getline(cin, SDT);
    cout << "Nhap email: ";
    getline(cin, Email);

    LuongCoBan = NhapSoThuc("Nhap luong co ban (VND): ", 0);
}

void NhanVien::xuat() const {
    cout << "Ma nhan vien: " << left << setw(8) << MaNhanVien
         << " | Ho ten: " << setw(20) << HoTen
         << " | Tuoi: " << setw(3) << Tuoi
         << " | So dien thoai: " << setw(12) << SDT
         << " | Luong: " << right << setw(10) << (long long)TinhLuong() << " VND";
}

string NhanVien::getHoTen() const { return HoTen; }

void LapTrinhVien::nhap() {
    NhanVien::nhap();
    Overtime = NhapSoNguyen("Nhap so gio overtime: ", 0);
}

void LapTrinhVien::xuat() const {
    NhanVien::xuat();
    cout << " | Chuc vu: Lap trinh vien | OverTime: " << Overtime << "h\n";
}

double LapTrinhVien::TinhLuong() const {
    return LuongCoBan + (Overtime * 200000.0);
}

void KiemChungVien::nhap() {
    NhanVien::nhap();
    SoLoi = NhapSoNguyen("Nhap so loi phat hien duoc: ", 0);
}

void KiemChungVien::xuat() const {
    NhanVien::xuat();
    cout << " | Chuc vu: Kiem chung vien | Loi: " << SoLoi << "\n";
}

double KiemChungVien::TinhLuong() const {
    return LuongCoBan + (SoLoi * 50000.0);
}
