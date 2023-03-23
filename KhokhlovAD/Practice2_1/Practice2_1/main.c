#include <stdio.h>
#include <stdlib.h>
#include "zagolovok.h"

int main()
{
	
	Owners* owner = read_inf();
	print_inf(owner, owner[0].n);
	search_owner(owner, owner[0].n);
	free_inf(&owner, owner[0].n);
	
	return 0;
}