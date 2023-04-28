#include "Prototypes.h"

#include <fstream>
#include <iostream>

#define NUM_EUROPE_COUNTRIES 19



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

void TAgencyBook::CountAgencies(ifstream& file) {
	string str;
	string buffer = "List agencies:";
	int c = 0;
	int j = 0;
	int ch = 0;
	int num;
	int len_buffer = buffer.length();
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
						count_agencies *= q;
						count_agencies += num;
						if (q == 1) {
							q *= 10;
						}
						i++;
					}
					break;
				}
			}
		}
		if (count_agencies != 0) {
			file.seekg(1, ios_base::cur);
			break;
		}
		if (count_agencies == 0) {
			file.seekg(1, ios_base::cur);
		}
	}
	file.seekg(0, ios_base::beg);
}

int* TAgencyBook::CountTServices(ifstream& file) {
	int* num_services = nullptr;
	string str;
	string buffer = "Directions:";
	int c = 0;
	int ch = 0;
	int num;
	int j = 0;
	int len_buffer = buffer.length();
	num_services = new int[count_agencies];
	for (int i = 0; i < count_agencies; i++) {
		num_services[i] = 0;
	}
	while (j < count_agencies) {
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
	int* num_services = CountTServices(file);
	const string list_agencies = "List agencies:";
	const string directions = "Directions:";
	int len_list = list_agencies.length();
	int len_directs = directions.length();
	int i = 0;
	int j = 0;
	int c;
	agencies = new TAgency[count_agencies];
	for (i = 0; i < count_agencies; i++) {
		agencies[i] = TAgency(num_services[i]);
	}
	for (i = 0; i < count_agencies; i++) {
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


void TAgencyBook::show_all_data() {
	int i = 0;
	int j = 0;
	int num;
	for (i = 0; i < count_agencies; i++) {
		cout << agencies[i].name << endl;
		for (j = 0; j < agencies[i].num_services; j++) {
			cout << agencies[j];//Give the i-th object of the TAgency array
		}
	}
}

int* TAgencyBook::counter_euro_countries() {
	int i = 0;
	int j = 0;
	int k = 0;
	int* num_euro_countries = new int[count_agencies];
	for (i = 0; i < count_agencies; i++) {
		num_euro_countries[i] = 0;
	}
	for (i = 0; i < count_agencies; i++) {
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

void TAgencyBook::create(TAgencyBook& Object) {//find european countries and create european massive}
	int j = 0;//counter num_services
	int k = 0;//counter euro_zones
	int z = 0;//counter new_agencies_list
	int* num_euro_countries = Object.counter_euro_countries();
	int i = 0;//counter num_agencies
	agencies = new TAgency[count_agencies];//copy TAgency_array
	for (i = 0; i < count_agencies; i++) {
		agencies[i] = TAgency(Object.agencies[i]);//copy TAgency_objects
	}
	for (i = 0; i < count_agencies; i++) {
		agencies[i].num_services = num_euro_countries[i];//overwriting the number of referrals
	}
	for (i = 0; i < count_agencies; i++) {
		while (k < NUM_EUROPE_COUNTRIES && z < agencies[i].num_services) {
			if (Object.agencies[i].services[j].country == euro_zone[k]) {
				agencies[i].services[z].country = Object.agencies[i].services[j].country;
				agencies[i].services[z].travel_conditions = Object.agencies[i].services[j].travel_conditions;
				agencies[i].services[z].excursion_services = Object.agencies[i].services[j].excursion_services;
				agencies[i].services[z].host_service = Object.agencies[i].services[j].host_service;
				agencies[i].services[z].ticket_price = Object.agencies[i].services[j].ticket_price;
				z++;
				j++;
				k = 0;
			}
			else k++; if (k == NUM_EUROPE_COUNTRIES) { j++; k = 0; }
		}
		z = 0;
		j = 0;
	}
	delete[] num_euro_countries;
}

TAgencyBook::TAgencyBook() {
	agencies = nullptr;
	count_agencies = 0;
}

TAgencyBook::TAgencyBook(const string& path) : TAgencyBook() {
	ifstream file;
	file.open(path);
	if (file.is_open() == 0) {
		abort();
	}
	CountAgencies(file);
	file_reader(file);
}

void TAgencyBook::output_data_EZONES() {
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < count_agencies; i++) {
		if (agencies[i].num_services != 0) {
			cout << agencies[i].name << endl;
			cout << agencies[i];
			cout << endl;
		}
	}
}



TAgencyBook::TAgencyBook(const TAgencyBook& object) {
	count_agencies = object.count_agencies;
	agencies = new TAgency[count_agencies];
}

TAgencyBook::~TAgencyBook() {
	for (int i = 0; i < count_agencies; i++) {
		delete[] agencies[i].services;
	}
	delete[] agencies;
}

TAgency::TAgency() {
	num_services = 0;
	name = "";
	services = nullptr;
}

TAgency::TAgency(int num_services) {
	this->num_services = num_services;
	services = new TService[num_services];//creating a service structure for each facility
}

TAgency::TAgency(const TAgency& object) {
	num_services = object.num_services;
	services = new TService[num_services];
	name = object.name;
}

ostream& operator<<(ostream& stream, const TAgency& obj) {
	for (int i = 0; i < obj.num_services; i++) {
		cout << obj.services[i].country << endl;
		cout << obj.services[i].travel_conditions << endl;
		cout << obj.services[i].excursion_services << endl;
		cout << obj.services[i].host_service << endl;
		cout << obj.services[i].ticket_price << endl;
		cout << endl;
	}
	return stream;
}