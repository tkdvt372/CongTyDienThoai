#pragma once
#include"NhanVien.h"
class nvVanPhong :public NhanVien
{
private:
	int SoNgayLamViec;
	float TroCap;
public:
	int getSoNgayLamViec();
	float getTroCap();
	void setSoNgayLamViec(int);
	void setTroCap(float);
	float TinhLuong();
	void Nhap();
	void Xuat();
	nvVanPhong();
	~nvVanPhong();
};

