#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "banki.h"
#define LENGTH 512
#define LEN 100

int strcount(char* path) {
    int count = 0;
    char* s = (char*)malloc(1000 * sizeof(char));
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("ERROR: Could not open file!\n");
        return 1;
    }
    while (1) {
        if (fgets(s, 1000, file) != NULL) {
            if (strcmp(s, "\n") != 0) {
                count++;
            }
        }
        else {
            break;
        }
    }
    fclose(file);
    free(s);
    return count;
}

bankstruct* allocbanki(int stringcount) {
    bankstruct* banki = (bankstruct*)malloc(sizeof(bankstruct) * stringcount);
    return banki;
}

vkladstruct* allocvklads(int stringcount) {
    vkladstruct* banki = (vkladstruct*)malloc(sizeof(vkladstruct) * stringcount);
    return banki;
}
void workfile(bankstruct* banki,vkladstruct* vklads, char* path, int stringcount) {
    char* token;
    char delim[] = ",\n";
    int i = 0;
    int j = 0;
    FILE* file = fopen(path, "r");
    char str[LENGTH];
    if (file == NULL) {//проверка
        printf("ERROR: Could not open file!\n");
        return 1;
    }
    while (1) {
        if (fgets(str, 512, file) != NULL) {
            for (token = strtok(str, delim); token; token = strtok(NULL, delim)) {
                switch (i) {
                case 0:
                    strcpy(banki[j].bankname, token);
                    break;
                case 1:
                    strcpy(banki[j].banktype, token);
                    break;
                case 2:
                    vklads[j].saving = strtof(token, NULL);
                    break;
                case 3:
                    vklads[j].debit = strtof(token, NULL);
                    break;
                case 4:
                    vklads[j].cumulative = strtof(token, NULL);
                    break;
                case 5:
                    vklads[j].saving_month = strtof(token, NULL);
                    break;
                case 6:
                    vklads[j].debit_month = strtof(token, NULL);
                    break;
                case 7:
                    vklads[j].cumulative_month = strtof(token, NULL);
                    i = -1;
                    j++;
                    break;
                }
                i++;
            }
        }
        else {
            break;
        }
    }
    fclose(file);

}
void choosesaving(int sumvkl, int your_month, bankstruct* banki,vkladstruct* vklads, int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].saving;

    int koef=0;
    for (i = 1; i < stringcount; i++) {
        if (vklads[i].saving > maxproc && your_month >= vklads[i].saving_month) {
            koef =(int) your_month / vklads[i].saving_month;
            maxproc = vklads[i].saving;
            maxI = i;
        }
        else if (your_month < vklads[i].saving_month) {
            continue;
        }

    }

    int j;
    double summa = sumvkl;
    for (j = 0; j < koef; j++) {
        summa *= (1 + maxproc / 100);
    }
    printf("Best saving invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI].bankname, summa);
}

void choosedebit(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].debit;
    int koef=0;

    for (i = 1; i < stringcount; i++) {
        if (vklads[i].debit > maxproc && your_month >= vklads[i].debit_month) {
            koef = (int) your_month / vklads[i].debit_month;
            maxproc = vklads[i].debit;
            maxI = i;
        }
        else if (your_month < vklads[i].debit_month) {
            continue;
        }

    }

    int j;
    double summa = sumvkl;
    for (j = 0; j < koef; j++) {
        summa *= (1 + maxproc / 100);
    }
    printf("Best debit invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI].bankname, summa);
}

void choosecumulative(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].cumulative;
    int koef=0;

    for (i = 1; i < stringcount; i++) {
        if (vklads[i].cumulative > maxproc && your_month>= vklads[i].cumulative_month) {
            koef = (int) your_month / vklads[i].cumulative_month;
            maxproc = vklads[i].cumulative;
            maxI = i;
        }
        else if (your_month < vklads[i].cumulative_month) {
            continue;
        }
        
    }

    int j;
    double summa = sumvkl;
    for (j = 0; j < koef; j++) {
        summa *= (1 + maxproc / 100);
    }
    
    printf("Best cumulative invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI].bankname, summa);
}

/*
void choose(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, int stringcount) {
    int i;
    int j;
    for (i = 0; i < 3; i++) {

        for (j = 0; j < stringcount; j++) {

        }
    }
}*/

void freebanki(bankstruct* banki) {
    free(banki);
}
void freevklads(vkladstruct* vklad) {
    free(vklad);
}