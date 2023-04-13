#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;
int main()
{
	int n, k;
	Owner* owners = read_inf(n);
	cout <<"number of owners =" << n << endl << endl;
	print_inf(owners, n);
	Owner* owner1 = search_owner(owners, n, k);
	print_inf(owner1, k);
	delete[] owners;
	delete[] owner1;
}