#include "bubblesort.h"
void BubbleSort(int* a, int len)
{
    int tmp;
    for (int g = 0; g < len; g++) {
        for (int j = 0; j < len - g - 1; j++) {
            if (a[j + 1] < a[j])
            {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}