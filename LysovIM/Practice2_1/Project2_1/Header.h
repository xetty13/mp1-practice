#ifndef _STRUCT_H
#define _STRUCT_H
typedef struct
{
    char* postal_code;
	char* Country;
	char* Region;
	char* Area;
	char* City;
	char* Street;
	char* House;
	char* Apart;
}Address;
typedef struct
{
	int year;
    int month;
	int day;
}Date;	
typedef struct
{
    char* Surname;
    char* Name;
    char* Middle_name;
    char* Gender;
    char* Nation;
    Date date;
    char* height;
    char* weight;
    char* phone_number;
    Address address;
}One_Person;
void Allocate_memory_for_one_person(One_Person** person);
int Count_struct_in_file(FILE* file);
void Reading_a_file_line(One_Person* person,FILE* file);
void Print_Inforamation(One_Person* person);
void sorting_for_surname(One_Person** person, int n);
void Reading_File(One_Person*** person, int* n);
void Free_memory(One_Person** person);
 #endif;