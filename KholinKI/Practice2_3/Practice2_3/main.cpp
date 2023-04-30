#include <iostream>
#include "Prototypes.h"

using namespace std;

int main() {
	const string path = "C://TouristAgences.txt";
	TAgencyBook Object(path);


	TAgencyBook European_Object(Object);

	European_Object.create(Object);
	European_Object.output_data_EZONES();
	return 0;
}//delete: European_Object->Object;