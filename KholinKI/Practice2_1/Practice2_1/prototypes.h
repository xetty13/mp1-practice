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
	char* name;
	TService *services;
} TAgency;

int CountAgencies(int num_agencies, FILE* fptr); //count agencies
int* CountTServices(int* num_services, int num_agencies, FILE* fptr);//count directions

void allocate_TAgency(TAgency** pointer, int num_services);//allocating guide list...
void allocate_TServices(TAgency** ptr,int num_services);//allocating list of service
void file_reader(FILE* fptr, TAgency*** list,int num_agencies,int* num_services);//reading data
void search_string(FILE* fptr);
void output_all_data(FILE* fptr, TAgency** list, int num_agencies, int* num_services);//all data
void output_data_EZONES(FILE* fptr, TAgency** pointer, char* e_zone[],int num_agencies,int* num_services);//data about euro zones
void free_memory(TAgency** pointer, int num_agencies, int* num_services);//freeing up memory
#endif