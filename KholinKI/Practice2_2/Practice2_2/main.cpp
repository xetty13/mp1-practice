#include <iostream>
#include "Prototypes.h"

using namespace std;

int main() {
	const string path = "C://TourisAgences.txt";
	TAgencyBook Object(path);	

	TAgencyBook European_Object;
	European_Object = TAgencyBook(Object);

	European_Object.create(Object);
	European_Object.output_data_EZONES();
	return 0;
}