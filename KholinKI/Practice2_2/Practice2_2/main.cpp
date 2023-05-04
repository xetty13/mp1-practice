#include <iostream>
#include "Prototypes.h"

using namespace std;

int main() {
	const string path = "C://TouristAgences.txt";
	TAgencyBook Object(path);
	TAgencyBook* europeCountries = Object.Get_Europe_Countries();
	cout << *(europeCountries);
	return 0;
}