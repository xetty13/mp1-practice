

#include "Impl.cpp"


//Tourist Guide.The guide contains a list of travel agenciesand the services they offer
//(country, city or itinerary of the cruise, accommodation and travel conditions, excursions, host service, price of the trip).
//Provide a list of travel agencies offering tours to Eurozone countries.




int main(int argc, char* argv[]) {

	try {
		ifstream file;//creating file va
		int num_agencies;
		TAgency* linker = nullptr;
		TAgency** my_list_agencies;
		TAgency** new_agency_list;

		file.open("C://TouristAgences.txt");//open the file for reading

		if (file.is_open() == 0) {
			throw ifstream();
		}

		num_agencies = linker->file_reader(file, my_list_agencies);//read


		new_agency_list = linker->find_euro_countries(my_list_agencies, num_agencies);

		new_agency_list[0]->output_data_EZONES(new_agency_list, num_agencies);
		file.close();
		linker->free_memory(my_list_agencies, num_agencies);
		linker->free_european_memory(new_agency_list, num_agencies);
		return 0;
	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}

}