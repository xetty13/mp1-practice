
#include <iostream>
#include "class TService.h"
#include "class TAgency.h"


TAgency::TAgency() {
	num_agencies = 0;
	num_services = NULL;
	name = "";
	services = NULL;
}

TAgency::TAgency(int num_services,int num_agencies) {
	this->num_agencies = num_agencies;
	this->num_services = num_services;
}

TAgency::~TAgency() {
	for (int is = 0; is < num_agencies; is++) {
		delete[] this[is].services;
	}
	delete[] this;
}

TService::TService() {
	country = "";
	travel_conditions = "";
	excursion_services = "";
	host_service = "";
	ticket_price = "";
}

TService::TService(string country, string travel_conditions, string excursion_services, string host_service, string ticket_price) {

}//додумать как заполнить через конструктор
