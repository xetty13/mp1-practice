#define _CRT_SECURE_NO_WARNINGS
#include "workers.h";
#include <iostream>
using namespace std;

int main() {
	string path = get_path();
	labor labor_exchange(path);
	int percent=labor_exchange.higher_education();
	cout << "Percentage of employees with higher education:" << percent << " % " << endl;
	return 0;
}
