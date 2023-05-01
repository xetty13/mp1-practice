#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "banki.h"

using namespace std;


int main() {
	string path = "C:\\Users\\abobi\\OneDrive\\Рабочий стол\\banki2.txt";
	int stringcount = strcount(path);

	bankstruct* banki = allocbanki(stringcount);
	vkladstruct* vklads = allocvklads(stringcount);
	workfile(banki, vklads, path, stringcount);

	int sumvkl = 0;
	int your_month = 0;
	cout << "Enter count of money" << endl;
	cin >> sumvkl;
	cout << "For how long is the contribution made" << endl;
	cin >> your_month;

	int n = 3;
	int m = 0;
	bestbank* bests = allocbest(n);
	int sav = choosesaving(sumvkl, your_month, banki, vklads, bests, stringcount);
	int deb = choosedebit(sumvkl, your_month, banki, vklads, bests, stringcount);
	int cum = choosecumulative(sumvkl, your_month, banki, vklads, bests, stringcount);

	if ((sav + deb + cum) == 3) {
		cout << "It is impossible to make a profit because the selected period is less than the minimum " << endl;
		return 0;
	}
	else {
		chooseprint(bests, n);
	}

	freebanki(banki, stringcount);
	freevklads(vklads);
	freebests(bests, n);
	return 0;

}
