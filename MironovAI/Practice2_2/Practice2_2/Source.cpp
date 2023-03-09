#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "Header_banks.h"
#include <fstream>
#define MAX_PATH 100 // Max path length 
#define MAX_NAME 20  // Max name of banks length
using namespace std;




int read(BanksData** data, int* p, char* path) {
    ifstream infile(path);
    if (!infile) {
        cout << "This file isn`t exist" << endl;
        return 1;
    }
    else {
        infile >> (*p);
        int n = *p;
        (*data) = new BanksData[n];
        for (int i = 0; i < n; i++) {
     
            infile >> (*data)[i].name >> (*data)[i].ownership >> (*data)[i].count;
            (*data)[i].deposits.resize((*data)[i].count);
            for (int j = 0; j < (*data)[i].count; j++) {
                infile >> (*data)[i].deposits[j].name >> (*data)[i].deposits[j].period >> (*data)[i].deposits[j].conditions;
            }
        }
        infile.close();
        return 0;
    }
}

void input_path(char* path) {
    printf("Input a path with file type: \n");
    cin >> path;
    printf("\n \nYour path:  \n%s \n\n", path);
}
void print_data(BanksData* data, int n) {
    cout << "Yours data: " << "\n \n";
    for (int i = 0; i < n; i++) {

        cout << data[i].name << " " << data[i].ownership << " " << data[i].count << endl;
        for (int j = 0; j < data[i].count; j++) {
            cout << data[i].deposits[j].name << " " << data[i].deposits[j].period << " " << data[i].deposits[j].conditions << endl;
        }
        cout << "\n \n";
    }
}
void input_user_data(int* user_year, float* user_money) {
    do {
        printf("For how long would you like to open a deposit? \n");
        cin >> (*user_year);

        if ((*user_year) <= 0 || (*user_year) >= 100) {
            printf("Wrong period, try again\n");
        }
    } while ((*user_year) <= 0 || (*user_year) >= 100);
    do {
        printf("How much would you like to open a deposit for (rubles)? \n");
        cin >> (*user_money);

        if ((*user_money) <= 0) {
            printf("Wrong period, try again\n");
        }
    } while ((*user_money) <= 0);
}


pair<int, float> BanksData::best_deposit(int user_year, float user_money) {
    float profit = 0;
    int  id = -1;
    for (int j = 0; j < count; j++) {
        if (user_year % deposits[j].period == 0) {
            float tmp_profit = user_money * (pow(1 + (deposits[j].conditions * 0.01), user_year));// formule
            if (profit < tmp_profit) {
                profit = tmp_profit;
                id = j;         
            }
        }
    }
    pair<int, float> q;
    q.first = id;
    q.second = profit;
    return q;
}

triple comparing(BanksData* data, int user_year, float user_money, int n) {
    triple ans;
    BanksData best_data = data[0];
    best_data.best_suggestion = best_data.best_deposit(user_year, user_money);
    ans.id1 = 0;
    ans.id2 = best_data.best_suggestion.first;
    ans.profit = best_data.best_suggestion.second;
    for (int i = 1; i < n; i++) {
        data[i].best_suggestion = data[i].best_deposit(user_year, user_money);
        if (best_data < data[i]) {
            best_data = data[i];
            ans.id1 = i;
            ans.id2 = data[i].best_suggestion.first;
            ans.profit = data[i].best_suggestion.second;
        }
    }
    return ans;
}
