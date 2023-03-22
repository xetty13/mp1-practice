#ifndef _HEAD
#define _HEAD
using namespace std;

struct Owner
{
	string name;
	string surname;
	string patronymic;
	string date;
	string carnum;
	unsigned long gibdd;
	string phnum;
	unsigned long tehpas;
};

Owner* read_inf(int& n);
void print_inf(Owner* o, int n);
void search_owner(Owner* o, int n);
#endif