#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "merge.h"
#include "qsort.h"
#include "bubblesort.h"
#define LENGTH 50
int size[LENGTH];
int size_copy[LENGTH];
int i = 0;

char names[LENGTH][LENGTH];
CHAR path[MAX_PATH];

long long int count = 0;

void findfiles(CHAR* path);
void merge(int* a, int left, int mid, int right);
void mergeSort(int* a, int left, int right);
void BubbleSort(int* a, int len);
void QuickSort(int* a, size_t low, size_t high);
void copy_arr(int* source, int* rep, int len)
{
    for (int j = 0; j < len; j++) {
        rep[j] = source[j];
    }
}
void StartTimer()
{
    LARGE_INTEGER A;
    QueryPerformanceCounter(&A);
    count = A.QuadPart;

}
void StopTimer()
{
    LARGE_INTEGER A;
    QueryPerformanceCounter(&A);
    printf("and spent %.2lf ms\n", (double)(A.QuadPart - count) / 1000);
}
void print_files()
{
    for (int j = 0; j < i; j++) {
        for (int g = 0; g < i; g++) {
            if (size[g] == size_copy[j]) {
                printf("%s, %d bytes\n", names[g], size[g]);
                break;
            }
        }
    }
}

void findfiles(CHAR* path)
{
    i = 0;
    WIN32_FIND_DATAA files;
    HANDLE lastfile;
    lastfile = FindFirstFileA(path, &files);
    FindNextFileA(lastfile, &files);
    if (lastfile != INVALID_HANDLE_VALUE) {
        while (FindNextFileA(lastfile, &files)) {
            strcpy(names[i], files.cFileName);
            size[i] = files.nFileSizeLow;
            printf("%s, %d bytes\n", names[i], size[i]);
            i++;
        }
    }
    FindClose(lastfile);
}
int main()
{
    int n;
    printf("Enter directory:");
    scanf("%s", &path);
    findfiles(path);
    do {
        printf("choose a sort\n");
        scanf("%d", &n);
        copy_arr(size, size_copy, i);
        StartTimer();
        if (n == 1) {
            mergeSort(size_copy, 0, i - 1);
            printf("MergeSort did this:\n");
        }
        else if (n == 2) {
            BubbleSort(size_copy, i);
            printf("BubbleSort did this:\n");
        }
        else if (n == 3) {
            QuickSort(size_copy, 0, i - 1);
            printf("QuickSort did this:\n");
        }
        else if (n == 0) {
            return 0;
        }
        print_files();
        StopTimer();

    } while (1);
}
/*void merge(int* a, int left, int mid, int right)
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
/*void QuickSort(int* a, int low, int high) {
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
}*/