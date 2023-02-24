#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
		printf("\n1.Add a new worker ");
		printf("\n2.All employees with higher education");
		printf("\n3.Exit");
		printf("\nEnter your choice:");
		scanf("%d", &answer);
		switch (answer) {
		case 1: adding ()  ; break;
		case 2: workers(); break;
		case 3: return 0;
		}
	} while (answer != 3);
}

int adding() {
	worker* w;
	char str[1000];
	FILE* file;
	int n;
	file = fopen("label exchange.txt", "a");
	printf("How many workers do you want to add:");
	scanf("%d", &n);
	w = (worker*)calloc(n, sizeof(worker));
	for (int i = 0; i < n; i++)
	{
		printf("Enter id:\n");
		scanf("%s", w[i].id);
		printf("Enter profession:\n");
		scanf("%s", w[i].profession);
		printf("Enter education:\n");
		scanf("%s", w[i].education);
		printf("Enter last job:\n");
		scanf("%s", w[i].last_job);
		printf("Enter reason of dismiss:\n");
		scanf("%s", w[i].rsn_dismis);
		printf("Enter family status : \n");
		scanf("%s", w[i].family_status);
		printf("Enter contact information:\n");
		scanf("%s", w[i].contact_info);
		fwrite(&w[i], sizeof(worker), 1, file);
	}

	fclose(file);
	return 0;
}

int workers () {
	int counter=0;
	worker w;
	char str[1000];
	FILE* file;
	file = fopen("label exchange.txt", "r");
	printf("All employees with higher education from the database:\n");
	while (fread(&w, sizeof(worker), 1, file)) {
		if (strcmp(w.education, "no") != 0) {
			printf("%s: %s", w.id, w.education);
			counter++;
		}

		}
	}
