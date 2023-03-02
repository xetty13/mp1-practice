#include <stdio.h>
#include <stdlib.h>
#include "Header_banks.h"
#define MAX_PATH 100 // Max path length 



int main() {

    char* path = (char*)malloc(sizeof(char) * MAX_PATH);
    input_path(path);

    FILE* file;
    file = fopen(path, "r");
    if (file == NULL) {
        printf("\n Uncorrect path\n");
        return 0;
    }

    int n;
    fscanf(file, "%d", &n);

    BanksData* data = (BanksData*)malloc(sizeof(BanksData) * n);
    read(file, data, n);
    print_data(data, n);

    int user_year;
    float user_money;
    input_user_data(&user_year, &user_money);
    pair ans = comparing(data, n, user_year, user_money);

    printf("\n The best suggestion for you in %s %s.\n \n if you would invest %.2f in %s deposit at a %.2f per year\n \nYour benefit in %d years will be %.2f rubles \n", data[ans.id1].ownership, data[ans.id1].name, user_money, data[ans.id1].deposits[ans.id2].name, data[ans.id1].deposits[ans.id2].conditions, user_year, ans.profit);

    freedata(&data, n);

    free(path);
    free(data);
    return 0;


}