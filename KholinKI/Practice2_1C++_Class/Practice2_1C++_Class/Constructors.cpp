
#include "class TService.h"
#include "class TAgency.h"



TAgency::TAgency() {
	num_services = 0;
	name = "";
	services = nullptr;
}

TAgency::TAgency(int count_services) {
	this->num_services = count_services;
	this->services = new TService[count_services];//creating a service structure for each facility ;automatic call constructor
}

TService::TService() {
	country = "";
	travel_conditions = "";
	excursion_services = "";
	host_service = "";
	ticket_price = "";
}



