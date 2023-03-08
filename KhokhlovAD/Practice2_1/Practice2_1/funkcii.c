#include <stdio.h>
#include <stdlib.h>
#include "zagolovok.h"




void read_inf(Owners* owner, FILE* f, int n)
{
	for (int i = 0; i < n; i++) 
	{
		owner[i].name = (char*)malloc(sizeof(char) * 40);
		owner[i].date = (char*)malloc(sizeof(char) * 11);
		owner[i].carnum = (char*)malloc(sizeof(char) * 6);
		owner[i].phnum = (char*)malloc(sizeof(char) * 12);
		fscanf(f, "%s %s %s %d %s %d", owner[i].name, owner[i].date, owner[i].carnum, &owner[i].gibdd, owner[i].phnum, &owner[i].tehpas);
	}
}


void print_inf(Owners* owner, int n)
{
	for (int i = 0; i < n; i++)
	{

		printf("%s\n %s\n %s\n %d\n %s\n %d\n\n", owner[i].name, owner[i].date, owner[i].carnum, owner[i].gibdd, owner[i].phnum, owner[i].tehpas);
	}
}

int search_owner(Owners* owner, int gibdd, int n)
{
	int flag=0;
	for (int i = 0; i < n; i++)
	{
		if (owner[i].gibdd == gibdd)
		{
			flag++;
			printf("%s\n %s\n %s\n %d\n %s\n %d\n\n", owner[i].name, owner[i].date, owner[i].carnum, owner[i].gibdd, owner[i].phnum, owner[i].tehpas);
		}
	}
	if (flag == 0)
	{
		printf("incorrect number of gibdd\n");
		return 1;
	}
	return 0;
}

void free_inf(Owners** owner, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		
		free((*owner)[i].name);
		//free((*owner)[i].date);
		//free((*owner)[i].carnum);
		//free((*owner)[i].phnum);
		
	}
	free(*owner);
}