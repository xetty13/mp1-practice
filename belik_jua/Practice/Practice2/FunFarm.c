#include <stdio.h>

void main()
{
	int i, n, bull = 0, cow = 0, a, j, m;
	int num[10], inp[10];
	
	do {
		printf("n = ");
		scanf("%d",&n);
	} while ((n <= 0) || (n > 10));

	for (i = n; i > 0; i--)
	{
		num[i] = i;
	}

	do {
		bull = 0;
		cow = 0;
		do {
			m = 0;
			printf("number = ");
			scanf("%d", &a);
			for (i = n; i > 0; i--)
			{
				inp[i] = a % 10;
				a = a / 10;
			}
			for (i = n; i > 0; i--)
			{
				for (j = (i - 1); j > 0; j--)
				{
					if (inp[i] == inp[j]) m++;
				}
			}
		} while (m != 0);
		for (i = n; i > 0; i--)
		{
			for (j = n; j > 0; j--)
			{
				if ((num[i] == inp[j]) && (i == j)) bull++;
				if ((num[i] == inp[j]) && (j != i)) cow++;
			}
		}
		printf("cow = %d and bull = %d \n", cow, bull);
	} while (bull != n);
	printf("you win");
}