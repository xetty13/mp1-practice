#include <iostream>
#include "display.h"
#include "receipt.h"
using namespace std;


void TDisplay::StartMenu() {
	cout << "Добро пожаловать на кассу!\n" << endl;
	cout << "1. Начать" << endl;
	cout << "0. Выход\n" << endl;
}
void TDisplay::MainMenu() {
	
	cout << "1. Отсканировать товары" << endl;
	cout << "2. Оплатить" << endl;
	cout << "3. Посмотреть корзину" << endl;
	cout << "4. Удалить товар из корзины" << endl;
	cout << "0. Выход\n" << endl;
}

void TDisplay::ScanAns(int& ans) {
	do {
		cin >> ans;
	} while (ans < 0 ||  ans > mainmenu);
}

void TDisplay::MenuScanProduct(const TReceipt& r) {
	if (r.Count()) r.Show();
	cout << "1. Начать сканирование." << endl;
	
	cout << "2. Режим: ";
	if (scanmode) cout << "Вводить количество продукта" << endl;
	else cout << "Не вводить количество продукта" << endl;
	
	cout << "Чтобы закончить сканирование, введите 0.\n" << endl;
}
void TDisplay::MenuScanAns(int& ans) {
	do {
		cin >> ans;
	} while (ans < 0 || ans > menuscanproduct);
}


void TDisplay::ChangeScanMode() {
	if (scanmode) scanmode = 0;
	else scanmode = 1;
}

void TDisplay::Line(string l, int count) {
	for (int i = 0; i < count; i++)
		cout << l;
	cout << endl;
}