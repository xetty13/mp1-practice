#ifndef _CARS_H
#define _CARS_H
#include <string>
#include <vector>
using namespace std;

class Car
{
private:
	string brand;
	string color;
	string serial_number;
	string registration_number;
	string count_door;
	string year;
	string price;
public:
	Car();
	Car(string brand, string color, string serial_number, string registration_number, string count_door, string year, string price);
	bool operator<(const Car& guest_car) const;
	friend std::ostream& operator<<(std::ostream& output_stream, const Car& car);

};


string GetFilePath();
Car ReadCarEntity(ifstream& file);
vector<Car> ReadCarFile(const string& filepath);
Car FindOldestCar(const vector<Car>& cars);

#endif _CARS_H

