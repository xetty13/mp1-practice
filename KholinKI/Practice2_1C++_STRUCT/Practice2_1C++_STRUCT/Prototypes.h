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
	string name;
	TService* services;
};

int CountAgencies(int num_agencies, ifstream& fptr); //count agencies
int* CountTServices(int* num_services, int num_agencies, ifstream& file);//count directions

void allocate_TAgency(TAgency*& pointer, int num_services);//allocating guide list...
void file_reader(ifstream& file, TAgency**& list, int num_agencies, int*& num_services);//reading data
void search_string(ifstream& file);
void output_all_data(TAgency**& pointer,int num_agencies,int*& num_services);//all data
void output_data_EZONES(TAgency** list, string  e_zone[], int num_agencies, int*& num_services);//data about euro zones
void free_memory(TAgency**& pointer,int num_agencies,int*& num_services);

#endif