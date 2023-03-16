#ifndef _prototypes_h
#define _prototypes_h

#define LEN 256
#define NAgencies 7

typedef struct
{
	char* country;
	char* travel_conditions;
	char* excursion_services;
	char* host_service;
	char* ticket_price;
} TService;

typedef struct
{
	char* name;
	TService *services;
} TAgency;

TAgency* allocate_TAgency(TAgency** pointer);
void free_memory(TAgency** pointer);

/*TAgency* file_reader(FILE* fptr, TAgency**);
void output_data_file(FILE* fptr, TAgency** pointer);
void output_data_EZONES(FILE* fptr, TAgency** pointer, char *e_zone[]);
void free_memory(TAgency** pointer);
*/

#endif