#include "banki.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* path = "C:\\Users\\abobi\\OneDrive\\Рабочий стол\\banki2.txt";
	int stringcount= strcount(path);

	bankstruct* banki = alloc(stringcount);

	workfile(banki, path, stringcount);

	int sumvkl=0;
	printf("Enter count of money\n");
	scanf("%d", &sumvkl);
	
	choosesaving(sumvkl, banki, stringcount);
	choosedebit(sumvkl, banki, stringcount);
	choosecumulative(sumvkl, banki, stringcount);
		
	freebanki(banki);
	return 0;

}