#ifndef _class TAgency_
#define _class TAgency_
#include <fstream>
#include "class TService.h"

using namespace std;


class TAgency {
	friend const ostream& operator<<(ostream& stream, const TAgency& list);
public:

	int num_services;
	TService* services;
	string name;

	TAgency(void);
	TAgency(int count_services);

	int CountAgencies(ifstream& file);
	int* CountTServices(ifstream& file);
	int file_reader(ifstream& file, TAgency**& list);
	int* counter_euro_countries(TAgency**& list, int num_agencies);//count euro countries
	TAgency** find_euro_countries(TAgency**& list, int num_agencies);//find european countries and create european massive
	void output_all_data(TAgency**& list, int num_agencies);//all data
	void output_data_EZONES(TAgency**& new_list, int num_agencies);//output european massive!:)
	void free_memory(TAgency**& pointer, int num_agencies);
	void free_european_memory(TAgency**& euro_pointer, int num_agencies);
};
#endif