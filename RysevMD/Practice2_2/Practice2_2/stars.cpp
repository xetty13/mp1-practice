#include <iostream>
#include <fstream>
#include "stars.h"

using namespace std;

void allocate(Constellation** cns) {
	(*cns) = new Constellation[10];
	for (int i = 0; i < 10; i++) {
		(*cns)[i].stars = new Star[5];
	}
}
void cfree(Constellation** cns) {
	delete [] (*cns)->stars;
	delete []  (*cns);
}

void read_data(Constellation* cns) {
	ifstream in;
	in.open("data.txt");
	if (in.is_open()) {
		for (int i = 0; i < 10; i++) {
			in >> cns[i].name;
			for (int j = 0; j < 5; j++) {
				in >> cns[i].stars[j].name;
				in >> cns[i].stars[j].dist >> cns[i].stars[j].magnitude >> cns[i].stars[j].deg >> cns[i].stars[j].min >> cns[i].stars[j].sec;
			}
		}
	}
	in.close();
}
void cnst_table(Constellation* cns) {
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "." << cns[i].name << " \t\t " << i + 6 << "." << cns[i + 5].name << endl;
	}
	cout << "\nOutput format:\n\n  name distance magnitude coordinates(deg, min, sec)\n\n";
}
void print_data(Constellation* cns, int num) {
	cout << endl << cns[num].name << endl;
	for (int i = 0; i < 5; i++) {
		cout << "  " << cns[num].stars[i].name << " " << cns[num].stars[i].dist << " " << cns[num].stars[i].magnitude << " ";
		cout << cns[num].stars[i].deg << "° " << cns[num].stars[i].min << "' " << cns[num].stars[i].sec << "\"" << endl;
	}


}
void choice(Constellation* cns) {
	int num = -1;
	cout << "Choice a constellation" << endl;
	while (num != 0) {
		cout << endl << ">> number: ";
		cin >> num;
		if (num < 0 || num > 10) cout << "Number not found" << endl;
		else if (num != 0) print_data(cns, num - 1);
	}
}
