#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");

	string filename;
	cin >> filename;
	TSchool school(filename);
	cout << school;
	school.sorting();
	cout << school;
	return 0;
}