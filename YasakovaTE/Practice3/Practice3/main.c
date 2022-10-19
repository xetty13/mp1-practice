#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
	int len, i, a, number;
    float g, k;
    g = 10;
    srand((unsigned int)time(NULL));
	printf("Choose the length of the number (from 2 to 5): ");
    do {
        scanf(" %d", &len);
        if ((len > 5) || (len < 2)) {
            printf("Incorrect number entered. Try again: ");
        }
    } while ((len > 5) || (len < 2));
    k = pow(g, len);
    printf("%f", k);
    number = 0;
    for (i = 1; i < len; i++)
    {
        a = 1 + rand() % (1000000);
        number = number + a * k;
    }
    printf("%d", number);
}