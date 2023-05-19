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
	//Base* e = base.get_elements();
	std::cout << "Hi. Lets start.\n\nThis is all our products: " << endl;  cout << base << endl;

	while (true) {


		std::cout << "Choose what do u wanna do " << endl;
		std::cout << "Input 0 :kill the programm 1: add some products 2: remove some products 3: output receipt(cart) 4: print all products " << endl;
		
		int user, f=1; cin >> user;
		
		if (user == 0) {
			f = 0;
			std::cout << "Have a nice day! " << endl; 
			return;
		}
		if (user == 1) {

			f = 0;
			std::cout << "Which one do u wanna add ? Pls input code of product" << endl;
			string product;  cin >> product;
			int count = 0, ucount;
			Cart tmp;
			Base pr = base.get_elements()[0];
			for (int i = 0; i < base.len(); i++) {

				if (base.get_elements()[i].get_product() == product) {
					pr = base.get_elements()[i];
					
					if (q.find(pr)!=nullptr) {
						std::cout << "Your product: " << pr.get_product();
						count = pr.get_count()  - tmp.get_count();
						break;
					}
					else {
						std::cout << "Your product: " << pr.get_product();
						count = pr.get_count();
						break;
					}
				}
			}
			
			if (pr == base.get_elements()[0] &&  !(base.get_elements()[0].get_product() == product)) {
				std::cout << "Sorry, we dont have this product now" << endl;
				continue;
			}
			std::cout << "Input a count of products between 0 and " << count << endl;
			cin >> ucount;
			if (ucount < 0 || ucount > count) {
				std::cout << "Wrong count. Try again" << endl;
				continue;
			}
			if (ucount == 0) continue;
			base[base.find_id(pr)].set_count(pr.get_count() - ucount);
			if (q.find(pr)!=nullptr)
				q.add(*q.find(pr), ucount);
			else {
				q.add(pr.get_product(), ucount);

			}
			cout << "\nDone!" << endl;
		}
		if (user == 2) {

			f = 0;
			q.print_cart();
			if (q.empty())
			{
				cout << "Nothing in the cart. Add something!\n" << endl;
				continue;	
			}
			std::cout << "Which one do u wanna remove ? Pls input code of product" << endl;
			string product;  cin >> product;
			Base* pr = nullptr;
			int ucount;			
			Cart* tmp = q.find(product);
			if (tmp == nullptr) {
				std::cout << "Sorry, we dont have this product in the cart " << endl;
				continue;
			}
			std::cout << "Input a count of products between 0 and " << tmp->get_count() << endl;
			cin >> ucount;

			if (ucount < 0 || ucount > tmp->get_count()) {
				std::cout << "Wrong count. Try again" << endl;
				continue;
			}
			q.remove(*tmp, ucount);
			cout << "\nDone!" << endl;
			q.print_cart();

		}
		if (user == 3)
		{
			f = 0;
			if (q.empty())
			{
				cout << "Nothing in the cart. Add something.\n" << endl;
				continue;
			}
			cout << "Time of receipt formation: " << endl;
			q.pdata();
			q.print_cart();
			cout << "Total cost: " << q.sum() << endl;
		}
		if (user == 4)
		{
			cout << base;
			f = 0;
		}
		if (f) cout << "Input Date is wrong. Try again. " << endl;
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
ifstream& operator>>(ifstream& buf, Product& Date)
{
	buf >> Date.code >> Date.name >> Date.cost;
	return buf;
}
ostream& operator<<(ostream& buf, const Product& Date)
{
	buf << Date.code << " " << Date.name << " " << Date.cost << " " << endl;
	return buf;
}
istream& operator>>(istream& buf, Product& Date)
{
	buf >> Date.code >> Date.name >> Date.cost;
	return buf;
}
const Product& Product::operator=(const Product& new_product)
{
	if (*this == new_product) return *this;
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


//Date
void Date::now() {
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

ifstream& operator>>(ifstream& buf, Base& Date) {
	
	buf >> Date.product >> Date.count;
	return buf;
}
istream& operator>>(istream& buf, Base& Date) {
	buf >> Date.product >> Date.count;
	return buf;
}
ostream& operator<<(ostream& buf, const Base& Date) {
	buf <<  Date.product << Date.count << endl;
	return buf;
}
bool Base::operator == (const string& str) const
{
	return product == str; 
}
bool Base::operator == (const Base& base) const
{
	return product == base.product;
}
bool Base::operator != (const Base& base) const
{
	return !(*this == base);
}


Product Base::get_product() const
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


//Cart 
bool Cart::operator == (const Cart& tmp) const 
{
	if (tmp.product == nullptr) return product == nullptr;
	return (*(product) == *(tmp.product));
}
bool Cart::operator == (const Base & tmp) const {
	return (*product == tmp.get_product());
}
bool Cart::operator != (const Cart& tmp) const
{
	return !(product == tmp.product);
}
bool Cart::operator == (const string& tmp) const {
	return *product == tmp;
}
bool Cart::operator <= (const int& ncount) const {
	return count <= ncount;
}
Cart& Cart::operator = (const Cart& tmp) {
	product = tmp.product;
	count = tmp.count;
	cost = tmp.cost;
	return *this;
}
Cart& Cart::operator += (const int& ncount)
{
	count += ncount;
	return *this;
}
Cart& Cart::operator -= (const int& ncount) {
	count -= ncount;
	return *this;
}

Product* Cart::get_product() const
{
	return product;
}
int Cart::get_count() const
{
	return count;
}
double Cart::get_cost() const
{
	return cost;
}

//Receipt

const Receipt& Receipt::operator=(const Receipt& receipt)
{
	if (*this == receipt) return *this;
	num = receipt.num;
	size = receipt.size;
	Date = receipt.Date;
	cart = receipt.cart;
	return *this;
}

//functions
void Receipt::add(const Cart& product, const int& count)
{
	int id = cart.find_id(product);
	if (id != -1)
	{
		if (cart[id] == product) {
			cart[id] += count;
			return;
		}
	}
	size += 1;
	cart.push_back(product);
}
void Receipt::add(const Product product, const int& count )
{
	Cart tmp(product, count, product.get_cost());
	add(tmp, count);
}

void Receipt::remove(const Cart& product, const int& count)
{
	int id = cart.find_id(product);
	if (id != -1)
	{
		if (cart[id] <= count) { cart.pop_id(id); size--; }
		else { cart[id] -= count; }
	}
}
double Receipt::sum() const
{
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + cart[i].get_cost() * cart[i].get_count();
	}
	return sum;
}
void Receipt::print_cart() const {
	if (!size) cout << "Nothing in the cart. Add something!" << endl;
	cout << "Your products: " << endl;
	cout << cart << endl;
}
void Receipt::pdata() {
	Date.now();
}
void Receipt::set_num(const int& q) {
	(q > 0) ? num = q : num = 1;
}

Cart* Receipt::find(const Base& product) const
{
	for (int i = 0; i < size; i++)
	{
		if (cart[i] == product)
			return &cart[i];
	}
	return nullptr;
}
Cart* Receipt::find(const string& product) const
{
	Cart tmp;
	for (int i = 0; i < size; i++)
	{
		if (cart[i] == product)
			return &cart[i];
	}
	return nullptr;
}

int Receipt::len() const
{
	return size;
}
bool Receipt::empty()
{
	return size == 0;
}