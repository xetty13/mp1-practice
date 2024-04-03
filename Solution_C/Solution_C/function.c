#include "func.h"
#include "date.h"
#include <string.h>

void menu() {
    printf("=================\n");
    printf("Выберите подходящий режим: \n");
    printf("1.Вывести весь список спортсменов(вся информация)\n");
    printf("2.Вывести атлетов по определенному виду спорта\n");
    printf("3.Вывести рекордсмена, отдельного вида спорта\n");
    printf("4.Выход из программы\n");
    printf("=================\n");
    printf("Ваш выбор: ");
}

void read(const char* filename, SportsmenLib* slib)
{
    n->Name = (char*)malloc(sizeof(char) * Buffer);
    n->Surname = (char*)malloc(sizeof(char) * Buffer);
    n->Gender = ((char*)malloc(sizeof(char) * Buffer));
    n->DateOfBirth = ((char*)malloc(sizeof(char) * Buffer));
    n->Nation = ((char*)malloc(sizeof(char) * Buffer));
    n->Sport = ((char*)malloc(sizeof(char) * Buffer));
    n->Club = ((char*)malloc(sizeof(char) * Buffer));
    char* str[Buffer];
    if (fgets(str, Buffer, f) != NULL)
    {
        fscanf(f,"%s", n->Name);
        fscanf(f,"%s", n->Surname);
        fscanf(f,"%s", n->Gender);
        fscanf(f,"%s", n->DateOfBirth);
        fscanf(f,"%s", n->Nation);
        fscanf(f,"%s", n->Sport);
        fscanf(f,"%s", n->Club);
        fscanf(f,"%d", &n->Record);
    }
    return 0;
}

void write(info* n) 
{
    printf("%s ", n->Name);
    printf("%s ", n->Surname);
    printf("%s ", n->Gender);
    printf("%s ", n->DateOfBirth);
    printf("%s ", n->Nation);
    printf("%s ", n->Sport);
    printf("%s ", n->Club);
    printf("%d score", n->Record);
}

