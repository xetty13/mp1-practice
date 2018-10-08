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
		num[i] = 1;
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
			for (j = 0; j > 0; j--)
			{
				if ((num[j] == inp[i]) && (i == j)) bull++;
				else if (num[j] == inp[i]) cow++;
			}
		}
		printf("cow = %d and bull = %d", cow, bull);
	} while (bull != n);
	printf("you win");
}