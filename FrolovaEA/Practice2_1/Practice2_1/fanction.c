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

void allocate_stock(product** shipment, date** data, int number)
{
    (*shipment) = (product*)malloc(sizeof(product) * number);
    (*data) = (product*)malloc(sizeof(product) * number);
    //  for(int i = 0; i < number; i++)
    //  shipment->name = (char*)malloc(sizeof(char) * 200);
    for (int i = 0; i < number; i++) {
        (*shipment + i)->name = (char*)malloc(sizeof(char) * 200);
        //        printf("addr: %x\n", (*shipment + i));
    }

    for (int i = 0; i < number; i++) {
        (*shipment + i)->unit = (char*)malloc(sizeof(char) * 200);
        //        printf("addr: %x\n", (*shipment + i));
    }
}

void fill_shipment(product* shipment, date* data, int number)
{
    int flag = 0, j = 0;
    char str[200], sep[10] = ";";
    char* istr;
    int r;
    FILE* file;
    file = fopen("sklad.txt", "r");
    while (j != number) {
        fgets(str, 200, file);

        istr = strtok(str, ";/");
        flag++;
        if (flag == 1) {
            strcpy(shipment[j].name, istr);
            //                        printf("%s\n", shipment[j].name);
        }
        while (istr != NULL)
        {
            istr = strtok(NULL, ";/");
            flag++;

            if (flag == 2) {
                //                                printf("%s, %d\n", istr, flag);

                strcpy(shipment[j].unit, istr);
                //                                printf("%s\n", shipment[j].unit);
            }

            if (flag == 3) {
                //                                printf("%s, %d\n", istr, flag);

                shipment[j].price = atoi(istr);
                //                                printf("%.2f\n", shipment[j].price);
            }

            if (flag == 4) {
                //                printf("%s, %d\n", istr, flag);

                shipment[j].number = atoi(istr);
                //                printf("%d\n", shipment[j].number);
            }

            if (flag == 5) {
                //                                                printf("%s, %d\n", istr, flag);

                data[j].day = atoi(istr);
                //                printf("%d\n", data[j].day);
            }

            if (flag == 6) {
                //                                                printf("%s, %d\n", istr, flag);

                data[j].month = atoi(istr);
                //                printf("%d\n", data[j].month);
            }

            if (flag == 7) {
                //                                                printf("%s, %d\n", istr, flag);

                data[j].year = atoi(istr);
                //                printf("%d\n", data[j].year);
            }


        }
        flag = 0;
        j++;
    }

}

void find_null(product* shipment, date* data, int number)
{
    for (int i = 0; i < number; i++)
    {
        if (shipment[i].number == 0) {
            printf("%s\t", shipment[i].name);
            printf("%s\t", shipment[i].unit);
            printf("%.2f\t", shipment[i].price);
            printf("%d\t", shipment[i].number);
            printf("%d.%d.%d\n", data[i].day, data[i].month, data[i].year);

        }
    }
}

void free_stock(product** shipment, date** data, int number)
{
    for (int i = 0; i < number; i++) {
        free((*shipment + i)->name);
        free((*shipment + i)->unit);
    }
    free(*shipment);


    free(*data);
}