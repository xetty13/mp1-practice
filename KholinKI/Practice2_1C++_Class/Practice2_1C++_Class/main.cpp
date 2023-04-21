#include "TAgencyBook.h"
#include <clocale>
#include <iostream>
#include <fstream>

//Tourist Guide.The guide contains a list of travel agencies and the services they offer
//(country, city or itinerary of the cruise, accommodation and travel conditions, excursions, host service, price of the trip).
//Provide a list of travel agencies offering tours to Eurozone countries.



int main(int argc, char* argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");

	std::string path = "C://TouristAgences.txt";//creating file var
	TAgency* agencies = NULL;
	TAgencyBook my_list(agencies, path);

	TAgencyBook European_massive(my_list);//new mass

	European_massive.find_euro_countries();//create new corrected massive

	European_massive.output_data_EZONES();

	return 0;
}
