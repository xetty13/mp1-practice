#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
#define L 10

void Command()
{
    printf("\n1 - scan item \n");
    printf("2 - display description \n");
    printf("3 - add item to check \n");
    printf("4 - form a check \n");
    printf("5 - calculate the total \n");
}

void Gen(int a[], int n, double m)
{
    int i;
    srand((unsigned int)time(0));
    for (i = 1; i < n; i++)
        a[i] = m / RAND_MAX * rand() + 1;
}

int Scan(int goo[], int num)
{
    char tov[4];
    int tmp, i;
    do
    {
        printf("Enter barcode \n");
        scanf("%s", &tov);
        tmp = tov[3] - '0' + (tov[2] - '0') * 10 + (tov[1] - '0') * 100 + (tov[0] - '0') * 1000; 
    } 
    while ((tmp < 0) || (tmp > N)); 
    goo[num] = tmp; 
    for (i = 0; i < 4; i++)
        tov[i] = NULL;
    do
    {
        printf("Enter the quantity of goods \n");
        scanf("%d", &tmp); 
    } 
    while ((tmp < 0) || (tmp > 1000));
    return tmp;
}

void Desciption(char prod[][L], int pr[], int dis[], int num)
{
    int i;
    printf("id ");
        for (i = 0; i < L; i++)
            printf("%c", prod[num][i]); 
    printf(" price %d dis %d \n", pr[num], dis[num]);
}

void AddToCheck(int quan[], int num, int q)
{
    quan[num] += q;
}

void Form(int quan[], char prod[][L], int pr[], int dis[])
{
    int i, tov;
    int check = 0, total = 0;
    for (i = 1; i < N; i++)
    {
        if (quan[i] > 0)
        {
            Desciption(prod, pr, dis, i);
            tov = quan[i] * pr[i] * (100 - dis[i]) / 100;
            printf("quan %d total %d \n", quan[i], tov);
            check += (pr[i] * quan[i]);
            total += (pr[i] * quan[i] * (100 - dis[i]) / 100);
        }
    }
    if (check > 0)
    {
        i = (check - total) * 100 / check;
        printf("without discount %d discount %d total %d \n", check, i, total);
    }
    else
        printf("No products added");
}

void main()
{
    int num = 0, i, j, q;
    int quan[N] = {0}, pr[N], dis[N], goo[N];
    char prod[N][L] = { "0000 Pack ", "0001 Milk ", "0002 Bread", "0003 Egg  ", "0004 Flour", "0005 Apple", "0006 Meat ", "0007 Fish " }; 
    for (i = 8; i < N; i++)
    {
        prod[i][0] = (i / 1000) + '0';
        prod[i][1] = (i / 100) % 10 + '0';
        prod[i][2] = (i / 10) % 10 + '0';
        prod[i][3] = (i % 10) + '0';
        for (j = 4; j < L; j++)
            prod[i][j] = prod[i % 8][j];
    }
    Gen(pr, N, 1000.0); 
    Gen(dis, N, 50.0);
    q = Scan(goo, num); 
    do
    {
        Command();
        scanf("%d", &i);
        printf("\n");
        switch (i) {
        case 1: 
            q = Scan(goo, num);
            break;
        case 2:
            Desciption(prod, pr, dis, goo[num]);
            break;
        case 3: 
            AddToCheck(quan, goo[num], q);
            num++;
            break;
        case 4:
            Form(quan, prod, pr, dis);
            break;
        case 5:
            Form(quan, prod, pr, dis);
            break;
        }
    } 
    while (i != 5);
}
