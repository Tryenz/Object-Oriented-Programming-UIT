#include "NhanVien.h"
#include <iomanip>

int NhapSoNguyen(const string& ThongBao, int MinVal) {
    int GiaTri;
    while (true) {
        cout << ThongBao;
        if (cin >> GiaTri && GiaTri >= MinVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return GiaTri;
        }
        cout << "[Loi] Du lieu khong hop le! Vui long nhap lai so (>= " << MinVal << ").\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double NhapSoThuc(const string& ThongBao, double MinVal) {
    double GiaTri;
    while (true) {
        cout << ThongBao;
        if (cin >> GiaTri && GiaTri >= MinVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return GiaTri;
        }
        cout << "[Loi] Du lieu khong hop le! Vui long nhap lai so (>= " << MinVal << ").\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void NhanVien::nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);

    while (true) {
        Ngay = NhapSoNguyen("Nhap ngay sinh: ", 1);
        if (Ngay <= 31) break;
        cout << "[Loi] Ngay sinh khong duoc vuot qua 31!\n";
    }

    while (true) {
        Thang = NhapSoNguyen("Nhap thang sinh: ", 1);
        if (Thang <= 12) break;
        cout << "[Loi] Thang sinh khong duoc vuot qua 12!\n";
    }

    Nam = NhapSoNguyen("Nhap nam sinh: ", 1900);
}

void NhanVien::xuat() const {
    cout << "Ho ten: " << left << setw(20) << HoTen
         << "| Ngay sinh: " << right << setfill('0') << setw(2) << Ngay << "/"
         << setw(2) << Thang << "/" << Nam << setfill(' ');
}

int NhanVien::getNgay() const { return Ngay; }
int NhanVien::getThang() const { return Thang; }
int NhanVien::getNam() const { return Nam; }
string NhanVien::getHoTen() const { return HoTen; }

void NVSanXuat::nhap() {
    NhanVien::nhap();
    LuongCanBan = NhapSoThuc("Nhap luong can ban (VND): ", 0);
    SoSanPham = NhapSoNguyen("Nhap so san pham: ", 0);
}

void NVSanXuat::xuat() const {
    NhanVien::xuat();
    cout << " | Luong can ban: " << setw(10) << (long long)LuongCanBan
         << " | So san pham: " << setw(4) << SoSanPham
         << " | Luong: " << (long long)TinhLuong() << " VND\n";
}

double NVSanXuat::TinhLuong() const {
    return LuongCanBan + SoSanPham * 5000.0;
}

void NVVanPhong::nhap() {
    NhanVien::nhap();
    SoNgayLamViec = NhapSoNguyen("Nhap so ngay lam viec: ", 0);
}

void NVVanPhong::xuat() const {
    NhanVien::xuat();
    cout << " | So ngay lam: " << setw(7) << SoNgayLamViec
         << " | Luong: " << (long long)TinhLuong() << " VND\n";
}

double NVVanPhong::TinhLuong() const {
    return SoNgayLamViec * 100000.0;
}
