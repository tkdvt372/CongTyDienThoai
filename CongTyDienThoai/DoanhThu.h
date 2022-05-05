#pragma once
#include<bits/stdc++.h>
using namespace std;
class DoanhThu
{
private:
	float TienVon, Thue, TienThue, PhuThu, Thu, Chi, TongTien;
public:
	DoanhThu();
	~DoanhThu();
	float getTienVon();
	float getThue();
	float getPhuThu();
	float getThu();
	float getChi();
	float getTienThue();
	float getTongTien();
	void setThu(float a);
	void setChi(float a);
	void setTienThue(float a);
	void setTongTien(float a);
	void setTienVon(float a);
	void setThue(float a);
	void setPhuThu(float a);
	friend istream& operator >> (istream& is, DoanhThu* p);
	friend ostream& operator << (ostream& os, DoanhThu* p);
};


