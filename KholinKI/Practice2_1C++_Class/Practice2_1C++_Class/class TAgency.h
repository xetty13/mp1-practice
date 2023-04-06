#ifndef _class TAgency_
#define _class TAgency_
#include <fstream>
#include "class TService.h"

using namespace std;


class TAgency {
public:

	int num_services;
	TService* services;
	string name;

	TAgency(void);
	TAgency(int count_services);
	~TAgency();


	int file_reader(ifstream& file, TAgency**& list);
	void output_all_data(TAgency**& list,int num_agencies);//all data
	void output_data_EZONES(TAgency**& list, int num_agencies);
	friend const ostream& operator<<(ostream& stream, const TAgency**& list);

};
#endif