#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int answer;
	do {
		printf("MENU:\n");
		printf("1.Add a new worker\n");
		printf("2.All employees with higher education\n");
		printf("3.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &answer);
		switch (answer) {
		case 1: adding(); break;
		case 2: workers(); system("pause"); break;
		case 3: return 0;
		}
	} while (answer != 3);
}
