#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#define const_c 30



int cntStruct(FILE* file)
{
	int cnt = 0;
	int any;
	FILE* f = fopen(file, "r");
	if (f == NULL) {
		return -1;
	}
	do {
		any = fgetc(f);
		if (any == '\n') {
			cnt++;
		}
	} while (any != EOF);
	fclose(f);
	return cnt;
}

void allocate_person(Person** p)
{
	(*p) = (Person*)malloc(sizeof(Person) * 1);
	(*p)->surname = (char*)malloc(sizeof(char) * const_c);
	(*p)->name = (char*)malloc(sizeof(char) * const_c);
	(*p)->patronymic = (char*)malloc(sizeof(char) * const_c);
	(*p)->gender = (char*)malloc(sizeof(char) * const_c);
	(*p)->nation = (char*)malloc(sizeof(char) * const_c);
	(*p)->date = (char*)malloc(sizeof(char) * const_c);
	(*p)->height = (char*)malloc(sizeof(char) * const_c);
	(*p)->weight = (char*)malloc(sizeof(char) * const_c);
	(*p)->num_phone = (char*)malloc(sizeof(char) * const_c);
	(*p)->postal_code = (char*)malloc(sizeof(char) * const_c);
	(*p)->ad.country = (char*)malloc(sizeof(char) * const_c);
	(*p)->ad.region = (char*)malloc(sizeof(char) * const_c);
	(*p)->ad.city = (char*)malloc(sizeof(char) * const_c);
	(*p)->ad.district = (char*)malloc(sizeof(char) * const_c);
	(*p)->ad.street = (char*)malloc(sizeof(char) * const_c);
	(*p)->ad.house = (char*)malloc(sizeof(char) * const_c);
	(*p)->ad.apartament = (char*)malloc(sizeof(char) * const_c);
}

void fill_data(Person* p, FILE* file)
{
	char str[200], sep[10] = ";";
	char* istr;
	int flag = 0;
	fgets(str, 200, file);
	istr = strtok(str, sep);
	while (str != NULL)
	{
		if (flag == 0)
			strcpy(p->surname, istr);
		if (flag == 1)
			strcpy(p->name, istr);
		if (flag == 2)
			strcpy(p->patronymic, istr);
		if (flag == 3)
			strcpy(p->gender, istr);
		if (flag == 4)
			strcpy(p->nation, istr);
		if (flag == 5)
			strcpy(p->date, istr);
		if (flag == 6)
			strcpy(p->height, istr);
		if (flag == 7)
			strcpy(p->weight, istr);
		if (flag == 8)
			strcpy(p->num_phone, istr);
		if (flag == 9)
			strcpy(p->postal_code, istr);
		if (flag == 10)
			strcpy(p->ad.country, istr);
		if (flag == 11)
			strcpy(p->ad.region, istr);
		if (flag == 12)
			strcpy(p->ad.city, istr);
		if (flag == 13)
			strcpy(p->ad.district, istr);
		if (flag == 14)
			strcpy(p->ad.street, istr);
		if (flag == 15)
			strcpy(p->ad.house, istr);
		if (flag == 16)
			strcpy(p->ad.apartament, istr);
		if (flag == 17)
			break;
		istr = strtok(NULL, sep);
		flag++;
	}
}


void read(Person*** p, int* n, const FILE* file)
{
	int i, j;
	file = fopen(file, "r");
	if (file == NULL)
	{
		printf("FiLe error");
		return 1;
	}
	(*n) = cntStruct("people.txt"); // считаем количество структур

	*p = (Person**)malloc(sizeof(Person*) * (*n));// выделяем под структуры
	for (i = 0; i < (*n); i++)
	{
		allocate_person(&((*p)[i])); // выделяем память для каждой структуры
		fill_data((*p)[i], file);// заполняем структуру

	}
	fclose(file);
}
void print_persons(Person* p)
{
	printf("\nFIO: %s ", p->surname);
	printf("%s ", p->name);
	printf("%s \n", p->patronymic);
	printf("Gender: %s \n", p->gender);
	printf("Nation: %s \n", p->nation);
	printf("Date: %s \n", p->date);
	printf("Height: %s \n", p->height);
	printf("Weight: %s \n", p->weight);
	printf("Phone number: %s \n", p->num_phone);
	printf("Postal code: %s \n", p->postal_code);
	printf("Country: %s \n", p->ad.country);
	printf("Region: %s region \n", p->ad.region);
	printf("Address: city: %s, ", p->ad.city);
	printf("%s district, ", p->ad.district);
	printf("%s street, ", p->ad.street);
	printf("house number: %s, ", p->ad.house);
	printf("apartament: %s \n", p->ad.apartament);
	printf("====================================================================================");

}
void Sort(Person** p, int n)
{
	Person* tmp;
	allocate_person(&tmp);
	int i, j;

	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[j]->surname, p[i]->surname) != 0)
			{
				if (strcmp(p[j]->surname, p[i]->surname) < 0)
				{
					tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
			else
			{
				if (strcmp(p[j]->name, p[i]->name) < 0)
				{
					tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
		}

}

void free_person(Person** p) {
	free((*p)->ad.apartament);
	free((*p)->ad.house);
	free((*p)->ad.street);
	free((*p)->ad.district);
	free((*p)->ad.city);
	free((*p)->ad.region);
	free((*p)->ad.country);
	free((*p)->postal_code);
	free((*p)->num_phone);
	free((*p)->weight);
	free((*p)->height);
	free((*p)->date);
	free((*p)->nation);
	free((*p)->gender);
	free((*p)->patronymic);
	free((*p)->name);
	free((*p)->surname);
	free(*p);
}