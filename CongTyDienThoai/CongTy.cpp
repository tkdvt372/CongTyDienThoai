#include "CongTy.h"
CongTy::CongTy()
{
	DemDT = 0;
	DemNV = 0;
	DemTB = 0;
	TongLuongNV = 0;
	TongCP = 0;
}
CongTy::~CongTy()
{
	ofstream file2;
	file2.open("test.txt", ios_base::out);
	int a = DemNV;
	int b = DemDT;
	int c = DemTB;
	file2 << a << "\n";
	file2 << b << "\n";
	file2 << c;
	file2.close();
}
void CongTy::importTotal()
{
	this->importDem();
	this->importDataNV();
	this->importDataTB();
	this->importDataDT();
}
void CongTy::importDem()
{
	ifstream file3;
	file3.open("test.txt", ios_base::in);
	file3 >> DemNV;
	file3 >> DemDT;
	file3 >> DemTB;
	file3.close();
}
void CongTy::importDataNV()
{
	fstream file;
	ifstream FileIn;
	int arr[100];
	FileIn.open("vitri.txt", ios::in);
	file.open("nhanvien.dat", ios::in | ios::binary);
	for (int i = 0; i < DemNV; i++)
	{
		FileIn >> arr[i];
	}
	for (int i = 0; i < DemNV; i++)
	{
		if (arr[i] == 1)
		{
			nvVanPhong* a = new nvVanPhong;
			NhanVien* temp1 = new nvVanPhong;
			file.read((char*)(a), sizeof(nvVanPhong));
			((nvVanPhong*)temp1)->setSoNgayLamViec(a->getSoNgayLamViec());
			((nvVanPhong*)temp1)->setTroCap(a->getTroCap());
			temp1->setHoTen(a->getHoTen());
			temp1->setGioiTinh(a->getGioiTinh());
			temp1->setNgaySinh(a->getNgaySinh());
			temp1->setQueQuan(a->getQueQuan());
			temp1->setTuoi(a->getTuoi());
			DanhSachNhanVien.push_back(temp1);
		}
		if (arr[i] == 2)
		{
			nvSanXuat* b = new nvSanXuat;
			NhanVien* temp2 = new nvSanXuat;
			file.read((char*)(b), sizeof(nvSanXuat));
			((nvSanXuat*)temp2)->setSoSanPham(b->getSoSanPham());
			temp2->setHoTen(b->getHoTen());
			temp2->setGioiTinh(b->getGioiTinh());
			temp2->setNgaySinh(b->getNgaySinh());
			temp2->setQueQuan(b->getQueQuan());
			temp2->setTuoi(b->getTuoi());
			DanhSachNhanVien.push_back(temp2);
		}
		if (arr[i] == 3)
		{
			nvQuanLi* c = new nvQuanLi;
			NhanVien* temp3 = new nvQuanLi;
			file.read((char*)(c), sizeof(nvQuanLi));
			((nvQuanLi*)temp3)->setHeso(c->getHeSo());
			((nvQuanLi*)temp3)->setThuong(c->getThuong());
			temp3->setHoTen(c->getHoTen());
			temp3->setGioiTinh(c->getGioiTinh());
			temp3->setNgaySinh(c->getNgaySinh());
			temp3->setQueQuan(c->getQueQuan());
			temp3->setTuoi(c->getTuoi());
			DanhSachNhanVien.push_back(temp3);
		}
	}
	FileIn.close();
	file.close();
}

void CongTy::importDataTB()
{
	fstream file;
	file.open("thuebao.dat", ios::in | ios::binary);
	for (int i = 0; i < DemTB; i++)
	{
		ThueBao* e = new ThueBao;
		Nguoi* temp = new ThueBao;
		file.read((char*)(e), sizeof(ThueBao));
		((ThueBao*)temp)->setCuocPhi(e->getCuocPhi());
		((ThueBao*)temp)->setLoaiTB(e->getLoaiTB());
		((ThueBao*)temp)->setMaTB(e->getMaTB());
		((ThueBao*)temp)->setNgayDK(e->getNgayDK());
		((ThueBao*)temp)->setSoDienThoai(e->getSoDienThoai());
		((ThueBao*)temp)->setTgNgoaiMang(e->getTgNgoaiMang());
		((ThueBao*)temp)->setTgNoiMang(e->getTgNoiMang());
		temp->setHoTen(e->getHoTen());
		temp->setGioiTinh(e->getGioiTinh());
		temp->setNgaySinh(e->getNgaySinh());
		temp->setQueQuan(e->getQueQuan());
		temp->setTuoi(e->getTuoi());
		DanhSachThueBao.push_back(temp);
	}
	file.close();
}
void CongTy::importDataDT()
{
	fstream file;
	DoanhThu* p = new DoanhThu;
	file.open("doanhthu.dat", ios::in | ios::binary);
	for (int i = 0; i < DemDT; i++)
	{
		DoanhThu* temp = new DoanhThu;
		file.read((char*)(p), sizeof(DoanhThu));
		temp->setTienVon(p->getTienVon());
		temp->setThue(p->getThue());
		temp->setPhuThu(p->getPhuThu());
		temp->setChi(temp->getTienThue() + this->TongLuong());
		temp->setThu(this->TongCuocPhi() + temp->getPhuThu());
		temp->setTongTien(temp->getTienVon() + temp->getThu() - temp->getChi());
		if (temp->getTongTien() < 0)
			temp->setTongTien(0);
		DoanhThuTong.push_back(temp);
	}
	file.close();
}
void CongTy::NhapNV()
{
	fstream file;
	ofstream FileOut;
	FileOut.open("vitri.txt", ios::app);
	file.open("nhanvien.dat", ios::app | ios::binary);
	int n;
	do
	{
		cout << "\n1.Nhan vien van phong\n";
		cout << "2.Nhan vien san xuat\n";
		cout << "3.Nhan vien quan li\n";
		cout << "4.Thoat\n";
		do
		{
			cout << "lua chon cua ban la: ";
			cin >> n;
			if (n < 1 || n > 4)
			{
				cout << "Vui long nhap lai!\n";
			}
		} while (n < 1 || n > 4);
		switch (n)
		{
		case 1:
		{
			nvVanPhong* temp1 = new nvVanPhong;
			temp1->Nhap();
			file.write((char*)(temp1), sizeof(nvVanPhong));
			DanhSachNhanVien.push_back(temp1);
			FileOut << 1 << " ";
			DemNV++;
			file.seekg(0, ios::end);
			break;
		}
		case 2:
		{
			nvSanXuat* temp2 = new nvSanXuat;
			temp2->Nhap();
			file.write((char*)(temp2), sizeof(nvSanXuat));
			FileOut << 2 << " ";
			DanhSachNhanVien.push_back(temp2);
			DemNV++;
			file.seekg(0, ios::end);
			break;
		}
		case 3:
		{
			nvQuanLi* temp3 = new nvQuanLi;
			temp3->Nhap();
			file.write((char*)(temp3), sizeof(nvQuanLi));
			FileOut << 3 << " ";
			DanhSachNhanVien.push_back(temp3);
			DemNV++;
			file.seekg(0, ios::end);
			break;
		}
		case 4:
		{
			return;
		}
		default:
			break;
		}
	} while (n > 1 || n < 4);

	for (int i = 0; i < n; i++)
	{
	}
	file.close();
	FileOut.close();
}
void CongTy::XuatNV()
{
	cout << "\nSo luong: " << DemNV << endl;
	cout << "\n---------------Danh sach nhan vien--------------- \n";
	int n;
	do
	{
		cout << "\n1.Sap xep tu thap den cao theo luong.\n";
		cout << "2.Sap xep tu cao den thap theo luong.\n";
		cout << "3.Xuat cac nhan vien van phong.\n";
		cout << "4.Xuat cac nhan vien san xuat.\n";
		cout << "5.Xuat cac nhan vien quan li.\n";
		cout << "6.Thoat\n";
		do
		{
			cout << "lua chon cua ban la: ";
			cin >> n;
			if (n < 1 || n > 6)
			{
				cout << "Vui long nhap lai!\n";
			}
		} while (n < 1 || n > 6);
		system("cls");
		switch (n)
		{
		case 1:
			for (int i = 0; i < DemNV - 1; i++)
			{
				for (int j = i + 1; j < DemNV; j++)
				{
					if (DanhSachNhanVien[i]->TinhLuong() > DanhSachNhanVien[j]->TinhLuong())
						swap(DanhSachNhanVien[i], DanhSachNhanVien[j]);
				}
			}
			for (int i = 0; i < DemNV; i++)
			{
				DanhSachNhanVien[i]->Xuat();
			}
			system("pause");
			system("cls");
			break;

		case 2:
			for (int i = 0; i < DemNV - 1; i++)
			{
				for (int j = i + 1; j < DemNV; j++)
				{
					if (DanhSachNhanVien[i]->TinhLuong() <= DanhSachNhanVien[j]->TinhLuong())
						swap(DanhSachNhanVien[i], DanhSachNhanVien[j]);
				}
			}
			for (int i = 0; i < DemNV; i++)
			{
				DanhSachNhanVien[i]->Xuat();
			}
			system("pause");
			system("cls");
			break;

		case 3:
			for (int i = 0; i < DemNV; ++i)
			{
				if (DanhSachNhanVien[i]->getLuongCB() == 1500000)
				{
					DanhSachNhanVien[i]->Xuat();
				}
			}
			system("pause");
			system("cls");
			break;

		case 4:
			for (int i = 0; i < DemNV; ++i)
			{
				if (DanhSachNhanVien[i]->getLuongCB() == 1000000)
				{
					DanhSachNhanVien[i]->Xuat();
				}
			}
			system("pause");
			system("cls");
			break;
		case 5:
			for (int i = 0; i < DemNV; ++i)
			{
				if (DanhSachNhanVien[i]->getLuongCB() == 2000000)
				{
					DanhSachNhanVien[i]->Xuat();
				}
			}
			system("pause");
			system("cls");
			break;
		case 6:
			return;
		default:
			system("cls");
			return;
		}
	} while (n != 6);
}
void CongTy::TimKiemNV()
{
	cout << "\nTim ten nhan vien: ";
	string name;
	getline(cin, name);
	cout << "\nNhan vien can tim la: ";
	bool check = false;
	for (int i = 0; i < DemNV; i++)
	{
		if (DanhSachNhanVien[i]->getHoTen() == name)
		{
			DanhSachNhanVien[i]->Xuat();
			cout << endl;
			check = true;
		}
	}
	if (!check)
	{
		cout << "Khong tim thay nhan vien!";
	}
}

void CongTy::NhapTB()
{
	fstream file;
	file.open("thuebao.dat", ios::app | ios::binary);
	int n;
	cout << "\nNhap so luong thue bao: ";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "\nThue bao thu " << i + 1 << endl;
		ThueBao* temp = new ThueBao;
		temp->Nhap();
		file.write((char*)(temp), sizeof(ThueBao));
		DemTB++;
		file.seekg(0, ios::end);
		DanhSachThueBao.push_back(temp);
	}
	file.close();
}
void CongTy::XuatTB()
{
	int n;
	do
	{
		cout << "\n1.Sap xep tu thap den cao theo cuoc phi.\n";
		cout << "2.Sap xep tu cao den thap theo cuoc phi.\n";
		cout << "3.Xuat cac thue bao tra truoc.\n";
		cout << "4.Xuat cac thue bao tra sau.\n";
		cout << "5.Thoat\n";
		do
		{
			cout << "lua chon cua ban la: ";
			cin >> n;
			if (n < 1 || n > 5)
			{
				cout << "Vui long nhap lai!\n";
			}
		} while (n < 1 || n > 5);
		system("cls");
		switch (n)
		{
		case 1:
			for (int i = 0; i < DemTB - 1; i++)
			{
				for (int j = i + 1; j < DemTB; j++)
				{
					if (((ThueBao*)DanhSachThueBao[i])->getCuocPhi() > ((ThueBao*)DanhSachThueBao[j])->getCuocPhi())
						swap(DanhSachThueBao[i], DanhSachThueBao[j]);
				}
			}
			for (int i = 0; i < DemTB; i++)
			{
				DanhSachThueBao[i]->Xuat();
			}
			system("pause");
			system("cls");
			break;

		case 2:
			for (int i = 0; i < DemTB - 1; i++)
			{
				for (int j = i + 1; j < DemTB; j++)
				{
					if (((ThueBao*)DanhSachThueBao[i])->getCuocPhi() < ((ThueBao*)DanhSachThueBao[j])->getCuocPhi())
						swap(DanhSachThueBao[i], DanhSachThueBao[j]);
				}
			}
			for (int i = 0; i < DemTB; i++)
			{
				DanhSachThueBao[i]->Xuat();
			}
			system("pause");
			system("cls");
			break;

		case 3:
			for (int i = 0; i < DemTB; ++i)
			{
				if (((ThueBao*)DanhSachThueBao[i])->getLoaiTB() == 0)
				{
					DanhSachThueBao[i]->Xuat();
				}
			}
			system("pause");
			system("cls");
			break;

		case 4:
			for (int i = 0; i < DemTB; ++i)
			{
				if (((ThueBao*)DanhSachThueBao[i])->getLoaiTB() == 1)
				{
					DanhSachThueBao[i]->Xuat();
				}
			}
			system("pause");
			system("cls");
			break;

		default:
			system("cls");
			return;
		}
	} while (n != 5);
}
void CongTy::TimKiemTB()
{
	cout << "\nNhap ma thue bao muon tim: ";
	string ma;
	cin.ignore();
	getline(cin, ma);
	cout << "\nThue bao can tim la: ";
	bool check = false;
	for (int i = 0; i < DemTB; i++)
	{
		if (((ThueBao*)DanhSachThueBao[i])->getMaTB() == ma)
		{
			DanhSachThueBao[i]->Xuat();
			cout << endl;
			check = true;
		}
	}
	if (!check)
	{
		cout << "Khong tim thay thue bao!\n";
	}
}
void CongTy::NhapDT()
{
	fstream file;
	file.open("doanhthu.dat", ios::binary | ios::app);
	int n;
	cout << "\nNhap so thang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		DoanhThu* temp = new DoanhThu;
		cin >> temp;
		temp->setTienThue(temp->getTienVon() * temp->getThue());
		temp->setChi(temp->getTienThue() + this->TongLuong());
		temp->setThu(this->TongCuocPhi() + temp->getPhuThu());
		if (temp->getThu() < temp->getChi()) {
			temp->setTongTien(0);
		}
		else {
			temp->setTongTien(temp->getTienVon() + temp->getThu() - temp->getChi());
		}
		file.write((char*)(temp), sizeof(DoanhThu));
		DemDT++;
		file.seekg(0, ios::end);
		DoanhThuTong.push_back(temp);
		file.seekg(0, ios::end);
	}
	file.close();
}
void CongTy::XuatDT()
{
	for (int i = 0; i < DemDT; i++)
	{
		cout << "\n==========Thong ke thang thu " << i + 1 << "======== " << endl;
		cout << DoanhThuTong[i];
		cout << "\nTien thue phai tra: " << size_t(DoanhThuTong[i]->getTienThue());
		float a = this->TongLuong();
		cout << "\nTong luong nhan vien: " << size_t(a);
		cout << "\nTong thu: " << size_t(DoanhThuTong[i]->getThu());
		cout << "\nTong chi: " << size_t(DoanhThuTong[i]->getChi());
		cout << "\n=>Tong Tien: " << size_t(DoanhThuTong[i]->getTongTien()) << endl;
	}
}

float CongTy::TongLuong()
{
	TongLuongNV = 0;
	try
	{
		for (int i = 0; i < DemNV; ++i)
		{
			TongLuongNV += DanhSachNhanVien[i]->TinhLuong();
		}
	}
	catch (const std::exception&)
	{
		TongLuongNV = 0;
	}
	return TongLuongNV;
}
float CongTy::TongCuocPhi()
{
	try
	{
		for (int i = 0; i < DemTB; i++)
		{
			TongCP += ((ThueBao*)DanhSachThueBao[i])->getCuocPhi();
		}
	}
	catch (const std::exception&)
	{
		TongCP = 0;
	}
	return TongCP;
}