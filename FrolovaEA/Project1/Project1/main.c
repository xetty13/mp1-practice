#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


/* функция проверяет на совпадение вводимые цифр(массив, длина массива, символ который надо сравнить)


*/

int is_valid(char a[5], int size, char c)
{
	int no = size, i;
	for (i = 0; i < size; i++)
		if (a[i] != c)
			no--;
	if (no == 0)
		a[size] = c;
	//	printf("no = %d, c = %c\n", no, c);
	return !no;
}
int main()
{
	char my[5];
	int bulls = 0, size = 0, cows = 0, digits = 0;
	char numbers[10] = "0123456789", ch;
	char enter[5], c = ' ';


	// контроль ввода данных 
	do {
		printf("Enter digit number (from 2 to 5): ");
		scanf("%d", &size);
	} while (size < 2 || size > 5);


	//	scanf_s("%d", &size);
	//	printf("\n%c, %d ", c, size);

	printf("\nEnter %d digits or q for quit\n", size);

	// заполняем массив рандомными цифрами
	srand((unsigned)time(NULL));
	while (digits < size) {
		ch = numbers[rand() % 10];
		if (is_valid(my, digits, ch)) {
			digits++;
			//			printf("\t%c", ch);
		}
	}
	/*	printf("my number is ");
		for (int i = 0; i < size; i++)
			printf("%c", my[i]);
		printf("\n");*/
		//	printf("my number is %c%c%c%c%c%c\n",my[0],my[1],my[2],my[3],my[4],my[5]);
	bulls = cows = digits = 0;

	while (c != 'q' && c != 'Q')
		if (isdigit(c = _getch())) // контроль ввода данных isdigit (является ли десятичной цифрой)
			if (is_valid(enter, digits, c))
			{
				printf("%c", c);
				for (int i = 0; i < size; i++)
					if (my[i] == c)
						if (i == digits)
							bulls++;
						else
							cows++;
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
	printf("\npress any key\n");
	_getch();
	return 0;
}