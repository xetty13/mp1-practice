#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workers.h";
#define N 100

char* get_Path() {
	char* path = (char*)malloc(_MAX_PATH * sizeof(char));
	do {
		printf("Enter the file path:");
		gets(path);
		FILE* file = fopen(path, "r");
		if (file == NULL) {
			printf("Ooops.....Something went wrong......\n");
		}
		else {
			fclose(file);
			return path;
		}
	} while (1);
}

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
	}
}

int amount(char* path) {
	int amount = 0;
	char* str = (char*)malloc(N * sizeof(char));
	FILE* file = fopen(path, "r");
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
	free(str);
	return amount;
}

void adding(worker* w, char* path) {
	char* token;
	char srch[] = ";\n";
	int i = 0;
	int j = 0;
	FILE* file = fopen(path, "r");
	char* str = (char*)malloc(1024 * sizeof(char));
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
					w[j].contact_info = atoi(token);
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
}

void higher_education(worker* w, int count) {
	float counter = 0;
	int i;
	printf("All employees with higher education from the database:\n");
	for (i = 0; i < count ; i++) {
		if (strcmp(w[i].education, "no") != 0) {
			printf("%-5s %20s\n", w[i].id, w[i].education);
			counter++;
		}
	}
printf("Percentage of employees with higher education:%.3f%%\n ", (counter / count) * 100);
system("pause");
system("cls");
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
	}
	free(*w);
}
