#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "workers.h";
#define N 100

void databse() {
	FILE* file;
	char table[N];
	setlocale(LC_ALL, "Rus");
	file = fopen("label exchange.txt", "r");
	if (file == NULL) { printf("Can't open file"); return 1; }
	while (fgets(table, N, file) != NULL) {
		printf("%s", table);
	}
	int n = amount();
	printf("Total employees-% d\n", n );
	system("pause");
	system("cls");
	fclose(file);
}

int amount() {
	int n = 0;
	FILE* file;
	char table[N];
	file = fopen("label exchange.txt", "r");
	while (fgets(table, N, file) != NULL) {
		n++;
	}
	return n/2;
	fclose(file);
}

int higher_education() {
	float counter = 0;
	worker w;
	FILE* file;
	int n =amount();
	file = fopen("label exchange.txt", "r");
	if (file == NULL) { printf("Can't open file"); return 1; }
	printf("All employees with higher education from the database:\n");
	while (fread(&w, sizeof(worker), 1, file)) {
		if (strcmp(w.education, "no") != 0) {
			printf("%-5s%-20s\n", w.id, w.education);
			counter++;
		}
	}
	printf("Percentage of employees with higher education:%f\n ", (counter / N) * 100);
	fclose(file);
}

void percent() {
	FILE* file;
	char table[N];
	char arr[N];
	int counter = 0;
	setlocale(LC_ALL, "Rus");
	file = fopen("label exchange.txt", "r");
	if (file == NULL) { printf("Can't open file"); return 1; }
	fgets(arr, N, file);
	while (fgets(table, N, file) != NULL) {
		if (strcmp(arr, "нет") == 0) {
			counter++;
		}
	}
	printf("Total employees-% d\n", counter);

}
