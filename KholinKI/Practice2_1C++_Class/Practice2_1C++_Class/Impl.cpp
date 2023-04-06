
#include "class TAgency.h"
#include "prototypes.h"
#include "class TService.h"
#include <string>

#define NUM_EUROPE_COUNTRIES 20

string euro_zone[NUM_EUROPE_COUNTRIES] = {//list of eurozone countries
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


ifstream create_file() {
	try {
		ifstream file;//creating file var


		file.open("C://TouristAgences.txt");//open the file for reading

		if (file.is_open() == 0) {
			throw ifstream();
		}
		return file;
	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}
}

int CountAgencies(ifstream& file) {
	file.seekg(0, ios_base::beg);
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
	file.seekg(0, ios_base::beg);
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

void search_string(ifstream& file) {//look for the first occurrence of the string	
	string str;
	int c;
	int len;
	do {
		c = file.get();
	} while (c == 10);
	file.seekg(-1, ios_base::cur);
}


int TAgency::file_reader(ifstream& file, TAgency**& list) {
	ifstream file_copy;
	file_copy = create_file();
	int num_agencies = CountAgencies(file_copy);
	int* num_services = CountTServices(file);//count directions
	string buffer;
	const string list_agencies = "List agencies:";
	const string directions = "Directions:";
	int len_list = list_agencies.length();
	int len_directs = directions.length();
	int j = 0;
	int c;
	list = new TAgency *[num_agencies]; //create a dynamic array of objects
	int i = 0;
	for (i = 0; i < num_agencies; i++) {
		list[i] = new TAgency(num_services[i]);
	}
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
	return num_agencies;
}
void TAgency::output_all_data(TAgency**& list,int num_agencies) {//all data
	int i = 0;
	int j = 0;
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

void TAgency::output_data_EZONES(TAgency**& list, int num_agencies) {
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < num_agencies; i++) {
		cout << list[i]->name << endl;
		while (j < list[i]->num_services) {
			while (k < NUM_EUROPE_COUNTRIES) {
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

const ostream& operator<<(ostream& stream, const TAgency**& list) {
	ifstream file;
	file = create_file();
	int num_agencies = CountAgencies(file);
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < num_agencies; i++) {
		stream << list[i]->name << endl;
		while (j < list[i]->num_services) {
			while (k < NUM_EUROPE_COUNTRIES) {
				if (list[i]->services[j].country == euro_zone[k]) {
					stream << list[i]->services[j].country << endl;
					stream << list[i]->services[j].travel_conditions << endl;
					stream << list[i]->services[j].excursion_services << endl;
					stream << list[i]->services[j].host_service << endl;
					stream << list[i]->services[j].ticket_price << endl;
					stream << endl;
					break;
				}
				k++;
				if (k == NUM_EUROPE_COUNTRIES && list[i]->num_services == 1) {
					stream << "(No suitable destination found!)" << endl;
				}
			}
			k = 0;
			j++;
		}
		j = 0;
	}
	return stream;
}
