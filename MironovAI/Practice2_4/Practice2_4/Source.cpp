#include "Header.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
void Receipt::add(const Product& product, const int& count )
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
	if (!size) {
		cout << "Nothing in the cart. Add something!" << endl;
		return;
	}
	cout << "\nYour products:\n ";
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
bool Receipt::empty() const
{
	return size == 0;
}