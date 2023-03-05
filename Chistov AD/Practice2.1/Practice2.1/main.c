#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int answer;
	do {
		printf("MENU:\n");
		printf("1.The entire database of employees\n");
		printf("2.All employees with higher education\n");
		printf("3.Percentage of employees with higher education\n");
		printf("4.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &answer);
		switch (answer) {
		case 1: databse();  	break;
		case 2: higher_education(); system("pause"); break;
		case 3: percent(); break;
		case 4: return 0;
		}
	} while (answer != 4);
}

