#include "output.h"
#include <stdio.h>

void output(char** filesName, unsigned long* filesSize, int* filesIndex, int count, long long time)
{
    for (int i = 0; i < count; i++) {
        printf("%s", filesName[filesIndex[i]]);
        printf(" %lu B\n", filesSize[i]);
    }
    printf("It took %lld milliseconds to sort\n\n", time);
}
