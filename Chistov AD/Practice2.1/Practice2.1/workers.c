#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "workers.h";

int adding() {
	worker* w;
	FILE* file;
	int n;
	printf("How many workers do you want to add:");
	scanf("%d", &n);
	file = fopen("label exchange.txt", "a+");
	if (file == NULL) { printf("Can't open file"); return 1; }
	w = (worker*)calloc(n, sizeof(worker));
	for (int i = 0; i < n; i++)
	{
		printf("Enter id:\n");
		scanf("%s", w[i].id);
		/*printf("Enter profession:\n");
		scanf("%s", w[i].profession);	*/
		printf("Enter education:\n");
		scanf("%s", w[i].education);
		/*
		printf("Enter last job:\n");
		scanf("%s", w[i].last_job);
		printf("Enter reason of dismiss:\n");
		scanf("%s", w[i].rsn_dismis);
		printf("Enter family status : \n");
		scanf("%s", w[i].family_status);
		printf("Enter contact information:\n");
		scanf("%s", w[i].contact_info);
		*/
		fwrite(&w[i], sizeof(worker), 1, file);
	}
	free(w);
	system("cls");
	fclose(file);
}

int workers() {
	float counter = 0;
	worker w;
	FILE* file;
	float  N = amount();
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

float amount() {
	FILE* file;
	file = fopen("label exchange.txt", "r");
	fseek(file, 0, SEEK_END);
	float n = ftell(file) / sizeof(worker);
	return n;
	fclose(file);
}

