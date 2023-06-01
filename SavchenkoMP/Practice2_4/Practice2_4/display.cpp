#include <iostream>
#include <string>
#include "display.h"
#include "receipt.h"
using namespace std;

void dsp::StartMenu() {
	cout << "Добро пожаловать на кассу!\n" << endl;
	cout << "1. Начать" << endl;
	cout << "0. Выход\n" << endl;
}
void dsp::MainMenu() {
	Line("-", 50);
	cout << "1. Отсканировать товары" << endl;
	cout << "2. Оплатить" << endl;
	cout << "3. Посмотреть корзину" << endl;
	cout << "4. Удалить товар из корзины" << endl;
	cout << "0. Выход" << endl;
	Line("-", 50);
	cout << endl;
}

void dsp::ScanAns(int& ans) {
	do {
		cin >> ans;
	} while (ans < 0 || ans > mainmenu);
}

void dsp::MenuScanAns(int& ans) {
	do {
		cin >> ans;
	} while (ans < 0 || ans > menuscanproduct);
}


void dsp::Line(string l, int count) {
	for (int i = 0; i < count; i++)
		cout << l;
	cout << endl;
}

void dsp::Press2Continue() {
	int tmp;
	cout << "\nНажмите любую клавишу, чтобы продолжить.\n" << endl;
	cin >> tmp;
}