#include "SinhVien.h"
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
        cout << "[Loi] Vui long nhap so nguyen >= " << MinVal << "!\n";
        XoaBoDem();
    }
}

double NhapDiem(const string& ThongBao) {
    double Diem;
    while (true) {
        cout << ThongBao;
        if (cin >> Diem && Diem >= 0.0 && Diem <= 10.0) {
            XoaBoDem();
            return Diem;
        }
        cout << "[Loi] Diem phai la so tu 0.0 den 10.0!\n";
        XoaBoDem();
    }
}

void SinhVien::nhap() {
    cout << "Nhap ma so sinh vien: ";
    getline(cin, MaSinhVien);
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);

    TongTinChi = NhapSoNguyen("Nhap tong so tin chi: ", 0);
    DiemTrungBinh = NhapDiem("Nhap diem trung binh: ");
}

void SinhVien::xuat() const {
    cout << "MSSV: " << left << setw(10) << MaSinhVien
         << " | Ho ten: " << setw(20) << HoTen
         << " | Tin chi: " << setw(4) << TongTinChi
         << " | DTB: " << setw(4) << DiemTrungBinh;
}

double SinhVien::getDiemTrungBinh() const { return DiemTrungBinh; }
string SinhVien::getHoTen() const { return HoTen; }

void SVCaoDang::nhap() {
    SinhVien::nhap();
    DiemThiTN = NhapDiem("Nhap diem thi tot nghiep: ");
}

void SVCaoDang::xuat() const {
    SinhVien::xuat();
    cout << " | He: Cao dang"
         << " | Diem tot nghiep: " << setw(4) << DiemThiTN
         << " | Ket qua: " << (XetTotNghiep() ? "Dat" : "Khong Dat") << "\n";
}

bool SVCaoDang::XetTotNghiep() const {
    return (TongTinChi >= 120 && DiemTrungBinh >= 5.0 && DiemThiTN >= 5.0);
}

void SVDaiHoc::nhap() {
    SinhVien::nhap();
    cout << "Nhap ten luan van: ";
    getline(cin, TenLuanVan);
    DiemLuanVan = NhapDiem("Nhap diem luan van: ");
}

void SVDaiHoc::xuat() const {
    SinhVien::xuat();
    cout << " | He: Dai hoc "
         << " | Diem luan van: " << setw(4) << DiemLuanVan
         << " | Ket qua: " << (XetTotNghiep() ? "Dat" : "Khong Dat") << "\n";
}

bool SVDaiHoc::XetTotNghiep() const {
    return (TongTinChi >= 170 && DiemTrungBinh >= 5.0 && DiemLuanVan >= 5.0);
}
