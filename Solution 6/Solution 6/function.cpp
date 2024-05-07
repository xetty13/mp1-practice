#include "function.h"

void menu()
{
    setlocale(LC_ALL, "ru");
    std::cout << "=================" << std::endl;
    std::cout << "Выберите подходящий режим: " << std::endl;
    std::cout << "1. Вывести весь список спортсменов" << std::endl;
    std::cout << "2. Вывести рекордсмена в определенном виде спорта" << std::endl;
    std::cout << "3. Выйти из программы" << std::endl;
    std::cout << "=================" << std::endl;
    std::cout << "Введите Ваш выбор: ";
}