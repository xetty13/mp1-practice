#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 

void main()
{
	int a[10], b[10];
	int n, cows = 0, bulls = 0, p, p1, i, j, f;
	int temp = 1;
	do
	{
		printf("Enter number of digits: ");
		scanf("%d", &n);
		if ((n <= 0) || (n >= 10))
			printf("Number does not exist \n");
	} while ((n <= 0) || (n >= 10));
	srand((unsigned int)time(0));
	while (temp)
	{
		temp = 0;
		for (i = 0; i < n; i++)
			a[i] = rand() % 9;
		if (a[0] == 0)
			a[0] = rand() % 9 + 1;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (a[i] == a[j])
				{
					temp = 1;
					break;
				}
	}
	while (bulls != n)
	{
		do
		{
			i = 0, f = 0;
			printf("Enter your number: ");
			scanf("%d", &p);
			p1 = p;
			while (p1 != 0)
			{
				p1 = p1 / 10;
				i++;
			}
			if (i == n)
			{
				for (i = n - 1; i > -1; i--)
				{
					b[i] = p % 10;
					p = p / 10;
				}
				for (i = 0; i < n - 1; i++)
					for (j = i + 1; j < n; j++)
						if (b[i] == b[j])
							f = 1;
			}
			else f = 1;
			if (f == 1)
				printf("Your number is incorrect.Try again.\n");
		} while (f != 0);
		cows = 0;
		bulls = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (b[i] == a[j])
					cows++;
		for (int i = 0; i < n; i++)
			if (a[i] == b[i])
				bulls++;
		printf("Cows: %d\n", cows);
		printf("Bulls: %d\n", bulls);
	}
	printf("You win!!!");
}

