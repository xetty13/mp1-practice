#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Header.h"
void Allocate_memory_for_one_person(One_Person** person)
{
	(*person) = (One_Person*)malloc(sizeof(One_Person) * 1);
	(*person)->Surname = (char*)malloc(sizeof(char) * 50);
	(*person)->Name = (char*)malloc(sizeof(char) * 50);
	(*person)->Middle_name = (char*)malloc(sizeof(char) * 50);
	(*person)->Gender = (char*)malloc(sizeof(char) * 50);
	(*person)->Nation = (char*)malloc(sizeof(char) * 50);
	(*person)->height = (char*)malloc(sizeof(char) * 50);
	(*person)->weight = (char*)malloc(sizeof(char) * 50);
	(*person)->phone_number = (char*)malloc(sizeof(char) * 50);
	(*person)->address.postal_code = (char*)malloc(sizeof(char) * 50);
	(*person)->address.Country = (char*)malloc(sizeof(char) * 50);
	(*person)->address.Region= (char*)malloc(sizeof(char) * 50);
	(*person)->address.Area = (char*)malloc(sizeof(char) * 50);
	(*person)->address.City = (char*)malloc(sizeof(char) * 50);
	(*person)->address.Street = (char*)malloc(sizeof(char) * 50);
	(*person)->address.House = (char*)malloc(sizeof(char) * 50);
	(*person)->address.Apart = (char*)malloc(sizeof(char) * 50);
}
int Count_struct_in_file(FILE* file)
{
	int count = 0;
	int symbol;
	FILE* source_file = fopen(file, "r");
	if (source_file == NULL)
	{
		printf("Error opening the file");
		return -1;
	}
	do
	{
		symbol = fgetc(source_file);
		if (symbol == '\n')
			count ++;
		
	} while (symbol != EOF); //EOF - end file
	fclose(source_file); //Clouse file
	return count;
}
void Reading_a_file_line(One_Person* person,FILE* file)
{
	char Current_line[300];
	char Sepapration_Element[10] = ";";
	int number = 0;
	char* ishod_str;
		
	fgets(Current_line, 300, file);
	ishod_str = strtok(Current_line, Sepapration_Element);
	while (Current_line != NULL)
	{
		if (number == 0) {
			strcpy(person->Surname,ishod_str);
		}
		if (number == 1) {
			strcpy(person->Name, ishod_str);
		}
		if (number == 2) {
			strcpy(person->Middle_name, ishod_str);
		}
		if (number == 3) {
			strcpy(person->Gender, ishod_str);
		}
		if (number == 4) {
			strcpy(person->Nation, ishod_str);
		}
		if (number == 5) {
			person->date.year= atoi(ishod_str);
		}
		if (number == 6) {
			person->date.month=atoi(ishod_str);
		}
		if (number == 7) {
			person->date.day=atoi(ishod_str);
		}
		if (number == 8) {
			strcpy(person->height, ishod_str);
		}
		if (number == 9) {
			strcpy(person->weight, ishod_str);
		}
		if (number == 10) {
			strcpy(person->phone_number, ishod_str);
		}
		if (number == 11) {
			strcpy(person->address.postal_code, ishod_str);
		}
		if (number == 12) {
			strcpy(person->address.Country, ishod_str);
		}
		if (number == 13) {
			strcpy(person->address.Region, ishod_str);
		}
		if (number == 14) {
			strcpy(person->address.Area, ishod_str);
		}
		if (number == 15) {
			strcpy(person->address.City, ishod_str);
		}
		if (number == 16) {
			strcpy(person->address.Street, ishod_str);
		}
		if (number == 17) {
			strcpy(person->address.House, ishod_str);
		}
		if (number == 18) {
			strcpy(person->address.Apart, ishod_str);
		}
		if ((number == 19)||(number>19)) {
			break;
		}
		ishod_str = strtok(NULL, Sepapration_Element);
		number++;
	}
}
void Print_Inforamation(One_Person* person)	
{
	printf("=================================================================\n");
	printf("\nSurname: %s", person->Surname); 
	printf("\n Name %s", person->Name); 
	printf("\n Middle_name %s", person->Middle_name);
	printf("\nGender: %s", person->Gender);
	printf("\n Nationality: %s", person->Nation);
	printf("\n Height: %s", person->height);
	printf("\n Weight: %s", person->weight);
	printf("\nBirthday: %d %d %d", person->date.day, person->date.month, person->date.year);
	printf("\nTelephone Number: %s", person->phone_number);
	printf("\nHome address: ");
	printf("\nPostal Code: %s", person->address.postal_code);
	printf("\nCountry: %s", person->address.Country);
	printf("\nDistrict: %s", person->address.Region);
	printf("\nAreal: %s", person->address.Area);
	printf("\nTown: %s", person->address.City);
	printf("\nStreet: %s", person->address.Street);
	printf("\nHouse: %s", person->address.House);
	printf("\nApartament: %s", person->address.Apart);
	printf("\n=================================================================\n");
}
void sorting_for_surname(One_Person** person, int n)
{
	One_Person* temp;
	Allocate_memory_for_one_person(&temp);
	int i;
	int j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(person[j]->Surname, person[i]->Surname) != 0)
			{
				if (strcmp(person[j]->Surname, person[i]->Surname) < 0)
				{
					temp = person[i];
					person[i] = person[j];
					person[j] = temp;
				}
			}
			else if (strcmp(person[j]->Surname, person[i]->Surname) == 0)
			{
				if (strcmp(person[j]->Name, person[i]->Name) < 0)
				{
					temp = person[i];
					person[i] = person[j];
					person[j] = temp;
				}
			}
			else if ((strcmp(person[j]->Surname, person[i]->Surname) == 0)&&(strcmp(person[j]->Name, person[i]->Name)))
			{
				if (strcmp(person[j]->Middle_name, person[i]->Middle_name) < 0)
				{
					temp = person[i];
					person[i] = person[j];
					person[j] = temp;
				}
			}
		}
}//linear sorting by surname
void Free_memory(One_Person** person)
{
	free((*person)->address.Apart);
	free((*person)->address.House);
	free((*person)->address.Street);
	free((*person)->address.City);
	free((*person)->address.Area);
	free((*person)->address.Region);
	free((*person)->address.Country);
	free((*person)->address.postal_code);
	free((*person)->phone_number);
	free((*person)->weight);
	free((*person)->height);
	
	free((*person)->Nation);
	free((*person)->Gender);
	free((*person)->Middle_name);
	free((*person)->Name);
	free((*person)->Surname);
	free(*person);
}
void Reading_File(One_Person*** person, int* n, const FILE* file) {
	int i;
	int j;
	file = fopen(file, "r");
	if (file == NULL)
	{
		printf("Error with open file");
		return -1;
 	}
	(*n)  = Count_struct_in_file("Many_Persons.txt");
	*person = (One_Person**)malloc(sizeof(One_Person*) * (*n));
	for (i = 0; i < (*n); i++)
	{
		Allocate_memory_for_one_person(&((*person)[i]));
		Reading_a_file_line((*person)[i], file);
	}
	fclose(file);
}