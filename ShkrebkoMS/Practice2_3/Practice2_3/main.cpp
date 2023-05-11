#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <sstream>


int main()
{
	setlocale(LC_ALL, "Rus");

	string path = get_path();

	TLib full_library(path);

	cout << full_library;
	int choose_section_number;
	TLib sectionLibrary;
	do
	{

		full_library.print_unique_sections();
		cin >> choose_section_number;

		if (choose_section_number != 0)
		{

			sectionLibrary = full_library.search_by_section(full_library.GetUnicSection(choose_section_number - 1));
			cout << sectionLibrary;
		}

	} while (choose_section_number != 0);


	return 0;
}
