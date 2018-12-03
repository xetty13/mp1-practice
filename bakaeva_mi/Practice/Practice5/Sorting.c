#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 7
#define k 6
#define n1 0
#define n2 5
int arr[N] = { 0 };


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
    int copy[N];

    for (i = 0; i < n; i++)
        copy[i] = a[i];

    for (i = 0; i < n; i++)
    {
        min = copy[i];
        minidx = i;
        for (j = i + 1; j < n; j++)
            if (copy[j] < min)
            {
                min = copy[j];
                minidx = j;
            }
        copy[minidx] = copy[i];
        copy[i] = min;
    }
    output(copy, N);
    printf("\n");
}

void insert_sort(int a[], int n)
{
    int i, j, tmp;
    int copy[N];

    for (i = 0; i < n; i++)
        copy[i] = a[i];

    for (i = 1; i < n; i++)
    {
        tmp = copy[i];
        j = i - 1;
        while ((j >= 0) && (copy[j] > tmp))
        {
            copy[j + 1] = copy[j];
            copy[j] = tmp;
            j--;
        }
    }
    output(copy, N);
    printf("\n");
}

void bubble_sort(int a[], int n)
{
    int i, j, tmp;
    int copy[N];

    for (i = 0; i < n; i++)
        copy[i] = a[i];
    for (i = 0; i < n; i++)
        for (j = 1; j < n; j++)
            if (copy[j - 1] > copy[j])
            {
                tmp = copy[j];
                copy[j] = copy[j - 1];
                copy[j - 1] = tmp;
            }
    output(copy, N);
    printf("\n");
}

void count_sort(int a[], int n)
{
    int i, j, idx, min, max;
    int count[k] = { 0 };
    int copy[N];

    for (i = 0; i < n; i++)
        copy[i] = a[i];

    min = copy[0];
    max = copy[0];
    for (i = 0; i < n; i++)
    {
        if (min > copy[i]) min = copy[i];
        if (max < copy[i]) max = copy[i];
    }
    idx = 0;
    for (i = 0; i < n; i++)
    {
        count[copy[i]]++;
        
        for (i = min; i < max + 1; i++)
            for (j = 0; j < count[i]; j++)
                copy[idx++] = i;
    }
    output(copy, N);
    printf("\n");
}

void quick_split(int a[], int *i, int *j, int p)
{
    int tmp;
    do
    {
        while (a[*i] < p) *i++;
        while (a[*j] > p) *j--;
        if (*i <= *j)
        {
            tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
        }
    } while (*i < *j);
}

void quick_sort(int a[], int s1, int s2)
{
    int m = (s1 + s2) / 2;
    int i = s1, j = s2;
    int copy[N];

    for (i = 0; i < N; i++)
        copy[i] = a[i];
    quick_split(a, &i, &j, m);
    if (i > s1) quick_sort(copy, i, j);
    if (j < s2) quick_sort(copy, j, s2);
    output(copy, N);
    printf("\n");
}

void main()
{
    input(arr, N);
    output(arr, N);

    choose_sort(arr, N);

    insert_sort(arr, N);

    bubble_sort(arr, N);

    count_sort(arr, N);

    system("pause");

}