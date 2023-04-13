
#pragma once
#ifndef _prototypes_h
#define _prototypes_h

#include <fstream>
#include <string>
using namespace std;

struct TService// list of service
{
	string country;
	string travel_conditions;
	string excursion_services;
	string host_service;
	string ticket_price;
};

struct TAgency // Tourist agency
{
	int num_services;
	string name;
	TService* services;
};

int CountAgencies(ifstream& fptr); //count agencies
int* CountTServices(ifstream& file);//count directions

void allocate_TAgency(TAgency*& pointer, int count_services);//allocating guide list...
int file_reader(ifstream& file, TAgency**& list);//reading data
void search_string(ifstream& file);
void output_all_data(TAgency**& pointer, int num_agencies);//all data
int* counter_euro_countries(TAgency**& list, int num_agencies);//count euro countries
TAgency** find_euro_countries(TAgency**& list, int num_agencies);//find european countries and create european massive
void output_data_EZONES(TAgency**& new_list, int num_agencies);//output european massive!:)
ostream& operator<<(ostream& stream, const TAgency& obj);
void free_memory(TAgency**& pointer, int num_agencies);//delete memory old massive
void free_european_memory(TAgency**& euro_pointer, int num_agencies);//delete memore new massive
#endif