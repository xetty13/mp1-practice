#include "title.h"

istream& operator >>(istream& os, Shop& shop) {
	os >> shop.name >> shop.adress.street >> shop.phone_number >> shop.specialization >> shop.op[0].Day >> shop.op[0].open.hours
		>> shop.op[0].open.minutes >> shop.op[0].close.hours >> shop.op[0].close.minutes >> shop.op[1].Day >> shop.op[1].open.hours >>
		shop.op[1].open.minutes >> shop.op[1].close.hours >> shop.op[1].close.minutes >> shop.op[2].Day >> shop.op[2].open.hours >>
		shop.op[2].open.minutes >> shop.op[2].close.hours >> shop.op[2].close.minutes >> shop.op[3].Day >> shop.op[3].open.hours >>
		shop.op[3].open.minutes >> shop.op[3].close.hours >> shop.op[3].close.minutes >> shop.op[4].Day >> shop.op[4].open.hours >>
		shop.op[4].open.minutes >> shop.op[4].close.hours >> shop.op[4].close.minutes >> shop.op[5].Day >> shop.op[5].open.hours >>
		shop.op[5].open.minutes >> shop.op[5].close.hours >> shop.op[5].close.minutes >> shop.op[6].Day >> shop.op[6].open.hours >>
		shop.op[6].open.minutes >> shop.op[6].close.hours >> shop.op[6].close.minutes >> shop.form_of_ownership >> shop.adress.postcode;
	return os;
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

List::List(string adress) {
	ifstream base(adress);
	string line;
	int count = 0;
	if (base.is_open()) {
		cout << "File opened successfully!\n";
		while (!base.eof()) {
			getline(base, line);
			count++;
		}
	}
	else {
		cout << "Error opening file";
		exit(1);
	}
	//base.seekg(0);
	base.close();
	ifstream file(adress);
	this->count = count-1;
	shop = new Shop[this->count];
	for (int j = 0; j < this->count; j++)
		shop[j].op = new Opening_Hours[7];
	for (int i = 0; i < this->count; i++)
	{
		file >> shop[i];

	}
	file .close();
}
List::List() {
	count = 1;
	shop = new Shop[1];
	shop[0] = Shop();

}
List::~List() {
	for (int i = 0; i < count; i++) {
		delete[] shop[i].op;
	}
	delete[] shop;
}
Shop::Shop() {
	name = " ";
	phone_number = " ";
	specialization = " ";
	op = new Opening_Hours[7];
	for (int i = 0; i < 7; i++)
		op[i] = Opening_Hours();
	form_of_ownership = " ";
	adress = Adress();
}
Time::Time() {
	minutes = " ";
	hours = " ";
}
Opening_Hours::Opening_Hours() {
	Day = " ";
	open = Time::Time();
	close = Time::Time();
}
Opening_Hours& Opening_Hours::operator=(const Opening_Hours& other)
{
	this->Day = other.Day;
	this->open = other.open;
	this->close = other.close;
	return *this;
}
List& List::correct_base(List& first) {
	int count = 0;
	for (int i = 0; i < first.count; i++) {
		if (((first.shop[i].specialization.compare("Products")) == 0)) {
			for (int j = 0; j < 7; j++) {
				if (first.shop[i].op[j].open.hours != "00" || first.shop[i].op[j].open.minutes != "00" || first.shop[i].op[j].close.hours != "00" || first.shop[i].op[j].close.minutes != "00")
					break;
				else {
					if (j == 6) count++;
				}
			}

		}
	}
	this->count = count;
	this->shop = new Shop[this->count];
	for (int c = 0; c < this->count; c++)
		this->shop[c].op = new Opening_Hours[7];
	for (int j = 0; j < this->count; j++) {
		for (int i = 0; i < first.count; i++) {
			if (first.shop[i].specialization.compare("Products") == 0) {
				for (int d = 0; d < 7; d++) {
					if (first.shop[i].op[d].open.hours != "00" || first.shop[i].op[d].open.minutes != "00" || first.shop[i].op[d].close.hours != "00" || first.shop[i].op[d].close.minutes != "00")
						d = 6;
					else {
						if (d == 6) {
							this->shop[j] = first.shop[i];
							j++;
						}
					}
				}
			}
		}
	}
	return *this;
}
Adress& Adress::operator=(const Adress& other)
{
	this->street = other.street;
	this->postcode = other.postcode;
	return *this;
}
Shop& Shop::operator=(const Shop& other) {
	this->name = other.name;
	this->specialization = other.specialization;
	this->form_of_ownership = other.form_of_ownership;
	this->phone_number = other.phone_number;
	this->adress = other.adress;
	this->op = new Opening_Hours[7];
	for (int i = 0; i < 7; i++) {
		this->op[i] = other.op[i];
	}
	return *this;
}
List& List::operator=(const List& other)
{
	this->count = other.count;
	if (this->shop != nullptr)
		delete[] this->shop;
	this->shop = new Shop[other.count];
	for (int j = 0; j < other.count; j++)
		this->shop[j].op = new Opening_Hours[7];
	for (int i = 0; i < other.count; i++)
		this->shop[i] = other.shop[i];
	return *this;
}
