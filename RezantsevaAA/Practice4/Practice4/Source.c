#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <cstring>
void scan(char code[]);
char barcode[10][4] = { "1001","1002","1003","1004","1005","1006","1007","1008","1009","1010" };
char products[10][15] = { "eggs","milk", "meat","tea","cheese","bread","pen","bottle of water", "crisps","honey" };
int price[10] = {30, 15, 200, 20, 60, 10, 5, 25, 40, 95};
float discount[10] = { 0.05, 0.15, 0.3, 0.25, 0.02, 0.02, 0.04, 0.1, 0.12, 0.25};
int main()
{
	char code;
	int i, flag;
	int count = 10;
	scan()
}
	void scan(char code[])
	{
		char code;
		do
		{
			printf("Scan the product: ");
			scanf(" %c", code);
		} while (strcmp(barcode, code) != 0);
}