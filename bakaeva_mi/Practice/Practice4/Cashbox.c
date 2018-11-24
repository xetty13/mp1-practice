#include <stdio.h>
//#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define s 4
#define k 30
#define N 10

char name[N][k] = { "Shower cabin 'Niagara'", "Kitchen sink 'Moidodyr'" , "Cupboard under the sink 'Amex'",
"Bath 'Roca Surest'", "Microwave 'Hot days'", "Fridge 'Telamon'" ,
"Coffee machine 'Ariston'" ,  "Dishwasher 'DeLonghi'" ,
"Washer 'Andy Aqua'" ,  "Cooker 'Flama'" };
int id[N + 1][s] = { { 1,2,5,8 },{ 1,5,7,3 },{ 1,8,1,5 },
{ 1,7,7,8 },{ 2,4,7,7 },
{ 3,6,2,5 },{ 5,0,7,8 },
{ 6,4,1,6 },{ 8,2,3,5 },{ 8,5,0,1 }, {0,0,0,0} };
int price[N] = { 60000, 20000, 25000, 55999, 30500, 63440, 12700, 29300, 32900, 24000 };
int sale[N] = { 20, 45, 50, 12, 35, 10, 15, 5, 20, 10 };
int check[N][s] = { 0 };
int count[N] = { 0 };
int stoim[N] = { 0 };
int pos;

int scan(int a[][s], int n)
{
    int id, id1, leng;
    int copy[s], i, fl = 0, pos1;
    do
    {
        printf(" Enter your id, please  ");
        scanf("%d", &id);
        id1 = id;
        leng = 0;

        if (id == 111)
            return 111;
        
        while (id1 != 0)
        {
            id1 /= 10;
            leng++;
        }
        if (leng != s) printf("\nId not found, sorry. Try again\n\n");
        if (leng == s)
        {
            id1 = id;
            for (i = s - 1; i >= 0; i--)
            {
                copy[i] = id1 % 10;
                id1 /= 10;
            }

            for (i = 0; i < s; i++)
                a[n - 1][i] = copy[i];

            i = 0;
            while ((a[i][0] != copy[0]) || (a[i][1] != copy[1]) || (a[i][2] != copy[2]) || (a[i][3] != copy[3]))
                i++;

            if (i == n - 1) pos1 = -1;
            else pos1 = i;
        }

    } while ((leng != s) && (pos != -1));
    return pos1;
}

void inform(int pos1, int a[][s], int n, char b[][k], int f_price[], int f_sale[])
{
    int i = 0;
    for (i = 0; i < s; i++)
        printf("%d", a[pos1][i]);
    printf("    ");
    for (i = 0; i < k; i++)
        printf("%c", b[pos1][i]);
    printf("");
    printf("%d rub", f_price[pos1]);
    printf("  ");
    printf("%d %%", f_sale[pos1]);
    printf("\n\n");
}

void add_check(int a[][s], int n, int b[][s], int pos1, int c[])
{
    int i, j, fl = 0;
    char otv;

    do
    {
        printf("Do you want to add product to check?(+ or -) ");
        scanf(" %c", &otv);
        printf("\n");
    } while ((otv != '+') && (otv != '-'));

    if (otv == '+') 
    {
        for (i = 0; i < n; i++)
        {
                if (a[i][0] == b[pos1][0] && a[i][1] == b[pos1][1] && a[i][2] == b[pos1][2] && a[i][3] == b[pos1][3])
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
                if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0 && a[i][3] == 0)
                {
                    for (j = 0; j < s; j++)
                        a[i][j] = b[pos1][j];
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
            for (j = 0; j < k; j++)
                printf( "%c", f_name[i][j]);
            printf("  ");
            printf("%d %%", f_sale[i]);
            printf("\n");
            printf("%d", f_count[i]);
            printf(" * ");
            printf("%d rub", f_price[i]);
            printf("          = ");
            st = f_count[i] * (1 - (f_sale[i] / 100.0)) * f_price[i];
            printf("%.2lf", st);
            printf("\n\n");
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

void output_id_name(int a[][s], int n, char b[][k])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < s; j++)
            printf(" %d", a[i][j]);
        printf("    ");
        for (j = 0; j < k; j++)
            printf("%c", b[i][j]);
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
    int pos;
    do
    {
        printf("\n Go to menu  - 111\n----------------\n\n");
        pos = scan(id, N + 1);
        if (pos == 111)
            break;
        if (pos == -1)
            printf("\n Id not found, sorry. Try again\n\n");
        else
        {
            inform(pos, id, N, name, price, sale);
            add_check(check, N, id, pos, count);
        }
    } while (pos != 111);
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
    int id[N][s] = { 0 };
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
