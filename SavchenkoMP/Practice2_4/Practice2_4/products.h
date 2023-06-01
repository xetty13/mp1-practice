#ifndef _PRODUCTS_H
#define _PRODUCTS_H
#include <iostream>
#include <iomanip> // setfill(), setw()
#include <string>
using namespace std;

class TProduct {
private:
	string code;
	string name;
	double cost;
public:
	TProduct(const string& _code = "", const string& _name = "", const double _cost = 0);
	void Set(const string _code, const string _name, const double _cost);
	string GetCode() const { return code; }
	string GetName() const { return name; }
	double GetCost() const { return cost; }

	bool operator==(const TProduct& p) const;
	const TProduct& operator=(const TProduct& p);

	// Печать всех данных о продукте без форматирования
	void Print() {
		cout << code << ' ' << name << ' ' << cost;
	}
	ostream& ostreamProduct(ostream& out);
	
	// Печать с выделенным количеством места (с форматированием)
	friend ostream& operator<<(ostream& out, const TProduct& p) {
		int NameLeng = 35;
		int CostLeng = 5;
		char NameFill = ' ';
		char CostFill = ' ';
		
		string tmp_name = p.name;
		if (tmp_name.length() > NameLeng)
			tmp_name.erase(NameLeng, tmp_name.length());
		
		out << p.code << ' ';
		out << setfill(NameFill) << setw(NameLeng) << tmp_name << ' ';
		out << setfill(CostFill) << setw(CostLeng) << p.cost << ' ';

		return out;
	}
};

#endif // !_PRODUCTS_H
