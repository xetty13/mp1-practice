#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int r(int l, int r) {
	return rand() % (r - l + 1) + l;
}

void main() {

	srand((unsigned int)time(NULL));

	int N, i, j, x, k_cow, k_bull, ans;
	int num[5], a_num[5], digits[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("Choose the length of the hidden number (from 2 to 5):\n");
	do {
		scanf("%d", &N);
		if (N < 2 || N > 5)
			printf("Incorrect length. Choose another:\n");
	}
	while (N < 2 || N > 5);

	// Number generanion
	x = r(1, 9);
	num[0] = x;
	digits[x] = -1;

	for (i = 1; i < N; i++) {
		do x = r(0, 9);
		while (digits[x] == -1);
		num[i] = x;
		digits[x] = -1;
	}

	// test of gen number
	//for (i = 0; i < N; i++) printf("%d", num[i]); printf("\n");

	// Search for a number
	printf("Try to guess an %d-digit number:\n\n", N);
	do {
		do {
			scanf("%d", &x);
			if (x < pow(10, N - 1) || x > pow(10, N) - 1)
				printf("Incorrect length. Choose another:\n\n");
		}
		while (x < pow(10, N - 1) || x > pow(10, N) - 1);

		ans = x;
		i = N - 1;
		while (x > 0) {
			a_num[i] = x % 10;
			x /= 10;
			i--;
		}

		k_cow = 0;
		k_bull = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				if (num[i] == a_num[j] && i == j)
					k_bull++;
				if (num[i] == a_num[j] && i != j)
					k_cow++;
			}
		printf("Cows = %d\n", k_cow);
		printf("Bulls = %d\n\n", k_bull);
		printf("==================\n");
	} while (k_bull != N);

	printf("Congratulations!\nThe hidden number is %d\n", ans);
}