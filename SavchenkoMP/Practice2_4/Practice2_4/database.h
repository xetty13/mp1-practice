#ifndef _DATABASE_H
#define _DATABASE_H
#include <iostream>
#include <fstream>
#include <string>
#include "products.h"
#include "container.h"
using namespace std;

class TDataLine {
private:
	TProduct product;
	int count;
public:
	TDataLine(const string _code = "", const string _name = "", const double _cost = 0, const int _count = 0);
	void Set(const string _code, const string _name, const double _cost, const int _count);
	void ChangeCount(int dcount) { count += dcount; }
	TProduct* GetProduct(){ return &product; }
	void Print();
	string GetCode() { return product.GetCode(); }
	string GetName() const { return product.GetName(); }
	double GetCost() const { return product.GetCost(); }
	int& GetProductCount() { return count; }
	
	bool operator==(const TDataLine& dl) const;
	bool operator!=(const TDataLine& dl) const;
	const TDataLine& operator=(const TDataLine& dl);
	friend ostream& operator<<(ostream& out, const TDataLine& d) {
		out << d.product << " " << setfill(' ') << setw(3) << d.count;
		return out;
	}
};


class TDataBase {
private:
	TContainer<TDataLine> products;
public:
	TDataBase(const string& filename = "data.txt");
	void ScanFile(const string& filename = "data.txt");

	void ArchiveData(const string& filename = "data.txt");
	void UpdateData(const string& filename = "data.txt");

	// Кол-во продуктов в базе данных
	int Size() { return products.Count(); } 

	// -1 - Продукт не найден
	int Check(const string& _code); 
	TProduct* GetProduct(int index);
	int& GetProductCount(int ind) { return products[ind].GetProductCount(); }
	int& GetProductCount(const string& _code);

	void PrintAll() {
		for (int i = 0; i < products.Count(); i++) {
			cout << "#" << i << ": ";
			products[i].Print();
		}
	}
	friend ostream& operator<<(ostream& out, const TDataBase& d) {
		for (int i = 0; i < d.products.Count(); i++)
			out << "№" << i << ": " << d.products[i] << endl;
		return out;
	}
	
};

#endif // !_DATABASE_H
