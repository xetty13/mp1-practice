#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "workers.h";
#define N 1000

void allocate(worker** w, int n  ) {
		int i;
		*w = (worker*)malloc(sizeof(worker) * 1);
		(*w)->id = (char**)malloc(n * sizeof(char*));
		for (i = 0; i < n; i++) {
			(*w)->id[i] = (char*)malloc(100 * sizeof(char));
		}
		(*w)->profession = (char**)malloc(n * sizeof(char*));
		for (i = 0; i < n; i++) {
			(*w)->profession[i] = (char*)malloc(100 * sizeof(char));
		}
		(*w)->last_job = (char**)malloc(n * sizeof(char*));
		for (i = 0; i < n; i++) {
			(*w)->last_job[i] = (char*)malloc(100 * sizeof(char));
		}
		(*w)->education = (char**)malloc(n * sizeof(char*));
		for (i = 0; i < n; i++) {
			(*w)->education[i] = (char*)malloc(1000 * sizeof(char));
		}
		(*w)->rsn_dismiss = (char**)malloc(n * sizeof(char*));
		for (i = 0; i < n; i++) {
			(*w)->rsn_dismiss[i] = (char*)malloc(100 * sizeof(char));
		}
		(*w)->family_status = (char**)malloc(n * sizeof(char*));
		for (i = 0; i < n; i++) {
			(*w)->family_status[i] = (char*)malloc(100 * sizeof(char));
		}
		(*w)->contact_info = (char**)malloc(n * sizeof(char*));
		for (i = 0; i < n; i++) {
			(*w)->contact_info[i] = (char*)malloc(100 * sizeof(char));
		}
	}

int counter( ) {
	setlocale(LC_ALL, "Russian");
	char c;
	int count = 0;
	FILE* file = fopen("label exchange.txt", "r");
if (file == NULL) { printf("Can't open file"); return 1; }
	for (c = getc(file); c != EOF; c = getc(file)) {
		count++;
	}
	fclose(file);
	return count;
}

int amount( ) {
	int amount = 0;
	char* s = (char*)malloc(N * sizeof(char));
	FILE* file = fopen("label exchange.txt", "r");
if (file == NULL) { printf("Can't open file"); return 1; }
	while (1) {
		if (fgets(s, N, file) != NULL) {
			if (strcmp(s, "\n") != 0) {
				amount++;
			}
		}
		else {
			break;
		}
	}
	fclose(file);
	free(s);
	return amount;
}

void database () {
	setlocale(LC_ALL, "Russian");	
	FILE* file = fopen("label exchange.txt", "r");;
	char table[N];
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

char* readFile(int charCount) {
	setlocale(LC_ALL, "Russian");
	FILE* file;
	file = fopen("label exchange.txt", "r");
	char* str = (char*)malloc(1024 * sizeof(char));
	char* buff = (char*)malloc(10 * charCount * sizeof(char));
	char* bcpy = (char*)malloc(10 * charCount * sizeof(char));
	if (file == NULL) { printf("Can't open file"); return 1; }
	while (1) {
		if (fgets(str, 1000, file) != NULL) {
			strcpy(bcpy, buff);
			snprintf(buff, charCount, "%s%s", str, bcpy);}
		else {
			break;
		}
	}
	free(str);
	free(bcpy);
	fclose(file);
	return buff;
}

void adding(worker* w, char* buff) {
	setlocale(LC_ALL, "Rus");
	char* token;
	char delim[] = ";\n";
	int i = 0;
	int j = 0;
	for (token = strtok(buff, delim); token; token = strtok(NULL, delim)) {
		switch (i) {
		case 0:
			w->id[j] = token;
			break;
		case 1:
			w->profession[j] = token;
			break;
		case 2:
			w->education[j] = token;
			break;
		case 3:
			w->last_job[j] = token;
			break;
		case 4:
			w->rsn_dismiss[j] = token;
			break;
		case 5:
			w->family_status; break;
		case 6:
			w->contact_info[j] = token;
			i = -1;
			j++;
			break;
		}
		i++;
	}
}

void higher_education(worker** w) {
	setlocale(LC_ALL, "Russian");
	float counter = 0;
	FILE* file;
	float  n = amount();
	file = fopen("label exchange.txt", "r");
	if (file == NULL) { printf("Can't open file"); return 1; }
	while (fread(&w, sizeof(worker), 1, file)) {
		if (strcmp((*w)->education, " нет'") != 0) {
			printf("%-5s%-20s\n", (*w)->id, (*w)->education);
			counter++;
		}
	}
	printf("Percentage of employees with higher education:%f\n ", (counter / n) * 100);
	fclose(file);
}
 void memory_free(worker** w, int n) {
	setlocale(LC_ALL, "Rus");
	int i;
	for (i = 0; i < n; i++) {
		(*w)->id[i] = NULL;
		free((*w)->id[i]);
	}
	free((*w)->id);
	for (i = 0; i < n; i++) {
		(*w)->profession[i] = NULL;
		free((*w)->profession[i]);
	}
	free((*w)->profession);
	for (i = 0; i < n; i++) {
		(*w)->education[i] = NULL;
		free((*w)->education[i]);
	}
	free((*w)->education);
	for (i = 0; i < n; i++) {
		(*w)->last_job[i] = NULL;
		free((*w)->last_job[i]);
	}
	free((*w)->last_job);
	for (i = 0; i < n; i++) {
		(*w)->rsn_dismiss[i] = NULL;
		free((*w)->rsn_dismiss[i]);
	}
	free((*w)->rsn_dismiss);
	for (i = 0; i < n; i++) {
		(*w)->family_status[i] = NULL;
		free((*w)->family_status[i]);
	}
	free((*w)->family_status);
	for (i = 0; i < n; i++) {
		(*w)->contact_info[i] = NULL;
		free((*w)->contact_info[i]);
	}
	free((*w)->contact_info);
	free(*w);
}

