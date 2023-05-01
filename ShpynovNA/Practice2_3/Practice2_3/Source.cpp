#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>

void main()
{
int n = 12;
char filename[31];
if (fgets(filename, 30, stdin) != NULL)
filename[strlen(filename) - 1] = '\0';
employees_t* g_empls = new employees_t[n];
pasports_t* g_pspts = new pasports_t[n];
createmem(n, filename, &g_empls, &g_pspts);
age_scan(n, g_empls, g_pspts);
delete[] g_empls;
delete[] g_pspts;
}