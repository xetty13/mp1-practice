#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define MAX_PATH 100 // Max path length 



int main() {
    int n;
    BanksData* data;
    do {
        n = read(&data);
    } while (n == 0);
    

    print_data(data, n);

    int user_year;
    float user_money;
    input_user_data(&user_year, &user_money);
    pair ans = comparing(data, n, user_year, user_money);

    printf("\n The best suggestion for you in %s %s.\n \n if you would invest %.2f in %s deposit at a %.2f per year\n \nYour benefit in %d years will be %.2f rubles \n", data[ans.id1].ownership, data[ans.id1].name, user_money, data[ans.id1].deposits[ans.id2].name, data[ans.id1].deposits[ans.id2].conditions, user_year, ans.profit);

    freedata(&data, n);
    free(data);
    return 0;


}