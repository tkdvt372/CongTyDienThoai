#include "nvSanXuat.h"
void nvSanXuat::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "\nNhap so san pham: ";
		cin >> SoSanPham;
	} while (SoSanPham < 0);
}
void nvSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "\nSo san pham: " << this->SoSanPham;
	cout << "\nLuong: " << size_t(this->TinhLuong()) << endl;
}
int nvSanXuat::getSoSanPham()
{
	return SoSanPham;
}
void nvSanXuat::setSoSanPham(int a)
{
	SoSanPham = a;
}
float nvSanXuat::TinhLuong() {
	Luong = SoSanPham * 2000 + LuongCB;
	return Luong;
}
nvSanXuat::nvSanXuat() {
	LuongCB = 1000000;
	SoSanPham = 0;
}
nvSanXuat::~nvSanXuat() {

}