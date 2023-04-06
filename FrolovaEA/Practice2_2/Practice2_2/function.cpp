#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "header.h"
using namespace std;

int cntLines(const string &filename) {

    string line;
    int f = 0;
    ifstream file(filename); // окрываем файл для чтения
    
    if (!file.is_open())
        throw "File open error";                          

    if (file.is_open())
    {
        while (getline(file, line))
        {
//            cout << line << endl;
            f++;
        }
    }

    file.close();     // закрываем файл
//    cout << f << endl;

//    cout << "End of program" << endl;
    return f;

}

void allocate_sklad(Product*& p, int size)
{
    p = new Product[size];
}

void fill_sklad(Product*& p, int size, const string& filename)
{
    string line;
    char str[200];
    char* istr;
    ifstream file(filename); // окрываем файл для чтения
    int j = 0,flag=0;

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
                    (p[j].name)=string( istr);
;
                }
                while (istr != NULL)
                {
                    istr = strtok(NULL, ";/");
                    flag++;

                    if (flag == 2) {
                        (p[j].unit)=string(istr);

                    }

                    if (flag == 3) {
                        p[j].price = atoi(istr);
                        
                    }

                    if (flag == 4) {
                        p[j].number = atoi(istr);
             
                    }

                    if (flag == 5) {
                        p[j].data.day = atoi(istr);

                    }

                    if (flag == 6) {
                        p[j].data.month = atoi(istr);
                
                    }

                    if (flag == 7) {
                        p[j].data.year = atoi(istr);
                
                    }


                }
                flag = 0;
                j++;
            }

            }
            

            

    }

    file.close();     
   
   
}

void find_null(Product*& p, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (p[i].number == 0) {
            cout << p[i].name << "\t" << p[i].unit << "\t" << p[i].price << "\t" << p[i].number << "\t";
            cout<< p[i].data.day << "." << p[i].data.month << "."<< p[i].data.year << endl;
            

        }
    }
}

void free_sklad(Product*& p, int size)
{
    delete[] p;
}

