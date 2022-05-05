#include "nvQuanLi.h"
void nvQuanLi::Nhap() {
	NhanVien::Nhap();
	cout << "\nHe so: ";
	cin >> HeSo;
	cout << "\nTien thuong: ";
	cin >> Thuong;
}
void nvQuanLi::Xuat() {
	NhanVien::Xuat();
	cout << "\nHe so: " << HeSo;
	cout << "\nTien Thuong: " << (size_t)Thuong;
	cout << "\nLuong: " << size_t(this->TinhLuong()) << endl;
}
float nvQuanLi::getHeSo()
{
	return HeSo;
}
float nvQuanLi::getThuong()
{
	return Thuong;
}
void nvQuanLi::setHeso(float a)
{
	HeSo = a;
}
void nvQuanLi::setThuong(float a)
{
	Thuong = a;
}
float nvQuanLi::TinhLuong() {
	Luong = LuongCB * HeSo + Thuong;
	return Luong;
}

nvQuanLi::nvQuanLi() {
	LuongCB = 2000000;
	HeSo = 0;
	Thuong = 0;
}
nvQuanLi::~nvQuanLi() {

}