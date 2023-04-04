#include <iostream>
#include <clocale>
#include <fstream>
#include "Impl.cpp"


//Tourist Guide.The guide contains a list of travel agenciesand the services they offer
//(country, city or itinerary of the cruise, accommodation and travel conditions, excursions, host service, price of the trip).
//Provide a list of travel agencies offering tours to Eurozone countries.




int main(int argc, char* argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");

	try {
		ifstream file;//creating file var
		const string* EU;

		file.open("C://TouristAgences.txt");//open the file for reading

		if (file.is_open() == 0) {
			throw ifstream();
		}
		int i = 0;
		TAgency** my_list_agencies;
		int num_agencies = CountAgencies(file);
		int* num_services = CountTServices(file);//count directions
		EU = euro_zone;
		my_list_agencies = new TAgency * [num_agencies]; //create a dynamic array of objects
		for (i = 0; i < num_agencies; i++) {
			my_list_agencies[i] = new TAgency(num_services[i]);//allocate first operation: = second:constructor
			my_list_agencies[i]->file_reader(file, my_list_agencies[i]);//read
			//my_list_agencies[i]->output_all_data(my_list_agencies[i]);//output
			//my_list_agencies[i]->output_data_EZONES(my_list_agencies[i], EU);
			//output_data_EZONES(my_list_agencies[i], EU);
			output_all_data(my_list_agencies[i]);
		}
		file.close();
		return 0;
	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}
	
}