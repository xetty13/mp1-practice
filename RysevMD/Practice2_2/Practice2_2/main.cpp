#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

int main() {
	system("chcp 1251");
	Constellation_library* lib;
	int count;

	read_data(lib, count);

	cnst_table(lib, count);
	choice(lib, count);

	return 0;
}
