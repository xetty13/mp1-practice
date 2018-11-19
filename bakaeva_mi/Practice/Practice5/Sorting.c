#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 7
#define k 15
#define n1 0
#define n2 5

void input(int a[], int n)
{
    int i;
    srand((unsigned int)time(0));
    for (i = 0; i < n; i++)
        a[i] = rand() % (n2 - n1) + n1;
}

void output(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void choose_sort(int a[], int n)
{
    int i, j, min, minidx;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        minidx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < min)
            {
                min = a[j];
                minidx = j;
            }
        a[minidx] = a[i];
        a[i] = min;
    }
}

void insert_sort(int a[], int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > tmp))
        {
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }
    }
}

void bubble_sort(int a[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
        for (j = 1; j < n; j++)
            if (a[j - 1] > a[j])
            {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
}

void count_sort(int a[], int n)
{
    int i, j, idx;
    int count[k] = { 0 };
    for (i = 0; i < n; i++)
    {
        count[a[i]]++;
        idx = 0;
        for (i = 0; i < k; i++)
            for (j = 0; j < count[i]; j++)
                a[idx++] = i;
    }
}

void main()
{
    int a[N] = { 0 };

    input(a, N);
    output(a, N);
    choose_sort(a, N);
    output(a, N);
    printf("\n");

    input(a, N);
    output(a, N);
    insert_sort(a, N);
    output(a, N);
    printf("\n");

    input(a, N);
    output(a, N);
    bubble_sort(a, N);
    output(a, N);
    printf("\n");

    input(a, N);
    output(a, N);
    count_sort(a, N);
    output(a, N);
    printf("\n");

    system("pause");

}