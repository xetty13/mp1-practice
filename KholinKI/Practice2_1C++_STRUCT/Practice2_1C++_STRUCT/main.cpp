#include <iostream>
#include <clocale>
#include <fstream>
#include "Impl.h"
#include <string>


using namespace std;

char euro_zone[20][15] = {//list of eurozone countries
	"Austria\n",
	"Belgium\n",
	"Cyprus\n",
	"Estonia\n",
	"Finland\n",
	"France\n",
	"Germany\n",
	"Greece\n",
	"Ireland\n",
	"Italy\n",
	"Latvia\n",
	"Lithuania\n",
	"Luxembourg\n",
	"Malta\n",
	"Netherlands\n",
	"Portugal\n",
	"Slovakia\n",
	"Slovenia\n",
	"Croatia\n"
};

int main(int argc, char* argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");

	char buf[399];
	int ch;

	char path[100] = "C://TouristAgences.txt";
	try {
		list_ag* my_objects = new list_ag[7];
		ifstream file(path);//open for reading
		if (!file.is_open()) {
			throw path;//problem var
		}
		int i = 0;
		for (i = 0; i < 7; i++) {
			do {
				file.getline(buf, 399);
				file.seekg(1, ios_base::cur);
				ch = buf[i];
			} while (!(ch >= 65 && ch <=90) || !(ch > 48 && ch <= 57) || !(ch >= 97 && ch <= 122));
			file.getline(my_objects[i].INFO.name_travel_agencies, 250, '\n');
			file.getline(my_objects[i].INFO.country, 150, '\n');
			file.getline(my_objects[i].INFO.travel_conditions, 500, '\n');
			file.getline(my_objects[i].INFO.excursion_services, 500, '\n');
			file.getline(my_objects[i].INFO.host_service, 300, '\n');
			file.getline(my_objects[i].INFO.ticket_price, 200, '\n');
		}
		int j = 0;
		while (j < 7) {
			cout << my_objects[j].INFO.name_travel_agencies << endl;
			cout << my_objects[j].INFO.country << endl;
			cout << my_objects[j].INFO.travel_conditions << endl;
			cout << my_objects[j].INFO.excursion_services << endl;
			cout << my_objects[j].INFO.host_service << endl;
			cout << my_objects[j].INFO.ticket_price << endl;
			j++;
		}
	}
	catch(char path[100]) {
		cout << "Wrong path!" << endl;
		exit(-1);
	}
	int i = 0;

	list_ag* pointer;
	char* p_ezone[20];//massive pointers
	for (i = 0; i < 20; i++) {
		p_ezone[i] = &euro_zone[i][0];//get adresses strings of list
	}
	//pointer = file_reader(&pointer);//process reading file and filling into structure
//	output_data_EZONES(fptr, &pointer, p_ezone);//the choice of eurozone countries
//	free_memory(&pointer);//wash my pens
	return 0;
}