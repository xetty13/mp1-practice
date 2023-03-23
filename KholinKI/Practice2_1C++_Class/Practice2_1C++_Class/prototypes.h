#pragma once

#ifndef _prototypes_h
#define _prototypes_h

#include <fstream>
#include <string>
using namespace std;
#define NAgencies 7


class TAgency {
public:
	char* name;
	char* country;
	char* travel_conditions;
	char* excursion_services;
	char* host_service;
	char* ticket_price;
public:
	TAgency(void);
	TAgency(int buffer);
	~TAgency();
	

};


ofstream& operator<<(ofstream& stream, const TAgency& Agency);

void allocate_TAgency(TAgency** pointer);//allocating guide list...
void file_reader(ifstream& file, TAgency*** list);//reading data
void search_string(ifstream& file);
void output_all_data(TAgency** pointer);//all data
void output_data_EZONES(TAgency** pointer, string  e_zone[]);//data about euro zones
void free_memory(TAgency** pointer);

#endif