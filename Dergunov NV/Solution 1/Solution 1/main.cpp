#include <iostream>
#include "header.h"

int main()
{
    TVector V1, V2;
    std::cin >> V1 >> V2;
    TVector res = V1 + V2;
    std::cout << "Summa: ";
    std::cout << res << std::endl;
    TVector res_min = V1 - V2;
    std::cout << "Rasnost: ";
    std::cout << res_min << std::endl;
    double proizv = V1 * V2;
    std::cout << "Umnojenie: ";
    std::cout << proizv << std::endl;
    return 0;
}
