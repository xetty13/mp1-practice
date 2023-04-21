

#include "Prototypes.h"
#include <iostream>
#include <fstream>

#define NUM_EUROPE_COUNTRIES 20

using namespace std;

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


int* TAgencyBook::CountTServices(ifstream& file) {
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


int TAgencyBook::CountAgencies(ifstream& file) {
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

void TAgencyBook::allocate_TAgency(TAgency& object, int count_services) {
	object.num_services = count_services;
	object.services = new TService[count_services];//creating a service structure for each facility
}


TAgencyBook::TAgencyBook(TAgency* agencies, string path) {
	try {
		file.open(path);
		if (file.is_open() == 0) {
			throw ifstream();
		}
		count = CountAgencies(file);
		int* num_services = CountTServices(file);//count directions
		agencies = new TAgency[count];
		int i = 0;
		for (i = 0; i < count; i++) {
			allocate_TAgency(agencies[i], num_services[i]);//Give the same pointer to create the structure
		}
		file_reader(file);
	}
	catch (const ifstream& exeption) {
		cout << "Unable open file!" << endl;
		exit(-1);
	}
}

TAgencyBook::TAgencyBook(const TAgencyBook& object) {
	count = object.count;
	agencies = new TAgency[count];
	for (int i = 0; i < count; i++) {
		agencies[i].num_services = object.agencies[i].num_services;
		agencies[i].services = new TService[agencies[i].num_services];
	}
}


void TAgencyBook::search_string(ifstream& file) {//look for the first occurrence of the string	
	string str;
	int c;
	int len;
	do {
		c = file.get();
	} while (c == 10);
	file.seekg(-1, ios_base::cur);
}

void TAgencyBook::file_reader(ifstream& file) {
	string buffer;
	const string list_agencies = "List agencies:";
	const string directions = "Directions:";
	int len_list = list_agencies.length();
	int len_directs = directions.length();
	int i = 0;
	int j = 0;
	int c;
	for (i = 0; i < count; i++) {
		this->search_string(file);
		getline(file, buffer);
		if (buffer.compare(0, len_list, list_agencies, 0, len_list) == 0 || buffer.compare(0, len_directs, directions, 0, len_directs) == 0) {
			do {
				c = file.get();
			} while (c == 10);
			file.seekg(-1, ios_base::cur);
			getline(file, agencies[i].name);
		}
		else agencies[i].name = buffer;
		for (j = 0; j < agencies[i].num_services; j++) {
			search_string(file);
			if (j == 0) {
				do {
					c = file.get();
				} while (c != 10);
			}
			getline(file, agencies[i].services[j].country);
			getline(file, agencies[i].services[j].travel_conditions);
			getline(file, agencies[i].services[j].excursion_services);
			getline(file, agencies[i].services[j].host_service);
			getline(file, agencies[i].services[j].ticket_price);
		}
	}
	file.seekg(0, ios_base::beg);
	file.close();
}
void  TAgencyBook::show_all_data() {
	int i = 0;
	int j = 0;
	int num;
	for (i = 0; i < count; i++) {
		cout << agencies[i].name << endl;
		for (j = 0; j < agencies[i].num_services; j++) {
			cout << agencies[i].services[j].country << endl;
			cout << agencies[i].services[j].travel_conditions << endl;
			cout << agencies[i].services[j].excursion_services << endl;
			cout << agencies[i].services[j].host_service << endl;
			cout << agencies[i].services[j].ticket_price << endl;
			cout << endl;
		}
	}
}

int* TAgencyBook::counter_euro_countries() {
	int i = 0;
	int j = 0;
	int k = 0;
	int* num_euro_countries;
	num_euro_countries = new int[count];
	for (i = 0; i < count; i++) {
		num_euro_countries[i] = 0;
	}
	for (i = 0; i < count; i++) {
		while (j < agencies[i].num_services) {
			while (k < NUM_EUROPE_COUNTRIES) {
				if (agencies[i].services[j].country == euro_zone[k]) {
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

void TAgencyBook::find_euro_countries() {
	int i = 0;//counter num_agencies
	int j = 0;//counter num_services
	int k = 0;//counter euro_zones
	int z = 0;//counter new_agencies_list
	int* num_euro_countries = counter_euro_countries();
	for (i = 0; i < count; i++) {
		agencies[i].name = agencies[i].name;
		while (j < agencies[i].num_services) {
			while (k < NUM_EUROPE_COUNTRIES && z < agencies[i].num_services) {
				if (agencies[i].services[j].country == euro_zone[k]) {
					agencies[i].services[z].country = agencies[i].services[j].country;
					agencies[i].services[z].travel_conditions = agencies[i].services[j].travel_conditions;
					agencies[i].services[z].excursion_services = agencies[i].services[j].excursion_services;
					agencies[i].services[z].host_service = agencies[i].services[j].host_service;
					agencies[i].services[z].ticket_price = agencies[i].services[j].ticket_price;
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
}

void  TAgencyBook::output_data_EZONES() {
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < count; i++) {
		if (agencies[i].num_services != 0) {
			cout << agencies[i].name << endl;
			while (j < agencies[i].num_services) {
				cout << agencies[i];
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

TAgencyBook::~TAgencyBook() {
	for (int i = 0; i < count; i++) {
		delete[] agencies[i].services;
	}
	delete[] agencies;
}

