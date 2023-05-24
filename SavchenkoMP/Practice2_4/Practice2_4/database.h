#ifndef _DATABASE_H
#define _DATABASE_H
#include <iostream>
#include <string>
#include "products.h"
#include "container.h"
using namespace std;

class TDataBase {
private:
	int n;
	TContainer<TProduct> product;
public:
	TDataBase(const string& filename = "data.txt");
	void ScanFile(const string& filename);

	int Check(const string& _code); // -1 - Продукт не найден
	TProduct* GetProduct(int index);

	void PrintAll() {
		for (int i = 0; i < n; i++) {
			cout << "№" << i << ": ";
			product[i].Print();
		}
	}
	friend ostream& operator<<(ostream& out, const TDataBase& d) {
		for (int i = 0; i < d.n; i++)
			out << "№" << i << ": " << d.product[i] << endl;
		return out;
	}
};

#endif // !_DATABASE_H
