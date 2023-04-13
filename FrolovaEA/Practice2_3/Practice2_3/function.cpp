#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "header.h"
using namespace std;

Product::Product() 
{
	name = "";
	unit = "";
	price = 0.0f;
	number = 0;
    data.day = 0;
    data.month = 0;
    data.year = 0;
}

Product::Product(string name, string unit, double price, int number, int day, int month, int year)
{
	this->name = name;
	this->unit = unit;
	this->price = price;
	this->number = number;
    this->data.day = day;
    this->data.month = month;
    this->data.year = year;

}

int cntLines(const string filename)
{

	string line;
	int f = 0;
	ifstream file(filename); // окрываем файл для чтения

	if (!file.is_open())
		throw "File open error";

	if (file.is_open())
	{
		while (getline(file, line))
		{
//			            cout << line << endl;
			f++;
		}
	}
	return f;

}

void allocate_stock(Product*& p, int size)
{
	p = new Product[size];
}

void Product::SetRes(string _name, string _unit, double _price, int _number, int _day, int _month, int _year)
{
    name = _name;
    unit = _unit;
    price = _price;
    number = _number;
    data.day = _day;
    data.month = _month;
    data.year = _year;

}

void fill_sklad(Product*& p, int size, const string filename)
{
    string line;
    char str[200];
    char* istr;
    ifstream file(filename); // окрываем файл для чтения
    int j = 0, flag = 0;

    if (!file.is_open())
        throw "File open error";

    if (file.is_open())
    {
        while (j != size) {

            while (getline(file, line))
            {
                string _name = " ";
                string _unit=" ";
                double _price=0;
                int _number=0;
                int _day=0;
                int _month=0;
                int _year=0;

                strcpy(str, line.c_str());
                istr = strtok(str, ";/");
                flag++;
                if (flag == 1) {
                    _name = string(istr);
//                                        cout << _name << endl;
                }
                while (istr != NULL)
                {
                    istr = strtok(NULL, ";/");
                    flag++;

                    if (flag == 2) {
                        _unit = string(istr);
//                                                cout << _unit << endl;
                    }

                    if (flag == 3) {
                        _price = atoi(istr);
//                                                cout << _price << endl;                         
                    }

                    if (flag == 4) {
                        _number = atoi(istr);
//                                                cout << _number << endl;              
                    }

                    if (flag == 5) {
                        _day = atoi(istr);
//                                                cout << _day << endl;
                    }

                    if (flag == 6) {
                        _month = atoi(istr);
//                                                cout << _month << endl;                
                    }

                    if (flag == 7) {
                        _year = atoi(istr);
//                                                cout << _year << endl;  
                        p[j].SetRes(_name, _unit, _price, _number, _day, _month, _year);
                    }


                }
                flag = 0;
                j++;
            }

        }




    }

    file.close();     // закрываем файл


}

ostream& operator <<(ostream& stream, const Product& p) {
    stream << p.name << " " << p.unit << " " << p.price<<" "<<p.number <<" "<<setw(2) << setfill('0') << p.data.day << "." << setw(2) << setfill('0') << p.data.month << "." << p.data.year << endl;
    return stream;
}

void find_NULL(Product*& p, int size) {
    for (int i = 0; i < size; i++)
    {
        if (p[i].number == 0) {
            cout << p[i].name << "\t" << p[i].unit << "\t" << p[i].price << "\t" << p[i].number<<"\t";
            cout<<setw(2)<<setfill('0')<<p[i].data.day << "." << setw(2) << setfill('0')<< p[i].data.month << "." << p[i].data.year << endl;

        }
    }
}


void free_stock(Product*& p)
{
	delete[]p;
}