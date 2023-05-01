#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "banki.h"
#define LENGTH 512
#define LEN 30

using namespace std;

int strcount(string path) {
    int stringcount = 0;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "ERROR: Could not open file!" << endl;
    }
    else {
        string line;
        while (getline(file, line))
        {
            if (line != "\0") {
                stringcount++;
            }
        }
        file.close();
    }
    return stringcount;
    /*char* s = (char*)malloc(1000 * sizeof(char));
    //FILE* file = fopen(path, "r");
    if (file == NULL) {
        cout<<"ERROR: Could not open file!"<< endl;
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
    return count;*/
}



bankstruct* allocbanki(int stringcount) {
    bankstruct* banki = new bankstruct[stringcount];

    return banki;
}
vkladstruct* allocvklads(int stringcount) {
    vkladstruct* banki = new vkladstruct[stringcount];
    return banki;
}
bestbank* allocbest(int n) {
    bestbank* bests = new bestbank[n];
    return bests;
}



void workfile(bankstruct* banki, vkladstruct* vklads, string path, int stringcount) {
    int i = 0;
    int j = 0;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "ERROR: Could not open file!" << endl;
    }
    else {
        string str;
        string line;
        string token;
        ifstream file(path);
        while (getline(file, line))
        {
            if (line == "\0") {
                continue;
            }
            stringstream ss(line);
            while (getline(ss, token, ',')) {
                switch (i) {
                case 0:
                    banki[j].bankname = token;
                    break;
                case 1:
                    banki[j].banktype = token;
                    break;
                case 2:
                    vklads[j].saving = stoi(token);
                    break;
                case 3:
                    vklads[j].debit = stoi(token);
                    break;
                case 4:
                    vklads[j].cumulative = stoi(token);
                    break;
                case 5:
                    vklads[j].saving_month = stoi(token);
                    break;
                case 6:
                    vklads[j].debit_month = stoi(token);
                    break;
                case 7:
                    vklads[j].cumulative_month = stoi(token);
                    i = -1;
                    j++;
                    break;
                }
                i++;
            }
        }
    }
    /*FILE* file = fopen(path, "r");
    char str[LENGTH];
    if (file == NULL) {//проверка
        cout <<"ERROR: Could not open file!"<< endl;
        //return 1;
    }
    while (1) {
        if (getline(str, 512, file) != NULL) {
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
    */
}



int choosesaving(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, bestbank* bests, int stringcount) {
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
        int a = 0;
        for (a = 0; a < koef; a++) {
            summa *= (double)(1.00 + maxproc / 100);
        }
        bests[0].bestname = banki[maxI].bankname;
        bests[0].besttype = "saving";
        bests[0].bestsum = summa;
        //cout<<("Best saving invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI]->bankname, summa);
        return 0;
    }
    else if (k == stringcount) {
        cout << "The saving invest is not suitable for the terms" << endl;
        return 1;
    }
}
int choosedebit(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, bestbank* bests, int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].debit;
    int koef = 0;
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < vklads[j].saving_month || vklads[j].saving_month == 0) {
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
            summa *= (double)(1.00 + maxproc / 100);
        }
        bests[1].bestname = banki[maxI].bankname;
        bests[1].besttype = "debit";
        bests[1].bestsum = summa;
        //cout << ("Best debit invest: BANK- banki[maxI]->bankname, in the next year you will receive summa" )<<endl;
        return 0;
    }
    else if (k == stringcount) {
        cout << "The debit invest is not suitable for the terms" << endl;
        return 1;
    }
}
int choosecumulative(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, bestbank* bests, int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].cumulative;
    int koef = 0;
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < vklads[j].saving_month || vklads[j].saving_month == 0) {
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
            summa *= (double)(1.00 + maxproc / 100);
        }
        bests[2].bestname = banki[maxI].bankname;
        bests[2].besttype ="cumulative";
        bests[2].bestsum = summa;
        //cout << ("Best cumulative invest: BANK- banki[maxI]->bankname, in the next year you will receive summa")<< endl;
        return 0;
    }
    else if (k == stringcount) {
        cout << "The debit invest is not suitable for the terms" << endl;
        return 1;
    }
}



void chooseprint(bestbank* bests, int n) {
    int i = 0;
    int k = 0;
    double maxsum = bests[0].bestsum;
    for (i = 0; i < n; i++) {
        if (bests[i].bestsum > maxsum) {
            maxsum = bests[i].bestsum;
            k = i;
        }
    }
    cout << "The best invest: BANK " << bests[k].bestname << ", his type -" << bests[k].besttype << ". The amount after receiving the deposit will be " << maxsum << endl;
}



void freebanki(bankstruct* banki, int stringcount) {
    delete[] banki;
}
void freevklads(vkladstruct* vklad) {
    delete[] vklad;
}
void freebests(bestbank* bests, int n) {
    delete[] bests;
}
