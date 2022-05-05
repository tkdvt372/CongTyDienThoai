#pragma once
#include<bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include"CongTy.h"
using namespace std;
class Menu
{
private:
    string* item, * itemNV, * itemTB, * itemDT;
    int _numberOfItem, _numberOfItemNV, _numberOfItemTB, _numberOfItemDT;
public:
    Menu();
    Menu(int, int);
    ~Menu();
    void start(CongTy*);
    void gotoxy(int, int);
    int move();
    void printMenu();
    void printMenuNV();
    void printMenuTB();
    void printMenuDT();
    void deleteMenu();
    int numberOfItem();
    int numberOfItemNV();
    int numberOfItemTB();
    int numberOfItemDT();
    string* getItem();
    string* getItemNV();
    string* getItemTB();
    string* getItemDT();
};

