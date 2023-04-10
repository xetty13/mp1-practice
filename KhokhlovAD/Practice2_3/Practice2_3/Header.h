#ifndef _HEADER
#define _HEADER
using namespace std;

class Data
{
private:
	int day;
	int month;
	int year;
public:
	int getMonth()const { return month; }            
	void setMonth(int month1) { month = month1; } 

	int getDay()const { return day; }
	void setDay(int day1) { day = day1; } 

	int getYear()const { return year; }
	void setYear(int year1) { year = year1; }

	Data() { day = 0; month = 0; year = 0; }
	Data(int d, int m, int y) { day = d; month = m; year = y; }
};

class Owner
{
private:
	string name;
	string surname;
	string patronymic;
	string carnum;
	unsigned long gibdd;
	string phnum;
	unsigned long tehpas;
	string data1;
public:
	Data date;
	string getData()const { return data1; }
	friend istream& operator>>(istream& in, Owner& o);
	friend ostream& operator<<(ostream& out, const Owner& o);
	unsigned long getGibdd()const { return gibdd; }
};

Owner* read_inf(int& n);
void print_inf(Owner* o, int n);
Owner* search_owner(Owner* o, int& n);
#endif