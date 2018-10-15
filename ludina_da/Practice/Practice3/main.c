#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int n, chislo;
	setlocale(LC_ALL, "Rus");
	printf("Выберите режим 1 или 2: ");
	scanf("%d", &n);
	if(n == 1)
	{
		srand(time(NULL));
		chislo = 1 + rand() % 1000;

	}
	else if(n == 2) 
	{

	}
}