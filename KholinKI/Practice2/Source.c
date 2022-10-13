#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>

int random_function(int start, int end)
{
	int n;

	srand(time(NULL));

	n = (start - end) / RAND_MAX * rand() + start;

	return n;
	
}
 


void main() {
	setlocale(LC_CTYPE, "rus");
	int guess, n;
	n = random_function(1, 1000);
	printf("Ваше случайное число в заданном диапазоне= %d ", n);
}