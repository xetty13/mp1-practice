#pragma once
#include <stdio.h>
#include "prototypes.h"



void allocate_TAgency(TAgency** pointer) {
	int i = 0;
	(*pointer) = new TAgency;//creating a list of travel agencies
	(*pointer)->services = new TService;//creating a service structure for each facility
}

void search_string(ifstream& file) {//look for the first occurrence of the string
next:	
	int i = 0;
	int len;
	int code;
	int status = 0;
	string str;
	getline(file, str, '\n');//count to 0 inclusive
	len = str.length();
	do {
		while (i < len) {
			code = str[i];
			if (((code >= 48) && (code <= 57)) || ((code >= 65) && (code <= 90)) || ((code >= 97) && (code <= 122))) {
				status = 1;//The line is not empty
				break;
			}
			i++;
		}
		if (len == 0) {//This is a bad line
			file.seekg(1, ios_base::cur);
			goto next;
		}
		if (status == 1) {//This is a good line
			file.seekg(-len, ios_base::cur);
		}
		if (status == 0) {//This is a bad line
			file.seekg(1, ios_base::cur);
		}
	} while (status == 0);
}

void file_reader(ifstream& file, TAgency*** list) {
	*(list) = new TAgency* [NAgencies]; //create a dynamic array of objects
	int i = 0;
	for (i = 0; i < NAgencies; i++) {
		allocate_TAgency(&(*list)[i]);//Give the same pointer to create the structure
	}
	for (i = 0; i < NAgencies; i++) {
		search_string(file);
		getline(file,(*list)[i]->name);
		getline(file, (*list)[i]->services->country);
		getline(file, (*list)[i]->services->travel_conditions);
		getline(file, (*list)[i]->services->excursion_services);
		getline(file, (*list)[i]->services->host_service);
		getline(file, (*list)[i]->services->ticket_price);
	}
}
void output_all_data(TAgency** list) {
	int i = 0;
	while (i < NAgencies) {
		cout << list[i]->name << endl;
		cout << list[i]->services->country << endl;
		cout << list[i]->services->travel_conditions << endl;
		cout << list[i]->services->excursion_services << endl;
		cout << list[i]->services->host_service << endl;
		cout << list[i]->services->ticket_price << endl;
		i++;
	}
}

void output_data_EZONES(TAgency** list,string  e_zone[]) {
	int i = 0;
	int j = 0;
	for (i = 0; i < NAgencies; i++) {
		while (j < 20) {
			if (list[i]->services->country == e_zone[j]){
				cout << list[i]->name << endl;
				cout << list[i]->services->country << endl;
				cout << list[i]->services->travel_conditions << endl;
				cout << list[i]->services->excursion_services << endl;
				cout << list[i]->services->host_service << endl;
				cout << list[i]->services->ticket_price << endl;
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
	for (int i = 0; i < NAgencies; i++) {
		delete pointer[i]->services;
	}
	delete[] pointer;
}