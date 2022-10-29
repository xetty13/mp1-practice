#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#pragma warning(suppress : 4996)
#pragma warning(suppress : 4996)
#define N 5
int mass[N];



int main() {
	int l, i, n = 0, multi, k, q, j, m[N], p = 0, unique=1,old_n;
	srand(time(NULL));
	printf("Input length of riddled number: \n");
	scanf("%d", &l);
	do {
		for (i = 2, q = 9.9, multi = 10; i <= 5; i++, multi *= 10) {
			if (l == i) {
				n = multi + rand() % (q * multi - multi + 1);
				break;
			}
		}
		old_n = n;
		i = 0;
		while (n != 0) {
			k = n % 10;
			mass[i] = k;
			if (mass[i] < 0) {
				mass[i] == 0;
			}
			n = n / 10;
			i++;
		}
		for (i = 0; i < N; i++) {
			if (mass[i] < 0) {
				mass[i] = 0;
			}
		}
		for (i = 0; i < N; i++) {
			m[i] = mass[i];
		}
		for (i = 0, j = 4; i < 5; i++) {
			mass[i] = m[j];
			j = j - 1;
		}
		unique = 1;
		for (i = 0; i < N; i++) {
			for (j = i+1; j < N; j++) {
				if (mass[i] == 0) {
					break;
				}
				else if (mass[i] == mass[j]) {
					unique = 0;
					break;
				}
			}
			if (unique == 0) {
				break;
			}
		}
	} while (unique == 0);
	printf("\n");

	for (i = 0; i < N; i++) {
			p = 10 * p + mass[i];
		}
	printf("Computer`s number: %d\n", p);

	return 0;
}



