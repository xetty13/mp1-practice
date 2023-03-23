#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;

int main()
{

    int size = cntLines("sklad.txt");
    
    Product* p = new Product[size];
    Date* d = new Date[size];

    fill_sklad(p, d, size, "sklad.txt");
    find_null(p,d,size);


    delete[] d;
    delete[] p;

}

