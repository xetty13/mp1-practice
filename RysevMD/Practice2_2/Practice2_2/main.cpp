#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

int main() {
	system("chcp 1251");
	Constellation* constellations;
	int count;

	read_data(constellations, count);

	cnst_table(constellations, count);
	choice(constellations, count);

	cfree(constellations);

	return 0;
}
