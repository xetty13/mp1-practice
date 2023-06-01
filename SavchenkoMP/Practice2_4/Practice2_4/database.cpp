#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "products.h"
#include "container.h"
#include "database.h"
#include "datentime.h"
using namespace std;

// ========== TDataLine ========== //
TDataLine::TDataLine(const string _code, const string _name, const double _cost, const int _count) {
	product.Set(_code, _name, _cost);
	count = _count;
}
void TDataLine::Set(const string _code, const string _name, const double _cost, const int _count) {
	product.Set(_code, _name, _cost);
	count = _count;
}
void TDataLine::Print() {
	product.Print();
	cout << count << " шт." << endl;
}

bool TDataLine::operator==(const TDataLine& dl) const {
	if (product.GetCode() == dl.product.GetCode()) return true;
	return false;
}
bool TDataLine::operator!=(const TDataLine& dl) const {
	return !((*this) == dl);
}
const TDataLine& TDataLine::operator=(const TDataLine& dl) {
	if (this != &dl) {
		product = dl.product;
		count = dl.count;
	}
	return (*this);
}


// ========== TDataBase ========== //
TDataBase::TDataBase(const string& filename) {
	ScanFile(filename);
}
void TDataBase::ScanFile(const string& filename) {
	ifstream file(filename);
	string line;

	if (file.is_open()) {
		products.ChangeMemorry(1000, 100);
		while (getline(file, line)) {
			istringstream iss(line);
			string code;
			string name;
			double cost;
			int count;

			if (iss >> code >> name >> cost >> count) {
				TDataLine dl(code, name, cost, count);
				products.Add(dl);
			}
			else {
				file.close();
				string exp = "Ошибка чтения данных из строки: " + line;
				throw std::out_of_range(exp);
			}
		}
		products.Compress();
		file.close();
	}
	else {
		string exp = "Невозможно открыть файл: " + filename;
		throw std::out_of_range(exp);
	}
}

void TDataBase::ArchiveData(const string& filename) {
	string tmp_name = filename;
	tmp_name.erase(tmp_name.length() - 4, tmp_name.length());
	
	TDate date;
	TTime time;
	date.setCurrentDay();
	time.setCurrentTime();
	string new_filename = tmp_name + "_archive_" + time.StringTime() + "_" + date.StringDate() + ".txt";

	ofstream file(new_filename);
	if (file.is_open()) {
		for (int i = 0; i < products.Count(); i++) {
			file << products[i].GetCode() << " " << products[i].GetName() << " " << products[i].GetCost() << " " << products[i].GetProductCount() << "\n";
		}
		file.close();
	}
	else {
		string exp = "fdtbARCHIVEERROR";
		throw std::out_of_range(exp);
	}
	
}
void TDataBase::UpdateData(const string& filename) {
	ofstream file(filename);
	if (file.is_open()) {
		for (int i = 0; i < products.Count(); i++) {
			file << products[i].GetCode() << " " << products[i].GetName() << " " << products[i].GetCost() << " " << products[i].GetProductCount() << "\n";
		}
		file.close();
	}
	else {
		string exp = "fdtbUPDATEERROR";
		throw std::out_of_range(exp);
	}
}


int TDataBase::Check(const string& _code) {	// -1 - Продукт не найден
	for (int i = 0; i < products.Count(); i++)
		if (products[i].GetCode() == _code)
			return i;
	return -1;
}

TProduct* TDataBase::GetProduct(int index) {
	if (index < 0 || index > products.Count()) {
		string exp = "dtbINDOUTOFRANGE";
		throw std::out_of_range(exp);
	}
	return products[index].GetProduct();
}

int& TDataBase::GetProductCount(const string& _code) {
	int ind = Check(_code);
	if (ind < 0) {
		string exp = "dtbCOUТNONEXISTPROD";
		throw std::out_of_range(exp);
	}
	return products[ind].GetProductCount();
}