#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workers.h";
#define N 100

void allocate_workers(worker** w, int n)
{
	(*w) = (worker*)malloc(sizeof(worker) * n);
	for (int i = 0; i < n; i++) {
		(*w + i)->id = (char*)malloc(sizeof(char) * N);
		(*w + i)->profession = (char*)malloc(sizeof(char) * N);
		(*w + i)->education = (char*)malloc(sizeof(char) * N);
		(*w + i)->last_job = (char*)malloc(sizeof(char) * N);
		(*w + i)->rsn_dismiss = (char*)malloc(sizeof(char) * N);
		(*w + i)->family_status = (char*)malloc(sizeof(char) * N);
		(*w + i)->contact_info = (char*)malloc(sizeof(char) * N);

	}
}

int amount() {
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

void adding(worker* w) {
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
 					strcpy(w[j].id, token);
					break;
				case 1:
					strcpy(w[j].profession, token);
					break;
				case 2:
					strcpy(w[j].education, token);
					break;
				case 3:
					strcpy(w[j].last_job, token);
					break;
				case 4:
					strcpy(w[j].rsn_dismiss, token);
					break;
				case 5:
					strcpy(w[j].family_status, token);
					break;
				case 6:
					strcpy(w[j].contact_info, token);
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
	for (i = 0; i < count ; i++) {
		if (strcmp(w[i].education, "no") != 0) {
			printf("%-5s%-20s\n", w[i].id, w[i].education);
			counter++;
		}
	}
printf("Percentage of employees with higher education:%.3f%%\n ", (counter / count) * 100);
system("pause");
system("cls");
fclose(file);
}

void free_workers(worker** w, int n)
{
	for (int i = 0; i < n; i++) {
		free((*w + i)->id);
		free((*w + i)->profession);
		free((*w + i)->education);
		free((*w + i)->last_job);
		free((*w + i)->rsn_dismiss);
		free((*w + i)->family_status);
		free((*w + i)->contact_info);
	}
	free(*w);
}
