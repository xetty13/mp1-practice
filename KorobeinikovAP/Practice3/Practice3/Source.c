#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 5
#define M 10
#include <stdlib.h>


int main() {
	int a[N] = { 0 };
	int ind[M] = { 0 };
	int u_a[N] = { 0 };
	int u_ind[M] = { 0 };
	int k, i, j,  number, st, user_n;
	int flag, flag1, tmp;
	int bulls, cows, attempts;


	printf("Input k ");
	scanf ("%d", &k);
	while ((k<2) ||(k>5)) {
		printf("Incorrect data. Try again. Input 2 < k < 5 ");
		scanf ("%d", &k);
	}


	srand((unsigned int)time(NULL));
	a[0] = 1 + rand() % 9;
	for (i = 1; i <= k-1; i++) {
		flag = 1;
		while (flag == 1) {
			flag = 0;
			tmp = rand() % 10;
			for (j = 0; j < i; j++)
				if (tmp == a[j]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				a[i] = tmp;
		}		
	}
	for (i = 0; i < k; i++) {
		ind[ a[i] ] = i+1;
	}
	printf("\n ");

	st = 1;
	number = 0;
	for (i = k - 1; i >= 0; i--) {
		number += a[i] * st;
		st *= 10;
	}


	flag = 1;
	attempts = 0;
	while (flag == 1) {
		attempts += 1;
		printf("Guess the hidden number \n");
		scanf("%d", &user_n);
		while ((user_n < 10) || (user_n > 99999)) {
			printf("Incorrect data. Try again. Input 9 < number < 1000000. ");
			scanf("%d ", &user_n);
		}
		for (i = k - 1; i > -1; i--) {
			u_a[i] = user_n % 10;
			user_n /= 10;
		}


		flag1 = 0;
		for (i = 0; i <= k - 1; i++) {
			for (j = i + 1; j <= k - 1; j++)
				if (u_a[i] == u_a[j]) {
					printf("Incorrect data. Try again. The numbers should not be repeated \n");
					flag1 = 1;
					break;
				}
			if (flag1 == 1)
				break;
		}
		if (flag1 == 1) 
			continue;
		
		for (i = 0; i < k; i++) {
			u_ind[ u_a[i] ] = i + 1;
		}
		bulls = 0;
		cows = 0;
		for (i = 0; i <= k - 1; i++)
			for (j = 0; j <= k - 1; j++)
				if (u_a[i] == a[j])
					if (u_ind[a[j]] == ind[a[j]]) 
						bulls += 1;
					else 
						cows += 1;
		if (bulls == k) {
			printf("Congratulations! You guessed the number in %d attempts!", attempts);
			flag = 0;
		}
		else {
			printf("bulls = %d, cows = %d \n", bulls, cows);
		}
	}



	return 0;
}