#include "GiaoDich.h"
#include <iomanip>

int NhapSoNguyen(const string& ThongBao, int MinVal, int MaxVal) {
    int GiaTri;
    while (true) {
        cout << ThongBao;
        if (cin >> GiaTri && GiaTri >= MinVal && GiaTri <= MaxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return GiaTri;
        }
        cout << "[Loi] Du lieu sai! Vui long nhap so tu " << MinVal << " den " << MaxVal << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double NhapSoThuc(const string& ThongBao, double MinVal) {
    double GiaTri;
    while (true) {
        cout << ThongBao;
        if (cin >> GiaTri && GiaTri > MinVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return GiaTri;
        }
        cout << "[Loi] Du lieu sai! Vui long nhap so lon hon " << MinVal << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

bool NgayHopLe(int Ngay, int Thang, int Nam) {
    if (Thang < 1 || Thang > 12 || Nam < 1900 || Nam > 2100) return false;

    int NgayToiDa[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0)) {
        NgayToiDa[2] = 29;
    }

    return (Ngay >= 1 && Ngay <= NgayToiDa[Thang]);
}
void GiaoDich::nhap() {
    cout << "Nhap ma giao dich: ";
    cin >> MaGiaoDich;

    while (true) {
        cout << "Nhap ngay, thang, nam giao dich: ";
        if (cin >> Ngay >> Thang >> Nam) {
            if (NgayHopLe(Ngay, Thang, Nam)) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        cout << "[Loi] Ngay thang nam khong ton tai! Vui long nhap lai.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    DonGia = NhapSoThuc("Nhap don gia (VND/m2): ", 0);
    DienTich = NhapSoThuc("Nhap dien tich (m2): ", 0);
}

void GiaoDich::xuat() const {
    cout << "Ma giao dich: " << left << setw(10) << MaGiaoDich
         << " | Ngay giao dich: " << right << setfill('0') << setw(2) << Ngay << "/"
         << setw(2) << Thang << "/" << Nam << setfill(' ')
         << " | Don gia: " << left << setw(12) << (long long)DonGia
         << " | Dien tich: " << setw(6) << DienTich;
}

int GiaoDich::getThang() const { return Thang; }
int GiaoDich::getNam() const { return Nam; }

void GiaoDichDat::nhap() {
    GiaoDich::nhap();
    while (true) {
        cout << "Nhap loai dat (A, B, C): ";
        cin >> LoaiDat;
        LoaiDat = toupper(LoaiDat);
        if (LoaiDat == 'A' || LoaiDat == 'B' || LoaiDat == 'C') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cout << "[Loi] Chi duoc phep nhap A, B hoac C!\n";
    }
}

void GiaoDichDat::xuat() const {
    GiaoDich::xuat();
    cout << " | Loai dat: " << LoaiDat
         << " | Thanh tien: " << (long long)ThanhTien() << " VND\n";
}

double GiaoDichDat::ThanhTien() const {
    if (LoaiDat == 'A') return DienTich * DonGia * 1.5;
    return DienTich * DonGia;
}

void GiaoDichNhaPho::nhap() {
    GiaoDich::nhap();
    int Choice = NhapSoNguyen("Chon loai nha (1 - Cao cap, 2 - Thuong): ", 1, 2);
    LoaiNha = (Choice == 1) ? "cao cap" : "thuong";

    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);
}

void GiaoDichNhaPho::xuat() const {
    GiaoDich::xuat();
    cout << " | Loai nha: " << left << setw(8) << LoaiNha
         << " | Dia chi: " << setw(20) << DiaChi
         << " | Thanh tien: " << (long long)ThanhTien() << " VND\n";
}

double GiaoDichNhaPho::ThanhTien() const {
    if (LoaiNha == "cao cap") return DienTich * DonGia;
    return DienTich * DonGia * 0.9;
}

void GiaoDichChungCu::nhap() {
    GiaoDich::nhap();
    cout << "Nhap ma can ho: ";
    cin >> MaCan;
    ViTriTang = NhapSoNguyen("Nhap vi tri tang: ", 1, 150);
}

void GiaoDichChungCu::xuat() const {
    GiaoDich::xuat();
    cout << " | Ma can: " << left << setw(8) << MaCan
         << " | Vi Tri Tang: " << setw(3) << ViTriTang
         << " | Thanh tien: " << (long long)ThanhTien() << " VND\n";
}

double GiaoDichChungCu::ThanhTien() const {
    if (ViTriTang == 1) return DienTich * DonGia * 2.0;
    else if (ViTriTang >= 15) return DienTich * DonGia * 1.2;
    return DienTich * DonGia;
}
