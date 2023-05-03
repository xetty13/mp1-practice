#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "banki.h"

using namespace std;


int main() {

	string path = "C:\\Users\\abobi\\OneDrive\\Рабочий стол\\banki2.txt";
	int stringcount = strcount(path);
	bestbank bank(stringcount);
	
	bank.workfile(path, stringcount);

	int sumvkl = 0;
	int your_month = 0;
	cout << "Enter count of money" << endl;
	cin >> sumvkl;
	cout << "For how long is the contribution made" << endl;
	cin >> your_month;

	int n = 3;
	int sav = bank.choosesaving(sumvkl, your_month, stringcount);
	int deb = bank.choosedebit(sumvkl, your_month, stringcount);
	int cum = bank.choosecumulative(sumvkl, your_month, stringcount);

	if ((sav + deb + cum) == 3) {
		cout << "It is impossible to make a profit because the selected period is less than the minimum " << endl;
		return 0;
	}
	else {
		bank.chooseprint(n);
	}

	return 0;

}
