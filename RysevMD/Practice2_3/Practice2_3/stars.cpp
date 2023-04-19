#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

Constellation_library::Constellation_library(int n) {
	count = n;
	cns = new Constellation * [n];
}
Constellation_library:: ~Constellation_library() {
	delete (*cns);
	delete[] cns;
}

Constellation::Constellation(std::string Cname, int n) {
	count = n;
	name = Cname;
	stars = new Star[n];
}
Constellation:: ~Constellation() {
	delete[] stars;
}

void read_data(Constellation_library*& lib, int& cnt) {
	ifstream in;
	string path, name;
	int st_cnt;
	cout << endl << "Enter the path: ";
	cin >> path;
	in.open(path);
	if (in.is_open()) {
		in >> cnt;
		lib = new Constellation_library(cnt);
		for (int i = 0; i < cnt; i++) {
			in >> name >> st_cnt;
			lib->cns[i] = new Constellation(name, st_cnt);
			in >> lib->cns[i];
		}
		in.close();
	}
}

void cnst_table(Constellation_library* lib, int count) {
	for (int i = 0; i < count / 2; i++) {
		cout << i + 1 << "." << lib->cns[i]->name << " \t\t " << i + 6 << "." << lib->cns[i + 5]->name << endl;
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

void choice(Constellation_library* lib, int count) {
	string con;
	cout << "Choice a constellation" << endl;
	do {
		int flag = 0;
		cout << endl << ">> ";
		cin >> con;
		if (con == "stop") flag = 1;
		for (int i = 0; i < count && flag == 0; i++) {
			if (lib->cns[i]->name == con) {
				cout << lib->cns[i];
				flag = 1;
			}
		}
		if (!flag) cout << "Not found. Please, choose constellation from table" << endl;

	} while (con != "stop");
	delete lib;
}