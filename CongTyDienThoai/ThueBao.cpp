#include "ThueBao.h"
ThueBao::ThueBao() {
	LoaiTB = 0;
	MaTB = "";
	SoDienThoai = "";
	NgayDK = "";
	TgNgoaiMang = 0;
	TgNoiMang = 0;
}
ThueBao::ThueBao(string HoTen, string QueQuan, string NgaySinh, int Tuoi
	, int GioiTinh, int loai, string ma, string Sdt, string ngaydk
	, float noim, float ngoaim, float cuoc) :Nguoi(HoTen, QueQuan, NgaySinh, Tuoi, GioiTinh)
{
	LoaiTB = loai;
	MaTB = ma;
	SoDienThoai = Sdt;
	NgayDK = ngaydk;
	TgNgoaiMang = ngoaim;
	TgNoiMang = noim;
	CuocPhi = cuoc;
}
ThueBao::~ThueBao() {
}
int ThueBao::getLoaiTB() {
	return LoaiTB;
}
string ThueBao::getMaTB() {
	return MaTB;
}
string ThueBao::getSoDienThoai()
{
	return SoDienThoai;
}
string ThueBao::getNgayDK()
{
	return NgayDK;
}
float ThueBao::getTgNoiMang()
{
	return TgNoiMang;
}
float ThueBao::getTgNgoaiMang()
{
	return TgNgoaiMang;
}
float ThueBao::getCuocPhi() {
	return CuocPhi;
}
void ThueBao::setLoaiTB(int a)
{
	this->LoaiTB = a;
}
void ThueBao::setMaTB(string a)
{
	MaTB = a;
}
void ThueBao::setSoDienThoai(string a)
{
	SoDienThoai = a;
}
void ThueBao::setNgayDK(string a)
{
	NgayDK = a;
}
void ThueBao::setTgNoiMang(float a)
{
	TgNoiMang = a;
}
void ThueBao::setTgNgoaiMang(float a)
{
	TgNgoaiMang = a;
}
void ThueBao::setCuocPhi(float a)
{
	CuocPhi = a;
}
void ThueBao::Nhap() {
	Nguoi::Nhap();
	cin.ignore();
	cout << "\nNhap ma thue bao: ";
	getline(cin, MaTB);
	cout << "\nNhap so dien thoai: ";
	getline(cin, SoDienThoai);
	cout << "\nNhap ngay dang ky: ";
	getline(cin, NgayDK);
	cout << "\nNhap loai thue bao(0-Tra truoc 1-Tra sau) :";
	cin >> LoaiTB;
	cout << "\nNhap thoi gian goi ngoai mang: ";
	cin >> TgNgoaiMang;
	cout << "\nNhap thoi gian goi noi mang: ";
	cin >> TgNoiMang;
	CuocPhi = TgNgoaiMang * 3000 + TgNoiMang * 1500;
}
void ThueBao::Xuat() {
	Nguoi::Xuat();
	cout << "\nMa thue bao: " << MaTB;
	cout << "\nSo dien thoai: " << SoDienThoai;
	cout << "\nNgay dang ky: " << NgayDK;
	cout << "\nLoai thue bao: ";
	if (LoaiTB == 0) {
		cout << "Thue bao tra truoc";
	}
	else {
		cout << "Thue bao tra sau";
	}
	cout << "\nThoi gian goi ngoai mang: " << TgNgoaiMang;
	cout << "\nThoi gian goi noi mang: " << TgNoiMang;
	cout << "\nCuoc phi: " << size_t(CuocPhi) << endl;
}