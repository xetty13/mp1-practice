#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
#include <fstream>
using namespace std;

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
#endif // !_PRODUCTH_
