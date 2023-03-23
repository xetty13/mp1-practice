
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "prototypes.h"

int CountAgencies(int num_agencies, FILE* fptr) {
	char str[LEN];
	char* str_p;
	char buffer[LEN] = "List agencies:";
	int i = 0;
	int c = 0;
	while (!feof(fptr)) {
		
		fgets(str, LEN, fptr);
		fseek(fptr, -1, SEEK_CUR);
		if (strncmp(str, buffer, strlen(buffer)) == 0) {
			str_p = str;
			for (i = 0; i < strlen(str) - 1; i++) {
				c = str[i];
				if (c >= 49 && c < 58) {
					num_agencies = atoi(str_p);
					break;
				}
				else str_p++;
			}

		}
		if (num_agencies == 0) {
			fseek(fptr, 1, SEEK_CUR);
		}
		if (num_agencies !=0) {
			break;
		}
	}
	fseek(fptr, 0, SEEK_SET);
	return num_agencies;
}

int* CountTServices(int* num_services, int num_agencies, FILE* fptr) {
	
	char str[LEN];
	char* str_p;
	char buffer[LEN] = "Directions:";
	char* buffer_p = NULL;
	int i, j;
	int c = 0;
	i = j = 0;
	buffer_p = buffer;
	while (j < num_agencies) {
		fgets(str, LEN, fptr);
		//fseek(fptr, -1, SEEK_CUR);
		if (strncmp(str, buffer, strlen(buffer_p)) == 0) {
			str_p = str;
			for (i = 0; i < strlen(str) - 1; i++) {
				c = str[i];
				if (c >= 49 && c < 58) {
					*(num_services + j) = atoi(str_p);
					j++;
					break;
				}
				else str_p++;
			}

		}
		if (num_services == 0) {
			fseek(fptr, 1, SEEK_CUR);
		}
	}
	fseek(fptr, 0, SEEK_SET);
	return num_services;
}

void allocate_TAgency(TAgency** pointer,int num_services) {
	(*pointer) = (TAgency*)malloc(sizeof(TAgency));//creating a list of travel agencies
	(*pointer)->name = (char*)malloc(sizeof(char) * LEN);
	(*pointer)->services = (TService*)malloc(sizeof(TService) * num_services);//creating a service structure for each facility
}

void allocate_TServices(TAgency** ptr,int num_services) {
		int i = 0;
		for (int i = 0; i < num_services; i++) {
			(*ptr)->services[i].country = (char*)malloc(sizeof(char) * LEN);
			(*ptr)->services[i].travel_conditions = (char*)malloc(sizeof(char) * LEN);
			(*ptr)->services[i].excursion_services = (char*)malloc(sizeof(char) * LEN);
			(*ptr)->services[i].host_service = (char*)malloc(sizeof(char) * LEN);
			(*ptr)->services[i].ticket_price = (char*)malloc(sizeof(char) * LEN);
		}
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

void file_reader(FILE * fptr, TAgency *** list,int num_agencies,int* num_services) {
	*(list) = (TAgency**)malloc(sizeof(TAgency*)*num_agencies); //create a dynamic array of objects
	int i = 0;
	int c = 0;
	int j = 0;
	char buffer1[LEN] = "List agencies:";
	char buffer2[LEN] = "Directions:";
	int num;
	for (i = 0; i < num_agencies; i++) {
		num = *(num_services + i);
		allocate_TAgency(&(*list)[i],num);//Give the same pointer to create the structure
	}
	for (i = 0; i < num_agencies; i++) {
		num = *(num_services + i);
		allocate_TServices(&(*list)[i], num);//Give the same pointer to create the structure
	}
	for (i = 0; i < num_agencies; i++) {
		search_string(fptr);
		fseek(fptr, -2, SEEK_CUR);
		fgets((*list)[i]->name, LEN, fptr);
		if ((strncmp((*list)[i]->name, buffer1, strlen(buffer1)) == 0) || (strncmp((*list)[i]->name, buffer2, strlen(buffer2))) == 0) {
			do {
				c = fgetc(fptr);//переделать в функцию
			} while (c == 10);
			fgets((*list)[i]->name, LEN, fptr);
		}
		for (j = 0; j < *(num_services + i); j++) {
			search_string(fptr);
			fseek(fptr, -1, SEEK_CUR);
			if (j == 0) {
				do {
					c = fgetc(fptr);
				} while (c != 10);
			}
			fgets((*list)[i]->services[j].country, LEN, fptr);
			fgets((*list)[i]->services[j].travel_conditions, LEN, fptr);
			fgets((*list)[i]->services[j].excursion_services, LEN, fptr);
			fgets((*list)[i]->services[j].host_service, LEN, fptr);
			fgets((*list)[i]->services[j].ticket_price, LEN, fptr);
		}
	}
}

void output_all_data(FILE* fptr, TAgency** list,int num_agencies,int* num_services) {
	int i = 0;
	int j = 0;
	for (i = 0; i < num_agencies; i++) {
		for (j = 0; j < *(num_services + i); j++) {
			search_string(fptr);
			printf("%s",list[i]->services[j].country);
			printf("%s", list[i]->services[j].travel_conditions);
			printf("%s", list[i]->services[j].excursion_services);
			printf("%s", list[i]->services[j].host_service);//выводит криво
			printf("%s", list[i]->services[j].ticket_price);
			printf("\n");
		}
	}
}

/*
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
*/