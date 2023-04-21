#ifndef _class TAgency_
#define _class TAgency_
#include <fstream>
#include "class TService.h"

using namespace std;


class TAgency {
	friend  ostream& operator<<(ostream& stream, const TAgency& list);
public:

	int num_services;
	TService* services;
	string name;	
};
#endif