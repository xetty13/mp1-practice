#include "TAgencyBook.h"

#include <fstream>
#include <iostream>

#define NUM_EUROPE_COUNTRIES 19
#define NUM_PARAMS 5

enum FileExeption { NullPtrFile = -1 };

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

void TService::set_service(TService& object, ifstream& file) {
	getline(file, object.country);
	getline(file, object.travel_conditions);
	getline(file, object.excursion_services);
	getline(file, object.host_service);
	getline(file, object.ticket_price);
}

void TService::set_service(const TService& object) {
	country = object.country;
	travel_conditions = object.travel_conditions;
	excursion_services = object.excursion_services;
	host_service = object.host_service;
	ticket_price = object.ticket_price;
}

void TAgencyBook::file_reader(ifstream& file) {
	string buffer;
	string name;
	
	int* num_services = CountTServices(file);
	const string list_agencies = "List agencies:";
	const string directions = "Directions:";
	int len_list = list_agencies.length();
	int len_directs = directions.length();
	int i = 0;
	int j = 0;
	int c;
	agencies = new TAgency*[count_agencies];
	for (i = 0; i < count_agencies; i++) {
		agencies[i] = new TAgency(num_services[i]);
	}
	for (i = 0; i < count_agencies; i++) {
		this->search_string(file);
		getline(file, buffer);
		if (buffer.compare(0, len_list, list_agencies, 0, len_list) == 0 || buffer.compare(0, len_directs, directions, 0, len_directs) == 0) {
			do {
				c = file.get();
			} while (c == 10);
			file.seekg(-1, ios_base::cur);

			getline(file, name);
			agencies[i]->set_name(name);
		}
		else { name = buffer; agencies[i]->set_name(name); }

		for (j = 0; j < agencies[i]->get_num_services(); j++) {
			search_string(file);
			if (j == 0) {
				do {
					c = file.get();
				} while (c != 10);
			}
			
			agencies[i]->get_TService()[j].set_service(agencies[i]->get_TService()[j], file);
			

			
		}
	}
	file.seekg(0, ios_base::beg);
	file.close();
}


void TAgencyBook::show_all_data() {
	int i = 0;
	string name;
	for (i = 0; i < count_agencies; i++) {
		name = agencies[i]->get_name();
		cout << name;
		cout << *(agencies[i]);//Give the i-th object of the TAgency array
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
		while (j < agencies[i]->get_num_services()) {
			while (k < NUM_EUROPE_COUNTRIES) {
				if (agencies[i]->get_TService()[j].get_country() == euro_zone[k]) {
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
	agencies = new TAgency*[count_agencies];//copy TAgency_array
	for (i = 0; i < count_agencies; i++) {
		agencies[i] = new TAgency(*(Object.agencies[i]));//copy TAgency_objects
	}
	for (i = 0; i < count_agencies; i++) {
		agencies[i]->set_num_services(num_euro_countries[i]);//overwriting the number of referrals
	}
	for (i = 0; i < count_agencies; i++) {
		while (k < NUM_EUROPE_COUNTRIES && z < agencies[i]->get_num_services()) {
			if (Object.agencies[i]->get_TService()[j].get_country() == euro_zone[k]) {
				agencies[i]->get_TService()[z].set_service(Object.agencies[i]->get_TService()[j]);//set service
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
	try {
		ifstream file;
		file.open(path);
		if (file.is_open() == 0) {
			FileExeption f_ex = NullPtrFile;
			throw f_ex;
		}
		CountAgencies(file);
		file_reader(file);
	}
	catch (enum FileExeption f_ex) {
		cout << "File not found!  The programm is over with code " << f_ex << endl;
	}
}

void TAgencyBook::output_data_EZONES() {
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < count_agencies; i++) {
		if (agencies[i]->get_num_services() != 0) {
			cout << agencies[i]->get_name() << endl;
			cout << *(agencies[i]);
			cout << endl;
		}
	}
}



TAgencyBook::TAgencyBook(const TAgencyBook& object) {
	count_agencies = object.count_agencies;
	agencies = new TAgency*[count_agencies];
}

TAgency::~TAgency() {
	delete services;
}

TAgencyBook::~TAgencyBook() {
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

TService::TService(void) {
	country = "";
	travel_conditions= "";
	excursion_services= "";
	host_service= "";
	ticket_price= "";
}

ostream& operator<<(ostream& stream, const TAgency& obj) {
	cout << endl;
	for (int i = 0; i < obj.num_services; i++) {
		cout << obj.services[i].get_country() << endl;
		cout << obj.services[i].get_travel_conditions() << endl;
		cout << obj.services[i].get_excursion_services() << endl;
		cout << obj.services[i].get_host_service() << endl;
		cout << obj.services[i].get_ticket_price() << endl;
		cout << endl;
	}
	return stream;
}