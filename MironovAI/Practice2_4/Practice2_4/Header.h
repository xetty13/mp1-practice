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
template<typename Type> // template for "Cart" and "Base"
void print_all_products(const Type* products,const int size)
{
	cout << "Products: \n " << endl;
	for (int i = 0; i < size; i++) {
		cout << products[i] << endl;
	}
} 
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
	friend ifstream& operator>>(ifstream& buf, Product& data);
	friend istream& operator>>(istream& buf, Product& data);
	friend ostream& operator<<(ostream& buf, const Product& data);
	Product& operator=(const Product& new_product);
	bool operator==(const string& str) const;
	bool operator==(const Product& prod) const;
	//getters
	string get_name() const;
	string get_code() const;
	double get_cost() const;
};


class Base {
private:
	Product* product;
	int count;
public:
	Base() {
		count = 0;
		product = nullptr;
	}
	/*
	virtual ~Base()
	{
		count = 0;
		if (product != nullptr) delete product;
	}
	*/
	
	friend ifstream& operator>>(ifstream& buf, Base& data);
	friend ostream& operator<<(ostream& buf, const Base& data); 
	friend istream& operator>>(istream& buf, Base& data);
	bool operator == (const string& str) const;
	bool operator == (const Base& base) const;
	bool operator != (const Base& base) const;
	Product* get_product() const;
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
	Cart(const Product*& pr, const int& ncount,const double& ncost = 0) {
		product = new Product;
		*product = *pr;
		count = ncount;
		cost = ncost;
	}
	friend ifstream& operator>>(ifstream& buf, Cart& data) {
		if (data.product == nullptr) data.product = new Product;
		buf >> *(data.product) >> data.count >> data.cost;
		return buf;
	}
	friend ostream& operator<<(ostream& buf, const Cart& data) {
		buf << *(data.product) << data.count << endl;
		return buf;
	}
	friend istream& operator>>(istream& buf, Cart& data) {
		if (data.product == nullptr) data.product = new Product;
		buf >> *(data.product) >> data.count >> data.cost;
		return buf;
	}
	//bool operator != (Product tmp) { return (product != tmp.product); }
	bool operator == (const Cart& tmp) const{
		return (*(product) == *(tmp.product));
	}
	bool operator == (const Base& tmp) const { 
		return (product == tmp.get_product()); 
	}
	bool operator != (const Cart& tmp) const {
		return !(product == tmp.product); 
	}
	bool operator == (const string& tmp) const {
		return *product == tmp;
	}
	bool operator <= (const int& ncount) const { 
		return count <= ncount; 
	}
	Cart& operator = (const Cart& tmp) {
		product = tmp.product;
		count = tmp.count;
		cost = tmp.cost;
		return *this;
	}
	Cart& operator += (const int& ncount)
	{
		count += ncount;
		return *this;
	}
	Cart& operator -= (const int& ncount) {
		count -= ncount;
		return *this;
	}
	
	Product* get_product() const
	{
		return product;
	}
	int get_count() const
	{
		return count;
	}
	double get_cost() const
	{
		return cost;
	}
};
//Data
struct Data
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
	Data data;
	NewConteiner<Cart> cart;

public:
	//constructors
	Receipt() { 
		num = 0; size = 0; data.timeinfo = NULL;
	}
	/*
	Receipt(int nnum, int nsize, Cart*& nproducts)
	{
		num = nnum;
		size = nsize;
		cart = NewConteiner<Cart>(size, nproducts);
	}
	*/
	Receipt(const Receipt& receipt)
	{
		num = receipt.num;
		size = receipt.size;
		data = receipt.data;
		cart = NewConteiner<Cart>(receipt.cart);
	}

	//destrictor
	virtual ~Receipt() {}

	//overloaded operations
	friend istream& operator>>(istream& buf, Receipt& data)
	{
		buf >> data.num >> data.size >> data.cart;
		return buf;
	}
	friend ostream& operator<<(ostream& buf, Receipt& data)
	{
		buf << "\nNumber of a receipt: " << data.num << endl;
		buf << "Data: " << endl;
		data.data.now();
		buf << "Products: \n";
		for (int i = 0; i < data.size; i++) {
			buf << data.cart[i];
		}
		buf << endl;
		return buf;
	}
	Receipt& operator=(const Receipt& receipt) 
	{
		num = receipt.num;
		size = receipt.size;
		data = receipt.data;
		cart = receipt.cart;
		return *this;
	}
	
	//functions
	void add(const Cart product, const int& count = 0)
	{
		int ncount = 0;
		if (!count) ncount = product.get_count();
		for (int i = 0; i < size; i++) {
			if (cart[i] == product) {
				cart[i] += ncount;
				return;
			}
		}
		size += 1;
		cart.push_back(product);
	}
	void add(const Product* product, const int& count)
	{
		Cart tmp(product, count, product->get_cost());
		add(tmp, count);
	}

	void remove(const Cart& product, const int& count)
	{
		for (int i = 0; i < size; i++) {
			if (cart[i] == product) {
				if (cart[i] <= count) { cart.pop_id(i); }
				else { cart[i] -= count; }
			}
		}
	}
	double sum() const
	{
		double sum = 0;
		for (int i = 0; i < size; i++) {
			sum = sum + cart[i].get_cost() * cart[i].get_count();
		}
		return sum;
	}
	void print_cart() const { 
		if (!size) cout << "Nothing in the cart. Add something!" << endl;
		cout << "Your products:: " << endl;
		for (int i = 0; i < size; i++)
			cout << cart << endl;
	}
	void pdata() { 
		data.now(); 
	}
	void set_num(const int& q) { 
		(q > 0) ? num = q : num = 1; 
	}

	Cart& find(const Base& product) const
	{
		Cart tmp;
		for (int i = 0; i < size; i++)
		{
			if (cart[i] == product)
				return cart[i];
		}
		return tmp;
	}
	Cart& find(const string& product) const
	{
		Cart tmp;
		for (int i = 0; i < size; i++)
		{
			if (cart[i] == product)
				return cart[i];
		}
		return tmp;
	}

	int len() const
	{
		return size;
	}
};

#endif

//constructors

