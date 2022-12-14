#include "qsort.h"
#define LENGTH 50
int size[LENGTH];
int size_copy[LENGTH];
void QuickSort(int* a, int low, int high) {
    int tmp, pivot, j = high, g = low;

    pivot = a[(low + (high - low) / 2)];
    do {
        while (a[g] < pivot) {
            g++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (g <= j) {
            if (a[g] > a[j]) {
                tmp = a[g];
                a[g] = a[j];
                a[j] = tmp;
            }
            g++;
            if (j > 0) {
                j--;
            }
        }
    } while (g <= j);

    if (g < high) {
        QuickSort(a, g, high);
    }
    if (j > low) {
        QuickSort(a, low, j);
    }
}