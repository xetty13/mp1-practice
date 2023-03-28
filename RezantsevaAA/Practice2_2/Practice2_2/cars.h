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

	friend ostream& operator<<(ostream& output_stream, const Car& car);

};

string GetFilePath();

Car ReadCarEntity(ifstream& file); 
Car FindOldestCar(const vector <Car>& cars); 

vector <Car>  ReadCarFile(const string& filepath); 
#endif _CARS_H
