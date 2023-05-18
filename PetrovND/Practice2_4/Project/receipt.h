#ifndef _RECEIPT_H
#define _RECEIPT_H
#include "container.h"
#include <vector>
#include <string>
using namespace std;

class Product {
public:
	Product(int code, const string& name, double price);
	Product();
	int getCode() const;
	float getPrice() const;
	string getName() const;
private:
	int code;
	string name;
	float price;
};

struct dataBase {
	dataBase(const string& path);
	~dataBase();
	Product* searchProductByCode();
	vector<pair<Product*, int>> data;
};

struct Time {
	int hour;
	int minute;
};

struct date {
	int day;
	int mounth;
	int year;
};

class ReceiptLine {
public:
	ReceiptLine();
	ReceiptLine(Product* product, int count);
	Product* getProduct() const;
	int getCount() const;
	float getSumm() const;
	void setCount(int count);
	void setSumm(int summ);
private:
	Product* product;
	int count;
	float summ;
};

class Receipt {
public:
	Receipt();
	Receipt(int code);
	Receipt(const Receipt& other);
	void reset();
	double getTotal();
	void dataUpdate(dataBase& data);
	void addItem(Product* product, dataBase& data);
	void removeItem(Product* product);
	Receipt& operator=(const Receipt& other);
	friend ostream& operator<<(ostream& os, Receipt& receipt);
private:
	int code;
	Time time_;
	date date;
	void setTime();
	Container<ReceiptLine> pr;
};
#endif // !_RECEIPT_H
