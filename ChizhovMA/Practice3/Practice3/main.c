#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int n;

int main()
{
	int i, x, j, cow=0, bull=0;
	int a[5];
	int b[5];
	printf("Enter the length of the number (2-5) ");
	do {
		scanf("%d", &n);
	} while (n < 0 || n > 5);
	

	do {
		srand((unsigned int)time(NULL));
		for (i = 0; i < n; i++)
			a[i] = rand() % 10;

	} while (Check(a)==0);

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	
	printf("\nEnter non-repeating digits of the same length\n");
	scanf("%d", &x);

	while (x > 0)
	{
		for (i = n - 1; i >= 0; i--)
		{
			b[i] = x % 10;
			x = x / 10;
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", b[i]);

	while (true)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (a[i] == b[j])
				{
					if (i == j)
						bull++;
					else
						cow++;
				}
			}
		}
		
		
		if (bull == n)
		{
			printf("You guessed the number!");
			break;
		}
		else
			printf("\n%d cow(s) and %d bull(s) were found\n", cow, bull);

		printf("Enter a new number\n");
		scanf("%d", &x);

		while (x > 0)
		{
			for (i = n - 1; i >= 0; i--)
			{
				b[i] = x % 10;
				x = x / 10;
			}
		}
		cow = 0;
		bull = 0;
	}

	return 0;
}


int Check(int *arr)
{
	int Un_index = 0, Cur_index;
	int flag = 1;
	for (Cur_index = 0; Cur_index < n; Cur_index++)
	{
		if ((Cur_index != Un_index) && (arr[Cur_index] != arr[Un_index]))
		{
			Un_index++;
			Cur_index = 0;
			flag = 1;
		}
		else
			flag = 0;
	}

	return flag;
}
