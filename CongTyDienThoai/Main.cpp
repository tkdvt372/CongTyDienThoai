#include"CongTy.h"
#include"Menu.h"
int main() {
	CongTy* ct = new CongTy;
	Menu* menu = new Menu;
	menu->start(ct);
	delete ct, menu;
	system("pause");
	return 0;
}