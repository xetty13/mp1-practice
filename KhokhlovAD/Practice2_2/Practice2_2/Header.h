#ifndef _HEAD
#define _HEAD
using namespace std;

struct Data
{
	string day;
	string month;
	string year;
};
struct Owner
{
	string name;
	string surname;
	string patronymic;
	Data date;		
	string carnum;
	unsigned long gibdd;
	string phnum;
	unsigned long tehpas;
	friend istream& operator>>(istream& in, Owner& o);
	friend ostream& operator<<(ostream& out, const Owner& o);
};

Owner* read_inf(int& n);
void print_inf(Owner* o, int n);
Owner* search_owner(Owner* o, int& n);
#endif