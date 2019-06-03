#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define s 4
#define k 30
#define N 10

char name[N][k] = { "Shower cabin 'Niagara'", "Kitchen sink 'Moidodyr'" , "Cupboard under the sink 'Amex'",
"Bath 'Roca Surest'", "Microwave 'Hot days'", "Fridge 'Telamon'" ,
"Coffee machine 'Ariston'" ,  "Dishwasher 'DeLonghi'" ,
"Washer 'Andy Aqua'" ,  "Cooker 'Flama'" };
char id[N + 1][s] = { "1258", "1573", "1815",
"1778", "2477",
"3625","5078",
"6416", "8235", "8501", "0000" };
int price[N] = { 60000, 20000, 25000, 55999, 30500, 63440, 12700, 29300, 32900, 24000 };
int sale[N] = { 20, 45, 50, 12, 35, 10, 15, 5, 20, 10 };
int check[N] = { 0 };
int count[N] = { 0 };
int stoim[N] = { 0 };
int pos;

int scan(char code[][s], int n)
{
    int i, _pos;
    char copy[N];

    printf(" Enter your id, please  ");
    scanf("%s", &copy);

    if (strlen(copy) != s) //Если код не подходит по длине
        return -1;

        for (i = 0; i < n + 1; i++)
            if (strncmp(copy, code[i], 4) == 0)
            {
                return i;
            }
    return -1;
}

void inform(int pos, char code[][s], int n, char name[][k], int f_price[], int f_sale[])
{
    printf("%.4s", code[pos]);
    printf("    ");
    printf("%s", name[pos]);
    printf("");
    printf("%d rub", f_price[pos]);
    printf("  ");
    printf("%d %%", f_sale[pos]);
    printf("\n\n");
}

void add_check(int check[], int n, char code[][s], int _pos, int c[])
{
    int i, j, fl = 0;
    char otv[2];

    do
    {
        printf("Do you want to add product to check?(+ or -) ");
        scanf(" %s", &otv);
        printf("\n");
    } while ((otv == '+') || (otv == '-'));

    if (otv[0] == '+') 
    {
        for (i = 0; i < n; i++)
        {
            //Проверка на существование товара в чеке
            if (check[i] == _pos)
            {
                fl = 1;
                c[i]++;
                break;
            }
        }

        if (fl == 0)
        { 
            for (i = 0; i < n; i++)
            {
                if (check[i] == 0)
                {
                    check[i] = _pos;
                    break;
                }
            }
            c[i]++;
        }
    }
}

void show_check(int n, char f_name[][k], int f_count[], int f_price[], int f_sale[])
{
    int i = 0, j = 0;
    double st = 0.0;

    for (i = 0; i < n; i++)
    {
        if (f_count[i] != 0)
        {
            printf( "%s", f_name[check[i]]);
            printf("  ");
            printf("%d %%", f_sale[check[i]]);
            printf("\n");
            printf("%d", f_count[i]);
            printf(" * ");
            printf("%d rub", f_price[check[i]]);
            printf("          = ");
            st = f_count[i] * (1 - (f_sale[check[i]] / 100.0)) * f_price[check[i]];
            printf("%.2lf", st);
            printf("\n");
        }
    }
}

void final_sum(int f_count[], int f_sale[], int f_price[], int n)
{
    double sum = 0.0;
    int i;
    char dateStr[9];
    char timeStr[9];
    for (i = 0; i < n; i++)
        sum += f_count[i] * (1 - (f_sale[i] / 100.0)) * f_price[i];
    printf(" \n\n-------------------------------------\n");
    printf(" OOO 'RUSOLA'\n");
    printf(" Check number %d\n", rand() % 499 + 200);
    printf(" Cashier: Kireeva");
    printf(" \n-------------------------------------\n");
    show_check(N, name, count, price, sale);
    printf("=====================================\n");
    _strdate(dateStr);
    _strtime(timeStr);
    printf(" %s", dateStr);
    printf("    ");
    printf(" %s", timeStr);
    printf("");
    printf(" \n=====================================\n");
    printf(" TOTAL                  = ");
    printf("%.2lf\n\n", sum);

}

void menu()
{
    printf(" ----\n MENU\n ----\n");
    printf(" 1) Show id and product list\n");
    printf(" 2) Scan new product\n");
    printf(" 3) Show check\n");
    printf(" 4) Close the check and show final amount\n");
    printf(" 5) Show menu\n");
    printf(" 6) Exit\n\n");
}

int get_variant(int count)
{
    int variant;
   
    do
    {
        printf(" Enter the menu number  "); 
        scanf("%d", &variant);
    }while ((variant < 1) || (variant > count));

    return variant;
}

void output_id_name(char code[][s], int n, char name[][k])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
            printf(" %.4s", code[i]);
        printf("    ");
            printf("%s", name[i]);
        printf("\n");
    }
    printf("\n\n");
}

void num1()
{
    printf("\n");
    output_id_name(id, N, name);
}

void num2()
{
    int _pos;
    do
    {
        _pos = scan(id, N + 1);
        if (_pos == -1)
            printf("\n Id not found, sorry. Try again\n\n");
        else
        {
            inform(_pos, id, N, name, price, sale);
            add_check(check, N, id, _pos, count);
        }
    } while (_pos == -1);
}

void num3()
{
    show_check(N, name, count, price, sale);
}

void num4()
{
    final_sum(count, sale, price, N);
}

void main()
{
    int variant;

    menu();
    do
    {   
        variant = get_variant(6);

        switch (variant)
        {
        case(1):
            num1();
            break;
        case(2):
            num2();
            break;
        case(3):
            num3();
            break;
        case(4):
            num4();
            break;
        case(5):
            menu();
            break;
        };
    } while (variant != 6);
    return;
}
