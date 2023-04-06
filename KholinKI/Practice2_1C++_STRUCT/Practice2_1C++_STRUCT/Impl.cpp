
#include <iostream>
#include "prototypes.h"

#define NUM_EUROPE_COUNTRIES 20

string euro_zone[20] = {//list of eurozone countries
	"Austria",
	"Belgium",
	"Cyprus",
	"Estonia",
	"Finland",
	"France",
	"Germany",
	"Greece",
	"Ireland",
	"Italy",
	"Latvia",
	"Lithuania",
	"Luxembourg",
	"Malta",
	"Netherlands",
	"Portugal",
	"Slovakia",
	"Slovenia",
	"Croatia"
};

int CountAgencies(ifstream& file) {
	string str;
	string buffer = "List agencies:";
	int num_agencies = 0;
	int c = 0;
	int j = 0;
	int ch = 0;
	int num;
	int len_buffer = buffer.length();
	num_agencies = 0;
	while (!file.eof()) {
		getline(file, str);
		int len_str = str.length();
		file.seekg(-1, ios_base::cur);
		if (str.compare(0, len_buffer, buffer, 0, len_buffer) == 0) {
			int i = 0;
			for (i = 0; i < len_str; i++) {
				c = str[i];
				if (c >= 49 && c < 58) {
					int q = 1;
					while (str[i] != '\0') {
						ch = str[i];
						num = static_cast<int>(ch) - 48;
						num_agencies *= q;
						num_agencies += num;
						if (q == 1) {
							q *= 10;
						}
						i++;
					}
					break;
				}
			}
		}
		if (num_agencies != 0) {
			file.seekg(1, ios_base::cur);
			break;
		}
		if (num_agencies == 0) {
			file.seekg(1, ios_base::cur);
		}
	}
	file.seekg(0, ios_base::beg);
	return num_agencies;
}

int* CountTServices(ifstream& file) {
	int num_agencies=0;
	int* num_services=0;
	string str;
	string buffer = "Directions:";
	int c = 0;
	int ch = 0;
	int num;
	int j = 0;
	int len_buffer = buffer.length();
	num_agencies = CountAgencies(file);
	num_services = new int[num_agencies];
	for (int i = 0; i < num_agencies; i++) {
		num_services[i] = 0;
	}
	while (j < num_agencies) {
		getline(file, str);
		int len_str = str.length();
		file.seekg(-1, ios_base::cur);
		if (str.compare(0, len_buffer, buffer, 0, len_buffer) == 0) {
			int i = 0;
			for (i = 0; i < len_str; i++) {
				c = str[i];
				if (c >= 49 && c < 58) {
					int q = 1;
					while (str[i] != '\0') {
						ch = str[i];
						num = static_cast<int>(ch) - 48;
						num_services[j] *= q;
						num_services[j] += num;
						if (q == 1) {
							q *= 10;
						}
						
						i++;
					}
					j++;
					break;
				}
			}
		
		}
		else file.seekg(1, ios_base::cur);
	}
	file.seekg(0, ios_base::beg);
	return num_services;
}

void allocate_TAgency(TAgency*& pointer,int count_services) {
	pointer = new TAgency;//creating a list of travel agencies
	pointer->num_services = count_services;
	pointer->services = new TService[count_services];//creating a service structure for each facility
}

void search_string(ifstream& file) {//look for the first occurrence of the string	
	string str;
	int c;
	int len;
	do {
		c = file.get();
	} while (c == 10);
	file.seekg(-1, ios_base::cur);
}

int file_reader(ifstream& file, TAgency**& list) {
	int num_agencies = CountAgencies(file);//count agencies
	int* num_services = CountTServices(file);//count directions
	int num = 0;
	string buffer;
	const string list_agencies = "List agencies:";
	const string directions = "Directions:";
	int len_list = list_agencies.length();
	int len_directs = directions.length();
	list = new TAgency* [num_agencies]; //create a dynamic array of objects
	int i = 0;
	for (i = 0; i < num_agencies; i++) {
		num = num_services[i];
		allocate_TAgency(list[i],num);//Give the same pointer to create the structure
	}
	int j = 0;
	int c;
	int count = 0;
	for (i = 0; i < num_agencies; i++) {
		search_string(file);
		getline(file, buffer);
		if (buffer.compare(0, len_list, list_agencies, 0, len_list) == 0 || buffer.compare(0, len_directs, directions, 0, len_directs) == 0) {
			do {
				c = file.get();
			} while (c == 10);
			file.seekg(-1, ios_base::cur);
			getline(file, list[i]->name);
		}
		else list[i]->name = buffer;
		for (j = 0; j < list[i]->num_services; j++) {
			search_string(file);
			if (j == 0) {
				do {
					c = file.get();
				} while (c != 10);
			}
			getline(file, list[i]->services[j].country);
			getline(file, list[i]->services[j].travel_conditions);
			getline(file, list[i]->services[j].excursion_services);
			getline(file, list[i]->services[j].host_service);
			getline(file, list[i]->services[j].ticket_price);
		}
	}
	file.seekg(0, ios_base::beg);
	delete[] num_services;
	return num_agencies;
}
void output_all_data(ifstream& file,TAgency**& list,int num_agencies) {
	int i = 0;
	int j = 0;
	int num;
	for(i=0;i <num_agencies;i++){
		cout << list[i]->name << endl;
		for (j = 0; j < list[i]->num_services; j++) {
			cout << list[i]->services[j].country << endl;
			cout << list[i]->services[j].travel_conditions << endl;
			cout << list[i]->services[j].excursion_services << endl;
			cout << list[i]->services[j].host_service << endl;
			cout << list[i]->services[j].ticket_price << endl;
			cout << endl;
		}
	}
}

void output_data_EZONES(ifstream& file,TAgency**& list,int num_agencies) {
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < num_agencies; i++) {
		cout << list[i]->name << endl;
		while (j < list[i]->num_services) {
			while(k < 20){
				if (list[i]->services[j].country == euro_zone[k]) {
					cout << list[i]->services[j].country << endl;
					cout << list[i]->services[j].travel_conditions << endl;
					cout << list[i]->services[j].excursion_services << endl;
					cout << list[i]->services[j].host_service << endl;
					cout << list[i]->services[j].ticket_price << endl;
					cout << endl;
					break;
				}
				k++;
				if (k == 20 && list[i]->num_services == 1) {
					cout << "(No suitable destination found!)" << endl;
				}
			}
			k = 0;
			j++;
		}
		j = 0;
	}
}


void free_memory(TAgency**& pointer,int num_agencies) {
	for (int i = 0; i < num_agencies; i++) {
		delete[] pointer[i]->services;
	}
	delete[] pointer;
}