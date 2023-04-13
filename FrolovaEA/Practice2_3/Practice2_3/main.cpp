#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;

int main()
{
    Product* p;

    int size = cntLines("sklad.txt");

    cout << size << endl;

    allocate_stock(p, size);

    fill_sklad(p,size, "sklad.txt");

    find_NULL(p, size);





    free_stock(p);
}
