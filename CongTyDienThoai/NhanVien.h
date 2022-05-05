#include"Nguoi.h"
#pragma once
class NhanVien :public Nguoi
{
protected:
	float Luong, LuongCB;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual float TinhLuong() {
		return Luong;
	};
	virtual float getLuongCB();
	NhanVien();
	NhanVien(string, string, string, int, int, float, float);
	~NhanVien();
};

