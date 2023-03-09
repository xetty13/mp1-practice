#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#define const_c 30



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

void fill_data(Person* p,FILE* file)
{
	fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
		(p->surname),
		(p->name),
		(p->patronymic),
		(p->gender),
		(p->nation),
		(p->date),
		(p->height),
		(p->weight),
		(p->num_phone),
		(p->postal_code),
		(p->ad.country),
		(p->ad.region),
		(p->ad.city),
		(p->ad.district),
		(p->ad.street),
		(p->ad.house),
		(p->ad.apartament));

}

void read(Person*** p, int* n)
{ // передается адресс массива объектов "p"
	int i,j;
	FILE* file = fopen("people.txt", "r");
	if (file == NULL)
	{
		printf("Fike error");
		return;
	}
	fscanf(file, "%d", n); // здесь n уже адресс

	*p = (Person**)malloc(sizeof(Person*) * (*n));// выделение памяти под массив указателей на объекты
	for (i = 0; i < (*n); i++)
	{
		allocate_person(&((*p)[i])); // выделение памятти под каждый объект
		fill_data((*p)[i], file);// чтениее строки из файла и запись в объект
		
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