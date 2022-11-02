#include <stdio.h>
#include <stdlib.h>

/*
int main() {
	int len;
	int number;
	int i;
	int q = 0, w = 0, e = 0, r = 0, t = 0;


	printf("input length of number\n");
	scanf_s("%d", &len);


	// length of number 2 
	if (len == 2) {
		int c = 0,j = 0,k;

		srand(time(NULL));
		number = 10 + rand() % (99 - 10 + 1);
		c = number;

		int a[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int b[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		
		for (j = 0; j < 2; j++) {
			k = c % 10;
			c /= 10;
			a[k] += 1;
		}

		for (j = 0; j < 11; j++) {
			printf("%d", a[j]);
		}
	}


	// length of number 3
	if (len == 3) {

		
		srand(time(NULL));
		number = 100 + rand() % (999 - 100 + 1);
		q = number / 100;
		w = (number / 10) % 10;
		e = number % 10;
		while ((q == w) && (q == e) && (w == e)) {
			srand(time(NULL));
			number = 100 + rand() % (999 - 100 + 1);
			q = number / 100;
			w = (number / 10) % 10;
			e = number % 10;
		}
		printf("%d", number);

	}



	// length of number 4 
	if (len == 4) {

		do {
			srand(time(NULL));
			number = 1000 + rand() % (9999 - 1000 + 1);
			q = number / 1000;
			w = (number / 100) % 10;
			e = (number / 10) % 10;
			r = number % 10;
			printf("%d, %d, %d, %d", q,w,e,r);
		} while ((q!=w)&&(q!=e)&&(q!=r)&&(w!=e)&&(w!=r)&&(e!=r));
		printf(" %d", number);
	}



	// length of number 5 
	if (len == 5) {

		do {
			srand(time(NULL));
			number = 10000 + rand() % (99999 - 10000 + 1);
		} while ((number % 10) == (number / 10));
		printf("%d", number);

	}



	return 0;
}

*/




int main() {
	int len;
	int number;
	int k, j, i = 0;

	printf("input length of number\n");
	scanf_s("%d", &len);
	int userNum = 0, cows = 0, bulls = 0;
	

	//length of number 2 
	if (len == 2) {
		int arr1[2], arr2[2];
		srand(time(NULL));
		number = 10 + rand() % (99 - 10 + 1);
		arr1[0] = number / 10;
		arr1[1] = number % 10;

		for (i = 0; i < 2; i++) {
			printf("%d", arr1[i]);
		}

		while (cows != 2) {
			cows = 0;
			bulls = 0;
			printf("enter a number\n");
			scanf_s("%d", &userNum);
			arr2[0] = userNum / 10;
			arr2[1] = userNum % 10;
			for (j = 0; j < 2; j++) {
				if (arr1[j] == arr2[j]) {
					cows += 1;
				}
				for (k = 0; k < 2; k++) {
					if (arr1[j] == arr2[k]) {
						bulls += 1;
					}
				}
			}
			printf("cows: %d", cows);
			printf("bulls: %d", bulls);
		}
		printf("you win, congratulations");
	}

	//length of number 3 
	if (len == 3) {
		int arr1[3], arr2[3];
		srand(time(NULL));
		number = 100 + rand() % (999 - 100 + 1);

		arr1[0] = number / 100;
		arr1[1] = (number / 10) % 10;
		arr1[2] = number % 10;

		for (i = 0; i < 3; i++) {
			printf("%d", arr1[i]);
		}

		while (cows != 3) {
			cows = 0;
			bulls = 0;
			printf("enter a number\n");
			scanf_s("%d", &userNum);
			arr2[0] = userNum / 100;
			arr2[1] = (userNum / 10) % 10;
			arr2[2] = userNum % 10;
			for (j = 0; j < 3; j++) {
				if (arr1[j] == arr2[j]) {
					cows += 1;
				}
				for (k = 0; k < 3; k++) {
					if (arr1[j] == arr2[k]) {
						bulls += 1;
					}
				}
			}
			printf("cows: %d", cows);
			printf("bulls: %d", bulls);
		}
		printf("you win, congratulations");
	}

	//length of number 4
	if (len == 4) {
		int arr1[4], arr2[4];
		srand(time(NULL));
		number = 1000 + rand() % (9999 - 1000 + 1);

		arr1[0] = number / 1000;
		arr1[1] = (number / 100) % 10;
		arr1[2] = (number / 10) % 10;
		arr1[3] = number % 10;

		for (i = 0; i < 4; i++) {
			printf("%d", arr1[i]);
		}

		while (cows != 4) {
			cows = 0;
			bulls = 0;
			printf("enter a number\n");
			scanf_s("%d", &userNum);
			arr2[0] = userNum / 1000;
			arr2[1] = (userNum / 100) % 10;
			arr2[2] = (userNum / 10) % 10;
			arr2[3] = userNum % 10;
			for (j = 0; j < 4; j++) {
				if (arr1[j] == arr2[j]) {
					cows += 1;
				}
				for (k = 0; k < 4; k++) {
					if (arr1[j] == arr2[k]) {
						bulls += 1;
					}
				}
			}
			printf("cows: %d", cows);
			printf("bulls: %d", bulls);
		}
		printf("you win, congratulations");
	}

	//length of number 5
	if (len == 5) {
		int arr1[5], arr2[5];
		srand(time(NULL));
		number = 10000 + rand() % (99999 - 10000 + 1);

		arr1[0] = number / 10000;
		arr1[1] = (number / 1000) % 10;
		arr1[2] = (number / 100) % 10;
		arr1[3] = (number / 10) % 10;
		arr1[4] = number % 10;

		for (i = 0; i < 5; i++) {
			printf("%d", arr1[i]);
		}

		while (cows != 5) {
			cows = 0;
			bulls = 0;
			printf("enter a number\n");
			scanf_s("%d", &userNum);
			arr2[0] = userNum / 10000;
			arr2[1] = (userNum / 1000) % 10;
			arr2[2] = (userNum / 100) % 10;
			arr2[3] = (userNum / 10) % 10;
			arr2[4] = userNum % 10;
			for (j = 0; j < 5; j++) {
				if (arr1[j] == arr2[j]) {
					cows += 1;
				}
				for (k = 0; k < 5; k++) {
					if (arr1[j] == arr2[k]) {
						bulls += 1;
					}
				}
			}
			printf("cows: %d", cows);
			printf("bulls: %d", bulls);
		}
		printf("you win, congratulations");
	}

	
	return 0;
}