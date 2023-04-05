#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;
extern int n;
int main()
{
	Owner* owners = read_inf(n);
	cout << "number of owners =" << n << endl << endl;
	print_inf(owners, n);
	Owner* owner1 = search_owner(owners, n);
	print_inf(owner1, n);
	delete[] owners;
	delete[] owner1;
}