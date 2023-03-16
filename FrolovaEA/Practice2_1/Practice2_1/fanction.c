#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "header.h"

int cntLines(const char* filename)
{
    int lines = 0;
    int any;    //any типа int, потому что EOF имеет тип int!
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }
    do {
        any = fgetc(f);
        //printf("%c", any);//debug
        if (any == '\n') {
            lines++;
        }
    } while (any != EOF);
    fclose(f);
    return lines;
}

void allocate_stock(product** shipment, int number)
{
    (*shipment) = (product*)malloc(sizeof(product) * number);
    //  for(int i = 0; i < number; i++)
    //  shipment->name = (char*)malloc(sizeof(char) * 200);
    for (int i = 0; i < number; i++) {
        (*shipment + i)->name = (char*)malloc(sizeof(char) * 200);
//        printf("addr: %x\n", (*shipment + i));
    }
}

void fill_shipment(product* shipment, int number)
{
    int flag = 0, j = 0;
    char str[200], sep[10] = ";";
    char* istr;
    int r;
    FILE* file;
    file = fopen("sklad.txt", "r");
    while (j != number) {
        fgets(str, 200, file);

        istr = strtok(str, sep);
        flag++;
        if (flag == 1) {
            strcpy(shipment[j].name, istr);
            //            printf("%s\n", shipment[j].name);
        }
        while (istr != NULL)
        {
            istr = strtok(NULL, sep);
            flag++;

            if (flag == 4) {
                //                printf("%s, %d\n", istr, flag);

                shipment[j].number = atoi(istr);
                //                printf("%d\n", shipment[j].number);
            }
        }
        flag = 0;
        j++;
    }

}

void find_null(product* shipment, int number)
{
    for (int i = 0; i < number; i++)
    {
        if (shipment[i].number == 0) { printf("%s\n", shipment[i].name); }
    }
}

void free_stock(product** shipment, int number)
{
    for (int i = 0; i < number; i++) {
        free((*shipment + i)->name);
    }
    free(*shipment);
}