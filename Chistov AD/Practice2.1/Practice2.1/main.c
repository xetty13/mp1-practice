#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int answer;
	do {
		printf("MENU:\n");
		printf("1.Add a new worker\n");
		printf("2.All employees with higher education\n");
		printf("3.Number of employees in the database:\n");
		printf("4.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &answer);
		switch (answer) {
		case 1: adding(); break;
		case 2: workers(); system("pause"); break;
		case 3: {float n = amount(); printf("%f\n", n); system("pause"); break; }
		case 4: return 0;
		}
	} while (answer != 4);
}
