#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
void main()
{
    int a[10], b[10];
    int n, cows = 0, bulls = 0, p, p1, i, j, f, c;
    int temp = 1;
    int s, sravn, partn, rez;
    do
    {
        printf("Enter number of digits: ");
        scanf("%d", &n);
        if ((n <= 0) || (n >= 10))
            printf("Number does not exist \n");
    } while ((n <= 0) || (n >= 10));
    srand((unsigned int)time(0));
    while (temp)
    {
        temp = 0;
        for (i = 0; i < n; i++)
            a[i] = rand() % 9;
        if (a[0] == 0)
            a[0] = rand() % 9 + 1;
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (a[i] == a[j])
                {
                    temp = 1;
                    break;
                }
    }

    while (bulls != n)
    {
        cows = 0;
        bulls = 0;
        printf("Enter your number: ");
        scanf("%d", &c);
        p =  c;
        while (p > 0)
        {

            f = 0;
            sravn = p % 10;
            p /= 10;
            s = p; //переменная для хранения числа
            while (s > 0)
            {
                partn = s % 10;
                s /= 10;
                if (partn == sravn)
                {
                    f++;
                    break;
                }
            }
            if (f != 0)
                break;
        }
        if (f > 0)
        {
            printf("Numbers must be different \n");
            continue;
        }
        for (i = n; i > 0; i--)
        {
            b[i - 1] = c % 10;
            c /= 10;
        }
        for (i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (b[i] == a[j])
                    cows++;
        for (i = 0; i < n; i++)
            if (a[i] == b[i])
                bulls++;
        if (cows >= bulls) //Без этого условия при отгадывании сохраняется
            cows -= bulls; //и число коров, и число быков
        printf("Cows: %d\n", cows);
        printf("Bulls: %d\n", bulls);
    }
    printf("You win!!!");
}