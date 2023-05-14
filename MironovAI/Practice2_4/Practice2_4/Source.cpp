#include "Header.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//global functions 
int PathError()
{
	std::cout << "This file isn`t exist. Be sure, that u writed a correct path with type *.<type>" << endl;
	return 1;
}
string input_path()
{
	string path; std::cout << "Input a path: \n "; cin >> path;
	ifstream file(path);
	if (!file) {
		throw PathError();
	}
	return path;
}
double operator+(int& f, Cart s) {
	double tmp = f;
	tmp += s.get_cost();
	return tmp;
}
void user() 
{
	
	NewConteiner<Base> base;  
	NewConteiner<Base>::read(input_path(), base);
	Receipt q;
	q.set_num(1);
	Base* e = base.get_elements();
	std::cout << "Hi. Lets start.\n  This is all our products: \n " << endl;  print_all_products(e, base.len());

	while (true) {


		std::cout << "Choose what do u wanna do " << endl;
		std::cout << "Input 0 :kill the programm, 1: add some products, 2: remove some products, 3: output receipt(end) " << endl;
		
		int user, f=1; cin >> user;
		
		if (user == 0) {
			f = 0;
			std::cout << "Have a nice day! " << endl; 
			for (int i = 0; i < base.len(); i++)
			{
				delete e[i].get_product();
			}
			return;
		}
		if (user == 1) {

			f = 0;
			std::cout << "Which one do u wanna add ? Pls input code of product" << endl;
			string product;  cin >> product;
			int count = 0, ucount;
			Cart tmp;
			Base* pr = nullptr;
			for (int i = 0; i < base.len(); i++) {

				if (*(base.get_elements()[i].get_product()) == product) {
					pr = &base.get_elements()[i];

					if (q.find(*pr).get_product()->get_name() != "") {
						std::cout << "Your product: " << *pr->get_product();
						count = pr->get_count()  - tmp.get_count();
						break;
					}
					else {
						std::cout << "Your product: " << *pr->get_product();
						count = pr->get_count();
						break;
					}
				}
			}
			if (pr == nullptr) {
				std::cout << "Sorry, we dont have this product now" << endl;
				continue;
			}
			std::cout << "Input a count of products between 0 and " << count << endl;
			cin >> ucount;
			if (ucount < 0 || ucount > count) {
				std::cout << "Wrong count. Try again" << endl;
				continue;
			}
			pr->set_count(pr->get_count() - ucount);
			if (q.find(*pr).get_product()->get_name() != "")
				q.add(q.find(*pr), ucount);
			else {
				q.add(pr->get_product(), ucount);

			}
			cout << "\nDone!" << endl;
		}
		if (user == 2) {

			f = 0;
			q.print_cart();
			std::cout << "Which one do u wanna remove ? Pls input code of product" << endl;
			string product;  cin >> product;
			Base* pr = nullptr;
			int ucount;			
			Cart tmp = q.find(product);
			if (tmp.get_product()->get_name() == "") {
				std::cout << "Sorry, we dont have this product in the cart " << endl;
				continue;
			}
			std::cout << "Input a count of products between 0 and " << tmp.get_count() << endl;
			cin >> ucount;

			if (ucount < 0 || ucount > tmp.get_count()) {
				std::cout << "Wrong count. Try again" << endl;
				continue;
			}
			q.remove(tmp, ucount);
			cout << "\nDone!" << endl;
			q.print_cart();

		}
		if (user == 3)
		{
			f = 0;
			cout << "Time of receipt formation: " << endl;
			q.pdata();
			q.print_cart();
			cout << "Total cost: " << q.sum() << endl;
		}
		if (f) cout << "Input data is wrong. Try again. " << endl;
	}
	
	std::cout << "Have a nice day! " << endl;

}


//Product

Product::Product()
{
	code = '*';
	name = '*';
	cost = 0;
}
Product::Product(const string& ncode, const string& nname, const double& ncost)
{
	code = ncode;
	name = nname;
	cost = ncost;
	
}
Product::Product(const Product& new_product)
{
	code = new_product.code;
	name = new_product.name;
	cost = new_product.cost;
}



//overloaded operations
ifstream& operator>>(ifstream& buf, Product& data)
{
	buf >> data.code >> data.name >> data.cost;
	return buf;
}
ostream& operator<<(ostream& buf, const Product& data)
{
	buf << data.code << " " << data.name << " " << data.cost << " " << endl;
	return buf;
}
istream& operator>>(istream& buf, Product& data)
{
	buf >> data.code >> data.name >> data.cost;
	return buf;
}
Product& Product::operator=(const Product& new_product)
{
	code = new_product.code;
	name = new_product.name;
	cost = new_product.cost;
	return *this;
}
bool Product::operator==(const string& str) const {
	return (code == str || name == str);
}
bool Product::operator==(const Product& prod) const
{
	return (code == prod.code && name == prod.name && cost == prod.cost);
}


string Product::get_name() const {
	if (this == nullptr) return "";
	return name; 
}
string Product::get_code() const {
	return code; 
}
double Product::get_cost() const {
	return cost;
}


//Data
void Data::now() {
	time_t rawtime; //creates and object of the built in time function
	time(&rawtime); //gets the time from the computer
	timeinfo = localtime(&rawtime); //store that time here
	/*
	year = timeinfo->tm_year + 1900;
	month = timeinfo->tm_mon + 1;
	day = timeinfo->tm_mday;
	hour = timeinfo->tm_hour;
	min = timeinfo->tm_min;
	sec = timeinfo->tm_sec;
	*/
	std::cout << asctime(timeinfo) << endl;
}


//Base
ifstream& operator>>(ifstream& buf, Base& data) {
	if (data.product == nullptr) data.product = new Product;
	buf >> *(data.product) >> data.count;
	return buf;
}
ostream& operator<<(ostream& buf, const Base& data) {
	buf << *(data.product) << data.count << endl;
	return buf;
}
istream& operator>>(istream& buf, Base& data) {
	if (data.product == nullptr) data.product = new Product;
	buf >> *(data.product) >> data.count;
	return buf;
}
bool Base::operator == (const string& str) const
{
	return *(product) == str; 
}
bool Base::operator == (const Base& base) const
{
	return *product == *(base.product);
}
bool Base::operator != (const Base& base) const
{
	return !(*this == base);
}


Product* Base::get_product() const
{
	return product;
}
int Base::get_count() const
{
	return count;
}
void Base::set_count(const int ucount)
{
	count = ucount;
}

