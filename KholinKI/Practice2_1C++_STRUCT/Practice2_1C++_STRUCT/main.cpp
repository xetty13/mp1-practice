#include <iostream>
#include <clocale>
#include <fstream>
#include "Impl.h"





string euro_zone[20] = {//list of eurozone countries
	"Austria",
	"Belgium",
	"Cyprus",
	"Estonia",
	"Finland",
	"France",
	"Germany",
	"Greece",
	"Ireland",
	"Italy",
	"Latvia",
	"Lithuania",
	"Luxembourg",
	"Malta",
	"Netherlands",
	"Portugal",
	"Slovakia",
	"Slovenia",
	"Croatia"
};

int main(int argc, char* argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");

	try {
		 ifstream file;//creating file var


		file.open("C://TouristAgences.txt");//open the file for reading

		if (file.is_open() == 0) {
			throw ifstream();
		}
		int i = 0;
		TAgency** my_list_agencies;
		file_reader(file, &my_list_agencies);
		//output_all_data(my_list_agencies);
		output_data_EZONES(my_list_agencies, euro_zone);
		file.close();
		free_memory(my_list_agencies);
	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}
	return 0;
}