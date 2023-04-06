#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;

int main()
{

    int size = cntLines("sklad.txt");
    
    Product* p;

    allocate_sklad(p, size);

    fill_sklad(p, size, "sklad.txt");
    find_null(p,size);

    free_sklad(p, size);


}

