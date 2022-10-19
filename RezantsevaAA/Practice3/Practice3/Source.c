#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
void main()
{

    srand(time(NULL));
    int number[] = 0;
	int n, element;
	printf("Enter the number of digits in the number from 2 to 5 ");
    do {
        scanf("%d", &n);
        if ((n > 5) || (n < 2)) {
            printf("Invalid number entered\n");
        }
    } while ((n > 5) || (n< 2));
    printf("%d", n);
    number[1] = 1 + rand() % (10);
    number[2] = rand() % (10)

}