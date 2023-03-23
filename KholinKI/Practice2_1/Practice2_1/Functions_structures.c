
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "prototypes.h"


void allocate_TAgency(TAgency** pointer) {
	int i = 0;
	(*pointer) = (TAgency*)malloc(sizeof(TAgency));//creating a list of travel agencies
	printf("Enter quantity services: \n");
	scanf("%d", &(*pointer)->num_services);
	(*pointer)->services = (TService*)malloc(sizeof(TService)*1);//creating a service structure for each facility
	(*pointer)->name = (char*)malloc(sizeof(char) * LEN);
}

void allocate_TServices(TAgency** ptr) {
		(*ptr)->services->country = (char*)malloc(sizeof(char) * LEN);
		(*ptr)->services->travel_conditions = (char*)malloc(sizeof(char) * LEN);
		(*ptr)->services->excursion_services = (char*)malloc(sizeof(char) * LEN);
		(*ptr)->services->host_service = (char*)malloc(sizeof(char) * LEN);
		(*ptr)->services->ticket_price = (char*)malloc(sizeof(char) * LEN);
}


void search_string(FILE* fptr) {//look for the first occurrence of the string
	int i = 0;
	char c = 32;
			fscanf(fptr, "%c", &c);
			if (c == 10) {
				do {
					fseek(fptr, 1, SEEK_CUR);
					fscanf(fptr, "%c", &c);
				} while (c == 10);
	}
}

void file_reader(FILE * fptr, TAgency *** list) {
	*(list) = (TAgency**)malloc(sizeof(TAgency*) * NAgencies); //create a dynamic array of objects
	int i = 0;
	for (i = 0; i < NAgencies; i++) {
		allocate_TAgency(&(*list)[i]);//Give the same pointer to create the structure
	}
	for (i = 0; i < NAgencies; i++) {
		allocate_TServices(&(*list)[i]);//Give the same pointer to create the structure
	}
	for (i = 0; i < NAgencies; i++) {
		search_string(fptr);
		fseek(fptr, -1, SEEK_CUR);
		fgets((*list)[i]->name, LEN, fptr);
		fgets((*list)[i]->services->country, LEN, fptr);
		fgets((*list)[i]->services->travel_conditions, LEN, fptr);
		fgets((*list)[i]->services->excursion_services, LEN, fptr);
		fgets((*list)[i]->services->host_service, LEN, fptr);
		fgets((*list)[i]->services->ticket_price, LEN, fptr);
	}
}

void output_all_data(FILE* fptr, TAgency** list) {
	int i = 0;
	while (i < NAgencies) {
		printf("%s", list[i]->name);
		printf("%s", list[i]->services->country);
		printf("%s", list[i]->services->travel_conditions);
		printf("%s", list[i]->services->excursion_services);
		printf("%s", list[i]->services->host_service);
		printf("%s", list[i]->services->ticket_price);
		printf("\n");
		i++;
	}
}


void output_data_EZONES(FILE* fptr, TAgency** pointer,char *e_zone[]) {
	int i = 0;
	int j = 0;
	for (i = 0; i < NAgencies; i++) {
		while (j < 20) {
			if (strcmp(pointer[i]->services->country, e_zone[j]) == 0) {
				printf("%s", pointer[i]->name);
				printf("%s", pointer[i]->services->country);
				printf("%s", pointer[i]->services->travel_conditions);
				printf("%s", pointer[i]->services->excursion_services);
				printf("%s", pointer[i]->services->host_service);
				printf("%s", pointer[i]->services->ticket_price);
				printf("\n");
				j = 0;
				break;
			}
			j++;
		}
		j = 0;
	}
}

void free_memory(TAgency** pointer) {
	for (int i = 0; i < NAgencies; i++) {//Freeing up memory from dynamic fields
		free(pointer[i]->services->country);
		free(pointer[i]->services->travel_conditions);
		free(pointer[i]->services->excursion_services);
		free(pointer[i]->services->host_service);
		free(pointer[i]->services->ticket_price);
	}

	for (int i = 0; i < NAgencies; i++) {//Freeing up memory from dynamic structure
		free(pointer[i]->services);
	}
	for (int i = 0; i < NAgencies; i++) {//Freeing up memory from dynamic structure
		free(pointer[i]);
	}
	free(pointer);//freeing up memory massive objects
}
