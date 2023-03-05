#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "workers.h";
#define N 100

void allocate(worker** w) {
	(*w) = (worker*)malloc(sizeof(worker) * 1);
	(*w)->id = (char*)malloc(sizeof(char) * N);
	(*w)->profession = (char*)malloc(sizeof(char) * N);
	(*w)->education = (char*)malloc(sizeof(char) * N);
	(*w)->last_job = (char*)malloc(sizeof(char) * N);
	(*w)->rsn_dismis = (char*)malloc(sizeof(char) * N);
	(*w)->family_status = (char*)malloc(sizeof(char) * N);
	(*w)->contact_info = (char*)malloc(sizeof(char) * N);
}

void databse() {
	setlocale(LC_ALL, "Rus");
	FILE* file;
	char table[N];
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

int higher_education(worker** w) {
	setlocale(LC_ALL, "Rus");
	float counter = 0;
	FILE* file;
	char* istr;
	char sep = ' ';
	char table[N];
	int i, j;
	int n =amount();
	file = fopen("label exchange.txt", "r");
	if (file == NULL) { printf("Can't open file"); return 1; }
	fgets(table, N, file);
	istr = strtok(table,sep);
	while (istr != NULL) {
		for (int i = 0; i < n; i++) {
			(*w)->id[i] = istr;
			istr = strtok(NULL, sep);
			(*w)->profession[i] = istr;
			istr = strtok(NULL, sep);
			(*w)->education[i] = istr;
			istr = strtok(NULL, sep);
			(*w)->last_job[i] = istr;
			istr = strtok(NULL, sep);
			(*w)->rsn_dismis[i] = istr;
			istr = strtok(NULL, sep);
			(*w)->family_status[i] = istr;
			istr = strtok(NULL, sep);
			(*w)->contact_info[i] = istr;
			istr = strtok(NULL, sep);
		}
	}
	while (fread(*w, sizeof(worker), 1, file)) {
		if (strcmp((*w)->education, "no") != 0) {
			printf("%-5s%-20s\n", (*w)->id, (*w)->education);
			counter++;
		}
	}
	
	printf("Percentage of employees with higher education:%f\n ", (counter / N) * 100);
	fclose(file);
}

void percent() {}

void free(worker** w) {
	free((*w)->id);
	free((*w)->profession);
	free((*w)->education);
	free((*w)->last_job);
	free((*w)->rsn_dismis);
	free((*w)->family_status);
	free((*w)->contact_info);
	free(*w);
}
