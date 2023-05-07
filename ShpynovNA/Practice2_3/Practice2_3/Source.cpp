#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>
void main()
{
	int n = 12;
	string filename;
	cin >> filename;
	employee* g_empls = new employee[n];
	createmem(n, filename, &g_empls);
	age_scan(n, g_empls);
	delete[] g_empls;
}