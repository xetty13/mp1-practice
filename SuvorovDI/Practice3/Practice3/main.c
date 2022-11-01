#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int an[5] = { -1, -1, -1, -1, -1 }, n = 0, len, i, gN, cDi = 0, endOfGame = 1;
	srand(time(NULL));

	printf("Let's play in Bull-n-cow game!\nChoose length of number (form 2 to 5) [2, 5]:\n");

	do {
		scanf_s("%d", &len);
	} while (len < 2 || len >5);

	i = 0;
	while (i < len) {
		int newN, flag = 1, j;
		newN = rand() % 10;

		for (j = 0; j < len; j++) {
			if (an[j] == newN)
				flag = 0;
		}

		if (flag && !(i == 0 && newN == 0)) {
			an[i] = newN;
			i++;
		}
	}

	// вывод загаданного числа
	/*for (i = 0; i < len; i++) {
		printf("' %d '", an[i]);
	}
	printf("\n");*/

	printf("I choose some number with length %d\nTry to guess:\n", len);

	// основной цикл игры
	while (endOfGame) {
		int c_Bull = 0, c_Cow = 0, copy, cDi, gNarr[5], i, j;

		do {
			cDi = 0;
			scanf_s("%d", &gN);
			copy = gN;
			while (copy > 0) {
				cDi++;
				copy /= 10;
			}
		} while (cDi != len);

		copy = gN;
		for (i = len - 1; i >= 0; i--) {
			gNarr[i] = copy % 10;
			copy /= 10;
		}

		//подсчёт коров
		for (i = 0; i < len; i++) {
			for (j = 0; j < len; j++) {
				if (gNarr[j] == an[i] && i != j) {
					c_Cow++;
				}
			}
		}

		//подсчёт быков:
		for (i = 0; i < len; i++) {
			if (an[i] == gNarr[i]) {
				c_Bull++;
			};
		}

		if (c_Bull == len) {
			endOfGame = 0;
			printf("You're WINNER! Congratulation!");
			break;
		}
		printf("Count of Bull: %d\nCount of Cow: %d\n", c_Bull, c_Cow);

	}

	return 0;
}