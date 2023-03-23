#ifndef _prototypes_h
#define _prototypes_h

#define LEN 256
#define NAgencies 7

typedef struct // list of service
{
	char* country;
	char* travel_conditions;
	char* excursion_services;
	char* host_service;
	char* ticket_price;
} TService;

typedef struct // Tourist agency
{
	int num_services;
	char* name;
	TService *services;
} TAgency;

int counter_agencies(int counter, FILE* fptr);//count agencies
void allocate_TAgency(TAgency** pointer);//allocating guide list...
void allocate_TServices(TAgency** ptr);//allocating list of service
void file_reader(FILE* fptr, TAgency*** list);//reading data
void search_string(FILE* fptr);
void output_all_data(FILE* fptr, TAgency** pointer);//all data
void output_data_EZONES(FILE* fptr, TAgency** pointer, char* e_zone[]);//data about euro zones
void free_memory(TAgency** pointer);


#endif