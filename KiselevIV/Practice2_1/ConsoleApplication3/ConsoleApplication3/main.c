#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banki.h"

int main() {
	//char* path = "C:\\Users\\abobi\\OneDrive\\Рабочий стол\\banki2.txt";
	char* path = getfile();//C:\Users\abobi\banki2.txt
	int stringcount= strcount(path);

	bankstruct** banki = allocbanki(stringcount);
	vkladstruct* vklads = allocvklads(stringcount);
	workfile(banki, vklads, path, stringcount);

	int sumvkl = 0;
	int your_month = 0;
	data_input(&sumvkl, &your_month);

	int n = 3;
	bestbank** bests = allocbest(n);
	chooseall(sumvkl, your_month, banki, vklads, bests, stringcount);
	freeall(bests, n, vklads, banki, stringcount);
	return 0;
}