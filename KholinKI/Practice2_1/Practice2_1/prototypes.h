#ifndef _prototypes_h
#define _prototypes_h

#define LEN 512

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

int CountAgencies(FILE* fptr);//count agencies
int* CountTServices(FILE* fptr);//count directions

void allocate_TAgency(TAgency** pointer, int count_services);//allocating guide list...
void allocate_TServices(TAgency** ptr);//allocating list of service
void file_reader(FILE* fptr, TAgency*** list);//reading data
void search_string(FILE* fptr);
void output_all_data(FILE* fptr, TAgency** list);//all data
void output_data_EZONES(FILE* fptr, TAgency** list, char* e_zone[]);//data about euro zones
void free_memory(TAgency*** pointer, FILE* fptr);//freeing up memory
#endif