#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main()
{
	int number,user_number,i;
	int zhak;
	long int a,b;//отрезок от а до b
	a=0;
	b=1000;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));
	do{
		printf("Укажите режим работы\n1 - отгадать самому;\n2 - загадать компьютеру;\n3 - выйти из программы\n");
		scanf("%d",&i);
		if (i==1)
		{
			number=rand()%1000;
			user_number=-1;
			while(user_number!=number)
			{
				printf("\n");
				scanf("%d", &user_number);
				if (number>user_number)
				{
					printf("\nЗагаданное число больше");
				}
				if (number<user_number)
				{
					printf("\Загаданное число меньше");
				}
				if (number==user_number)
				{
					printf("\nУгадали\n");
				}
			}
		}
		
		if (i==2)
		{
			do
			{
				number=a + rand()%(b - a + 1);
				printf("\n%d",number);
				printf("\n Оцените число\n1 если число болшьше,\n2 если число меньше,\n= если число равно загаданному\n");
				scanf("%d", &zhak);//Все прекрасно работает с числами, но как только пытаешься использовать символы и тип char сразу начинается ерунда
				if (zhak==1)
				{
					a=number+1;
				}
				if (zhak==2)
				{
					b=number-1;
				}
				if (zhak==3)
				{
					printf("Число угадано");
				}
			}while(zhak!=3);
		}
	}while(i!=3);
}