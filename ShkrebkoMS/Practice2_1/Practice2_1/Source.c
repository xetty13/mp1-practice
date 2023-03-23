#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
#include <locale.h>
#include <stdbool.h>

#define LONGLINE 255
#define LONTAUTHORNAME 255
void setAuthors(char* strTmp,TBook* book)
{
	char* pos1;
	char find[] = ",";
	int i,count = 0;
	char strTmp1[100];
	strcpy(strTmp1, strTmp);
	pos1 = strtok(strTmp, find);


	while (pos1 != NULL)
	{
		count++;
		pos1 = strtok(NULL, find);

	}
	book->Couaut = count;
	(book->Author) = malloc(sizeof( *(book->Author)) * count);
	for (i = 0; i < count; i++)
	{
		book->Author[i] = malloc(LONTAUTHORNAME);
	}
	
	pos1 = strtok(strTmp1, find);
	i = 0;
	while (pos1 != NULL)
	{
		strcpy(book->Author[i], pos1);
		i++;
		pos1 = strtok(NULL, find);

	}


}
void read(FILE* file,TBook* book, int* couaut)

{	
	int n,j=0,count=0;
	char line[LONGLINE];
	char* pos1;
	char find[] = ";";
	char strTmp[100];
	while (fgets(line, LONGLINE, file) != NULL)
	{
		pos1 = strtok(line, find);
		if (*pos1 == '\n')
		{
			break;
		}
		n = 0;
		strcpy(strTmp, pos1);

		

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
					if (strcmp(pos1, "Есть") == 0)
					{
						book->Availability = true;
					}
					else
					{
						book->Availability = false;
					}
					n++;
					break;
				}
				case (4):
				{
					book->Score= strtol(pos1,NULL,10);
					n++;
					break;
				}
			}

		}
		setAuthors(strTmp, book);
		book++;
	}

}
void print_book(TBook* book,int count)
{
	int i,j;

	printf("Имеются следующие книги в нашей библиотеке:\n\n");
	for (i = 0; i < count; i++)
	{
		printf("%d.", (i+1));
		printf("Автор -");
		for (j = 0; j < book[i].Couaut; j++)
		{
			printf(" %s, ", book[i].Author[j]);
		}
		printf("| Название книги - %s|", book[i].Name);
		printf(" Издательство - %s|", book[i].Publishing);
		printf(" Жанр - %s|",  book[i].Section);
		if(book->Availability)
		{
			printf("Наличие - Есть");
		}
		else
		{
			printf("Наличие - Нет");
		}
		printf("|Оценка - %d\n", book[i].Score);
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
			printf("%d.", j++);

			printf("Автор -");
			for (j = 0; j < book[i].Couaut; j++)
			{
				printf(" %s, ", book[i].Author[j]);
			}
			printf(" | Название книги - %s|", book[i].Name);
			printf(" Издательство - %s|", book[i].Publishing);
			printf(" Жанр - %s|", book[i].Section);
			if (book->Availability)
			{
				printf("Наличие - Есть");
			}
			else
			{
				printf("Наличие - Нет");
			}
			printf("|Оценка - %d\n", book[i].Score);
		}
		
	}
	
}

void free_mas(TBook* book,int count)
{
	int i,j;
	int pos;
	for (i = 0; i < count; i++)
	{
		pos = book[i].Couaut;
		for (j = 0; j < pos; j++)
		{
			free(book[i].Author[j]);
		}
		free(book[i].Author);
	}
}


