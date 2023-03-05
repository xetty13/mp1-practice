#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main(void)
{
    FILE* file;
    Person** per;
    int n, i, a;

    read(&per, &file, &n);
    for (i = 0; i < n; i++)
        print_persons(per[i]);
    Sort(per, n);

    do {
        printf("\nHow do you want to display the sorted list?\n1. In alphabetical ascending order\n2. In alphabetical descending order\nEnter a number: ");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("\n");
            for (i = 0; i < n; i++)
                print_persons(per[i]);
        }
        if (a == 2)
        {
            printf("\n");
            for (i = n - 1; i >= 0; i--)
                print_persons(per[i]);
        }
    } while ((a <= 0) || (a > 2));


    for (i = 0; i < n; i++)
        free_person(&(per[i]));
    return 0;
}