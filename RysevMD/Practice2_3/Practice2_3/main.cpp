#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

int main() {

	system("chcp 1251");
	string path = read_path();
	Constellation_library lib(path);
	choice(lib);

	return 0;
}
