#include <stdio.h> 
#define N 10 

int shtrih(int sh1[])
{
	int i, flag = 0, sh, sht2, sht;
	printf("Enter shtrih-cod: \n ");
	scanf("%d", &sht);
	for (i = 0; i < N; i++)
	{
		if (sh1[i] == sht)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return i;

	return -1;

}
void product(char name[][6], int price[], float sale[], int a)
{
	int i;
	for (i = 0; i < 7; i++)
		printf("Your product: % \n", name[a][i]);
	printf("\nCost: %d \n", price[a]);
	printf("\nSale: %0.0f%% \n", sale[a]);
}
double sum(int price[], float sale[], int a)
{
	int i;
	double sum = 0.0;
	for (i = 0; i < N; i++)
		sum += (1 - sale[a] / 100.0) * price[a];
	return sum;

}
void output_check(int name[][6], int price[], float sale[], int a)
{
	int i;
	printf(" OOO Prosto Kassa\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");
	printf(" Name Cost Sale Discount price \n");
	for (i = 0; i < N; i++)
	{
		printf("%c", name[i][6]);
		printf("%d", price[a]);
		printf("%0.0f", sale[a]);
		printf("%lf \n", (1 - sale[a] / 100.0) * price[a]);
		printf("----------------------------------");
		printf("TOTAL: %d \n", sum);
	}
}
void Menu()
{
	printf("-------- MENU ------- \n");
	printf("1. display product information \n");
	printf("2. show check \n");
}
void main()
{
	int a;
	int sh[N] = { 2348 , 1357 , 3585 , 1736 , 3461 , 9753 , 1528 , 6776 , 7913 , 4781 };
	char name[N][6] = { "bread" , "meat" , "fish", "egg" , "milk", "potato", "butter",
		"apple", "salt", "cheese" };
	int price[N] = { 20, 34, 54, 12, 65, 52, 76, 46, 19, 95 };
	float sale[N] = { 5, 15, 5, 20, 10, 35, 20, 40, 10, 25 };
	int menu;
	do
	{
		Menu();
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
		{
			a = shtrih(sh);
			if (a == -1)
			{
				printf("Your product does not found, try again \n");
				break;
			}
			product(name, price, sale, a);
			break;
		case 2:
			output_check(name, price, sale, N);
			break;
		}
		}
	} while (1);
}