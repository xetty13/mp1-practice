#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;

int main()
{
    Product* p;
    Date* d;

    int size = cntLines("sklad.txt");

    cout << size << endl;

    allocate_stock(p, d, size);

    fill_sklad(p, size, d, "sklad.txt");
//    fill_sklad(d, size, "sklad.txt");
    find_NULL(p, size,d);





    free_stock(p, d);
}
