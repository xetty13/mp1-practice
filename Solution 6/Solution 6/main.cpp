#include <iostream>
#include <locale.h>
#include "sLib.h"
#include "function.h"
int main(int argc, char** argv)
{
    int button = 0;
    std::string type;
    setlocale(LC_ALL, "ru");
    std::string filename;
    filename = argv[2];
    sLib myLib(atoi(argv[1]), filename);
    do {
        menu();
        std::cin >> button;
        switch (button)
        {
        case 1:
            myLib.printData();
            break;
        case 2:
            std::cout << "Введите вид спорта: ";
            std::cin >> type;
            myLib.printSearch(type);
            break;
        }
    } while (button != 3);
    std::cout << "Хорошего дня!!!";
    return 0;
}