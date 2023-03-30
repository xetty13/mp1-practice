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
}

Product::Product(string name, string unit, double price, int number)
{
	this->name = name;
	this->unit = unit;
	this->price = price;
	this->number = number;

}

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
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

void allocate_stock(Product*& p, Date*& d, int size)
{
	p = new Product[size];
	d = new Date[size];
}
/*
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
                strcpy(str, line.c_str());
                istr = strtok(str, ";/");
                flag++;
                if (flag == 1) {
                    (p[j].name) = string(istr);
//                                        cout << p[j].name << endl;
                }
                while (istr != NULL)
                {
                    istr = strtok(NULL, ";/");
                    flag++;

                    if (flag == 2) {
                        (p[j].unit) = string(istr);
//                                                cout << p[j].unit << endl;
                    }

                    if (flag == 3) {
                        p[j].price = atoi(istr);
//                                                cout << p[j].price << endl;                         
                    }

                    if (flag == 4) {
                        p[j].number = atoi(istr);
//                                                cout << p[j].number << endl;              
                    }
                }
                flag = 0;
                j++;
            }
        }
    }

    file.close();     // закрываем файл


}
*/
/*
void fill_sklad(Date*& d, int size, const string filename)
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
                strcpy(str, line.c_str());
                istr = strtok(str, ";/");
                flag++;
                
                while (istr != NULL)
                {
                    istr = strtok(NULL, ";/");
                    flag++;

                    

                    if (flag == 5) {
                        d[j].day = atoi(istr);
//                                                cout << d[j].day << endl;
                    }

                    if (flag == 6) {
                        d[j].month = atoi(istr);
//                                                cout << d[j].month << endl;                
                    }

                    if (flag == 7) {
                        d[j].year = atoi(istr);
//                                                cout << d[j].year << endl;                
                    }


                }
                flag = 0;
                j++;
            }

        }

    }

    file.close();     // закрываем файл


}
*/

void fill_sklad(Product*& p, int size, Date*& d, const string filename)
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
                strcpy(str, line.c_str());
                istr = strtok(str, ";/");
                flag++;
                if (flag == 1) {
                    (p[j].name) = string(istr);
                //                        cout << p[j].name << endl;
                }
                while (istr != NULL)
                {
                    istr = strtok(NULL, ";/");
                    flag++;

                    if (flag == 2) {
                        (p[j].unit) = string(istr);
                    //                            cout << p[j].unit << endl;
                    }

                    if (flag == 3) {
                        p[j].price = atoi(istr);
                    //                            cout << p[j].price << endl;                         
                    }

                    if (flag == 4) {
                        p[j].number = atoi(istr);
                    //                            cout << p[j].number << endl;              
                    }

                    if (flag == 5) {
                        d[j].day = atoi(istr);
                    //                            cout << d[j].day << endl;
                    }

                    if (flag == 6) {
                        d[j].month = atoi(istr);
                    //                            cout << d[j].month << endl;                
                    }

                    if (flag == 7) {
                        d[j].year = atoi(istr);
                    //                            cout << d[j].year << endl;                
                    }


                }
                flag = 0;
                j++;
            }

        }




    }

    file.close();     // закрываем файл


}

ostream& operator <<(ostream& stream,const Product& prod) {
    stream << prod.name << "\t" << prod.unit << "\t" << prod.price << "\t" << prod.number << endl;
    return stream;
}

ostream& operator <<(ostream& stream, const Date& prod) {
    stream << prod.day << "." << prod.month << "." << prod.year << endl;
    return stream;
}

void find_NULL(Product*& p, int size,Date*&d) {
    for (int i = 0; i < size; i++)
    {
        if (p[i].number == 0) {
            cout << p[i].name << "\t" << p[i].unit << "\t" << p[i].price << "\t" << p[i].number<<"\t";
            cout<<d[i].day << "." << d[i].month << "." << d[i].year << endl;

        }
    }
}


void free_stock(Product*& p, Date*& d)
{
	delete[]p;
	delete[]d;
}