#ifndef _DISPLAY_H
#define _DISPLAY_H
#include <iostream>
#include "receipt.h"
using namespace std;

struct TDisplay {
	// Кол-во пунктов в меню //////
	const int mainmenu = 4;
	const int menuscanproduct = 2;
	///////////////////////////////

	int scanmode = 0; // 0 - без ввода кол-ва; 1 - с вводом кол-ва
	void ChangeScanMode();

	void StartMenu();
	
	void MainMenu();
	void ScanAns(int& ans);
	
	void MenuScanProduct(const TReceipt& r);
	void MenuScanAns(int& ans);

	void Line(string l = "=", int count = 50);
};

#endif // !_DISPLAY_H
