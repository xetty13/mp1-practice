#include "receipt.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

int Product::getCode() { return code; }
float Product::getPrice() { return price; }
string Product::getName() { return name; }
Product& ReceiptLine::getProduct() { return product; }
int ReceiptLine::getCount() { return count; }
float ReceiptLine::getSumm() { return summ; }
void ReceiptLine::setCount(int count) { this->count = count; }
void ReceiptLine::setSumm(int summ) { this->summ = summ; }

string start() {
	string path;
	while (true) {
		cout << "Enter the file path..." << endl;
		getline(cin, path);
		ifstream file(path);
		if (file.good()) {
			file.close();
			return path;
		}
		cout << "ERROR: Could not open file!\n" << endl;
	}
}

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
		Product product(stoi(code), name, stof(price));
		data.push_back(make_tuple(product, stoi(count)));
	}
}

void menu(dataBase& data, Receipt& receipt) {
	int choice;
	do {
		cout << "0)Add 1)Remove 2)Count total cost 3)New receipt 4)Exit : ";
		cin >> choice;
		switch (choice) {
		case 0: {
			Product product = data.searchProductByCode();
			receipt.addItem(product, data);
			cout << receipt << endl;
			break;
		}
		case 1: {
			Product product = data.searchProductByCode();
			receipt.removeItem(product);
			cout << receipt << endl;
			break;
		}
		case 2: {
			cout << receipt;
			cout << "Total cost: " << receipt.getTotal() << endl;
			break;
		}
		case 3: {
			receipt.reset();
			break;
		}
		default:
			break;
		}
	} while (choice != 4);
}

Product dataBase::searchProductByCode() {
	bool isFound = false;
	int code;
	while (!isFound) {
		cout << "Enter product code: ";
		cin >> code;
		for (auto& tuple : data) {
			if (get<0>(tuple).getCode() == code && get<1>(tuple) > 0) {
				return get<0>(tuple);
				isFound = true;
			}
		}
		if (!isFound) {
			cout << "Invalid code or the product is out of stock " << endl;
		}
	}
}

void Receipt::addItem(Product& product, dataBase& db) {
	int quantity;
	bool isCorrectQuantity = false;
	while (!isCorrectQuantity) {
		cout << "Enter quantity: ";
		cin >> quantity;
		for (auto& tuple : db.data) {
			if (get<0>(tuple).getCode() == product.getCode() && get<1>(tuple) > quantity && quantity > 0) {
				isCorrectQuantity = true;
			}
		}
		if (!isCorrectQuantity) {
			cout << "Wrong quantity " << endl;
		}
	}
	for (int i = 0; i < pr.getSize(); i++) {
		if (pr[i].getProduct().getCode() == product.getCode()) {
			pr[i].setCount(pr[i].getCount() + quantity);
			pr[i].setSumm(pr[i].getProduct().getPrice() * pr[i].getCount());
			return;
		}
	}
	ReceiptLine line(product, quantity);
	pr.add(line);
}

void Receipt::removeItem(Product& product) {
	int i;
	for (i = 0; i < pr.getSize(); i++) {
		if (pr[i].getProduct().getCode() == product.getCode()) {
			pr.remove(i);
			return;
		}
	}
	cout << "The product is not in the receipt " << endl;
}

double Receipt::getTotal() {
	double total = 0;
	for (int i = 0; i < pr.getSize(); i++) {
		total += pr[i].getSumm();
	}
	return total;
}

Product::Product() : code(0), name(""), price(0) {}
Product::Product(int code, const string& name, double price) :
	code(code), name(name), price(price) {}
ReceiptLine::ReceiptLine() : count(0), summ(0) {}
ReceiptLine::ReceiptLine(Product product, int count) {
	this->product = product;
	this->count = count;
	summ = product.getPrice() * count;
}
Receipt::Receipt() { setTime(); }

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

ostream& operator<<(ostream& os, Receipt& receipt) {
	cout << endl;
	cout << receipt.time_.hour << ":" << receipt.time_.minute << " " << receipt.date.day << "." << receipt.date.mounth << "." << receipt.date.year << endl;
	for (int i = 0; i < receipt.pr.getSize(); i++) {
		ReceiptLine& receiptLine = receipt.pr[i];
		Product& product = receiptLine.getProduct();
		os << "Product: " << product.getName() << " - " << product.getPrice() << " Count: " << receiptLine.getCount() << " Total: " << receiptLine.getSumm() << endl;
	}
	return os;
}

