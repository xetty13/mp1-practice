#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;
int main()
{
	int n;
	Owner* owners = read_inf(n);
	cout <<"number of owners =" << n << endl << endl;
	print_inf(owners, n);
	search_owner(owners, n);
	delete[] owners;
}