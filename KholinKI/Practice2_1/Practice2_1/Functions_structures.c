
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "prototypes.h"


#define NUM_EUROPE_COUNTRIES 20

char euro_zone[NUM_EUROPE_COUNTRIES][15] = {//list of eurozone countries
	"Austria\n",
	"Belgium\n",
	"Cyprus\n",
	"Estonia\n",
	"Finland\n",
	"France\n",
	"Germany\n",
	"Greece\n",
	"Ireland\n",
	"Italy\n",
	"Latvia\n",
	"Lithuania\n",
	"Luxembourg\n",
	"Malta\n",
	"Netherlands\n",
	"Portugal\n",
	"Slovakia\n",
	"Slovenia\n",
	"Croatia\n"
};


int CountAgencies(FILE* fptr) {
	int num_agencies =0;
	char str[LEN];
	char* str_p;
	char buffer[LEN] = "List agencies:";
	int i = 0;
	int q = 1;
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

int* CountTServices(FILE* fptr) {
	int num_agencies;
	int* num_services;
	char str[LEN];
	char* str_p;
	char buffer[LEN] = "Directions:";
	char* buffer_p;
	int i, j;
	int len;
	int c = 0;
	i = j = 0;
	buffer_p = buffer;
	num_agencies = CountAgencies(fptr);
	num_services = (int*)malloc(sizeof(int) * num_agencies);
	for (i = 0; i < num_agencies; i++) {
		num_services[i] = 0;
	}
	while (j < num_agencies) {
		fgets(str, LEN, fptr);
		fseek(fptr, -1, SEEK_CUR);
		len = strlen(buffer_p);
		if (strncmp(str, buffer, len) == 0) {
			str_p = str;
			for (i = 0; i < strlen(str) - 1; i++) {
				c = str[i];
				if (c >= 49 && c < 58) {
					num_services[j] = atoi(str_p);
					j++;
					break;
				}
				else str_p++;
			}

		}
		if (num_services[j] == 0) {
			fseek(fptr, 1, SEEK_CUR);
		}
	}
	fseek(fptr, 0, SEEK_SET);
	return num_services;
}

void allocate_TAgency(TAgency** pointer) {
	(*pointer) = (TAgency*)malloc(sizeof(TAgency));//creating a list of travel agencies
	(*pointer)->name = (char*)malloc(sizeof(char) * LEN);
}

void allocate_TServices(TAgency* ptr, int count_services) {
		ptr->num_services = count_services;
		ptr->services = (TService*)malloc(sizeof(TService) * count_services);//creating a service structure for each facility
		for (int i = 0; i < ptr->num_services; i++) {
			ptr->services[i].country = (char*)malloc(sizeof(char) * LEN);
			ptr->services[i].travel_conditions = (char*)malloc(sizeof(char) * LEN);
			ptr->services[i].excursion_services = (char*)malloc(sizeof(char) * LEN);
			ptr->services[i].host_service = (char*)malloc(sizeof(char) * LEN);
			ptr->services[i].ticket_price = (char*)malloc(sizeof(char) * LEN);
		}
}


void search_string(FILE* fptr) {//look for the first occurrence of the string
	int i = 0;
	char c[LEN];
	int len;
	fgets(c, LEN, fptr);
			if (c[0] == 10) {
				do {
					fgets(c, LEN, fptr);
				} while (c[0] == 10);
				len = strlen(c);
				fseek(fptr, -len-1, SEEK_CUR);
	}
			else { len = strlen(c); fseek(fptr, -len - 1, SEEK_CUR); }
}

int file_reader(FILE * fptr, TAgency *** list) {
	int num_agencies = CountAgencies(fptr);
	int* num_services = CountTServices(fptr);
	*(list) = (TAgency**)malloc(sizeof(TAgency*)*num_agencies); //create a dynamic array of objects
	int i = 0;
	int c = 0;
	int j = 0;
	const char buffer1[LEN] = "List agencies:";
	const char buffer2[LEN] = "Directions:";
	int num;
	for (i = 0; i < num_agencies; i++) {
		allocate_TAgency(&(*list)[i]);//Give the same pointer to create the structure
	}
	for (i = 0; i < num_agencies; i++) {
		allocate_TServices((*list)[i], num_services[i]);//Give the same pointer to create the structure
	}
	for (i = 0; i < num_agencies; i++) {
		search_string(fptr);
		fgets((*list)[i]->name, LEN, fptr);
		if ((strncmp((*list)[i]->name, buffer1, strlen(buffer1)) == 0) || (strncmp((*list)[i]->name, buffer2, strlen(buffer2))) == 0) {
			do {
				c = fgetc(fptr);
			} while (c == 10);
			fseek(fptr, -1, SEEK_CUR);
			fgets((*list)[i]->name, LEN, fptr);
		}
		for (j = 0; j < (*list)[i]->num_services; j++) {
			search_string(fptr);
			if (j==0) {
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
	fseek(fptr, 0, SEEK_SET);
	free(num_services);
	return num_agencies;
}

void output_all_data(FILE* fptr, TAgency** list, int num_agencies) {
	int i = 0;
	int j = 0;
	for (i = 0; i < num_agencies; i++) {
		printf("%s", list[i]->name);
		for (j = 0; j < list[i]->num_services; j++) {
			search_string(fptr);
			printf("%s",list[i]->services[j].country);
			printf("%s", list[i]->services[j].travel_conditions);
			printf("%s", list[i]->services[j].excursion_services);
			printf("%s", list[i]->services[j].host_service);
			printf("%s", list[i]->services[j].ticket_price);
			printf("\n");
		}
	}
}


void output_data_EZONES(FILE* fptr, TAgency** list, int num_agencies) {
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < num_agencies; i++) {//going over the TAgency
		printf("%s", list[i]->name);
		for (j = 0; j < list[i]->num_services;j++) {//going over the TServices
			for (k = 0; k < NUM_EUROPE_COUNTRIES; k++) {//scanning base of data 
				if (strcmp(list[i]->services[j].country, euro_zone[k]) == 0) {
					printf("%s", list[i]->services[j].country);
					printf("%s", list[i]->services[j].travel_conditions);
					printf("%s", list[i]->services[j].excursion_services);
					printf("%s", list[i]->services[j].host_service);
					printf("%s", list[i]->services[j].ticket_price);
					printf("\n");
				}
				if (k == NUM_EUROPE_COUNTRIES && list[i]->num_services == 1) {
					printf("(No suitable destination found!)");
				}
			}
		}
	}
}

void free_memory(TAgency** pointer, int num_agencies){
	int i, j;
	for ( i = 0; i < num_agencies; i++) {//Freeing up memory from dynamic fields
		for (j = 0; j < pointer[i]->num_services; j++) {
			free(pointer[i]->services[j].country);
			free(pointer[i]->services[j].travel_conditions);
			free(pointer[i]->services[j].excursion_services);
			free(pointer[i]->services[j].host_service);
			free(pointer[i]->services[j].ticket_price);
		}
	}

	for (i = 0; i < num_agencies; i++) {
		free(pointer[i]->name);
		free(pointer[i]->services);//massive  TService
		free(pointer[i]);//object	
	}
	free(pointer);//freeing up memory massive pointers
}
