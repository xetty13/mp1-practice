#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "banki.h"
#define LENGTH 512
#define LEN 30

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
    char* path = (char*)malloc(_MAX_PATH * sizeof(char)); //!!!!!(free)
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
    bankstruct** banki = (bankstruct**)malloc(sizeof(bankstruct*) * stringcount);
    for (i = 0; i < stringcount; i++) {
        banki[i] = (bankstruct*)malloc(sizeof(bankstruct));
        banki[i]->bankname = (char*)malloc(sizeof(char) * LEN);
        banki[i]->banktype = (char*)malloc(sizeof(char) * LEN);
    }

   
    return banki;
}
vkladstruct* allocvklads(int stringcount) {
    vkladstruct* banki = (vkladstruct*)malloc(sizeof(vkladstruct) * stringcount);
    return banki;
}
bestbank** allocbest(int n) {
    int i = 0;
    bestbank** bests = (bestbank**)malloc(sizeof(bestbank*) * n);
    for (i = 0; i < n; i++) {
        bests[i] = (bestbank*)malloc(sizeof(bestbank));
        bests[i]->bestname = (char*)malloc(sizeof(char) * LEN);
        bests[i]->besttype = (char*)malloc(sizeof(char) * LEN);
    }
    return bests;
}



void workfile(bankstruct** banki,vkladstruct* vklads, char* path, int stringcount) {
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
                    strcpy(banki[j]->bankname, token);
                    break;
                case 1:
                    strcpy(banki[j]->banktype, token);
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

void data_input(int* sumvkl, int* your_month) {
    printf("Enter count of money\n");
    scanf("%d", sumvkl);
    printf("For how long is the contribution made\n");
    scanf("%d", your_month);
}


void chooseall(int sumvkl, int your_month, bankstruct** banki, vkladstruct* vklads, bestbank** bests, int stringcount) {
    int n = 3;
    int sav = choosesaving(sumvkl, your_month, banki, vklads, bests, stringcount);
    int deb = choosedebit(sumvkl, your_month, banki, vklads, bests, stringcount);
    int cum = choosecumulative(sumvkl, your_month, banki, vklads, bests, stringcount);
    if ((sav + deb + cum) == 3) {
        printf("It is impossible to make a profit because the selected period is less than the minimum\n");
        return 0;
    }
    else {
        chooseprint(bests, n);
    }
}

int choosesaving(int sumvkl, int your_month, bankstruct** banki, vkladstruct* vklads, bestbank** bests, int stringcount) {
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < vklads[j].saving_month || vklads[j].saving_month == 0) {
            k += 1;
        }
    }
    if (k != stringcount) {
        int maxI = 0;
        int i;
        float maxproc = vklads[0].saving;
        int koef = 0;
        for (i = 1; i < stringcount; i++) {
            if (vklads[i].saving > maxproc && your_month >= vklads[i].saving_month) {
                koef = (int)your_month / vklads[i].saving_month;
                maxproc = vklads[i].saving;
                maxI = i;
            }
        }
        double summa = sumvkl;
        for (j = 0; j < koef; j++) {
            summa *= (double) (1.00 + maxproc / 100);
        }
        strcpy(bests[0]->bestname, banki[maxI]->bankname);
        strcpy(bests[0]->besttype, "saving");
        bests[0]->bestsum = summa;//printf("Best saving invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI]->bankname, summa);
        return 0;
    }
    else if (k == stringcount) {
        printf("The saving invest is not suitable for the terms\n");
        return 1;
    }
}
 int choosedebit(int sumvkl, int your_month, bankstruct** banki, vkladstruct* vklads, bestbank** bests, int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].debit;
    int koef=0;
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < vklads[j].saving_month || vklads[j].saving_month==0) {
            k += 1;
        }
    }
    if (k != stringcount) {
        for (i = 1; i < stringcount; i++) {
            if (vklads[i].debit > maxproc && your_month >= vklads[i].debit_month) {
                koef = (int)your_month / vklads[i].debit_month;
                maxproc = vklads[i].debit;
                maxI = i;
            }          
        }   
        double summa = sumvkl;
        for (j = 0; j < koef; j++) {
            summa *= (double) (1.00 + maxproc / 100);
        }
        strcpy(bests[1]->bestname, banki[maxI]->bankname);
        strcpy(bests[1]->besttype, "debit");
        bests[1]->bestsum = summa;//printf("Best debit invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI]->bankname, summa);
        return 0;
    }
    else if (k == stringcount) {
        printf("The debit invest is not suitable for the terms\n");
        return 1;
    }
}
int choosecumulative(int sumvkl, int your_month, bankstruct** banki, vkladstruct* vklads, bestbank** bests, int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].cumulative;
    int koef=0;
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < vklads[j].saving_month || vklads[j].saving_month==0) {
            k += 1;
        }
    }
    if (k != stringcount) {
        for (i = 1; i < stringcount; i++) {
            if (vklads[i].cumulative > maxproc && your_month >= vklads[i].cumulative_month) {
                koef = (int)your_month / vklads[i].cumulative_month;
                maxproc = vklads[i].cumulative;
                maxI = i;
            }
        }     
        double summa = sumvkl;
        for (j = 0; j < koef; j++) {
            summa *=(double) (1.00 + maxproc / 100);
        }
        strcpy(bests[2]->bestname, banki[maxI]->bankname);
        strcpy(bests[2]->besttype, "cumulative");
        bests[2]->bestsum = summa;//printf("Best cumulative invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI]->bankname, summa);
        return 0;
    }
    else if (k == stringcount) {
        printf("The debit invest is not suitable for the terms\n");
        return 1;
    }
}



void chooseprint(bestbank** bests,int n) {
    int i = 0;
    int k = 0;
    double maxsum = bests[0]->bestsum;
    for (i = 0; i < n; i++) {
        if (bests[i]->bestsum > maxsum) {
            maxsum = bests[i]->bestsum;
            k = i;
        }
    }
    printf ("The best invest: BANK- %s, his type- %s .The amount after receiving the deposit will be %.2lf \n", bests[k]->bestname, bests[k]->besttype,maxsum);
}

void freeall(bestbank** bests, int n, vkladstruct* vklads, bankstruct** banki, int stringcount) {
    void freebanki(bankstruct * *banki, int stringcount);
    void freevklads(vkladstruct * vklad);
    void freebests(bestbank * *bests, int n);
}

void freebanki(bankstruct** banki, int stringcount) {
    int i = 0;
    for (i = 0; i < stringcount; i++) {
        free(banki[i]->bankname);
        free(banki[i]->banktype);
        free (banki[i]);
    }
    free(banki);
}
void freevklads(vkladstruct* vklad) {
    free(vklad);
}
void freebests(bestbank** bests, int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        free(bests[i]->bestname);
        free(bests[i]->besttype);
        free(bests[i]);
    }
    free(bests);
}
