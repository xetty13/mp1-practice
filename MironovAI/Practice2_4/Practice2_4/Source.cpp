#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//global functions 
int PathError()
{
	std::cout << "This file isn`t exist. Be sure, that u writed a correct path with type *.<type>" << endl;
	return 1;
}
int IndexError(int index, int size) {
	cout << "Index Error. A index should be the greater (or equal) than 0 and the less than " << size << "\nU inputed: " << index << endl;
	return -1; 
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
template<typename T>
int operator+(int& f, Cart<T> s) {
	int tmp = f;
	tmp += s.cost;
}
void user() 
{
	
	NewConteiner<Base<Product>> base;  NewConteiner<Base<Product>>::read(input_path(), base);
	Receipt<Cart<Product>> q;
	q.set_num(1);
	std::cout << "Hi. Lets start.\n  This is all our products: \n " << endl;  print_all_products(base.get_elements(), base.len());

	while (true) {


		std::cout << "Choose what do u wanna do " << endl;
		std::cout << "Input 0 :kill the programm, 1: add some products, 2: remove some products, 3: output receipt(end) " << endl;
		
		int user, f=1; cin >> user;
		
		if (user == 0) {
			f = 0;
			std::cout << "Have a nice day! " << endl; return;
		}
		if (user == 1) {

			f = 0;
			std::cout << "Which one do u wanna add ? Pls input code of product" << endl;
			string product;  cin >> product;
			int count = 0, ucount;
			Cart<Product> tmp;
			Base<Product>* pr = nullptr;
			for (int i = 0; i < base.len(); i++) {

				if (base.get_elements()[i].product == product) {
					pr = &base.get_elements()[i];

					if (q.find(*pr).product.get_name() != "") {
						std::cout << "Your product: " << pr->product;
						count = pr->count - tmp.count;
						break;
					}
					else {
						std::cout << "Your product: " << pr->product;
						count = pr->count;
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
			pr->count -= ucount;
			if (q.find(*pr).product.get_name() != "")
				q.add(q.find(*pr), ucount);
			else {
				q.add(pr->product, ucount);

			}
			cout << "\nDone!" << endl;
		}
		if (user == 2) {

			f = 0;
			q.print_cart();
			std::cout << "Which one do u wanna remove ? Pls input code of product" << endl;
			string product;  cin >> product;
			Base<Product>* pr = nullptr;
			int ucount;			
			Cart<Product> tmp = q.find(product);
			if (tmp.product.get_name() == "") {
				std::cout << "Sorry, we dont have this product in the cart " << endl;
				continue;
			}
			std::cout << "Input a count of products between 0 and " << tmp.count << endl;
			cin >> ucount;

			if (ucount < 0 || ucount > tmp.count) {
				std::cout << "Wrong count. Try again" << endl;
				break;
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
//constructors and destructor
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
Product::Product(Product& new_product)
{
	code = new_product.code;
	name = new_product.name;
	cost = new_product.cost;
}
Product::~Product()
{
	code = ' ';
	name = ' ';
	cost = 0;
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
bool Product::operator==(string& str) { return (code == str || name == str); }
bool Product::operator==(Product& prod)
{
	return (code == prod.code && name == prod.name && cost == prod.cost);
}
//getters
string Product::get_name() { return name; }
string Product::get_code() { return code; }
double Product::get_cost() { return cost; }





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



