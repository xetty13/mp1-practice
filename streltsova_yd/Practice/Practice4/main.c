#include <stdio.h>
#define N 4
void main()
{
    int mode, i, string;
    char str[N];
    printf ("\n");
    printf ("Choose a mode. Enter 1 - 5\n");
    do 
    {
        scanf ("%d", &mode);
    } while ((mode != 1) && (mode != 2) && (mode != 3) && (mode != 4) && (mode != 5));
    if (mode == 1)
    {
         do
            {
                scanf ("%d", &string);
            } while ((string < 1) || (string > 9999));
            for (i = 1; i <= N; i++)
            {
                str[N - i] = char(string % 10);
                string /= 10;
            }
    }
    if (mode == 2)
    {

    }
}