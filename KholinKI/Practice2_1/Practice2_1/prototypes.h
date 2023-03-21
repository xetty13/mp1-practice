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
	char* name;
	TService *services;
} TAgency;

void allocate_TAgency(TAgency** pointer);//allocating guide list...
void file_reader(FILE* fptr, TAgency*** list);//reading data
void allocate_TServices(TAgency** ptr);//allocating list of service
void search_string(FILE* fptr);
void output_all_data(FILE* fptr, TAgency** pointer);//all data
void output_data_EZONES(FILE* fptr, TAgency** pointer, char* e_zone[]);//data about euro zones
void free_memory(TAgency** pointer);


#endif