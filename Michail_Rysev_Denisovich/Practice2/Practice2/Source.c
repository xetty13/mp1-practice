#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void first() {
	int n, count = 1, num;

	srand((unsigned int)time(NULL));
	n = rand() % 1000 + 1;

	scanf("%d", &num);
	while (num != n) {
		(num > n) ? printf("Less \n") : printf("More \n");
		scanf("%d", &num);
		count += 1;
	}

	printf("Number guessed \n");
	printf("Attempts are made: %d", count);
}

void second() {
	int left = 1, right = 1000, count = 0, mid;
	char sign;

	printf("Use '<' if hidden number less \n");
	printf("Use '>' if hidden number more \n");
	printf("Use '=' if hidden number equal \n");

	while (left <= right) {
		mid = (left + right) / 2;
		count += 1;
		printf("%d? \n", mid);
		scanf(" %c", &sign);
		if (sign == '<') right = mid - 1;
		else if (sign == '>') left = mid + 1;
		else if (sign == '=') {
			printf("Attempts are made : % d", count);
			left = right + 1;
		}
	}

}

int main() {
	first();
	return 0;
}