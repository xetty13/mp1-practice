#include <iostream>
#include <vector>
#include "Header_banks.h"
using namespace std;


int main() {
    
    string path;
    input_path(path);
    int n;
    int* p = &n;
    BanksData* data;
    int q;

    do {
        q = read(data, p, path);
        if (q != 0) {
            input_path(path);
        }

    } while (q != 0);
    
    print_data(data, n);

    int user_year;
    float user_money;
    input_user_data(&user_year, &user_money);


    triple ans = comparing(data, user_year, user_money, n);

    cout << "!!!" << endl;
    cout << "\n" << "The best suggestion for you in " << data[ans.id1].ownership << " " << data[ans.id1].name << endl;
    cout << "\n" << "if you would invest " << user_money << " in " << data[ans.id1].deposits[ans.id2].name << " at a " << data[ans.id1].deposits[ans.id2].conditions << " per year";
    cout << "\n \n" << "Your benefit in " << user_year << " years will be " << ans.profit << " rubles" << endl;
    return 0;
    
}