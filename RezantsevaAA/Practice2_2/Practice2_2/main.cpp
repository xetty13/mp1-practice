#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cars.h"
using namespace std;

int main()
{
	// get path to file with cars
	string filepath = GetFilePath();
	cout << filepath << endl;

	// read file and save info about cars to array
	vector <Car> cars = ReadCarFile(filepath);

	// find oldest car
	Car oldest_car = FindOldestCar(cars);

	// print answer
	cout << oldest_car;

	return 0;
}
//C:\Users\itmm-y23b\Desktop\directory\mp1-practice\RezantsevaAA\Practice2_2\Practice2_2\cars.txt