#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>
void main()
{
	int n = 12;
	string filename;
	cin >> filename;
	lib empls(filename);
	cout << "all employees:" << endl << empls << endl << endl << "elderly ones:" << endl << empls.output();
}
