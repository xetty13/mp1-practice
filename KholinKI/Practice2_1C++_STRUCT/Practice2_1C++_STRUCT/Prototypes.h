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
void file_reader(ifstream& file, TAgency**& list);//reading data
void search_string(ifstream& file);
void output_all_data(ifstream& file,TAgency**& pointer);//all data
void output_data_EZONES(ifstream& file,TAgency**& list,const string*& EU);//data about euro zones
void free_memory(ifstream& file, TAgency**& pointer);
#endif