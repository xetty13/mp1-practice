#include "person.h"
#include <iostream>
using namespace std;
int main() {
	string path = getPath();
	PersonsList pl(path);
	cout << pl << endl;
	pl.surname_sort();
	cout << "Sorted persons list:\n" << pl << endl;
	return 0;
}