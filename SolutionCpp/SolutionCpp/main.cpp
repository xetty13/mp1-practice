#include <iostream>
#include <locale.h>
#include "sLib.h"
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");
    std::string filename;
    filename = argv[2];
    std::cout << filename;
    sLib sLib(atoi(argv[1]),filename);
    return 0;
}