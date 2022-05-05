#pragma once
#include<bits/stdc++.h>
using namespace std;
class Nguoi
{
protected:
	string HoTen, QueQuan, NgaySinh;
	int Tuoi;
	int GioiTinh;
public:
	Nguoi();
	Nguoi(string, string, string, int, int);
	~Nguoi();
	string getHoTen();
	string getQueQuan();
	string getNgaySinh();
	int getTuoi();
	int getGioiTinh();
	void setHoTen(string a);
	void setQueQuan(string a);
	void setNgaySinh(string a);
	void setTuoi(int a);
	void setGioiTinh(int a);
	virtual void Nhap();
	virtual void Xuat();
};

