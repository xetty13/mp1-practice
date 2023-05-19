#ifndef _HEADER_H_
#define _HEADER_H_

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
using namespace std;

//functions
int PathError();
string input_path();
/*
template<typename Type> // template for "Cart" and "Base"
void print_all_products(const Type* products,const int size)
{
	cout << "Products: \n " << endl;
	for (int i = 0; i < size; i++) {
		cout << products[i] << endl;
	}
} 
*/
void user();


class Product
{
private:
	string code;
	string name;
	double cost;

public:
	//constructors
	Product();
	Product(const string& ncode, const string& nname, const double& ncost);
	Product(const Product& new_product);

	
	//overloaded operations
	friend ifstream& operator>>(ifstream& buf, Product& Date);
	friend istream& operator>>(istream& buf, Product& Date);
	friend ostream& operator<<(ostream& buf, const Product& Date);
	const Product& operator=(const Product& new_product);
	bool operator==(const string& str) const;
	bool operator==(const Product& prod) const;
	//getters
	string get_name() const;
	string get_code() const;
	double get_cost() const;
};


class Base {
private:
	Product product;
	int count;
public:
	Base() {
		count = 0;
	}
	friend ifstream& operator>>(ifstream& buf, Base& Date);
	friend ostream& operator<<(ostream& buf, const Base& Date); 
	friend istream& operator>>(istream& buf, Base& Date);
	bool operator == (const string& str) const;
	bool operator == (const Base& base) const;
	bool operator != (const Base& base) const;
	Product get_product() const;
	int get_count() const;
	void set_count(const int ucount);
};


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
	NewConteiner<Cart> cart;
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
		cart = NewConteiner<Cart>(receipt.cart);
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
	void add(const Product product, const int& count = 1);
	void remove(const Cart& product, const int& count);
	double sum() const;
	void print_cart() const;
	void pdata();
	void set_num(const int& q);
	Cart* find(const Base& product) const;
	Cart* find(const string& product) const;
	int len() const;
	bool empty();
};

#endif
