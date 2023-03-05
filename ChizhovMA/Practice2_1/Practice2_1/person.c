#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"


void allocate_person(Person** p)
{
	(*p) = (Person*)malloc(sizeof(Person) * 1);
	(*p)->surname = (char*)malloc(sizeof(char) * 30);
	(*p)->name = (char*)malloc(sizeof(char) * 30);
	(*p)->patronymic = (char*)malloc(sizeof(char) * 30);
	(*p)->gender = (char*)malloc(sizeof(char) * 10);
	(*p)->nation = (char*)malloc(sizeof(char) * 30);
	(*p)->date = (char*)malloc(sizeof(char) * 12);
	(*p)->height = (char*)malloc(sizeof(char) * 8);
	(*p)->weight = (char*)malloc(sizeof(char) * 8);
	(*p)->num_phone = (char*)malloc(sizeof(char) * 12);
	(*p)->postal_code = (char*)malloc(sizeof(char) * 10);
	(*p)->country = (char*)malloc(sizeof(char) * 30);
	(*p)->region = (char*)malloc(sizeof(char) * 30);
	(*p)->city = (char*)malloc(sizeof(char) * 30);
	(*p)->district = (char*)malloc(sizeof(char) * 30);
	(*p)->street = (char*)malloc(sizeof(char) * 30);
	(*p)->house = (char*)malloc(sizeof(char) * 8);
	(*p)->apartament = (char*)malloc(sizeof(char) * 5);
}

void fill_data(Person* p, FILE* file)
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
		(p->country),
		(p->region),
		(p->city),
		(p->district),
		(p->street),
		(p->house),
		(p->apartament));

}

void read(Person*** p, FILE** file, int* n)
{ // передается адресс массива объектов "p"
	int i;
	*(file) = fopen("people.txt", "r");
	fscanf(*(file), "%d", n); // здесь n уже адресс

	*(p) = (Person**)malloc(sizeof(Person*) * *(n)); // выделение памяти под массив указателей на объекты
	for (i = 0; i < *(n); i++)
	{
		allocate_person(&((*(p))[i])); // выделение памятти под каждый объект
		fill_data((*(p))[i], *(file)); // чтениее строки из файла и запись в объект
	}
	fclose(*(file));
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
	printf("Country: %s \n", p->country);
	printf("Region: %s region \n", p->region);
	printf("Address: city: %s, ", p->city);
	printf("%s district, ", p->district);
	printf("%s street, ", p->street);
	printf("house number: %s, ", p->house);
	printf("apartament: %s \n", p->apartament);
	printf("====================================================================================");

}
void Sort(Person** p, int* n)
{
	Person** tmp;
	tmp = (Person**)malloc(sizeof(Person*) * 1);
	allocate_person(tmp);
	int i, j;

	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[j]->surname, p[i]->surname) != 0)
			{
				if (strcmp(p[j]->surname, p[i]->surname) < 0)
				{
					*tmp = p[i];
					p[i] = p[j];
					p[j] = *tmp;
				}
			}
			else
			{
				if (strcmp(p[j]->name, p[i]->name) < 0)
				{
					*tmp = p[i];
					p[i] = p[j];
					p[j] = *tmp;
				}
			}
		}

}

void free_person(Person** p) {
	free((*p)->apartament);
	free((*p)->house);
	free((*p)->street);
	free((*p)->district);
	free((*p)->city);
	free((*p)->region);
	free((*p)->country);
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