#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>


int main()
{
	
	int z=0,count=0,unic,i;
	char line[LINE],word[LINE],str[LINE];
	char** unic_section=NULL;
	
	setlocale(LC_ALL, "Rus");
	TBook* lib;

	count = count_books(str);
	if (count == -1)
		return 1;
	
	lib = (TBook*)malloc(sizeof(TBook) * count);

	read(str,lib);

	unic = count_unic(lib, count);
	unic_section= create_section(lib,unic,count);
	
	print_book(lib, count);
	
	print_choose_book(lib, count,unic, unic_section);
	free_unic(unic_section,unic);
	free_mas(lib, count);

	return 0;
}