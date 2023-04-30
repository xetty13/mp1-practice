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

	choosesaving(sumvkl, your_month, banki, vklads, stringcount);
	choosedebit(sumvkl, your_month, banki, vklads, stringcount);
	choosecumulative(sumvkl, your_month, banki, vklads, stringcount);
	
	//choose(sumvkl, your_month, banki, vklads, stringcount);
		
	freebanki(banki, stringcount);
	freevklads(vklads);
	return 0;

}