#ifndef _prototypes_h
#define _prototypes_h

#include <fstream>
#include <string>
using namespace std;
#define NAgencies 7
#define buffer 256

typedef struct// list of service
{
	string country;
	string travel_conditions;
	string excursion_services;
	string host_service;
	string ticket_price;
}TService;

typedef struct // Tourist agency
{
	string name;
	TService* services;
}TAgency;


void allocate_TAgency(TAgency** pointer);//allocating guide list...
void file_reader(ifstream& file, TAgency*** list);//reading data
void search_string(ifstream& file);
void output_all_data(TAgency** pointer);//all data
void output_data_EZONES(TAgency** pointer, string  e_zone[]);//data about euro zones
void free_memory(TAgency** pointer);

#endif