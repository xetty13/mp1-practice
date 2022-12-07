#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#define N 5
#define B 5


int main() {

	int a[N], mycomp[B];
	int b, size = 0, cows = 0, bulls = 0, digits = 0, buff = 0, no_equal = 0;
	char c;

	printf("enter the number of digits of the number(from 2 to 5) or q for quit ");
	scanf_s("%d", &size);
	//	printf("size= %d", size);
	while ((size < 2) || (size > 5))
	{
		printf("enter the number of digits of the number");
		scanf_s("%d", &size);
		//
	}
	//	printf("size= %d", size);


	srand((unsigned int)time(NULL));
	mycomp[0] = 1 + rand() % 9;
	//	printf("%d\n", array[0]);
	digits++;
	while (digits < size) {
		buff = rand() % 10;
		//		printf("buff=%d, digits=%d\n", buff, digits);
		no_equal = digits;

		for (int i = 0; i < digits; i++)
			if (buff != mycomp[i]) no_equal--;

		if (no_equal == 0) {
			mycomp[digits] = buff;
			digits++;
		}
	}

	//printf("\nEnter %d digits or q for quit\n", size);
	for (int i = 0; i < size; i++)
		printf("%d", mycomp[i]);
	printf("\n");
	printf("\nEnter %d digits or q for quit\n", size);
	bulls = cows = digits = 0;
	
	c = getc(stdin);
	while (c != 'q' && c != 'Q') {
		for (int i = 0; i < size; i++) {

			if (mycomp[i] == ((int)c)) {
				if (i == digits)
					bulls++;
				else
					cows++;
			}
		}
		digits++;
		if (digits == size)
		{
			printf("\t\tbulls=%d cows=%d\n", bulls, cows);
			if (bulls == size) {
				printf("YOU WON!");
				break;
			}
			bulls = cows = digits = 0;
		}
	}

	return 0;
}


