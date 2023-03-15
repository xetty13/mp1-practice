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
		(*w)->id[i] = (char*)malloc(100 * sizeof(char));
	}
	(*w)->profession = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->profession[i] = (char*)malloc(100 * sizeof(char));
	}
	(*w)->education = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->education[i] = (char*)malloc(1000 * sizeof(char));
	}
	(*w)->last_job = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		(*w)->last_job[i] = (char*)malloc(100 * sizeof(char));
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

int amount( ) {
	int amount = 0;
	char* str = (char*)malloc(N * sizeof(char));
	FILE* file = fopen("label exchange.txt", "r");
if (file == NULL) { printf("Can't open file"); return 1; }
	while (1) {
		if (fgets(str, N, file) != NULL) {
			if (strcmp(str, "\n") != 0) {
				amount++;
			}
		}
		else {
			break;
		}
	}
	fclose(file);
	free(str);
	return amount;
}

void adding(worker* w ) {
	char* token;
	char srch[] = ";\n";
	int i = 0;
	int j = 0;
	FILE* file = fopen("label exchange.txt", "r");
	char* str = (char*)malloc(1024 * sizeof(char));
	if (file == NULL) { printf("Can't open file"); return 1; }
	while (1) {
		if (fgets(str, 1000, file) != NULL) {
			for (token = strtok(str, srch); token; token = strtok(NULL, srch)) {
				switch (i) {
				case 0:
					strcpy(w->id[j], token);
					break;
				case 1:
					strcpy(w->profession[j], token);
					break;
				case 2:
					strcpy(w->education[j], token);
					break;
				case 3:
					strcpy(w->last_job[j], token);
					break;
				case 4:
					strcpy(w->rsn_dismiss[j], token);
					break;
				case 5:
					strcpy(w->family_status[j], token);
					break;
				case 6:
					strcpy(w->contact_info[j], token);
					i = -1;
					j++;
					break;
				}
				i++;
			}
		}
		else {
			break;
		}
	}
	free(str);
	fclose(file);
}

void higher_education(worker* w, int count) {
	float counter = 0;
	FILE* file;
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
printf("Percentage of employees with higher education:%.3f%%\n ", (counter / count) * 100);
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
