#ifndef _DISPLAY_H
#define _DISPLAY_H
#include <iostream>
#include "receipt.h"
using namespace std;

namespace dsp
{
	// Кол-во пунктов в меню //////
	const int mainmenu = 4;
	const int menuscanproduct = 2;
	///////////////////////////////

	void StartMenu();

	void MainMenu();
	void ScanAns(int& ans);

	void MenuScanAns(int& ans);

	void Line(string l = "=", int count = 60);

	void Press2Continue();
};


#endif // !_DISPLAY_H
