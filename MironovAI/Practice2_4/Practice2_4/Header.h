#ifndef _HEADER_H_
#define _HEADER_H_

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
#include "GlobalFunctions.h"
#include "Product.h"
#include "Base.h"
using namespace std;

class Cart {
private:
	Product *product;
	int count;
	double cost;
public:
	Cart()
	{
		count = 0;
		cost = 0;
		product = nullptr;

	}
	Cart(const Product& pr, const int& ncount,const double& ncost = 0) {
		product = new Product;
		*product = pr;
		count = ncount;
		cost = ncost;
	}
	
	friend ifstream& operator>>(ifstream& buf, Cart& Date) {
		if (Date.product == nullptr) Date.product = new Product;
		buf >> *(Date.product) >> Date.count >> Date.cost;
		return buf;
	}
	friend istream& operator>>(istream& buf, Cart& Date) {
		if (Date.product == nullptr) Date.product = new Product;
		buf >> *(Date.product) >> Date.count >> Date.cost;
		return buf;
	}
	
	friend ostream& operator<<(ostream& buf, const Cart& Date) {
		buf << *(Date.product) << Date.count << endl;
		return buf;
	}
	//bool operator != (Product tmp) { return (product != tmp.product); }
	bool operator == (const Cart& tmp) const;
	bool operator == (const Base& tmp) const;
	bool operator != (const Cart& tmp) const;
	bool operator == (const string& tmp) const;
	bool operator <= (const int& ncount) const;
	Cart& operator = (const Cart& tmp);
	Cart& operator += (const int& ncount);
	Cart& operator -= (const int& ncount);
	
	Product* get_product() const;
	int get_count() const;
	double get_cost() const;
};
//Date
struct Date
{
	//int year, month, day, hour, min, sec;
	tm* timeinfo;
	void now();
};

//Receipt
class Receipt
{
private:
	int num;
	int size;
	Date Date;
	NewContainer<Cart> cart;
public:
	//constructors
	Receipt() {
		num = 0; size = 0; Date.timeinfo = NULL;
	}
	Receipt(const Receipt& receipt)
	{
		num = receipt.num;
		size = receipt.size;
		Date = receipt.Date;
		cart = NewContainer<Cart>(receipt.cart);
	}
	//overloaded operations
	/*
	friend istream& operator>>(istream& buf, Receipt& Date)
	{
		buf >> Date.num >> Date.size >> Date.cart;
		return buf;
	}
	*/

	friend ostream& operator<<(ostream& buf, Receipt& Date)
	{
		buf << "\nNumber of a receipt: " << Date.num << endl;
		buf << "Date: " << endl;
		Date.Date.now();
		buf << "Products: \n";
		for (int i = 0; i < Date.size; i++) {
			buf << Date.cart[i];
		}
		buf << endl;
		return buf;
	}
	bool operator == (const Receipt& r) { return (size == r.size && cart == r.cart); }
	const Receipt& operator=(const Receipt& receipt);
	//functions
	void add(const Cart& product, const int& count = 1);
	void add(const Product& product, const int& count = 1);
	void remove(const Cart& product, const int& count);
	double sum() const;
	void print_cart() const;
	void pdata();
	void set_num(const int& q);
	Cart* find(const Base& product) const;
	Cart* find(const string& product) const;
	int len() const;
	bool empty() const;
};

#endif
