#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void main()
{
	char filename[31];
	if (fgets(filename, 30, stdin) != NULL)
		filename[strlen(filename) - 1] = '\0';
	struct EmployeesInfo_t* g_empls;
	struct Pasports_t* g_pspts;
	int n = 12;
	allocstructmem(n, filename, &g_empls, &g_pspts);
	age_scan(n, g_empls, g_pspts);
	struct_free(g_empls, g_pspts);
}
