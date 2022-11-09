#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
char codes[10][4] = { "0001", "0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010", };
char name[10][10] = { "carrot", "potato", "tomato", "chips", "chocolate", "juice", "lemonade", "banana", "milk", "sour cream" };
int cost[10][3] = { "20", "10", "15", "80", "90", "150", "100", "40", "60", "70" };
int discount[10][2] = { "0.05", "0.08", "0.07", "0.3", "0.25", "0.35", "0.15", "0.04", "0.5", "0.12" };
int main()
{
	char code;
	int count = 10;
	int i, fl;
	while (1)
	{
		printf("Hello! Scan the product: ");
		scanf(" %c", code);
		fl = 0;
		for (i = 1; i < count; i++)
		{
			if (codes[i] == code)
			{
				fl = 1;
				break;
			}
		}
		if (fl == 0)
		{
			printf("An incorrect product code has been entered. Enter another one: ");
			
		}
	}



	return 0;
}