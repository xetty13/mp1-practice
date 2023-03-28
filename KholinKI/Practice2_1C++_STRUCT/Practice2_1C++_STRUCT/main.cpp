#include <iostream>
#include <clocale>
#include <fstream>
#include "Impl.cpp"


//Tourist Guide.The guide contains a list of travel agenciesand the services they offer
//(country, city or itinerary of the cruise, accommodation and travel conditions, excursions, host service, price of the trip).
//Provide a list of travel agencies offering tours to Eurozone countries.



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
		int num_agencies = 0;
		int* num_services;
		num_agencies = CountAgencies(num_agencies,file);
		num_services = new int[num_agencies];
		for (int i = 0; i < num_agencies; i++) {
			num_services[i] = 0;
		}
		num_services = CountTServices(num_services,num_agencies, file);
		int i = 0;
		TAgency** my_list_agencies;
		file_reader(file, my_list_agencies,num_agencies,num_services);
	//	output_all_data(my_list_agencies,num_agencies,num_services);
		output_data_EZONES(my_list_agencies, euro_zone,num_agencies,num_services);
		file.close();
		free_memory(my_list_agencies,num_agencies,num_services);

	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}
	return 0;
}