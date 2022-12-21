#include "merge.h"
#define LENGTH 50
int size[LENGTH];
int size_copy[LENGTH];
void merge(int* a, int left, int mid, int right)
{
    int i0 = 0, i1 = 0, i2 = left;
    int b[LENGTH];
    while ((i0 < (mid - left + 1)) && (i1 < (right - mid))) {
        if (a[left + i0] <= a[mid + i1 + 1]) {
            b[i2] = a[left + i0];
            i0++;
        }
        else {
            b[i2] = a[mid + i1 + 1];
            i1++;
        }
        i2++;
    }
    while (i0 < (mid - left + 1)) {
        b[i2] = a[left + i0];
        i0++;
        i2++;
    }
    while (i1 < (right - mid)) {
        b[i2] = a[mid + i1 + 1];
        i1++;
        i2++;
    }
    for (int j = left; j < i2; j++) {
        a[j] = b[j];
    }
}
void mergeSort(int* a, int left, int right)
{
    if (left < right) {
        int mid;
        mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
