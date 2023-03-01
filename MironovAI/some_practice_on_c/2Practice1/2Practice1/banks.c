#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Header_banks.h"
#define MAX_PATH 100 // Max path length 
#define MAX_NAME 30  // Max name of banks length



void input_path(char* path) {
    printf("Input a path with file type: \n");
    scanf("%s", path);
    printf("\n \nYour path:  \n%s \n\n", path);
}
void read(FILE* file, BanksData* data, int n) {

    for (int i = 0; i < n; i++) {
        data[i].name = (char*)malloc(sizeof(char) * MAX_NAME);
        data[i].ownership = (char*)malloc(sizeof(char) * MAX_NAME);

        fscanf(file, "%s %s %d", data[i].name, data[i].ownership, &data[i].count);

        data[i].conditions = (int*)malloc(sizeof(int) * data[i].count);
        data[i].periods = (int*)malloc(sizeof(int) * data[i].count);

        for (int j = 0; j < data[i].count; j++) {
            fscanf(file, "%d %f", &data[i].periods[j], &data[i].conditions[j]);

        }

    }
    fclose(file);
}
void print_data(BanksData* data, int n) {
    printf("Yours data: \n\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %d \n", data[i].name, data[i].ownership, data[i].count);
        for (int j = 0; j < data[i].count; j++) {
            printf("%d  %f\n", data[i].periods[j], data[i].conditions[j]);
        }
        printf("\n");
    }
}
void freedata(BanksData** data, int n) {
    for (int i = 0; i < n; i++) {
        free((*data)[i].name);
        free((*data)[i].ownership);
        free((*data)[i].conditions);
        free((*data)[i].periods);
    }
}
void input_user_data(int* user_year, float* user_money) {
    do {
        printf("For how long would you like to open a deposit? \n");
        scanf("%d", &(*user_year));

        if ((*user_year) <= 0 || (*user_year) >= 100) {
            printf("Wrong period, try again\n");
        }
    } while ((*user_year) <= 0 || (*user_year) >= 100);
    do {
        printf("How much would you like to open a deposit for (rubles)? \n");
        scanf("%f", &(*user_money));

        if ((*user_money) <= 0) {
            printf("Wrong period, try again\n");
        }
    } while ((*user_money) <= 0);
}

pair comparing(BanksData* data, int n, int user_year, int user_money) {
    float profit=0;
    int  id1 = -1;
    int id2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < data[i].count; j++)
            if (user_year % data[i].periods[j] == 0) {
                float tmp_profit = user_money * (pow(1 + (data[i].conditions[j] * 0.01), user_year));// formule
                if (profit < tmp_profit) {
                    profit = tmp_profit;
                    id1 = i;
                    id2 = j;
                }
            }
    }
    pair q;
    q.id1 = id1;
    q.id2 = id2;
    q.profit = profit;
    return q;
}
