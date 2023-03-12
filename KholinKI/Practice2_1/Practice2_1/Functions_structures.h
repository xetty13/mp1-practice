#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "prototypes.h"
#define MAX 1000
#define q_TAgences 7



list_ag* file_reader(FILE* fptr, list_ag** my_objects) {
	int i = 0;
	int j = 0;
	char c = 32;
	(*my_objects) = (list_ag*)malloc(sizeof(list_ag) * 7);
	while (i < q_TAgences) {
		if (i == i) {
			fscanf(fptr, "%c", &c);
			if (c == 10) {
				do {
					fseek(fptr, 1, SEEK_CUR);
					fscanf(fptr, "%c", &c);
				} while (c == 10);
			}
		}
		fseek(fptr, -2, SEEK_CUR);
		fgets((*my_objects)[i].INFO.name_travel_agencies, 25, fptr);
		fgets((*my_objects)[i].INFO.country, 15, fptr);
		fgets((*my_objects)[i].INFO.travel_conditions, 500, fptr);
		fgets((*my_objects)[i].INFO.excursion_services, 500, fptr);
		fgets((*my_objects)[i].INFO.host_service, 300, fptr);
		fgets((*my_objects)[i].INFO.ticket_price, 20, fptr);
		i++;
	}
	return (*my_objects);
}
void output_data_file(FILE* fptr, list_ag** pointer) {
	int i = 0;
	while (i < q_TAgences) {
		printf("%s", (*pointer)[i].INFO.name_travel_agencies);
		printf("%s", (*pointer)[i].INFO.country);
		printf("%s", (*pointer)[i].INFO.travel_conditions);
		printf("%s", (*pointer)[i].INFO.excursion_services);
		printf("%s", (*pointer)[i].INFO.host_service);
		printf("%s", (*pointer)[i].INFO.ticket_price);
		printf("\n");
		i++;
	}
}

void output_data_EZONES(FILE* fptr, list_ag** pointer,char *e_zone[]) {
	int i = 0;
	int j = 0;
	for (i = 0; i < q_TAgences; i++) {
		while (j < 20) {
			if (strcmp((*pointer)[i].INFO.country, e_zone[j]) == 0) {
				printf("%s", (*pointer)[i].INFO.name_travel_agencies);
				printf("%s", (*pointer)[i].INFO.country);
				printf("%s", (*pointer)[i].INFO.travel_conditions);
				printf("%s", (*pointer)[i].INFO.excursion_services);
				printf("%s", (*pointer)[i].INFO.host_service);
				printf("%s", (*pointer)[i].INFO.ticket_price);
				printf("\n");
				j = 0;
				break;
			}
			j++;
		}
		j = 0;
	}
}

void free_memory(list_ag **pointer) {
	free((*pointer));
}

