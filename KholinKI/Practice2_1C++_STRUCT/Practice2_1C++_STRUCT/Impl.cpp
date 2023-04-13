
#include <iostream>
#include "Prototypes.h"

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
	int num_agencies = 0;
	int* num_services = 0;
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

void allocate_TAgency(TAgency*& pointer, int count_services) {
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
	list = new TAgency * [num_agencies]; //create a dynamic array of objects
	int i = 0;
	for (i = 0; i < num_agencies; i++) {
		num = num_services[i];
		allocate_TAgency(list[i], num);//Give the same pointer to create the structure
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
void output_all_data(TAgency**& list, int num_agencies) {
	int i = 0;
	int j = 0;
	int num;
	for (i = 0; i < num_agencies; i++) {
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

int* counter_euro_countries(TAgency**& list, int num_agencies) {
	int i = 0;
	int j = 0;
	int k = 0;
	int* num_euro_countries;
	num_euro_countries = new int[num_agencies];
	for (i = 0; i < num_agencies; i++) {
		num_euro_countries[i] = 0;
	}
	for (i = 0; i < num_agencies; i++) {
		while (j < list[i]->num_services) {
			while (k < NUM_EUROPE_COUNTRIES) {
				if (list[i]->services[j].country == euro_zone[k]) {
					num_euro_countries[i]++;
					break;
				}
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
	}
	return num_euro_countries;
}

TAgency** find_euro_countries(TAgency**& list, int num_agencies) {
	int i = 0;//counter num_agencies
	int j = 0;//counter num_services
	int k = 0;//counter euro_zones
	int z = 0;//counter new_agencies_list
	int* num_euro_countries = counter_euro_countries(list, num_agencies);
	TAgency** new_agencies_list = new TAgency * [num_agencies];
	for (i = 0; i < num_agencies; i++) {
		allocate_TAgency(new_agencies_list[i], num_euro_countries[i]);
	}
	for (i = 0; i < num_agencies; i++) {
		new_agencies_list[i]->name = list[i]->name;
		while (j < list[i]->num_services) {
			while (k < NUM_EUROPE_COUNTRIES && z < new_agencies_list[i]->num_services) {
				if (list[i]->services[j].country == euro_zone[k]) {
					new_agencies_list[i]->services[z].country = list[i]->services[j].country;
					new_agencies_list[i]->services[z].travel_conditions = list[i]->services[j].travel_conditions;
					new_agencies_list[i]->services[z].excursion_services = list[i]->services[j].excursion_services;
					new_agencies_list[i]->services[z].host_service = list[i]->services[j].host_service;
					new_agencies_list[i]->services[z].ticket_price = list[i]->services[j].ticket_price;
					z++;
					break;
				}

				k++;
			}
			k = 0;
			j++;
		}
		z = 0;
		j = 0;
	}
	delete[] num_euro_countries;
	return new_agencies_list;
}

void output_data_EZONES(TAgency**& new_list, int num_agencies) {
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < num_agencies; i++) {
		if (new_list[i]->num_services != 0) {
			cout << new_list[i]->name << endl;
			while (j < new_list[i]->num_services) {
				cout << *(new_list[i]);
				cout << endl;
				j++;
			}
			j = 0;
		}
	}
}

ostream& operator<<(ostream& stream, const TAgency& obj) {
	cout << obj.services->country << endl;
	cout << obj.services->travel_conditions << endl;
	cout << obj.services->excursion_services << endl;
	cout << obj.services->host_service << endl;
	cout << obj.services->ticket_price << endl;
	return stream;
}


void free_memory(TAgency**& pointer, int num_agencies) {
	for (int i = 0; i < num_agencies; i++) {
		delete[] pointer[i]->services;
	}
	delete[] pointer;
}

void free_european_memory(TAgency**& euro_pointer, int num_agencies) {
	for (int i = 0; i < num_agencies; i++) {
		delete[] euro_pointer[i]->services;
	}
	delete[] euro_pointer;
}