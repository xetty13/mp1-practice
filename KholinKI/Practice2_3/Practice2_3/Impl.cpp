#include "TAgencyBook.h"

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
	
	
	int len_buffer = buffer.length();
	while (!file.eof()) {
		getline(file, str);
		int len_str = str.length();
		file.seekg(-1, ios_base::cur);
		if (str.compare(0, len_buffer, buffer, 0, len_buffer) == 0) {
			int i = 0;
			int c = 0;
			for (i = 0; i < len_str; i++) {
				c = str[i];
				if (c >= 49 && c < 58) {
					int q = 1;
					int ch = 0;
					int num;
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
	
	string str;
	string buffer = "Directions:";
	
	
	int j = 0;
	int len_buffer = buffer.length();
	int* num_services = nullptr;
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
			int c = 0;
			
			for (i = 0; i < len_str; i++) {
				c = str[i];
				if (c >= 49 && c < 58) {
					int q = 1;
					int num;
					int ch = 0;
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
	
	const string list_agencies = "List agencies:";
	const string directions = "Directions:";
	int i = 0;
	int j = 0;
	int c;
	int* num_services = CountTServices(file);
	agencies = new TAgency * [count_agencies];
	for (i = 0; i < count_agencies; i++) {
		agencies[i] = new TAgency(num_services[i]);
	}
	int len_directs = directions.length();
	int len_list = list_agencies.length();
	for (i = 0; i < count_agencies; i++) {
		this->search_string(file);
		getline(file, buffer);
		if (buffer.compare(0, len_list, list_agencies, 0, len_list) == 0 || buffer.compare(0, len_directs, directions, 0, len_directs) == 0) {
			do {
				c = file.get();
			} while (c == 10);
			file.seekg(-1, ios_base::cur);
			getline(file,agencies[i]->name);//own getline
		}
		else agencies[i]->name = buffer;
		for (j = 0; j < agencies[i]->num_services; j++) {
			search_string(file);
			if (j == 0) {
				do {
					c = file.get();
				} while (c != 10);
			}
			getline(file, agencies[i]->services[j].country);
			getline(file, agencies[i]->services[j].travel_conditions);
			getline(file, agencies[i]->services[j].excursion_services);
			getline(file, agencies[i]->services[j].host_service);
			getline(file, agencies[i]->services[j].ticket_price);
		}
	}
	file.seekg(0, ios_base::beg);
	delete[] num_services;
	file.close();
}


int TAgencyBook::counter_euro_agencies() {
	int i = 0;
	int j = 0;
	int k = 0;
	int flag = 0;
	int count_euro_agencies = 0;
	for (i = 0; i < count_agencies; i++) {
		while (j < agencies[i]->num_services) {
			while (k < NUM_EUROPE_COUNTRIES) {
				if (agencies[i]->services[j].country == euro_zone[k]) {
					count_euro_agencies++;
					flag = 1;
					break;
				}
				k++;
			}
			k = 0;
			if (flag == 1) {
				break;
			}
			j++;
		}
		flag = 0;
		j = 0;
	}
	return count_euro_agencies;
}

int* TAgencyBook::counter_euro_countries() {
	int* num_euro_countries = new int[count_agencies];
	int i = 0;
	for (i = 0; i < count_agencies; i++) {
		num_euro_countries[i] = 0;
	}
	int k = 0;
	int j = 0;
	for (i = 0; i < count_agencies; i++) {
		while (j < agencies[i]->num_services) {
			while (k < NUM_EUROPE_COUNTRIES) {
				if (agencies[i]->services[j].country == euro_zone[k]) {
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

TAgencyBook* TAgencyBook::Get_Europe_Countries() {//find european countries and create european massive}
	int* num_euro_countries = counter_euro_countries();
	TAgencyBook* europeCountries = new TAgencyBook();
	europeCountries->count_agencies = counter_euro_agencies();
	europeCountries->agencies = new TAgency * [europeCountries->count_agencies];//copy TAgency_array
	int j = -1;//counter num_services
	int k = 0;//counter euro_zones
	int z = 0;//counter new_agencies_list
	int i_saved = -1;
	int i = 0;//counter num_agencies
	for (i = 0; i < count_agencies; i++) {
		if (num_euro_countries[i] == 0) {
			continue;
		}
		else { j++; europeCountries->agencies[j] = new TAgency(num_euro_countries[i]); }

	}
	j = i = 0;
	for (i = 0; i < count_agencies; i++) {
		i_saved++;
		if (num_euro_countries[i] == 0) { i_saved--;  continue; }
		europeCountries->agencies[i_saved]->name = agencies[i]->name;
		while (k < NUM_EUROPE_COUNTRIES && z < num_euro_countries[i]) {

			if (agencies[i]->services[j].country == euro_zone[k]) {//find the European countries in the old array and insert them in the new one
				europeCountries->agencies[i_saved]->services[z].country = agencies[i]->services[j].country;
				europeCountries->agencies[i_saved]->services[z].travel_conditions = agencies[i]->services[j].travel_conditions;
				europeCountries->agencies[i_saved]->services[z].excursion_services = agencies[i]->services[j].excursion_services;
				europeCountries->agencies[i_saved]->services[z].host_service = agencies[i]->services[j].host_service;
				europeCountries->agencies[i_saved]->services[z].ticket_price = agencies[i]->services[j].ticket_price;
				z++;
				j++;
				k = 0;
			}
			else { k++; if (k == NUM_EUROPE_COUNTRIES) { j++; k = 0; } }
		}

		z = 0;
		j = 0;
	}
	delete[] num_euro_countries;
	return europeCountries;
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
			FileExeption f_ex = FileExeption::NullPtrFile;
			throw  f_ex;//generate object type of exeption
		}
		CountAgencies(file);
		file_reader(file);
	}
	catch (FileExeption f_ex) {
		cout << "File not found! The programm is over with code " << static_cast<int>(f_ex) << endl;
	}
}



TAgencyBook::TAgencyBook(const TAgencyBook& object) {
	count_agencies = object.count_agencies;
	agencies = new TAgency * [count_agencies];

}


TAgencyBook::~TAgencyBook() {

	delete[] agencies;
}

TAgency::~TAgency() {
	delete[] services;
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

ostream& operator<<(ostream& stream, const TAgencyBook& obj) {

	for (int i = 0; i < obj.count_agencies; i++) {
		cout << obj.agencies[i]->name << endl;
		for (int j = 0; j < obj.agencies[i]->num_services; j++) {
			cout << obj.agencies[i]->services[j].country << endl;
			cout << obj.agencies[i]->services[j].travel_conditions << endl;
			cout << obj.agencies[i]->services[j].excursion_services << endl;
			cout << obj.agencies[i]->services[j].host_service << endl;
			cout << obj.agencies[i]->services[j].ticket_price << endl;
			cout << endl;
		}

	}
	return stream;
}

TService::TService() {
	country = "";
	travel_conditions = "";
	excursion_services = "";
	host_service = "";
	ticket_price = "";
}
