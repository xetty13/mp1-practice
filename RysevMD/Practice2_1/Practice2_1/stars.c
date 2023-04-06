#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stars.h"

void Callocate(Constellation** cns, int c) {
	(*cns) = (Constellation*)malloc(sizeof(Constellation) * c);
}
void Sallocate(Star** st, int c) {
	(*st) = (Star*)malloc(sizeof(Star) * c);
}
void cfree(Constellation** cns) {
	free((*cns)->stars);
	free(*cns);
}


void read_data(Constellation** cns, int* count) {
	FILE* fp;
	char* path = (char*)malloc(sizeof(char) * 260);
	int cns_count, stars_count;
	printf("\nEnter the path: ");
	scanf("%s", path);
	fp = fopen(path, "r");
	fscanf(fp, "%d", &cns_count);
	(*count) = cns_count;
	Callocate(cns, cns_count);
	for (int i = 0; i < cns_count; i++) {
		fscanf(fp, "%s %d", (*cns)[i].name, &stars_count);
		(*cns)[i].count = stars_count;
		Sallocate(&(*cns)[i].stars, stars_count);
		for (int j = 0; j < stars_count; j++) {
			fscanf(fp, "%s %f %f %f %f %f", (*cns)[i].stars[j].name, &(*cns)[i].stars[j].dist, &(*cns)[i].stars[j].magnitude, &(*cns)[i].stars[j].deg, &(*cns)[i].stars[j].min, &(*cns)[i].stars[j].sec);
		}
	}
	free(path);
	fclose(fp);
}
void print_data(Constellation* cns, int n) {
	printf("\n%s:\n", cns[n].name);
	for (int j = 0; j < cns[n].count; j++) {
		printf("  %  s   %-0.3f   %0.3f   %0.3f°   %0.3f\'   %0.3f\"\n", cns[n].stars[j].name, cns[n].stars[j].dist, cns[n].stars[j].magnitude, cns[n].stars[j].deg, cns[n].stars[j].min, cns[n].stars[j].sec);
	}
	printf("\n");
}

void cnst_table(Constellation* cns, int count) {
	printf("\n");
	for (int i = 0; i < count / 2; i++) {
		printf("%d\. %s \t\t %d\. %s\n", i + 1, cns[i].name, i + 6, cns[i + 5].name);
	}
	printf("\nOutput format:\n\n  name distance magnitude coordinates(deg, min, sec)\n\n");
}
void choice(Constellation* cns, int count) {
	char con[100];
	printf("Choose a constellation\n");
	do {
		int flag = 0;
		printf(">> ");
		scanf("%s", con);
		if (strcmp(con, "stop") == 0) flag = 1;
		for (int i = 0; i < count && flag == 0; i++) {
			if (strcmp(con, cns[i].name) == 0) {
				print_data(cns, i);
				flag = 1;
			}
		}
		if (!flag) printf("Not found. Please, choose constellation from table\n");
	} while (strcmp(con, "stop") != 0);
	cfree(&cns);
}