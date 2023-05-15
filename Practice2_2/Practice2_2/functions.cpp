#include "title.h"
int count_shops(const string adress) {
	ifstream base(adress);

	string line;
	int lines = 0;
	if (base.is_open()) {
		cout << "File opened successfully!\n";
		while (!base.eof()) {
			getline(base, line);
			lines++;
		}
	}
	else {
		cout << "Error opening file";
		exit(1);
	}
	base.close();
	return lines-1;
}
List info(int& n, const string adress) {
	List list{};
	ifstream file(adress);
	list.count = n;
	list.shop = new Shop[list.count];
	for (int i = 0; i < n; i++) {
		list.shop[i].op = new Opening_Hours[7];
	}

	for (int i = 0; i < list.count; i++)
	{
		file >> list.shop[i].name >> list.shop[i].adress.street >> list.shop[i].phone_number >> list.shop[i].specialization >> list.shop[i].op[0].Day >> list.shop[i].op[0].open.hours
			>> list.shop[i].op[0].open.minutes >> list.shop[i].op[0].close.hours >> list.shop[i].op[0].close.minutes >> list.shop[i].op[1].Day >>  list.shop[i].op[1].open.hours >>
			list.shop[i].op[1].open.minutes >> list.shop[i].op[1].close.hours >> list.shop[i].op[1].close.minutes >> list.shop[i].op[2].Day >> list.shop[i].op[2].open.hours >> 
			list.shop[i].op[2].open.minutes >> list.shop[i].op[2].close.hours >> list.shop[i].op[2].close.minutes >> list.shop[i].op[3].Day >> list.shop[i].op[3].open.hours >> 
			list.shop[i].op[3].open.minutes >> list.shop[i].op[3].close.hours >> list.shop[i].op[3].close.minutes >> list.shop[i].op[4].Day >> list.shop[i].op[4].open.hours >> 
			list.shop[i].op[4].open.minutes >> list.shop[i].op[4].close.hours >> list.shop[i].op[4].close.minutes >> list.shop[i].op[5].Day >> list.shop[i].op[5].open.hours >>
			list.shop[i].op[5].open.minutes >> list.shop[i].op[5].close.hours >> list.shop[i].op[5].close.minutes >> list.shop[i].op[6].Day >> list.shop[i].op[6].open.hours >>
			list.shop[i].op[6].open.minutes >> list.shop[i].op[6].close.hours >> list.shop[i].op[6].close.minutes >> list.shop[i].form_of_ownership >> list.shop[i].adress.postcode;
			
	}
	file.close();
	return list;
}
ostream& operator<<(ostream& os, const List& list) {
	for (int j = 0; j < list.count; j++) {
		os << "\nName: " << list.shop[j].name << "\nAdress: " << list.shop[j].adress.street << "\nPhone number: " << list.shop[j].phone_number << "\nSpecialization : " << list.shop[j].specialization << "\nForm of ownership: " << list.shop[j].form_of_ownership << "\nPostcode: " << list.shop[j].adress.postcode << endl;
		for (int i = 0; i < 7; i++) {
			if (list.shop[j].op[i].open.hours == "closed")
				cout << list.shop[j].op[i].Day << ": closed" << endl;
			else {

				cout << list.shop[j].op[i].Day << ": " << list.shop[j].op[i].open.hours << ":" << list.shop[j].op[i].open.minutes << "-" << list.shop[j].op[i].close.hours << ":" << list.shop[j].op[i].close.minutes << endl;
			}
		}
	}
	return os;
}
int our_quantity(Shop* shops, int records) {
	int count = 0;
	for (int i = 0; i < records; i++) {
		if (((shops[i].specialization.compare("Products")) == 0)) {
			for (int j = 0; j < 7; j++) {
				if (shops[i].op[j].open.hours != "00" || shops[i].op[j].open.minutes != "00" || shops[i].op[j].close.hours != "00" || shops[i].op[j].close.minutes != "00")
					break;
				else {
					if (j == 6) count++;
				}
			}

		}
	}
	return count;
}
List correct_shop(Shop* shops, int length, int count) {
	List list{};
	list.count = count;
	list.shop = new Shop[list.count];
	for (int i = 0; i < count; i++) {
		list.shop[i].op = new Opening_Hours[7];
	}
	for (int c = 0; c < count; c++) {
		for (int i = 0; i < length; i++) {
			if (shops[i].specialization.compare("Products") == 0) {
				for (int j = 0; j < 7; j++) {
					if (shops[i].op[j].open.hours != "00" || shops[i].op[j].open.minutes != "00" || shops[i].op[j].close.hours != "00" || shops[i].op[j].close.minutes != "00")
						break;
					else {
						if (j == 6){
						list.shop[c].name = shops[i].name;
						list.shop[c].specialization = shops[i].specialization;
						list.shop[c].phone_number = shops[i].phone_number;
						list.shop[c].adress.street = shops[i].adress.street;
						list.shop[c].adress.postcode = shops[i].adress.postcode;
						list.shop[c].form_of_ownership = shops[i].form_of_ownership;
						for (int b = 0; b < 7; b++) {
							list.shop[c].op[b].Day = shops[i].op[b].Day;
							list.shop[c].op[b].open.hours = shops[i].op[b].open.hours;
							list.shop[c].op[b].open.minutes = shops[i].op[b].open.minutes;
							list.shop[c].op[b].close.hours = shops[i].op[b].close.hours;
							list.shop[c].op[b].close.minutes = shops[i].op[b].close.minutes;
						}
						c++;
						}
					}
					}
				}
			}
		}
		return list;
	}
void free_str(List* list,int length) {
	for (int i = 0; i < length; i++) {
		delete[] list->shop[i].op;
	}
	delete[] list->shop;
}
