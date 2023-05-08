#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "banki.h"
#define LENGTH 512
#define LEN 30
#define _CRT_SECURE_NO_WARNINGS

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

char* getfile() {
    char* path = (char*)malloc(_MAX_PATH * sizeof(char)); 
    do {
        printf("Enter the full location of the file\n");
        scanf("%s", path);
        FILE* file = fopen(path, "r");
        if (file == NULL) {
            printf("ERROR: Could not open file!\n");
        }
        else {
            fclose(file);
            return path;
        }
    } while (1);
}


bankstruct** allocbanki(int stringcount) {
    int i = 0;
    int j = 0;
    bankstruct** banki = (bankstruct**)malloc(sizeof(bankstruct*) * stringcount);
    for (i = 0; i < stringcount; i++) {
        banki[i] = (bankstruct*)malloc(sizeof(bankstruct));
        banki[i]->bankname = (char*)malloc(sizeof(char) * LEN);
        banki[i]->banktype = (char*)malloc(sizeof(char) * LEN);
        banki[i]->our_vklad = (vkladstruct**)malloc(sizeof(bankstruct*)*stringcount);
    }
      return banki;
}

void workfile(bankstruct** banki, char* path, int stringcount) {
    char* token;
    char delim[] = " ,\n";
    int i = 0;
    int j = 0;
    int l = 0;
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
                    strcpy(banki[j]->bankname, token);
                    
                    break;
                case 1:
                    strcpy(banki[j]->banktype, token);
                    break;
                case 2:
                    banki[j]->count = strtof(token, NULL);

                    for (l = 0; l < banki[j]->count; l++) {
                        banki[j]->our_vklad[l] = (vkladstruct*)malloc(sizeof(vkladstruct) * banki[j]->count);
                        banki[j]->our_vklad[l]->vkladname = (char*)malloc(sizeof(char) * LEN);
                    }
                    break;
                case 3:
                    strcpy(banki[j]->our_vklad[0]->vkladname, token);
                    break;
                case 4:
                    banki[j]->our_vklad[0]->rate = strtof(token, NULL);
                    break;
                case 5:
                    banki[j]->our_vklad[0]->times = strtof(token, NULL);
                    if (banki[j]->count == 1) {
                        i = -1;
                        j++;
                    }
                    break;
                case 6:
                    strcpy(banki[j]->our_vklad[1]->vkladname, token);
                    break;
                case 7:
                    banki[j]->our_vklad[1]->rate = strtof(token, NULL);
                    break;
                case 8:
                    banki[j]->our_vklad[1]->times = strtof(token, NULL);
                    if (banki[j]->count == 2) {
                        i = -1;
                        j++;
                    }
                    break;
                case 9:
                    strcpy(banki[j]->our_vklad[2]->vkladname, token);
                    break;
                case 10:
                    banki[j]->our_vklad[2]->rate = strtof(token, NULL);
                    break;
                case 11:
                    banki[j]->our_vklad[2]->times = strtof(token, NULL);
                    if (banki[j]->count == 3) {
                        i = -1;
                        j++;
                    }
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

void data_input(int* sumvkl, int* your_month, char* your_type) {
    printf("Enter count of money\n");
    scanf("%d", sumvkl);
    printf("For how long is the contribution made\n");
    scanf("%d", your_month);
    printf("Enter type of vklad(saving, debit or cumulative).\n");
    scanf("%s", your_type);
    if ((strcmp(your_type,"saving") != 0) && (strcmp(your_type, "debit") != 0) && (strcmp(your_type, "cumulative") != 0)){
        printf("ERROR!This type of vklad does not exist\n");
    }
}


void chooseall(int sumvkl, int your_month, bankstruct** banki,int stringcount, char* your_type) {

    if (strcmp(your_type, "saving") == 0) {
        choosesaving(sumvkl, your_month, banki, stringcount);
    }
    else if((strcmp(your_type, "debit") == 0)){
        choosedebit(sumvkl, your_month, banki, stringcount);
    }
    else if ((strcmp(your_type, "cumulative") == 0)) {
        choosecumulative(sumvkl, your_month, banki, stringcount);
    }
}

void choosesaving(int sumvkl, int your_month, bankstruct** banki,int stringcount) {
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < (banki[j]->our_vklad[0]->times)) {
            k += 1;
        }
    }
    if (k != stringcount) {
        int maxI = 0;
        int i;
        float maxproc = banki[0]->our_vklad[0]->rate;
        int koef = 0;
        for (i = 1; i < stringcount; i++) {
            if (banki[i]->our_vklad[0]->rate > maxproc && your_month >= banki[i]->our_vklad[0]->times) {
                koef = (int)your_month / banki[i]->our_vklad[0]->times;
                maxproc = banki[i]->our_vklad[0]->rate;
                maxI = i;
            }
        }
        double summa = sumvkl;
        for (j = 0; j < koef; j++) {
            summa *= (double) (1.00 + maxproc / 100);
        }
        printf("Best saving invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI]->bankname, summa);

    }
    else if (k == stringcount) {
        printf("The saving invest is not suitable for the terms\n");
    }
}
 void choosedebit(int sumvkl, int your_month, bankstruct** banki,int stringcount) {
    int maxI = 0;
    int i;
    float maxproc =-1;
    int koef=0;
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (banki[j]->count ==1){
            k += 1;
        }
        else if (your_month < banki[j]->our_vklad[1]->times) {
            k += 1;
        }
    }
    if (k != stringcount) {
        for (i = 1; i < stringcount; i++) {
            if (banki[i]->count >= 2){
                if (banki[i]->our_vklad[1]->rate > maxproc && your_month >= banki[i]->our_vklad[1]->times) {
                    koef = (int)your_month / banki[i]->our_vklad[1]->times;
                    maxproc = banki[i]->our_vklad[1]->rate;
                    maxI = i;
                }
            }          
        }   
        double summa = sumvkl;
        for (j = 0; j < koef; j++) {
            summa *= (double) (1.00 + maxproc / 100);
        }
        printf("Best debit invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI]->bankname, summa);
    }
    else if (k == stringcount) {
        printf("The debit invest is not suitable for the terms\n");
        return 1;
    }
}
void choosecumulative(int sumvkl, int your_month, bankstruct** banki, int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = -1;
    int koef=0;
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (banki[j]->count != 3) {
            k += 1;
        }
        else if (your_month < banki[j]->our_vklad[1]->times) {
            k += 1;
        }
    }
    if (k != stringcount) {
        for (i = 1; i < stringcount; i++) {
            if (banki[i]->count == 3) {
                if (banki[i]->our_vklad[2]->rate > maxproc && your_month >= banki[i]->our_vklad[2]->times) {
                    koef = (int)your_month / banki[i]->our_vklad[2]->times;
                    maxproc = banki[i]->our_vklad[2]->rate;
                    maxI = i;
                }
            }
        }     
        double summa = sumvkl;
        for (j = 0; j < koef; j++) {
            summa *=(double) (1.00 + maxproc / 100);
        }
        printf("Best cumulative invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI]->bankname, summa);
    }
    else if (k == stringcount) {
        printf("The debit invest is not suitable for the terms\n");
    }
}

void freebanki(bankstruct** banki, int stringcount) {
    int i = 0;
    int j = 0;
    for (i = 0; i < stringcount; i++) {
        free(banki[i]->bankname);
        free(banki[i]->banktype);
        for (j = 0; j < banki[i]->count; j++) {
            free(banki[i]->our_vklad[j]->vkladname);
        }
        free(banki[i]->our_vklad);
        free (banki[i]);
    }
    free(banki);
}
