#ifndef _prototypes_h
#define _prototypes_h

typedef struct {
	struct travel_agency_information {
		char name_travel_agencies[25];
		char country[15];
		char travel_conditions[500];
		char excursion_services[500];
		char host_service[300];
		char ticket_price[20];
	}INFO;//info about agences
}list_ag;//Addressing the agency by index

list_ag* file_reader(FILE* fptr, list_ag** my_objects);
void output_data_file(FILE* fptr, list_ag** pointer);
void output_data_EZONES(FILE* fptr, list_ag** pointer, char *e_zone[]);
void free_memory(list_ag** pointer);

#endif