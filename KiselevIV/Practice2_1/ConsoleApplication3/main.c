#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banki.h"

int main() {
	char* path = "C:\\Users\\abobi\\OneDrive\\Рабочий стол\\banki2.txt";
	int stringcount= strcount(path);

	bankstruct* banki = allocbanki(stringcount);
	vkladstruct* vklads = allocvklads(stringcount);
	workfile(banki, vklads, path, stringcount);

	int sumvkl=0;
	printf("Enter count of money\n");
	scanf("%d", &sumvkl);
	
	choosesaving(sumvkl, banki, vklads, stringcount);
	choosedebit(sumvkl, banki, vklads, stringcount);
	choosecumulative(sumvkl, banki, vklads, stringcount);
		
	freebanki(banki);
	freevklads(vklads);
	return 0;

}