#ifndef _PERSON_H
#define _PERSON_H

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
    char* country;
    char* region;
    char* city;
    char* district;
    char* street;
    char* house;
    char* apartament;

}Person;

void allocate_person(Person** p);
void fill_data(Person* p, FILE* file);
void read(Person*** p, FILE** file, int* n);
void print_persons(Person* p);
void Sort(Person** p, int* n);
void free_person(Person** p);

#endif // !_PERSON_H

