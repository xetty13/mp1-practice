#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 5
#include <stdlib.h>

int main() {
	int a[N] = { 0 };
	int k, i, tmp, j;
	printf("Input k ");
	scanf ("%d", &k);
	while ((k<2) ||(k>5)) {
		printf("Incorrect data. Try again. Input 2 < k < 5 ");
		scanf ("%d", &k);
	}
	srand((unsigned int)time(NULL));
	a[0] = 1 + rand() % 9;
	printf("%d", a[0]);
	for (i = 1; i <= k-1; i++) {
		tmp = rand() % 10;
		for (j=0; j < i; j++)
			if (tmp == a[j]) {
				tmp = rand() % 10;
				j = 0;
			}
		a[i] = tmp;
		pritnf("%d", a[i]);
	}
	return 0;
}