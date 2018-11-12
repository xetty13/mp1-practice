#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void Command()
{
    printf("1 - add item \n");
    printf("2 - display description \n");
    printf("3 - add item to check \n");
    printf("4 - form a check \n");
    printf("5 - calculate the total \n");
}

void Gen(int a[], int n, int m)
{
    int i;
    srand((unsigned int)time(0));
    for (i = 1; i < n; i++)
        a[i] = m / RAND_MAX * rand() + 1;
}

void Scan(int quan[], int goo[], int num)
{
    int temp;
    do
    {
        printf("Enter barcode \n");
        scanf("%d", &temp);
    } while ((temp < 0) || (temp > N));
    goo[num] = temp;
    do
    {
        printf("Enter the quantity of goods \n");
        scanf("%d", &temp);
    } while ((temp < 0) || (temp > 1000));
    quan[goo[num]] += temp;
}

void Desciption(char prod[], int pr[], int dis[], int num)
{
    printf("%d %s %d %d", num, prod[num], pr[num], dis[num]);
}

void AddToCheck(int *check, int *total, int quan[], int pr[], int dis[], int num)
{
    check += (pr[num] * quan[num]);
    total += (pr[num] * quan[num] * (100 - dis[num]) / 100);
}

void Form(int quan[], char prod[], int pr[], int dis[], int check, int total)
{
    int i;
    for (i = 1; i < N; i++)
    {
        if (quan[i] > 0)
        {
            Desciption(prod, pr, dis, i);
            printf("quan %d total %d \n", quan[i], quan[i] * pr[i] * (100 - dis[i]) / 100);
        }
    }
    printf("total %d \n", total);
    printf("discount %d \n", check * 100 / total);
}

void main()
{
    int num = 0, i, total = 0, check = 0;
    int quan[N] = {0}, pr[N], dis[N], goo[N];
    char prod[N];
    Gen(pr, N, 1000);
    Gen(dis, N, 50);
//    prod[1] = "Y";
//    prod[2] = "M";
    Scan(quan, goo, num);
    do
    {
        Command();
        scanf("%d", &i);
        switch (i) {
        case 1: 
            Scan(quan, goo, num);
            break;
        case 2:
            Desciption(prod, pr, dis, goo[num]);
            break;
        case 3: 
            AddToCheck(&check, &total, quan, pr, dis, goo[num]);
            num++;
            break;
        case 4:
            Form(quan, prod, pr, dis, check, total);
            break;
        case 5:
            Form(quan, prod, pr, dis, check, total);
            break;
        }
    } while (i != 5);
}