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

bankstruct* alloc(int stringcount) {
    bankstruct* banki = (bankstruct*)malloc(sizeof(bankstruct) * stringcount);
    return banki;
}

void workfile(bankstruct* banki, char* path, int stringcount) {
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
                    banki[j].saving = strtof(token, NULL);
                    break;
                case 3:
                    banki[j].debit = strtof(token, NULL);
                    break;
                case 4:
                    banki[j].cumulative = strtof(token, NULL);
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
void choosesaving(int sumvkl, bankstruct* banki, int stringcount) {
    int maxI = 0;
    int i = 0;
    float maxproc = banki[0].saving;
        
    for (i = 1; i < stringcount; i++) {
        if (banki[i].saving > maxproc) {
            maxproc = banki[i].saving;
            maxI = i;
        }
    }
    double summa = sumvkl * (1 + maxproc / 100);
    printf("Best saving invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI].bankname, summa);
}

void choosedebit(int sumvkl, bankstruct* banki, int stringcount) {
    int maxI = 0;
    int i = 0;
    float maxproc = banki[0].debit;

    for (i = 1; i < stringcount; i++) {
        if (banki[i].debit > maxproc) {
            maxproc = banki[i].debit;
            maxI = i;
        }
    }
    double summa = sumvkl * (1 + maxproc / 100);
    printf("Best debit invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI].bankname, summa);
}

void choosecumulative(int sumvkl, bankstruct* banki, int stringcount) {
    int maxI = 0;
    int i = 0;
    float maxproc = banki[0].cumulative;

    for (i = 1; i < stringcount; i++) {
        if (banki[i].cumulative > maxproc) {
            maxproc = banki[i].cumulative;
            maxI = i;
        }
    }
    double summa = sumvkl * (1 + maxproc / 100);
    printf("Best cumulative invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI].bankname, summa);
}

void freebanki(bankstruct* banki) {
    free(banki);

}
