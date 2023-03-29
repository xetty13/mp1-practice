#pragma once
#include <fstream>
#include <iostream>
#include "class TService.h"

using namespace std;


class TAgency {
public:		//дополнить методами
	int num_services;
	int num_agencies;
	TService* services;
	string name;

	TAgency(void);
	TAgency(int num_services,int num_agencies);
	~TAgency();

	int CountAgencies(int num_agencies, ifstream& file);
};