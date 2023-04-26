#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

Constellation_library::Constellation_library(string& path) {
	ifstream in;
	int st_cnt;
	string name;
	in.open(path);
	if (in.is_open()) {
		in >> count;
		cns = new Constellation[count];
		for (int i = 0; i < count; i++) {
			in >> name >> st_cnt;
			Constellation tmp(name, st_cnt);
			in >> &tmp;
			cns[i] = tmp;
		}
		in.close();
	}
}
Constellation_library:: ~Constellation_library() {
	delete[] cns;
	cns = nullptr;
	count = 0;
}

Constellation::Constellation(std::string Cname, int n) {
	count = n;
	name = Cname;
	stars = new Star[n];
}
Constellation:: ~Constellation() {
	delete[] stars;
	stars = nullptr;
	count = 0;
	name = "";
}

string read_path() {
	ifstream in;
	string path;
	cout << endl << "Enter the path: ";
	cin >> path;
	return path;
}

void cnst_table(Constellation_library* lib, int count) {
	for (int i = 0; i < count / 2; i++) {
		cout << i + 1 << "." << lib->getCns(i)->getName() << " \t\t " << i + 6 << "." << lib->getCns(i + 5)->getName() << endl;
	}
	cout << "\nOutput format:\n\n  name distance magnitude coordinates(deg, min, sec)\n\n";
}


std::ostream& operator<< (std::ostream& out, const Constellation* cns) {
	cout << endl << cns->name << endl;
	for (int i = 0; i < cns->count; i++) {
		cout << "  " << cns->stars[i].name << " " << cns->stars[i].dist << " " << cns->stars[i].magnitude << " ";
		cout << cns->stars[i].deg << "° " << cns->stars[i].min << "' " << cns->stars[i].sec << "\"" << endl;
	}
	return out;
}
std::istream& operator>> (std::istream& in, const Constellation* cns) {
	for (int j = 0; j < cns->count; j++) {
		in >> cns->stars[j].name;
		in >> cns->stars[j].dist >> cns->stars[j].magnitude >> cns->stars[j].deg >> cns->stars[j].min >> cns->stars[j].sec;
	}
	return in;
}

Constellation& Constellation::operator=(const Constellation& obj) {
	this->count = obj.count;
	this->name = obj.name;
	this->stars = new Star[count];
	for (int i = 0; i < this->count; i++) {
		this->stars[i] = obj.stars[i];
	}
	return *this;
}

Star& Star::operator=(const Star& obj) {
	deg = obj.deg;
	dist = obj.dist;
	magnitude = obj.magnitude;
	min = obj.min;
	name = obj.name;
	sec = obj.sec;
	return *this;
}

void choice(Constellation_library* lib, int count) {
	string con;
	cout << "Choice a constellation" << endl;
	do {
		int flag = 0;
		cout << endl << ">> ";
		cin >> con;
		if (con == "stop") flag = 1;
		for (int i = 0; i < count && flag == 0; i++) {
			if (lib->getCns(i)->getName() == con) {
				cout << lib->getCns(i);
				flag = 1;
			}
		}
		if (!flag) cout << "Not found. Please, choose constellation from table" << endl;

	} while (con != "stop");
}