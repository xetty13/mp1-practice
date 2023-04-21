#pragma once
#include "class TAgency.h"
#include <fstream>
#include <iostream>

using namespace std;

class TAgencyBook
{
public:
	ifstream file;
	TAgency* agencies;
    int count;
	TAgencyBook(TAgency* agencies, string path);
	TAgencyBook(const TAgencyBook& object);
	~TAgencyBook();

	int  CountAgencies(ifstream& file); //count agencies
    int* CountTServices(ifstream& file);//count directions
    void allocate_TAgency(TAgency& object, int count_services);//allocating guide list...
    void file_reader(ifstream& file);
    void search_string(ifstream& file);
    void show_all_data();//all data
    int* counter_euro_countries();//count euro countries
    void find_euro_countries();//find european countries and create european massive
    void output_data_EZONES();//output european massive!:)
};