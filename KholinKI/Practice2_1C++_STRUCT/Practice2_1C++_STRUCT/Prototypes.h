#pragma once

#define list_agences list_ag 

struct list_agences{
	struct travel_agency_information {
		char name_travel_agencies[25];
		char country[15];
		char travel_conditions[500];
		char excursion_services[500];
		char host_service[300];
		char ticket_price[20];
	}INFO;//info about agences
};//Addressing the agency by index

list_ag* file_reader(list_ag** my_objects);