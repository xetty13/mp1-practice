#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Size 10
#define n1pr 20
#define n2pr 5000
#define n1sale 1
#define n2sale 50
#define n1code 1
#define n2code 9999


int Stoimost(int f_code[], int f_id, int f_count)
{
    int j, pos;
    //Find id in massive and save possition 
    while (f_code[j] != f_id) j++;
    if (j == Size) printf("Error");
    else (pos = j);


}

void main()
{
    int Prices[Size], Sales[Size], Code[Size], i;
    int id, count; //id-id product

    //Zapolnenie cen i skidok
    for (i = 0; i < Size; i++)
    {

        Prices[i] = rand() % (n2pr - n1pr) + n1pr;
        Sales[i] = rand() % (n2sale - n1sale) + n1sale;
        Code[i] = rand() % (n2code - n1code) + n1code;
    }

    printf("Enter id product and his amount");
    scanf("%d", &id, &count);

    //function - create
    Stoimost(Code, id, count);


}