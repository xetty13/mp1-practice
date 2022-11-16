#include<stdio.h>
#define N 10
const char* products[N] = { "Limon","Milk","Eggs","Apple","Honey","Oil","Bread","Tea","Sausage","Cheese" };
const char* barcodes[N] = { "0101","2020","0303","4040","0505","6060","0707","8080","0909","1010" };
float price[N] = { 25.00, 69.00, 75.00, 80.00, 300.00, 120.00, 30.00, 80.00, 250.00, 400.00 };
float skidka[N] = { 4.50, 7.00, 5.00, 6.55, 21.35, 12.50, 5.00, 13.90, 42.10, 51.30 };
int counts[N] = { 0 };
double ctoim_b_sk = 0;
double ctoim = 0;
void chek();
void final();
void proverka();
void scan() {
	char code[5];
	printf("Vvedite shtrixcode: ");
	scanf("%s", &code);
	switch (code[0])
	{
	case 'h': //чек
		chek();
	case 'f': //вывод чека
		final();
	default:
		proverka();
		break;
	}
}

