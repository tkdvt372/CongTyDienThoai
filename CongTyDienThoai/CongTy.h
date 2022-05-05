#pragma once
#include "nvVanPhong.h"
#include "nvSanXuat.h"
#include "nvQuanLi.h"
#include"ThueBao.h"
#include"DoanhThu.h"
class CongTy
{
private:
	vector<NhanVien*> DanhSachNhanVien;
	vector<Nguoi*> DanhSachThueBao;
	vector<DoanhThu*> DoanhThuTong;
	int DemDT, DemNV, DemTB;
	float TongLuongNV, TongCP;
public:
	void NhapNV();
	void NhapDT();
	void NhapTB();
	void XuatTB();
	void TimKiemTB();
	void importDataDT();
	void importDataNV();
	void importDataTB();
	void importDem();
	void importTotal();
	void XuatNV();
	void TimKiemNV();
	void XuatDT();
	float TongLuong();
	float TongCuocPhi();
	CongTy();
	~CongTy();
};

