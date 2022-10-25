#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>



int main()
{
	int n, i;
	printf("Enter the length of the number (2-5) ");
	do {
		scanf("%d", &n);
	} while (n < 0 || n > 5);
	int* a = (int*)malloc(n * sizeof(int));

	do {


		srand((unsigned int)time(NULL));
		for (i = 0; i < n; i++)
			a[i] = rand() % 10;

	} while ((a[0] == a[1]) || (a[0] == a[2]) || (a[2] == a[3]) || (a[0] == a[3]) || (a[1] == a[2]) || (a[1] == a[3]) || (a[1] == a[4]) || (a[2] == a[3]) || (a[2] == a[4]) || a[3] == a[4]);

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	
	printf("Enter non-repeating digits of the same length\n");
	int* b = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &(b[i]));

	for (i = 0; i < n; i++)
		printf("%d ", b[i]);


	return 0;
}


