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
	double cost = 0;
public:
	void Set(const string _code, const string _name, const double _cost);
	string GetCode() { return code; }
	string GetName() { return name; }
	double GetCost() { return cost; }

	bool operator==(const TProduct& p);
	const TProduct& operator=(const TProduct& p);

	void Print() { // Печать всех данных о продукте
		cout << code << ' ' << name << ' ' << cost << ' ' << endl;
	}
	friend ostream& operator<<(ostream& out, const TProduct& p) { // Печать с выделенным количеством места
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
