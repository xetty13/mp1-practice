#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "products.h"
#include "container.h"
#include "database.h"
using namespace std;

TDataBase::TDataBase(const string& filename) {
	ScanFile(filename);
}
void TDataBase::ScanFile(const string& filename) {
	ifstream file(filename);
	string line;
	TProduct p;

	if (file.is_open()) {
		product.ChangeMemorry(1000, 100);
		while (getline(file, line)) {
			istringstream iss(line);
			string code;
			string name;
			double cost;

			if (iss >> code >> name >> cost) {
				p.Set(code, name, cost);
				product.Add(p);
			}
			else {
				file.close();
				string exp = "Ошибка чтения данных из строки: " + line;
				throw exp;
			}
		}
		n = product.Count();
		product.Compress();
		file.close();
	}
	else {
		string exp = "Невозможно открыть файл: " + filename;
		throw exp;
	}
}


int TDataBase::Check(const string& _code) { // -1 - Продукт не найден
	for (int i = 0; i < n; i++)
		if (product[i].GetCode() == _code)
			return i;
	return -1;
}

TProduct* TDataBase::GetProduct(int index) {
	if (index < 0 || index > n) {
		string exp = "dtbINDOUTOFRANGE";
		throw exp;
	}
	return &(product[index]);
}