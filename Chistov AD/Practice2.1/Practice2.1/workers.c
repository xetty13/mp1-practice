#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workers.h";
#define N 1000

void allocate(worker** w, int n) {
	int i;
	*w = (worker*)malloc(sizeof(worker) * 1);
	(*w)->id = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->id[i] = (char*)malloc(N * sizeof(char));
	}
	(*w)->profession = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->profession[i] = (char*)malloc(N * sizeof(char));
	}
	(*w)->last_job = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->last_job[i] = (char*)malloc(N * sizeof(char));
	}
	(*w)->education = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->education[i] = (char*)malloc(N * sizeof(char));
	}
	(*w)->rsn_dismiss = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->rsn_dismiss[i] = (char*)malloc(N * sizeof(char));
	}
	(*w)->family_status = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->family_status[i] = (char*)malloc(N * sizeof(char));
	}
	(*w)->contact_info = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->contact_info[i] = (char*)malloc(N * sizeof(char));
	}
}

int counter( ) {
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

char* readFile(int charCount) {
	FILE* file = fopen("label exchange.txt", "r");
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
	return buff;
}

void adding(worker* w, char* buff) {
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

void higher_education(worker* w, int count) {
	float counter = 0;
	FILE* file;
	float  n = amount();
	file = fopen("label exchange.txt", "r");
	if (file == NULL) { printf("Can't open file"); return 1; }
	int i;
	printf("All employees with higher education from the database:\n");
	for (i = 0; i < count; i++) {
		if (strcmp(w->education[i], "no") != 0) {
			printf("%-5s%-20s\n", w->id[i], w->education[i]);
			counter++;
		}
		else { continue; }
	}
printf("Percentage of employees with higher education:%.3f%%\n ", (counter / n) * 100);
system("pause");
system("cls");
fclose(file);
}

void memory_free(worker** w, int n) {
	int i;
	for (i = 0; i < n; i++) {
		free((*w)->id[i]);
	}
	free((*w)->id);
	for (i = 0; i < n; i++) {
		free((*w)->profession[i]);
	}
	free((*w)->profession);
	for (i = 0; i < n; i++) {
		free((*w)->education[i]);
	}
	free((*w)->education);
	for (i = 0; i < n; i++) {
		free((*w)->last_job[i]);
	}
	free((*w)->last_job);
	for (i = 0; i < n; i++) {
		free((*w)->rsn_dismiss[i]);
	}
	free((*w)->rsn_dismiss);
	for (i = 0; i < n; i++) {
		free((*w)->family_status[i]);
	}
	free((*w)->family_status);
	for (i = 0; i < n; i++) {
		free((*w)->contact_info[i]);
	}
	free((*w)->contact_info);
	free(*w);
}


