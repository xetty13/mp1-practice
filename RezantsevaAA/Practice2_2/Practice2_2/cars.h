#ifndef _CARS_H
#define _CARS_H
#include <string>
#include <vector>
using namespace std;

struct Car {
	string brand;
	string color;
	string serial_number;
	string registration_number;
	string count_door;
	string year;
	string price;
};

void PrintCar(Car &car);
string GetFilePath();
Car ReadCarEntity(ifstream& file);
vector <Car>  ReadCarFile(string filepath);

Car FindOldestCar(vector <Car> cars);

#endif _CARS_H
