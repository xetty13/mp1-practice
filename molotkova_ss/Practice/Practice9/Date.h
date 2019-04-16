#pragma once
class Date
{
private:
	int day;
	int month;
	int year;

public:
	void PrintDate();
	Date();
	Date(int day, int month, int year);
	~Date();
	bool operator == (const Date &date1)const;
};
