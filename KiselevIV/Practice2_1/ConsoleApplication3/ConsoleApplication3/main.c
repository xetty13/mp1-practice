#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banki.h"

int main() {
	char* path = "C:\\Users\\abobi\\OneDrive\\Рабочий стол\\banki2.txt";
	int stringcount= strcount(path);

	bankstruct** banki = allocbanki(stringcount);
	vkladstruct* vklads = allocvklads(stringcount);
	workfile(banki, vklads, path, stringcount);

	int sumvkl=0;
	int your_month=0;
	printf("Enter count of money\n");
	scanf("%d", &sumvkl);
	printf("For how long is the contribution made\n");
	scanf("%d", &your_month);

	int n = 3;
	int m = 0;
	bestbank** bests = allocbest(n);
	int sav = choosesaving(sumvkl, your_month, banki, vklads, bests, stringcount);
	int deb = choosedebit(sumvkl, your_month, banki, vklads, bests, stringcount);
	int cum = choosecumulative(sumvkl, your_month, banki, vklads, bests, stringcount);
	
	if ((sav+deb+cum)==3) {
		printf("It is impossible to make a profit because the selected period is less than the minimum\n");
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