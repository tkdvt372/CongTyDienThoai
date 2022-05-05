#include "NhanVien.h"
void NhanVien::Nhap() {
	Nguoi::Nhap();
}
void NhanVien::Xuat() {
	Nguoi::Xuat();
	cout << "\nLuong co ban: " << size_t(LuongCB);
}
float NhanVien::getLuongCB()
{
	return LuongCB;
}
NhanVien::NhanVien() {
	LuongCB = 200000;
	Luong = 0;
}
NhanVien::NhanVien(string ten, string que, string ngay, int tuoi, int gt, float Luong, float LuongCB) :Nguoi(ten, que, ngay, tuoi, gt)
{
	this->Luong = Luong;
	this->LuongCB = LuongCB;
}
NhanVien::~NhanVien() {
}