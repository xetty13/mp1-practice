#include <stdio.h>
#include <stdlib.h>
#include "zagolovok.h"

int main()
{
	int n, i, g, flag = 0;
	FILE* f;
	f = fopen("1.txt", "r");
	if (f == NULL)
	{
		printf("File not found\n");
		return 1;
	}
	else
		printf("file opened successfully\n");
	fscanf(f, "%d", &n);
	Owners* owner = (Owners*)malloc(sizeof(Owners) * n);
	printf("number of owners = %d\n", n);
	read_inf(owner, f, n);
	print_inf(owner, n);
	while (flag == 0)
	{
		printf("input number of gibdd = ");
		scanf("%d", &g);
		printf("\n");
		if (search_owner(owner, g, n) == 0)
			flag++;
	}
	free_inf(&owner, n);
	fclose(f);
	return 0;
}