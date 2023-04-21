#include "TAgencyBook.h"



TAgencyBook::TAgencyBook(TAgency* agencies, string path) {
	try {
		file.open(path);
		if (file.is_open() == 0) {
			throw ifstream();
		}
		count = CountAgencies(file);
		int* num_services = CountTServices(file);//count directions
		agencies = new TAgency[count];
		int i = 0;
		for (i = 0; i < count; i++) {
			allocate_TAgency(agencies[i], num_services[i]);//Give the same pointer to create the structure
		}
		file_reader(file);
	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}
}

TAgencyBook::TAgencyBook(const TAgencyBook& object) {
	count = object.count;
	agencies = new TAgency[count];
	for (int i = 0; i < count; i++) {
		agencies[i].num_services = object.agencies[i].num_services;
		agencies[i].services = new TService[agencies[i].num_services];
	}
}


TService::TService() {
	country = "";
	travel_conditions = "";
	excursion_services = "";
	host_service = "";
	ticket_price = "";
}

TAgencyBook::~TAgencyBook() {
	for (int i = 0; i < count; i++) {
		delete[] agencies[i].services;
	}
	delete[] agencies;
}


