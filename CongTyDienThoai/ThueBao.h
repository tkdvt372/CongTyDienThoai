#pragma once
#include"Nguoi.h"
class ThueBao :public Nguoi
{
private:
	int LoaiTB;
	string MaTB, SoDienThoai, NgayDK;
	float TgNoiMang, TgNgoaiMang, CuocPhi;
public:
	ThueBao();
	ThueBao(string, string, string, int, int, int, string, string, string, float, float, float);
	~ThueBao();
	int getLoaiTB();
	string getMaTB();
	string getSoDienThoai();
	string getNgayDK();
	float getTgNoiMang();
	float getTgNgoaiMang();
	float getCuocPhi();
	void setLoaiTB(int);
	void setMaTB(string);
	void setSoDienThoai(string);
	void setNgayDK(string);
	void setTgNoiMang(float);
	void setTgNgoaiMang(float);
	void setCuocPhi(float);
	void Nhap();
	void Xuat();
};

