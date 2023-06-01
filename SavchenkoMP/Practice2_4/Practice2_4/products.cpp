#include <iostream>
#include <string>
#include "products.h"
using namespace std;

TProduct::TProduct(const string& _code, const string& _name, const double _cost) {
	code = _code;
	name = _name;
	cost = _cost;
}

void TProduct::Set(const string _code, const string _name, const double _cost) {
	code = _code;
	name = _name;
	cost = _cost;
}

bool TProduct::operator==(const TProduct& p) const {
	if (code == p.code) return true;
	return false;
}

const TProduct& TProduct::operator=(const TProduct& p) {
	if (this != &p) {
		code = p.code;
		name = p.name;
		cost = p.cost;
	}
	return (*this);
}

ostream& TProduct::ostreamProduct(ostream& out) {
	out << code << " " << name << " " << cost;
	return out;
}