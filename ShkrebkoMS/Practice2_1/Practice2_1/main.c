#include <stdio.h>
#include "Header.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define LONGLINE 255

int main()
{
	
	int z=0,count=0,a;
	char line[100],word[20];
	setlocale(LC_ALL, "Rus");

	FILE* file = fopen("progr.txt", "r");
	TBook *lib;

	while (fgets(line, LONGLINE, file) != NULL)
	{
		count++;
	}

	rewind(file);

	lib = (TBook*)malloc(sizeof(TBook) * count);

	read(file,lib);
	
	print_book(lib, count);
	do {
		printf("\nКакой жанр вы хотите увидеть?\n");
		printf("1 - Роман-эпопея\n");
		printf("2 - Повесть\n");
		printf("3 - Фантастика\n");
		printf("4 - Проза\n");
		printf("0 - выход из программы\n");

		scanf("%d", &a);

		switch (a)
		{
			case(1):
			{
				strcpy(word, "Роман-эпопея");
				break;
			}
			case(2):
			{
				strcpy(word, "Повесть");
				break;
			}
			case(3):
			{
				strcpy(word, "Фантастика");
				break;
			}
			case(4):
			{
				strcpy(word, "Проза");
				break;
			}
			case(0):
			{
				return 0;
			}
		}
		if ((a > 0) && (a < 5))
		{
			print_section(lib, count, word);
		}
	} while (a!=0);

	free_mas(lib, count);
	fclose(file);
	free(lib);
	return 0;
}