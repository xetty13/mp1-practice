#include "person.h"
#include <iostream>
using namespace std;

int main() {//C:\Users\Ivan\Desktop\Prctice 2.2_00\Prctice 2.2_00\Persons.txt
	string path = getPath();
	persons_list ps(path);
	cout << ps;
	ps.surname_sort();
	menu(ps);
}