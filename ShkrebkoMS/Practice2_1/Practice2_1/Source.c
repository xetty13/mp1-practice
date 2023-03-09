#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h";
#include <locale.h>
#define LONGLINE 255

int read(FILE* file,TBook* book)

{	
	int n,count=0;
	char line[LONGLINE];
	char* pos1;
	char find[] = ";";
	while (fgets(line, LONGLINE, file) != NULL)
	{
		pos1 = strtok(line, find);
		if (*pos1 == '\n')
		{
			break;
		}
		strcpy(book->Author, pos1);
		n = 0;
		while (pos1 != NULL)
		{
			pos1 = strtok(NULL, find);
			switch (n)
			{
				case (0):
				{
					strcpy(book->Name, pos1);
					n++;
					break;
				}
				case (1):
				{
					strcpy(book->Publishing, pos1);
					n++;
					break;
				}
				case (2):
				{
					strcpy(book->Section, pos1);
					n++;
					break;
				}
				case (3):
				{
					strcpy(book->Availability, pos1);
					n++;
					break;
				}
				case (4):
				{
					strcpy(book->Score, pos1);
					n++;
					break;
				}
			}

		}
		count++;
		book++;
	}
	return count;
}
void print_book(TBook* book,int count)
{
	int i,j;
	printf("Имеются следующие книги в нашей библиотеке:\n\n");
	for (i = 0; i < count; i++)
	{
		printf("%d. Автор - %s| Название книги - %s|Издательство - %s|Жанр - %s|Наличие - %s|Оценка - %s\n", (i+1),book[i].Author, book[i].Name, book[i].Publishing, book[i].Section, book[i].Availability, book[i].Score);
	}
}

void print_section(TBook* book, int count, char* word)
{
	int i,j;
	j = 1;
	for (i = 0; i < count; i++)
	{
		if (strcmp(book[i].Section, word) == 0)
		{
			printf("%d. Автор - %s| Название книги - %s|Издательство - %s|Жанр - %s|Наличие - %s|Оценка - %s\n", j++, book[i].Author, book[i].Name, book[i].Publishing, book[i].Section, book[i].Availability, book[i].Score);
		}
		
	}
}


