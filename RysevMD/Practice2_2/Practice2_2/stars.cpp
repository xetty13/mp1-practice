#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

void allocate(Constellation*& cns, int cnt) {
	cns = new Constellation[cnt];
}
void allocate(Star*& st, int cnt) {
	st = new Star[cnt];
}

void cfree(Constellation*& cns) {
	delete [] cns->stars;
	delete []  cns;
}

void read_data(Constellation*& cns, int& cnt) {
	ifstream in;
	string path;
	int st_cnt;
	cout << endl << "Enter the path: ";
	cin >> path;
	in.open(path);
	if (in.is_open()) {
		in >> cnt;
		allocate(cns, cnt);
		for (int i = 0; i < cnt; i++) {
			in >> cns[i].name >> st_cnt;
			cns[i].count = st_cnt;
			allocate(cns[i].stars, st_cnt);
			for (int j = 0; j < st_cnt; j++) {
				in >> cns[i].stars[j].name;
				in >> cns[i].stars[j].dist >> cns[i].stars[j].magnitude >> cns[i].stars[j].deg >> cns[i].stars[j].min >> cns[i].stars[j].sec;
			}
		}
	}
	in.close();
}
void cnst_table(Constellation* cns, int count) {
	for (int i = 0; i < count / 2; i++) {
		cout << i + 1 << "." << cns[i].name << " \t\t " << i + 6 << "." << cns[i + 5].name << endl;
	}
	cout << "\nOutput format:\n\n  name distance magnitude coordinates(deg, min, sec)\n\n";
}
void print_data(Constellation* cns, int num) {
	cout << endl << cns[num].name << endl;
	for (int i = 0; i < cns[num].count; i++) {
		cout << "  " << cns[num].stars[i].name << " " << cns[num].stars[i].dist << " " << cns[num].stars[i].magnitude << " ";
		cout << cns[num].stars[i].deg << "° " << cns[num].stars[i].min << "' " << cns[num].stars[i].sec << "\"" << endl;
	}


}
void choice(Constellation* cns, int count) {
	string con;
	cout << "Choice a constellation" << endl;
	do {
		int flag = 0;
		cout << endl << ">> ";
		cin >> con;
		if (con == "stop") flag = 1;
		for (int i = 0; i < count && flag == 0; i++) {
			if (cns[i].name == con) {
				print_data(cns, i);
				flag = 1;
			}
		}
		if (!flag) cout << "Not found. Please, choose constellation from table" << endl;

	} while (con != "stop");
}
