#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

/*Обеспечить поиск безработных
с высшим образованием и вычислить процент таковых от общего числа безработных.*/

typedef struct worker {
	char id[20];
	char profession[10];
	char education[20];
	char last_job[100];
	char rsn_dismis[20];
	char family_status[10];
	char contact_info[20];
}worker;

int main() {
	int answer;
	do {
		printf("MENU:\n");
		printf("1.Add a new worker\n");
		printf("2.All employees with higher education\n");
		printf("3.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &answer);
		switch (answer) {
		case 1: adding(); break;
		case 2: workers(); break;
		case 3: return 0;
		}
	} while (answer != 3);
}

int adding() {
	worker* w;
	FILE* file;
	int n;
	file = fopen("label exchange.txt", "w+");
	if (file == NULL) { printf("Can't open file"); return 1; }
	printf("How many workers do you want to add:");
	scanf("%d", &n);
	w = (worker*)calloc(n, sizeof(worker));
	for (int i = 0; i < n; i++)
	{
		printf("Enter id:\n");
		gets(w[i].id);
		/*printf("Enter profession:\n");
		scanf("%s", w[i].profession);	*/	
		printf("Enter education:\n");
		gets(w[i].education);
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
	fclose(file);
}

int workers() {
	int counter = 0;
	worker w;
	char str[1000];
	FILE* file;
	int N = count();
	file = fopen("label exchange.txt", "r");
	if (file == NULL) { printf("Can't open file"); return 1; }
	printf("All employees with higher education from the database:\n");
	while (fread(&w, sizeof(worker), 1, file)) {
		if (strcmp(w.education, "no") != 0) {
			printf("%-5s%-20s\n", w.id, w.education);
			counter++;
		}
	}
	printf("Percentage of employees with higher education:%f\n ", (float)(counter / N)*100);
	fclose(file);
}

int amount() {
	worker w1;
	FILE* file;
	file = fopen("label exchange.txt", "r");
	fseek(file, 0, SEEK_END);
	int n = ftell(file) / sizeof(worker);
	return n;
}
