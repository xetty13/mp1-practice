#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

int main() {
	system("chcp 1251");
	string path = read_path();
	Constellation_library lib(path);
	int count = lib.getCount();

	cnst_table(&lib, count);
	choice(&lib, count);

	//delete &lib;
	return 0;
}
