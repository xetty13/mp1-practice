#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "utility.h"
using namespace std;

string intToString(int num, int minLeng, char fill) {
	ostringstream oss;
	oss << setw(minLeng) << setfill(fill) << num;
	return oss.str();
}