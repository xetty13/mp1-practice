#include <stdio.h>
#include <time.h>
#include <math.h>
int main()
{
	{
		int a[5] = { 0 }, b[5] = { 0 }, n = 0, i = 0, tries = 0, k, l, f = 1, n1, n2, bull = 0, cow = 0, tmp = 0;
		time_t t;
		srand((unsigned)time(&t));
		printf("Enter the length of the number (from 2 to 5): ");
		do {
			scanf_s("%d", &n);
			if ((n > 5) || (n < 2)) {
				printf("Invalid number entered. Try again\n ");
			}
		} while ((n > 5) || (n < 2));
		for (i = 0; i < n; i++) {							//generating a number with unique digits
			do {
				k = (rand() % 9) + 1;
				if ((a[0] != k) && (a[1] != k) && (a[2] != k) && (a[3] != k) && (a[4] != k)) {
					a[i] = k;
				}
			} while (a[i] == 0);
		}
		for (i = 0; i < n; i++) {							
			
		}
		for (i = 0; i < n; i++) {
			f *= 10;
		}
		do {
				printf("Enter your guess: ");

				do {											
					scanf_s("%d", &l);
					for (i = n - 1; i >= 0; i--) {
						b[i] = l % 10;
						l /= 10;
					}
					tmp = 0;
					for (i = 0; i < n; i++) {
						for (int kk = i + 1; kk < n; kk++) {
							if ((b[i] == b[kk]) || (b[kk] == 0)) {
									tmp = 1;
									break;
							}
						}
					}
					if (tmp == 1) {
						printf("you've entered a wrong number");
					}
			} while (tmp == 1);
			tries++;
			for (n1 = 0; n1 < n; n1++) {					
				for (n2 = 0; n2 < n; n2++) {
					if ((n1 == n2) && (a[n1] == b[n2])) {
						bull++;
					}
					else if ((n1 != n2) && (a[n1] == b[n2])) {
						cow++;
					}
				}
			}
			printf("bulls: %d\n", bull);
			printf("cows: %d\n", cow);
			if (bull == n) {
					printf("Congrats! Total attemts count: %d", tries);
					return 0;
			}
			cow = 0;
			bull = 0;
		}while (1);
	} 
}
