#include "DoanhThu.h"
istream& operator >> (istream& is, DoanhThu* p) {
	cout << "\nNhap tien von: ";
	cin >> p->TienVon;
	cout << "\nNhap thue(0-100):";
	cin >> p->Thue;
	p->Thue /= 100;
	cout << "\nNhap phu thu: ";
	cin >> p->PhuThu;
	p->TienThue = p->Thue * p->TienVon;
	return is;
}
ostream& operator << (ostream& os, DoanhThu* p) {
	cout << "\nTien von: " << size_t(p->TienVon);
	cout << "\nThue: " << p->Thue << "%";
	cout << "\nPhu thu: " << size_t(p->PhuThu);
	return os;
}
DoanhThu::DoanhThu() {
	TienVon = 50000000000;
	Thue = 0;
	PhuThu = 0;
	Thu = 0;
	Chi = 0;
	TongTien = 0;
	TienThue = 0;
}

DoanhThu::~DoanhThu() {

}

float DoanhThu::getTienVon() {
	return TienVon;
}
float DoanhThu::getThue() {
	return Thue;
}
float DoanhThu::getPhuThu() {
	return PhuThu;
}

float DoanhThu::getThu()
{
	return Thu;
}

float DoanhThu::getChi()
{
	return Chi;
}

float DoanhThu::getTienThue()
{
	return TienThue;
}

float DoanhThu::getTongTien()
{
	return TongTien;
}

void DoanhThu::setThu(float a)
{
	this->Thu = a;
}

void DoanhThu::setChi(float a)
{
	this->Chi = a;
}

void DoanhThu::setTienThue(float a)
{
	this->TienThue = a;
}

void DoanhThu::setTongTien(float a)
{
	this->TongTien = a;
}

void DoanhThu::setTienVon(float a)
{
	TienVon = a;
}

void DoanhThu::setThue(float a)
{
	Thue = a;
}

void DoanhThu::setPhuThu(float a)
{
	PhuThu = a;
}

