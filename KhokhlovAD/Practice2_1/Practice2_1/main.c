#include <stdio.h>
#include <stdlib.h>
#include "zagolovok.h"

int main()
{
	int n=0, i;
	Owners* owner = read_inf(&n);
	print_inf(owner, owner[0].n);
	search_owner(owner, owner[0].n);
	free_inf(&owner, owner[0].n);
	
	return 0;
}