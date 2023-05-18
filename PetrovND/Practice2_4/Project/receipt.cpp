#include "receipt.h"
#include "container.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

int Product::getCode() const { return code; }
float Product::getPrice() const { return price; }
string Product::getName() const  { return name; }
Product* ReceiptLine::getProduct() const { return product; }
int ReceiptLine::getCount() const { return count; }
float ReceiptLine::getSumm() const { return summ; }
void ReceiptLine::setCount(int count) { this->count = count; }
void ReceiptLine::setSumm(int summ) { this->summ = summ; }

dataBase::dataBase(const string& path) {
	ifstream file(path);
	string line;
	while (getline(file, line)) {
		if (line.empty()) {
			continue;
		}
		stringstream ss(line);
		string name, code, price, count;
		getline(ss, code, ';');
		getline(ss, name, ';');
		getline(ss, price, ';');
		getline(ss, count, ';');

		Product* product = new Product(stoi(code), name, stof(price));
		data.push_back(make_pair(product, stoi(count)));
	}
}

Product* dataBase::searchProductByCode() {
	bool isFound = false;
	int code;
	while (!isFound) {
		cout << "Enter product code: ";
		cin >> code;
		for (auto& pair : data) {
			if ((*pair.first).getCode() == code && pair.second > 0) {
				return pair.first;
				isFound = true;
			}
		}
		if (!isFound) {
			cout << "Invalid code or the product is out of stock " << endl;
		}
	}
}

void Receipt::addItem(Product* product, dataBase& db) {
	int quantity;
	bool isCorrectQuantity = false;
	while (!isCorrectQuantity) {
		cout << "Enter quantity: ";
		cin >> quantity;
		for (auto& pair : db.data) {
			if (pair.first->getCode() == (* product).getCode() && pair.second > quantity&& quantity > 0) {
				isCorrectQuantity = true;
				break;
			}
		}
		if (!isCorrectQuantity) {
			cout << "Wrong quantity " << endl;
		}
	}
	for (int i = 0; i < pr.getSize(); i++) {
		if ((*pr[i].getProduct()).getCode() == (*product).getCode()) {
			pr[i].setCount(pr[i].getCount() + quantity);
			pr[i].setSumm((*pr[i].getProduct()).getPrice() * pr[i].getCount());
			return;
		}
	}
	ReceiptLine line(product, quantity);
	pr.add(line);
}

void Receipt::removeItem(Product* product) {
	int i;
	for (i = 0; i < pr.getSize(); i++) {
		if ((*pr[i].getProduct()).getCode() == (*product).getCode()) {
			pr.remove(i);
			return;
		}
	}
	cout << "The product is not in the receipt " << endl;
}

double Receipt::getTotal() {
	double total = 0;
	for (int i = 0; i < pr.getSize(); i++) {
		total += pr.getCurrent().getSumm();
		pr.next();
	}
	return total;
}

void Receipt::dataUpdate(dataBase& data) {
	for (int i = 0; i < pr.getSize(); i++) {
		for (auto& pair : data.data) {
			if (pr[i].getProduct()->getCode() == pair.first->getCode()) {
				pair.second -= pr[i].getCount();
			}
		}
	}
}

void Receipt::reset() {
	setTime();
	pr.reset();
}

void Receipt::setTime() {
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);
	time_.hour = localTime->tm_hour;
	time_.minute = localTime->tm_min;
	date.day = localTime->tm_mday;
	date.mounth = localTime->tm_mon + 1;
	date.year = localTime->tm_year + 1900;
}

Product::Product() : code(0), name(""), price(0) {}
Product::Product(int code, const string& name, double price) :
	code(code), name(name), price(price) {}
ReceiptLine::ReceiptLine() : count(0), summ(0) {}
ReceiptLine::ReceiptLine(Product* product, int count) {
	this->product = product;
	this->count = count;
	summ = (*product).getPrice() * count;
}
Receipt::Receipt() { setTime(), code = 0; }
Receipt::Receipt(int code) { this->code = code, setTime(); }
Receipt::Receipt(const Receipt& other) :
	code(other.code), time_(other.time_), date(other.date), pr(other.pr) {}
dataBase::~dataBase() {
	for (auto& pair : data) {
		free(pair.first);
	}
	data.clear();
}

ostream& operator<<(ostream& os, Receipt& receipt) {
	cout << endl;
	cout << "receipt number: " << receipt.code << " " << receipt.time_.hour << ":" << receipt.time_.minute << " " << receipt.date.day << "." << receipt.date.mounth << "." << receipt.date.year << endl;
	for (int i = 0; i < receipt.pr.getSize(); i++) {
		ReceiptLine receiptLine = receipt.pr[i];
		Product* product = receiptLine.getProduct();
		os << "Product: " << (*product).getName() << " - " << (*product).getPrice() << " Count: " << receiptLine.getCount() << " Total: " << receiptLine.getSumm() << endl;
	}
	return os;
}

Receipt& Receipt::operator=(const Receipt& other) {
	if (this != &other) {
		code = other.code;
		time_ = other.time_;
		date = other.date;
		pr = other.pr;
	}
	return *this;
}