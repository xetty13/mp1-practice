#include <iostream>
#include "fileProcessing.h"
#include "userSide.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string fname;
	std::cin >> fname;
	Univ_database_t unsdata(fname);

	working_with_user(unsdata);

	return 0;
}