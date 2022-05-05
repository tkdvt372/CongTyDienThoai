#include "Menu.h"
void Menu::gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Menu::move()
{
    char c = _getch();
    if ((int)c == -32)
        c = _getch();
    switch ((int)c)
    {
    case 80:
        return 1;
    case 72:
        return 2;
    case 77:
        return 3;
    case 75:
        return 4;
    case 27:
        return 8;
    case 13:
        return 5;
    default:
        return 0;
    }
}
Menu::Menu()
{
    item = new string[100];
    _numberOfItem = 4;
    item[0] = "QUAN LY DOANH THU";
    item[1] = "QUAN LY THUE BAO";
    item[2] = "QUAN LY NHAN VIEN";
    item[3] = "THOAT";
}
Menu::Menu(int n, int type)
{
    if (type == 0)
    {
        itemNV = new string[100];
        this->_numberOfItemNV = n;
        itemNV[0] = "THEM NHAN VIEN";
        itemNV[1] = "XUAT THONG TIN NHAN VIEN";
        itemNV[2] = "TIM KIEM NHAN VIEN";
        itemNV[3] = "THOAT";
    }
    if (type == 1)
    {
        itemTB = new string[100];
        this->_numberOfItemTB = n;
        itemTB[0] = "THEM THUE BAO";
        itemTB[1] = "XUAT THONG TIN THUE BAO";
        itemTB[2] = "TIM KIEM THUE BAO";
        itemTB[3] = "THOAT";
    }
    if (type == 2)
    {
        itemDT = new string[100];
        this->_numberOfItemDT = n;
        itemDT[0] = "NHAP DOANH THU";
        itemDT[1] = "THONG KE TAI CHINH";
        itemDT[2] = "THOAT";
    }
}
Menu::~Menu()
{
}
void Menu::printMenu()
{
    for (int i = 0; i < _numberOfItem; i++)
    {
        gotoxy(3, i);
        cout << item[i];
        Sleep(100);
    }
}
void Menu::printMenuNV()
{
    for (int i = 0; i < _numberOfItemNV; i++)
    {
        gotoxy(3, i);
        cout << itemNV[i];
        Sleep(100);
    }
}
void Menu::printMenuTB()
{
    for (int i = 0; i < _numberOfItemTB; i++)
    {
        gotoxy(3, i);
        cout << itemTB[i];
        Sleep(100);
    }
}
void Menu::printMenuDT()
{
    for (int i = 0; i < _numberOfItemDT; i++)
    {
        gotoxy(3, i);
        cout << itemDT[i];
        Sleep(100);
    }
}
void Menu::deleteMenu()
{
    Sleep(100);
    gotoxy(0, 0);
    system("cls");
    Sleep(100);
}
int Menu::numberOfItem()
{
    return _numberOfItem;
}
int Menu::numberOfItemNV()
{
    return _numberOfItemNV;
}
int Menu::numberOfItemTB()
{
    return _numberOfItemTB;
}
int Menu::numberOfItemDT()
{
    return _numberOfItemDT;
}
string* Menu::getItem()
{
    return item;
}
string* Menu::getItemNV()
{
    return itemNV;
}
string* Menu::getItemTB()
{
    return itemTB;
}
string* Menu::getItemDT()
{
    return itemDT;
}
void Menu::start(CongTy* ct)
{
    ct->importTotal();
    int x;
    Menu* MenuNV = new Menu(4, 0);
    Menu* MenuTB = new Menu(4, 1);
    Menu* MenuDT = new Menu(3, 2);
    int SubMenu = 0;
    int line = 0;
    bool thoat = false;
    this->printMenu();
    this->gotoxy(0, line);
    cout << (char)3;
    while (!thoat)
    {
        if (_kbhit())
        {
            x = this->move();
            this->gotoxy(0, line);
            cout << " ";
            switch (x)
            {
            case 1:
            case 3:
            {
                if (SubMenu == 0)
                {
                    line++;
                    if (line >= this->numberOfItem())
                        line = 0;
                    break;
                }
                else if (SubMenu == 3)
                {
                    line++;
                    if (line >= MenuNV->numberOfItemNV())
                        line = 0;
                    break;
                }
                else if (SubMenu == 2)
                {
                    line++;
                    if (line >= MenuTB->numberOfItemTB())
                        line = 0;
                    break;
                }
                else if (SubMenu == 1)
                {
                    line++;
                    if (line >= MenuDT->numberOfItemDT())
                        line = 0;
                    break;
                }
            }
            case 2:
            case 4:
            {
                if (SubMenu == 0)
                {
                    line--;
                    if (line < 0)
                        line = this->numberOfItem() - 1;
                    break;
                }
                else if (SubMenu == 3)
                {
                    line--;
                    if (line < 0)
                        line = MenuNV->numberOfItemNV() - 1;
                    break;
                }
                else if (SubMenu == 2)
                {
                    line--;
                    if (line < 0)
                        line = MenuNV->numberOfItemTB() - 1;
                    break;
                }
                else if (SubMenu == 1)
                {
                    line--;
                    if (line < 0)
                        line = MenuDT->numberOfItemDT() - 1;
                    break;
                }
            }
            case 5:
            {
                if (SubMenu == 0)
                {
                    if (this->getItem()[line] == "QUAN LY DOANH THU")
                    {
                        this->deleteMenu();
                        SubMenu = 1;
                        line = 0;
                        MenuDT->gotoxy(0, line);
                        MenuDT->printMenuDT();
                    }
                    else if (this->getItem()[line] == "QUAN LY THUE BAO")
                    {
                        this->deleteMenu();
                        SubMenu = 2;
                        line = 0;
                        MenuTB->gotoxy(0, line);
                        MenuTB->printMenuTB();
                    }
                    else if (this->getItem()[line] == "QUAN LY NHAN VIEN")
                    {
                        this->deleteMenu();
                        SubMenu = 3;
                        line = 0;
                        MenuNV->gotoxy(0, line);
                        MenuNV->printMenuNV();
                    }
                    else if (this->getItem()[line] == "THOAT")
                    {
                        this->deleteMenu();
                        return;
                    }
                }
                else if (SubMenu == 1)
                {
                    if (MenuDT->getItemDT()[line] == "THOAT")
                    {
                        MenuDT->deleteMenu();
                        system("cls");
                        SubMenu = 0;
                        this->printMenu();
                        line = 0;
                        break;
                    }
                    if (MenuDT->getItemDT()[line] == "NHAP DOANH THU")
                    {
                        MenuDT->deleteMenu();
                        ct->NhapDT();
                        system("pause");
                        system("cls");
                        MenuDT->printMenuDT();
                        break;
                    }
                    if (MenuDT->getItemDT()[line] == "THONG KE TAI CHINH")
                    {
                        MenuDT->deleteMenu();
                        ct->XuatDT();
                        system("pause");
                        system("cls");
                        MenuDT->printMenuDT();
                        break;
                    }
                }
                else if (SubMenu == 2)
                {
                    if (MenuTB->getItemTB()[line] == "THEM THUE BAO")
                    {
                        MenuTB->deleteMenu();
                        ct->NhapTB();
                        system("pause");
                        system("cls");
                        MenuTB->printMenuTB();
                        break;
                    }
                    else if (MenuTB->getItemTB()[line] == "XUAT THONG TIN THUE BAO")
                    {
                        MenuTB->deleteMenu();
                        ct->XuatTB();
                        system("pause");
                        system("cls");
                        MenuTB->printMenuTB();
                        break;
                    }
                    else if (MenuTB->getItemTB()[line] == "TIM KIEM THUE BAO")
                    {
                        MenuTB->deleteMenu();
                        ct->TimKiemTB();
                        system("pause");
                        system("cls");
                        MenuTB->printMenuTB();
                        break;
                    }

                    else if (MenuTB->getItemTB()[line] == "THOAT")
                    {
                        MenuNV->deleteMenu();
                        system("cls");
                        SubMenu = 0;
                        this->printMenu();
                        line = 1;
                        break;
                    }
                }
                else if (SubMenu == 3)
                {
                    if (MenuNV->getItemNV()[line] == "THEM NHAN VIEN")
                    {
                        MenuNV->deleteMenu();
                        ct->NhapNV();
                        system("pause");
                        system("cls");
                        MenuNV->printMenuNV();
                        break;
                    }
                    if (MenuNV->getItemNV()[line] == "XUAT THONG TIN NHAN VIEN")
                    {
                        MenuNV->deleteMenu();
                        ct->XuatNV();
                        system("pause");
                        system("cls");
                        MenuNV->printMenuNV();
                        break;
                    }
                    if (MenuNV->getItemNV()[line] == "TIM KIEM NHAN VIEN")
                    {
                        MenuNV->deleteMenu();
                        ct->TimKiemNV();
                        system("pause");
                        system("cls");
                        MenuNV->printMenuNV();
                        break;
                    }

                    if (MenuNV->getItemNV()[line] == "THOAT")
                    {
                        MenuNV->deleteMenu();
                        system("cls");
                        SubMenu = 0;
                        line = 2;
                        this->printMenu();
                        break;
                    }
                }

                break;
            }
            case 8:
                thoat = true;
            }
            this->gotoxy(0, line);
            cout << (char)3;
        }
    }
    delete MenuNV, MenuDT, MenuTB;
}