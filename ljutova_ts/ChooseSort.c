#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void fill(int a[], int n)
{
	int i;
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++)
		a[i] = rand();
}
void choose_sort(int a[], int n)
{
	int i, min, j, minidx;
	for (i = 0; i < n; i++)
	{
		min = a[i];
		minidx = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				minidx = j;
			}
		}
		a[minidx] = a[i];
		a[i] = min;
	}
}
void output(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d", a[i]);
}
void main()
{
	int a[N];
	fill(a, N);
	output(a, N);
	system("pause");
}
