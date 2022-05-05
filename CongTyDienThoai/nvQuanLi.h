#include"NhanVien.h"
#pragma once
class nvQuanLi :public NhanVien
{
private:
	float HeSo, Thuong;
public:
	float getHeSo();
	float getThuong();
	void setHeso(float);
	void setThuong(float);
	float TinhLuong();
	void Nhap();
	void Xuat();
	nvQuanLi();
	~nvQuanLi();
};

