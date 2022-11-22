#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#define N 5
void main()
{
    srand(time(NULL));
    int number[N] = { 0 };
    int arr[N] = { 0 };
    int tries = 0;
    int n, i, raz, flag, j, r, p_num, cow, bull, check, d;
    printf("Enter the number of digits in the number from 2 to 5 ");
    do {
        scanf("%d", &n);
        if ((n > 5) || (n < 2)) {
            printf("Invalid number entered. Try again\n");
        }
    } while ((n > 5) || (n < 2));
    number[0] = 1 + rand() % (9);
    r = 0;
    flag = 1;
    for (i = 1; i < n; i++)
    {
        flag = 1;
        while (flag == 1) {
            r = rand() % 10;
            flag = 1;
            for (j = 0; j < i; j++)
            {
                if (number[j] == r)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                number[i] = r;
                break;
            }
        }
    }
    cow = 0;
    bull = 0;
    check = 10;
    for (i = 1; i < n - 1; i++)
    {
        check = check * 10;
    }
    while (bull != n)
    {
        printf("Try to guess the number: ");
        do {
            scanf(" %d", &p_num);
            if ((p_num < check) || (p_num >= check * 10))
            {
                printf("Incorrect number entered. Try again: ");
            }
            else
            {
                d = p_num;
                while (d > 0)
                {
                    if ((d % 10) == (d / 10 % 10))
                    {
                        printf("Incorrect number entered. Try again: ");
                        break;
                    }
                    d = d / 10;
                }
            }
        } while ((p_num < check) || (p_num >= check * 10));
        i = n - 1;
        while (p_num > 0)
        {
            arr[i] = p_num % 10;
            p_num = p_num / 10;
            i--;
        }
        bull = 0;
        cow = 0;
        for (i = 0; i < n; i++)
        {
            if (number[i] == arr[i])
            {
                bull++;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (number[i] == arr[j])
                {
                    if (i != j)
                        cow++;
                }
            }
            tries++;
        }
        printf("Number of bulls: %d. Number of cows: %d\n", bull, cow);
    }
    printf("Congratulations! You guessed the number in %d attempts", tries);
}