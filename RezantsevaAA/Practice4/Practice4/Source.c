#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
//#include <cstring>
int inarray();
void scan();
void addproduct(int i);
void addcount(int i);
char barcodes[10][5] = { "1001","1002","1003","1004","1005","1006","1007","1008","1009","1010" };
char products[10][15] = { "eggs","milk", "meat","tea","cheese","bread","pen","bottle of water", "crisps","honey" };
int prices[10] = {30, 15, 200, 20, 60, 10, 5, 25, 40, 95};
float discounts[10] = { 0.05, 0.15, 0.3, 0.25, 0.02, 0.02, 0.04, 0.1, 0.12, 0.25};
char* check[10][5];
int checklist = 0;

int main()
{
	scan();
	float sum = 0;
	for (int i = 0; i < checklist; i++)
	{
		sum += (int)check[i][3] * discounts[(int)check[i][4]];
	}
	printf(" %f", sum);
	return 0;
}
	int inarray(char* barcodes[10][5], char* barcode[5])
	{
		for (int i = 0; i < 10; i++)
		{
 			if (strcmp(barcodes[i], barcode) == 0)
			{
				return i;
			}
		}
		return -1;
	}
	void addproduct(int i)
	{
		check[checklist][0] = products[i];
		check[checklist][1] = prices[i];
		check[checklist][2] = '1';
		check[checklist][3] = (int)('1') * prices[i];
		check[checklist][4] = i;
		
	}
	void addcount(int i)
	{
		check[i][2] = (int)check[i][2]++;
		check[i][3] = (int)check[i][2]* prices[i];
	}
	void scan()
	{
		char* barcode[5];
		while (1) 
		{
			printf("Scan the product: ");
				scanf(" %4s", barcode);
				if (strcmp(barcodes, barcode) == 0)
				{
					break;
				}
				//printf(" %s", p_c);
				int i = inarray(&barcodes, &barcode);
				int j = inarray(check, barcode);
				if (i == -1)
				{
					printf("Invalid code. Scan the product again: ");
				}
				if ((i != -1)&&(j == -1))
				{
					addproduct(i);
				}
				if ((i != -1) && (j != -1))
				{
					addcount(j);
				}
		}
	}