#include <stdio.h>
#include <stdlib.h>
#include "zagolovok.h"




Owners* read_inf()
{
	FILE* f;
	int n;
	char* path = (char*)malloc(sizeof(char)*100);
	gets(path);  //1
	f = fopen(path, "r");
	if (f == NULL)
	{
		printf("File not found\n");
	}
	else
		printf("file opened successfully\n");
	fscanf(f, "%d", &n);	
	Owners* owner = (Owners*)malloc(sizeof(Owners) * n);
	printf("number of owners = %d\n", n);
	for (int i = 0; i < n; i++) 
	{
		owner[i].n = n;
		owner[i].name = (char*)malloc(sizeof(char) * 12);
		owner[i].surname = (char*)malloc(sizeof(char) * 12);
		owner[i].patronymic = (char*)malloc(sizeof(char) * 20);
		owner[i].date = (char*)malloc(sizeof(char) * 12);
		owner[i].carnum = (char*)malloc(sizeof(char) * 12);
		owner[i].phnum = (char*)malloc(sizeof(char) * 13);
		fscanf(f, "%s %s %s %s %s %d %s %d", owner[i].name, owner[i].surname, owner[i].patronymic, owner[i].date, owner[i].carnum, &owner[i].gibdd, owner[i].phnum, &owner[i].tehpas);
	}
	fclose(f);
	free(path);
	return owner;
}


void print_inf(Owners* owner, int n)
{
	for (int i = 0; i < n; i++)
	{

		printf("%s %s %s\n %s\n %s\n %d\n %s\n %d\n\n", owner[i].name, owner[i].surname, owner[i].patronymic, owner[i].date, owner[i].carnum, owner[i].gibdd, owner[i].phnum, owner[i].tehpas);
	}
}

int search_owner(Owners* owner, int n)
{

	int flag = 0, g;
	while (flag == 0)
	{
		printf("input number of gibdd = ");
		scanf("%d", &g);
		printf("\n");
		for (int i = 0; i < n; i++)
		{
			if (owner[i].gibdd == g)
			{
				flag++;
				printf("%s %s %s\n %s\n %s\n %d\n %s\n %d\n\n", owner[i].name, owner[i].surname, owner[i].patronymic, owner[i].date, owner[i].carnum, owner[i].gibdd, owner[i].phnum, owner[i].tehpas);
			}
		}
		if (flag == 0)
		{
			printf("incorrect number of gibdd\n");
		}
	}
	return 0;
}

void free_inf(Owners** owner, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		
		free((*owner)[i].name);
		free((*owner)[i].surname);
		free((*owner)[i].patronymic);
		free((*owner)[i].date);
		free((*owner)[i].carnum);
		free((*owner)[i].phnum);
		
	}
	free(*owner);
}