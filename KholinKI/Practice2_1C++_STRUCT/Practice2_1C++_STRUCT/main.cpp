
#include <clocale>
#include "Impl.cpp"


//Tourist Guide.The guide contains a list of travel agenciesand the services they offer
//(country, city or itinerary of the cruise, accommodation and travel conditions, excursions, host service, price of the trip).
//Provide a list of travel agencies offering tours to Eurozone countries.




int main(int argc, char* argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");

	try {
		ifstream file;//creating file var
		int num_agencies;
		TAgency** my_list_agencies;//old mass
		TAgency** European_massive;//new mass

		file.open("C://TouristAgences.txt");//open the file for reading

		if (file.is_open() == 0) {
			throw ifstream();
		}
		num_agencies = file_reader(file, my_list_agencies);

		European_massive = find_euro_countries(my_list_agencies, num_agencies);//create new corrected massive

		output_data_EZONES(European_massive, num_agencies);

		file.close();
		free_memory(my_list_agencies, num_agencies);
		free_european_memory(European_massive, num_agencies);
	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}
	return 0;
}

