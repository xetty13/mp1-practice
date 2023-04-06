

#include "Impl.cpp"


//Tourist Guide.The guide contains a list of travel agenciesand the services they offer
//(country, city or itinerary of the cruise, accommodation and travel conditions, excursions, host service, price of the trip).
//Provide a list of travel agencies offering tours to Eurozone countries.




int main(int argc, char* argv[]) {

	try {
		ifstream file;//creating file va
		int num_agencies;
		TAgency* controller = NULL; //helper;economy memory
		TAgency** my_list_agencies;

		file.open("C://TouristAgences.txt");//open the file for reading

		if (file.is_open() == 0) {
			throw ifstream();
		}
		

		num_agencies = controller->file_reader(file, my_list_agencies);//read
		//controller->output_data_EZONES(my_list_agencies, num_agencies);
		cout << my_list_agencies<< endl;
		
		delete controller;
		file.close();
		return 0;
	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}

}