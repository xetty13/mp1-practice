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
	bestbank** bests = allocbest(n);
	choosesaving(sumvkl, your_month, banki, vklads, bests, stringcount);
	choosedebit(sumvkl, your_month, banki, vklads, bests, stringcount);
	choosecumulative(sumvkl, your_month, banki, vklads, bests, stringcount);
	
	chooseprint(bests, n);
		
	freebanki(banki, stringcount);
	freevklads(vklads);
	freebests(bests, n);
	return 0;

}