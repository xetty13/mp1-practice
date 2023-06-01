#include <iostream>
#include <fstream>
#include <string>
#include "Product.h"
using namespace std;

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
	buf << Date.code << " " << Date.name << " " << Date.cost << " ";
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

