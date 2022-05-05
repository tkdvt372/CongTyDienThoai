#pragma once
#include"NhanVien.h"
class nvSanXuat :public NhanVien
{
private:
	int SoSanPham;
public:
	int getSoSanPham();
	void setSoSanPham(int);
	float TinhLuong();
	void Nhap();
	void Xuat();
	nvSanXuat();
	~nvSanXuat();
};

