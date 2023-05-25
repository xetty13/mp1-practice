#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
void main()
{
	One_Person** peop;
    int n;
    int i;
	int flag_m;
	char f[150];
	printf("Enter the name of the file to be sorted: \n");
    scanf("%s", f);
    Reading_File(&peop, &n, f);
    for (i = 0; i < n; i++)
        Print_Inforamation(peop[i]);
    sorting_for_surname(peop, n);

    do {
        printf("\nHow to dislay a sorted list:\n1)Asceling\n2)Ascending\n Choose a method: ");
        scanf("%d", &flag_m);
        if (flag_m == 1)
        {
            printf("\n");
            for (i = 0; i < n; i++)
                Print_Inforamation(peop[i]);
        }
        if (flag_m == 2)
        {
            printf("\n");
            for (i = n - 1; i >= 0; i--)
                Print_Inforamation(peop[i]);
        }
    } while ((flag_m <= 0) || (flag_m > 2));

    for (i = 0; i < n; i++)
        Free_memory(&(peop[i]));
}

