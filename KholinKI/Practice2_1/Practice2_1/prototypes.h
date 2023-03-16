#ifndef _prototypes_h
#define _prototypes_h

#define LEN 256

typedef struct
{
	char* country;
	char* host_service;
	char* travel_conditions;
	// все, что есть в информации об услуге в задаче
} TService;

typedef struct
{
	char* name;
	int num_services;
	TService *services;
} TAgency;

void allocate_struct() {
	int i = 0;
	TAgency** agencies = (*TAgency)malloc(sizeof(TAgency));
	printf("Enter num_sevices: \n");
	scanf("%d", &(*agencies)->num_services);
	for (i = 0; i < (*agencies)->num_services; i++) {
		(*list)->services[i] = (TService*)malloc(sizeof(TService));
	}
}
void free_memory(TAgency** list) {
	for (int i = 0; i < (*list)->num_services; i++){
		free((*list)->services[i]);
	}
}

/*TAgency* file_reader(FILE* fptr, TAgency**);
void output_data_file(FILE* fptr, TAgency** pointer);
void output_data_EZONES(FILE* fptr, TAgency** pointer, char *e_zone[]);
void free_memory(TAgency** pointer);
*/

#endif