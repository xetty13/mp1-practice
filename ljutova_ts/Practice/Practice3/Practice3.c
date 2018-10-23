#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
void main() 
{
    int n, ch, r, count = 0;
    printf("Rezhim raboti:\n");
    printf("1-computer zagadivaet chislo\n");
    printf("2-polzovatel zagadivaet chislo\n");
    scanf("%d", &r);
    if (r == 1)
    {
        ch = rand() % 1000 + 1;
        printf("%d \n", ch);
        {
            scanf("%d", &n);
            count++;
            if (n == ch)
                printf("Vi ugadali chislo!");
        }
    }
}