#include "Nguoi.h"
Nguoi::Nguoi() {
	HoTen = "";
	GioiTinh = 0;
	NgaySinh = "";
	QueQuan = "";
}
Nguoi::Nguoi(string ten, string que, string ngay, int tuoi, int gt)
{
	HoTen = ten;
	QueQuan = que;
	NgaySinh = ngay;
	Tuoi = tuoi;
	GioiTinh = gt;
}
Nguoi::~Nguoi() {

}
string Nguoi::getHoTen()
{
	return HoTen;
}
string Nguoi::getQueQuan()
{
	return QueQuan;
}
string Nguoi::getNgaySinh()
{
	return NgaySinh;
}
int Nguoi::getTuoi()
{
	return Tuoi;
}
int Nguoi::getGioiTinh()
{
	return GioiTinh;
}
void Nguoi::setHoTen(string a)
{
	HoTen = a;
}
void Nguoi::setQueQuan(string a)
{
	QueQuan = a;
}
void Nguoi::setNgaySinh(string a)
{
	NgaySinh = a;
}
void Nguoi::setTuoi(int a)
{
	Tuoi = a;
}
void Nguoi::setGioiTinh(int a)
{
	GioiTinh = a;
}
void Nguoi::Nhap() {
	cout << "\nNhap ho ten: ";
	cin.ignore();
	getline(cin, HoTen);
	cout << "\nNhap que quan: ";
	getline(cin, QueQuan);
	cout << "\nNhap ngay sinh: ";
	getline(cin, NgaySinh);
	cout << "\nNhap tuoi: ";
	cin >> Tuoi;
	cout << "\nNhap gioi tinh(0:Nam 1:Nu): ";
	cin >> GioiTinh;
}
void Nguoi::Xuat() {
	cout << "\nHo ten: " << HoTen;
	cout << "\nQue Quan: " << QueQuan;
	cout << "\nNgay sinh: " << NgaySinh;
	cout << "\nTuoi: " << Tuoi;
	if (GioiTinh == 0) {
		cout << "\nGioi tinh: Nam";
	}
	else if (GioiTinh == 1) {
		cout << "\nGioi tinh: Nu";
	}
	else {
		cout << "\nGioi tinh: Khong xac dinh";
	}
}