#include "cNhanVienSX.h"
#include <algorithm>

//Hàm kiểm tra và trả về giá trị bool xem năm truyền vào có phải năm nhuận không
bool NamNhuan(int nam)
{
	if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) return 1;
	return 0;
}
//Hàm sử dụng switch case nhận thông tin tháng và năm và trả về số ngày tương ứng
int SoNgayTrongThang(int thang, int nam)
{
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (NamNhuan(nam)) return 29;
		else return 28;
		break;
	default:
		return -1;
	}
}

cNhanVienSX::cNhanVienSX()
{
    ma = ten = "";
    ngay = thang = nam = 0;
    luong = 0;
}

cNhanVienSX::cNhanVienSX(string ma, string ten, int ngay, int thang, int nam, long long luong)
{
    this->ma = ma;
    this->ten = ten;
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
    this->luong = luong;
}

// getter
string cNhanVienSX::getMa() const { return ma; }
string cNhanVienSX::getTen() const { return ten; }
int cNhanVienSX::getNgay() const { return ngay; }
int cNhanVienSX::getThang() const { return thang; }
int cNhanVienSX::getNam() const { return nam; }
long long cNhanVienSX::getLuong() const { return luong; }

// setter
void cNhanVienSX::setMa(string ma) { this->ma = ma; }
void cNhanVienSX::setTen(string ten) { this->ten = ten; }
void cNhanVienSX::setNgay(int ngay) { this->ngay = ngay; }
void cNhanVienSX::setThang(int thang) { this->thang = thang; }
void cNhanVienSX::setNam(int nam) { this->nam = nam; }
void cNhanVienSX::setLuong(long long luong) { this->luong = luong; }

// nhập
void cNhanVienSX::Nhap()
{
    cout << "Nhap ma nhan vien: ";
    cin >> ma;

    cout << "Nhap ho ten nhan vien: ";
    cin.ignore();
    getline(cin, ten);

    cout << "Nhap ngay thang nam sinh: ";
    cin >> ngay >> thang >> nam;
    while (cin.fail() || ngay < 0 || ngay > 31 || thang < 0 || thang > 12 || nam < 0 || ngay > SoNgayTrongThang(thang, nam))
	{
		cin.clear();
		cin.ignore();
		cout << "Nhap ngay thang nam: ";
		cin >> ngay >> thang >> nam;
	}

    cout << "Nhap luong cua cua nhan vien: ";
    cin >> luong;
	while (luong < 0 || cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap luong cua cua nhan vien: ";
		cin >> luong;
	}
}

// xuất
void cNhanVienSX::Xuat() const
{
    cout << "- Ma nhan vien: " << ma << endl;
    cout << "- Ho va ten nhan vien: " << ten << endl;
	cout << "- Ngay thang nam sinh: ";
	if (ngay < 10) cout << 0;
	cout << ngay << "/";
	if (thang < 10) cout << 0;
	cout << thang << "/" << nam;
	cout << endl;
	cout << "- Luong: " << luong;
}

cListNhanVien::cListNhanVien() {}

cListNhanVien::cListNhanVien(vector<cNhanVienSX> x)
{
    this->n = x.size();
	for (int i = 0; i < n; i++)
	{
		nv.push_back(x[i]);
	}
}

int cListNhanVien::getN() const
{
    return n;
}

// nhập
void cListNhanVien::Nhap()
{
    //nhân viên mẫu
    cNhanVienSX mau("25521989", "VO TAN TRUYEN", 9, 2, 2007, 50000000);
    nv.push_back(mau);

    cout << "\n--- NHAN VIEN MAU ---\n";
    nv[0].Xuat();

    //thêm nhân viên
    cout << "\nNhap so nhan vien con lai: ";
    cin >> n;

    while (cin.fail() || n < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so nhan vien con lai: ";
		cin >> n;
	}

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin nhan vien " << i + 2 << ":\n";
        cNhanVienSX tmp;
        tmp.Nhap();
        nv.push_back(tmp);
    }

    n = nv.size();
}

// xuất
void cListNhanVien::Xuat() const
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Thong tin nhan vien thu " << i + 1 << " ---\n";
        nv[i].Xuat();
        cout << endl;
    }
}

// lương thấp nhất
cNhanVienSX cListNhanVien::luong_thap_nhat()
{
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (nv[i].getLuong() < nv[idx].getLuong())
            idx = i;

    return nv[idx];
}


// tổng lương
long long cListNhanVien::tong_luong() const
{
    long long s = 0;
    for (auto &i : nv)
        s += i.getLuong();
    return s;
}

// tuổi cao nhất
cNhanVienSX cListNhanVien::nv_cao_tuoi_nhat() const
{
    int idx = 0;

    for (int i = 1; i < n; i++)
    {
        if (
            nv[i].getNam() < nv[idx].getNam() ||
            (nv[i].getNam() == nv[idx].getNam() && nv[i].getThang() < nv[idx].getThang()) ||
            (nv[i].getNam() == nv[idx].getNam() && nv[i].getThang() == nv[idx].getThang() && nv[i].getNgay() < nv[idx].getNgay())
        )
        {
            idx = i;
        }
}

return nv[idx];
}

// sắp xếp
void cListNhanVien::sap_xep()
{
    sort(nv.begin(), nv.end(),
         [](cNhanVienSX a, cNhanVienSX b)
         {
             return a.getLuong() < b.getLuong();
         });
}
