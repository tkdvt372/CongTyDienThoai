#include "nvVanPhong.h"
void nvVanPhong::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "\nSo ngay lam viec: ";
		cin >> SoNgayLamViec;
	} while (SoNgayLamViec < 0);
	cout << "\nTro cap: ";
	cin >> TroCap;
}
void nvVanPhong::Xuat() {
	NhanVien::Xuat();
	cout << "\nSo ngay lam viec: " << SoNgayLamViec;
	cout << "\nTro cap: " << size_t(TroCap);
	cout << "\nLuong: " << size_t(this->TinhLuong()) << endl;
}
int nvVanPhong::getSoNgayLamViec()
{
	return this->SoNgayLamViec;
}
float nvVanPhong::getTroCap()
{
	return this->TroCap;
}
void nvVanPhong::setSoNgayLamViec(int a)
{
	this->SoNgayLamViec = a;
}
void nvVanPhong::setTroCap(float a)
{
	this->TroCap = a;
}
float nvVanPhong::TinhLuong() {
	Luong = LuongCB + SoNgayLamViec * 100000 + TroCap;
	return Luong;
}
nvVanPhong::nvVanPhong() {
	LuongCB = 1500000;
	SoNgayLamViec = 0;
	TroCap = 0;
}
nvVanPhong::~nvVanPhong() {

}