#include <stdio.h>
#include "cars.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    // get path to file with cars
    char* path = getPath();
    puts(path);

    // read file and save info about cars to array
    int count_of_cars;
    Car* cars = ReadCarFile(path, &count_of_cars);

    // find oldest car
    Car oldest_car = FindOldestCar(cars, count_of_cars);

    // print answer
    PrintCar(oldest_car);
    return 0;
}