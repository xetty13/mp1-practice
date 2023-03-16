#ifndef _PERSON_H
#define _PERSON_H

typedef struct
{
    char* country;
    char* region;
    char* city;
    char* district;
    char* street;
    char* house;
    char* apartament;
}Address;

typedef struct
{
    char* surname;
    char* name;
    char* patronymic;
    char* gender;
    char* nation;
    char* date;
    char* height;
    char* weight;
    char* num_phone;
    char* postal_code;
    Address ad;

}Person;

int cntStruct(FILE* file);
void allocate_person(Person** p);
void fill_data(Person* p, FILE* file);
void read(Person*** p, int* n);
void print_persons(Person* p);
void Sort(Person** p, int n);
void free_person(Person** p);

#endif // !_PERSON_H

