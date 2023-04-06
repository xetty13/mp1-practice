#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

int count_books(char* str)
{
	int count = 0;
	char line[LINE];

	printf("Введите название файла\n");
	gets(str);
	FILE* file = fopen(str, "r");

	if (file == NULL)
	{
		printf("Нет такого файла");
		return -1;
	}

	while (fgets(line, LONGLINE, file) != NULL)
	{
		count++;
	}
	fclose(file);
	return count;
}
void setAuthors(char* strTmp,TBook* book)
{
	char* pos1;
	char find[] = ",";
	int i,count = 0;
	char strTmp1[LINE];
	strcpy(strTmp1, strTmp);
	pos1 = strtok(strTmp, find);


	while (pos1 != NULL)
	{
		count++;
		pos1 = strtok(NULL, find);

	}
	book->Couaut = count;
	(book->Author) = malloc(sizeof(*(book->Author)) * count);
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
void read(char* str, TBook* book)

{	
	int n,j=0,count=0;
	char line[LONGLINE];
	char* pos1;
	char find[] = ";";
	char strTmp[LINE];
	FILE* file = fopen(str, "r");
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
	fclose(file);
}


int count_unic(TBook* book, int count)
{
	int unic = 0;
	int i, j;
	int flag;
	for (i = 0; i < count; i++)
	{
		flag = 0;
		for (j=i+1;j<count;j++)
		{

			if (strcmp(book[i].Section, book[j].Section) == 0)
			{
				flag++;
				break;
			}


		}
		if (flag == 0)
			unic++;
	}
	return unic;

}

char** create_section(TBook* book, int unic, int count)
{
	int i,flag,k,j;
	char** unic_section;
	unic_section = (char**)malloc(sizeof(char*) * unic);
	k = 0;
	for (i = 0; i < unic; i++)
	{
		unic_section[i] = (char*)malloc(sizeof(char)*LINE);
	}
	for (i = 0; i < count; i++)
	{
		flag = 0;
		for (j = i + 1; j < count; j++)
		{

			if (strcmp(book[i].Section, book[j].Section) == 0)
			{
				flag++;
				break;
			}


		}
		if (flag == 0)
		{
			strcpy(unic_section[k], book[i].Section);
			k++;
		}
	}
	return unic_section;
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
void print_choose_book(TBook* lib, int count,int unic,char** unic_section)
{
	int a,i;
	char word[20];
	do 
	{
		printf("\nКакой жанр вы хотите увидеть?\n");
		for (i = 0; i < unic; i++)
		{
			printf("%d - %s\n",i+1, unic_section[i]);
		}
		printf("Если хотите выйти, введите 0\n");
		scanf("%d", &a);

		
		
		if ((a > 0) && (a <= unic))
		{
			print_section(lib, count, unic_section[a-1]);
		}
	} while (a != 0);
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
	free(book);
}
void free_unic(char** unic_section, int unic)
{
	int i;

	for (i = 0; i < unic; i++)
	{
		free(unic_section[i]);
	}
	free(unic_section);
}


