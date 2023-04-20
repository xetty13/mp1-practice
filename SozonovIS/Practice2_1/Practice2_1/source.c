#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#include "header.h"
#define N 100

int counting() {
	FILE* file = fopen("C:\\Temp\\school.csv", "r");
	char line[200];
	int n = 0;
	if (file == NULL) {
		printf("File not defind\n");
		return 1;
	}
	else {
		while (!feof(file)) {
			fgets(line, 200, file);
			n++;
		}
	}
	return n;
	fclose(file);
}

void allocation(TSchool** school, int n) {
	int i = 0;
	(*school) = (TSchool*)malloc(sizeof(TSchool) * n);
	for (; i < n; i++) {
		(*school + i)->FIO = (char*)malloc(sizeof(char) * N);
		(*school + i)->Gender = (char*)malloc(sizeof(char) * N);
		(*school + i)->Date = (char*)malloc(sizeof(char) * N);
		(*school + i)->Address = (char*)malloc(sizeof(char) * N);
	}
}

void release(TSchool** school, int n) {
	int i = 0;
	for (; i < n; i++) {
		free((*school + i)->FIO);
		free((*school + i)->Gender);
		free((*school + i)->Date);
		free((*school + i)->Address);
	}
	free(*school);
}

void read_file(TSchool* school) {
	FILE* file = fopen("C:\\Temp\\school.csv", "r");
	int i, j = 0;
	char line[200];
	char* str;
	if (file == NULL) {
		printf("File not defind\n");
	}
	else {
		while (1) {
			if (fgets(line, 200, file) != NULL) {
				i = 0;
				str = strtok(line, ";");
				while (str != NULL) {
					switch (i) {
					case 0:
						strcpy(school[j].FIO, str);
						break;
					case 1:
						school[j].Class = atoi(str);
						break;
					case 2:
						strcpy(school[j].Gender, str);
						break;
					case 3:
						strcpy(school[j].Date, str);
						break;
					case 4:
						strcpy(school[j].Address, str);
						break;
					}
					i++;
					str = strtok(NULL, ";");
				}
				j++;
			}
			else {
				break;
			}
		}
	}
}



void print_file(TSchool* school, int n) {
	int i = 0;
	printf("ФИО           Класс      Пол      Дата рождения             Домашний адрес\n");
	printf("\n");
	for (; i < n; i++) {
		printf("%s     %d     %s     %s     %s\n", school[i].FIO, school[i].Class, school[i].Gender, school[i].Date, school[i].Address);
	}
}

void sorting(TSchool* school, int n) {
	int i = 0, j, k = 1;
	TSchool tmp;
	for (; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (school[i].Class > school[j].Class) {
				tmp = school[i];
				school[i] = school[j];
				school[j] = tmp;
			}
		}
	}
	i = 0;
	while (i < n) {
		while (school[i].Class == k) {
			j = i + 1;
			while (school[j].Class == k) {
				if (strcmp(school[i].FIO, school[j].FIO) > 0) {
					tmp = school[i];
					school[i] = school[j];
					school[j] = tmp;
				}
				j++;
			}
			i++;
		}
		k++;
	}
}