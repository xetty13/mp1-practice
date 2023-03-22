#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

int main() {
	system("chcp 1251");
	Constellation* constellations;

	allocate(&constellations);
	read_data(constellations);

	cnst_table(constellations);
	choice(constellations);

	cfree(&constellations);

	return 0;
}
