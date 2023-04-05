
#include "class TService.h"
#include "class TAgency.h"
#include "prototypes.h"


TAgency::TAgency() {
	num_services = NULL;
	name = "";
	services = NULL;
}

TAgency::TAgency(int count_services) {
	this->num_services = count_services;
	this->services = new TService[count_services];//creating a service structure for each facility ;automatic call constructor
}

TAgency::~TAgency() {
	ifstream file;
	file = create_file();
	int num_agencies = CountAgencies(file);
	for (int i = 0; i < num_agencies; i++) {
		delete[] this[i].services;
	}
	delete[] this;
	file.close();
}

TService::TService() {
	country = "";
	travel_conditions = "";
	excursion_services = "";
	host_service = "";
	ticket_price = "";
}



