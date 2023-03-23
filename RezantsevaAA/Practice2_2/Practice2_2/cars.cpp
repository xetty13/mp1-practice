#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cars.h"
using namespace std;

string GetFilePath()
{
	string filepath;
	cout << "Enter file path: ";
	cin >> filepath;
	return filepath;
}

Car ReadCarEntity(ifstream& file) {
	string car_brand;
	getline(file, car_brand);

	string car_color;
	getline(file, car_color);

	string car_serial_number;
	getline(file, car_serial_number);

	string car_registration_number;
	getline(file, car_registration_number);

	string car_count_door;
	getline(file, car_count_door);

	string car_year;
	getline(file, car_year);

	string car_price;
	getline(file, car_price);

	Car new_car = { car_brand, car_color, car_serial_number, car_registration_number, car_count_door, car_year, car_price };
	return new_car;
}

vector <Car>  ReadCarFile(string filepath) {

	ifstream file;
	file.open(filepath);
	if (!file.is_open()) { // check if the file can be opened
		throw "Failed to open file\n";
	}

	vector <Car> cars;


	// we assume that the file contains information about at least one car
	string tmp;
	while (1)
	{
		Car current_car = ReadCarEntity(file);
		cars.push_back(current_car);
		getline(file, tmp);
		if (file.eof())
		{
			break;
		}
	}
	file.close();
	return cars;
}

Car FindOldestCar(vector <Car> cars) {
	Car oldest_car = cars[0];
	for (int i = 1; i < cars.size(); ++i) {
		if (cars[i].year < oldest_car.year) {
			oldest_car = cars[i];
		}
	}
	return oldest_car;
}

void PrintCar(Car &car)
{
	cout << "Brand: " << car.brand << endl;
	cout << "Color: " << car.color << endl;
	cout << "Serial number: " << car.serial_number << endl;
	cout << "Regestrarion number: " << car.registration_number << endl;
	cout << "Numbers of doors: " << car.count_door << endl;
	cout << "Year of car manufacture: " << car.year << endl;
	cout << "Price: " << car.price << endl;
}