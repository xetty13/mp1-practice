#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <sstream>


int main()
{


	string line;
	string* unic_section;

	setlocale(LC_ALL, "Rus");
	
	string str;

	int count = count_books(str);


	
	TBook* lib = new TBook[count];
	read(str, lib, count);

	int  unic;
	unic = count_unic(lib, count);

	
	unic_section = create_section(lib, unic, count);
	print_book(lib, count);



	print_choose_book(lib, count, unic, unic_section);


	free_mas(lib, count);
	delete[] unic_section;
	return 0;
}

