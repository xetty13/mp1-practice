#include "func.h"
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
	return lines;
}
Shop* info(int& n, const string adress) {
	ifstream file(adress);
	Shop* shop = new Shop[n];
	for (int i = 0; i < n; i++) {
		shop[i].op = new Opening_Hours[7];
	}

	for (int i = 0; i < n; i++)
	{
		file >> shop[i].name >> shop[i].adress.street >> shop[i].phone_number >> shop[i].specialization >> shop[i].op[0].Day >> shop[i].op[0].open.hours >> shop[i].op[0].open.minutes >> shop[i].op[0].close.hours >> shop[i].op[0].close.minutes >> shop[i].op[1].Day >> shop[i].op[1].open.hours >> shop[i].op[1].open.minutes >> shop[i].op[1].close.hours >> shop[i].op[1].close.minutes >> shop[i].op[2].Day >> shop[i].op[2].open.hours >> shop[i].op[2].open.minutes >> shop[i].op[2].close.hours >> shop[i].op[2].close.minutes >> shop[i].op[3].Day >> shop[i].op[3].open.hours >> shop[i].op[3].open.minutes >> shop[i].op[3].close.hours >> shop[i].op[3].close.minutes >> shop[i].op[4].Day >> shop[i].op[4].open.hours >> shop[i].op[4].open.minutes >> shop[i].op[4].close.hours >> shop[i].op[4].close.minutes >> shop[i].op[5].Day >> shop[i].op[5].open.hours >> shop[i].op[5].open.minutes >> shop[i].op[5].close.hours >> shop[i].op[5].close.minutes >> shop[i].op[6].Day >> shop[i].op[6].open.hours >> shop[i].op[6].open.minutes >> shop[i].op[6].close.hours >> shop[i].op[6].close.minutes >> shop[i].form_of_ownership >> shop[i].adress.postcode;
			
	}
	file.close();
	return shop;
}
ostream& operator<<(ostream& os, const Shop& shop) {
	os << "\nName: " << shop.name << "\nAdress: " << shop.adress.street << "\nPhone number: " << shop.phone_number << "\nSpecialization : " << shop.specialization << "\nForm of ownership: " << shop.form_of_ownership << "\nPostcode: " << shop.adress.postcode << endl;
	for (int i = 0; i < 7; i++) {
		if (shop.op[i].open.hours == "closed")
			cout << shop.op[i].Day << ": closed" << endl;
		else {

			cout << shop.op[i].Day << ": " << shop.op[i].open.hours << ":" << shop.op[i].open.minutes << "-" << shop.op[i].close.hours << ":" << shop.op[i].close.minutes << endl;
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
Shop* correct_shop(Shop* shops, int length, int count) {
	Shop* shop = new Shop[count];
	for (int i = 0; i < count; i++) {
		shop[i].op = new Opening_Hours[7];
	}
	for (int c = 0; c < count; c++) {
		for (int i = 0; i < length; i++) {
			if (shops[i].specialization.compare("Products") == 0) {
				for (int j = 0; j < 7; j++) {
					if (shops[i].op[j].open.hours != "00" || shops[i].op[j].open.minutes != "00" || shops[i].op[j].close.hours != "00" || shops[i].op[j].close.minutes != "00")
						break;
					else {
						if (j == 6){
						shop[c].name = shops[i].name;
						shop[c].specialization = shops[i].specialization;
						shop[c].phone_number = shops[i].phone_number;
						shop[c].adress.street = shops[i].adress.street;
						shop[c].adress.postcode = shops[i].adress.postcode;
						shop[c].form_of_ownership = shops[i].form_of_ownership;
						for (int b = 0; b < 7; b++) {
							shop[c].op[b].Day = shops[i].op[b].Day;
							shop[c].op[b].open.hours = shops[i].op[b].open.hours;
							shop[c].op[b].open.minutes = shops[i].op[b].open.minutes;
							shop[c].op[b].close.hours = shops[i].op[b].close.hours;
							shop[c].op[b].close.minutes = shops[i].op[b].close.minutes;
						}
						c++;
						}
					}
					}
				}
			}
		}
		return shop;
	}
void free_str(Shop* shop,int length) {
	for (int i = 0; i < length; i++) {
		delete[] shop[i].op;
	}
	delete[] shop;
}
