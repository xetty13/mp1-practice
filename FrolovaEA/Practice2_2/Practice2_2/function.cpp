#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "header.h"
using namespace std;

int cntLines(const string filename) {

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

void allocate_sklad(Product*& p, Date*& d, int size)
{
    p = new Product[size];
    d = new Date[size];
}


/*
void fill_sklad(Product*& p, Date*& d, int size,const string filename)
{
    int flag = 0;
    ifstream file(filename);
    for (int i = 0; i < size; i++)
    {
        string line{};

        while ((getline(file >> ws, line, ';')) && (flag < 5))
        {
            cout << "flag=" << flag << endl;



            if (flag == 0)
            {
                p[i].name = line;
                cout << p[i].name << endl;

            }

/*            if (flag == 1)
            {
                p[i].unit = line;
                cout << p[i].unit << endl;
            }

            if (flag == 2)
            {
                p[i].price = stof(line);
                cout << p[i].price << endl;
            }

            if (flag == 3)
            {
                p[i].number = stoi(line);
                cout << p[i].number << endl;
            }
            if (flag == 4)
            {
                cout << "ok" << endl;
            }
            flag++;

        }
        flag = 0;

    }
    file.close();

}
*/



void fill_sklad(Product*& p, Date*& d, int size, const string filename)
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
                    //                    cout << p[j].name << endl;
                }
                while (istr != NULL)
                {
                    istr = strtok(NULL, ";/");
                    flag++;

                    if (flag == 2) {
                        (p[j].unit) = string(istr);
                        //                        cout << p[j].unit << endl;
                    }

                    if (flag == 3) {
                        p[j].price = atoi(istr);
                        //                        cout << p[j].price << endl;                         
                    }

                    if (flag == 4) {
                        p[j].number = atoi(istr);
                        //                        cout << p[j].number << endl;              
                    }

                    if (flag == 5) {
                        d[j].day = atoi(istr);
                        //                        cout << d[j].day << endl;
                    }

                    if (flag == 6) {
                        d[j].month = atoi(istr);
                        //                        cout << d[j].month << endl;                
                    }

                    if (flag == 7) {
                        d[j].year = atoi(istr);
                        //                        cout << d[j].year << endl;                
                    }


                }
                flag = 0;
                j++;
            }

        }




    }

    file.close();     // закрываем файл


}

void find_null(Product*& p, Date*& d, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (p[i].number == 0) {
            cout << p[i].name << "\t" << p[i].unit << "\t" << p[i].price << "\t" << p[i].number << "\t";
            cout << d[i].day << "." << d[i].month << "." << d[i].year << endl;


        }
    }
}

void free_sklad(Product*& p, Date*& d, int size)
{
    delete[] d;
    delete[] p;
}


