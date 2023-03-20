#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "prototypes.h"



TAgency* allocate_TAgency(TAgency** pointer) {
	int i = 0;
	(*pointer) = new TAgency[NAgencies];//creating a list of travel agencies
	for (i = 0; i < NAgencies; i++) {//allocating
		(*pointer)[i].name = new char[LEN];//creating names
	}
	for (i = 0; i < NAgencies; i++) {
		(*pointer)[i].services = new TService;//creating a service structure for each facility
	}
	return (*pointer);
}

void allocate_TServices(TAgency** ptr) {
	int i = 0;
	for (i = 0; i < NAgencies; i++) {
		(*ptr)[i].services->country = new char[LEN];
		(*ptr)[i].services->travel_conditions = new char[LEN];
		(*ptr)[i].services->excursion_services = new char[LEN];
		(*ptr)[i].services->host_service = new char[LEN];
		(*ptr)[i].services->ticket_price = new char[LEN];
	}
}


void search_string(FILE* fptr) {
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

void file_reader(FILE* fptr, TAgency** list) {
	int i = 0;
	for (i = 0; i < NAgencies; i++) {
		search_string(fptr);
		fseek(fptr, -1, SEEK_CUR);
		fgets((*list)[i].name, LEN, fptr);
		fgets((*list)[i].services->country, LEN, fptr);
		fgets((*list)[i].services->travel_conditions, LEN, fptr);
		fgets((*list)[i].services->excursion_services, LEN, fptr);
		fgets((*list)[i].services->host_service, LEN, fptr);
		fgets(((*list)[i].services->ticket_price), LEN, fptr);
	}
}
void output_all_data(FILE* fptr, TAgency** list) {
	int i = 0;
	while (i < NAgencies) {
		printf("%s", (*list)[i].name);
		printf("%s", (*list)[i].services->country);
		printf("%s", (*list)[i].services->travel_conditions);
		printf("%s", (*list)[i].services->excursion_services);
		printf("%s", (*list)[i].services->host_service);
		printf("%s", (*list)[i].services->ticket_price);
		printf("\n");
		i++;
	}
}

void free_memory(TAgency** pointer) {
	for (int i = 0; i < NAgencies; i++) {
		delete[](*pointer)[i].services->country;
		delete[](*pointer)[i].services->travel_conditions;
		delete[](*pointer)[i].services->excursion_services;
		delete[](*pointer)[i].services->host_service;
		delete[](*pointer)[i].services->ticket_price;//need int massive
	}
	for (int i = 0; i < NAgencies; i++) {
		delete[](*pointer)[i].services;
	}
	delete[] (*pointer);
}
/*
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
*/