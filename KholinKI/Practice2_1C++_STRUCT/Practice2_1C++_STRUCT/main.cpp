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

int main(int argc, char *argv[]) {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");

	string str;
	int ch;
	char path[100] = "C://TouristAgences.txt";
	try {
		list_ag* my_objects = new list_ag[7];
		ifstream file(path);//open for reading
		if (!file.is_open()) {
			throw path;//problem var
		}
											//придумать,как реализовать для string
		getline(file, str);
		for (int i = 0; i < 7; i++) {
			ch = c[i];

			if (ch == 10) {
				do {
					file.seekg(1, ios_base::beg);
					file.getline(c, 255, '\n');
					ch = c[0];
				} while (ch == 10);
				goto reading;//jump to output
			}
			else {
			reading:
				for (int j = 0; j < 1; j++) {
					file.seekg(-2, ios_base::cur);
					file.getline(my_objects[j].INFO.name_travel_agencies, 25, '\n');
					file.getline(my_objects[j].INFO.country, 15, '\n');
					file.getline(my_objects[j].INFO.travel_conditions, 500, '\n');
					file.getline(my_objects[j].INFO.excursion_services, 500, '\n');
					file.getline(my_objects[j].INFO.host_service, 300, '\n');
					file.getline(my_objects[j].INFO.ticket_price, 20, '\n');
				}
				break;
			}
		}
		int i = 0;
		while (i < 1) {
			cout << my_objects[i].INFO.name_travel_agencies << endl;
			cout << my_objects[i].INFO.country << endl;
			cout << my_objects[i].INFO.travel_conditions << endl;
			cout << my_objects[i].INFO.excursion_services << endl;
			cout << my_objects[i].INFO.host_service << endl;
			cout << my_objects[i].INFO.ticket_price << endl;
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