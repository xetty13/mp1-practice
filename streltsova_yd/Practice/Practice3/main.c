#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main (){
	int mode, n, n1, k, i1, i2, mid;
	char sign;
	printf ("Guess the number\n");
	printf ("Choose a game mode. Enter 1 to select mode 1 or 2 to select mode 2\n");
	do {
	scanf ("%d", &mode);
	} while ((mode != 1) || (mode != 2));
	if (mode == 1)
	{
		srand ((unsigned int) time (0));
		n = 1000.0 / RAND_MAX + 1;
		printf ("Number generated. Try to guess it. Enter a number from 1 to 1000\n");
		k = 0;
		while (n != n1)
		{
			do{
				scanf ("%d", &n1);
			}while ((n1 < 1) || (n1>1000));
			if (n > n1) 
				printf ("The number is greater\n");
			if (n < n1)
				printf ("Number less\n");
			k ++;
		}
		printf ("You guessed\n");
		printf ("Number of attempts = %d\n", k);
	}
	else
	{
		printf ("Enter a number from 1 to 1000\n");
		do{
			scanf ("%d", &n1);
			}while ((n1 < 1) || (n1>1000));
		i1 = 1; i2 = 1000; sign = ' ';
		while (sign != '=')
		{
			mid = (i1 + i2) / 2;
			printf ("%d", mid);
			do
			{
				scanf ("%c", &sign);
			}while ((sign != '<') || (sign != '>') || (sign != '='));
			
		}
	}
}
