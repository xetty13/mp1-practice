#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define K 10
#define N2 10
void fill(int a[], int n)
{
	int i;
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++)
		a[i] = rand() % 10;
}
void chooseSort(int a[], int n)
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
void insertSort(int a[], int n)
{
	int i, tmp, j;
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
void bubbleSort(int a[], int n)
{
	int i, tmp, j;
	{
		for (i = 0; i < n; i++)
		{
			for (j = 1; j < n; j++)
				if (a[j - 1] > a[j])
				{
					tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
				}
		}
	}
}
void countSort(int a[], int n)
{
	int i, idx = 0, j;
	int count[K];
	for (i = 0; i < K; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		count[a[i]] ++;
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < count[i]; j++)
			a[idx++] = i;
	}
}
void quick_split(int a[], int *i, int *j, int p)
{
	do
	{
		while (a[*i] < p)
			(*i)++;
		while (a[*j] > p)
			(*j)--;
		if (*i <= *j) {
			if (a[*i] > a[*j])
			{
				int tmp = a[*i];
				a[*i] = a[*j];
				a[*j] = tmp;
			}
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}
void quick_sort(int a[], int n1, int n2)
{
	int m;
	int i = n1; int j = n2;
	m = (n1 + n2) / 2;
	quick_split(a, &i, &j, a[m]);
	if (i < n2)
		quick_sort(a, n2, i);
	if (j > n1)
		quick_sort(a, n1, j);
}
void merge(int a[], int l, int m, int r)
{
	int i, j, s = 0;
	int *tmp = (int*)malloc(r - l + 1 * sizeof(int));
	i = l;
	j = m + 1;
	while ((i <= m) && (j <= r)) {
		if (a[i] <= a[j])
			tmp[s++] = a[i++];
		else
			tmp[s++] = a[j++];
	}
	while (i <= m)
		tmp[s++] = a[i++];
	while (j <= r)
		tmp[s++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = tmp[i - l];

}
void merge_sort(int a[], int l, int r)
{
	int m;
	if (l >= r)
		return;
	m = (l + r) / 2;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, m, r);
}
void output(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d", a[i]);
}
void main()
{
	int a[N], number, k = 0, p = 9;
	fill(a, N);
	printf("massiv: ");
	output(a, N);
	printf("\nChoose number of sort:");
	scanf("%d", &number);
	switch (number)
	{
	case 1:
		chooseSort(a, N);
		printf("Sort massiv: ");
		output(a, N);
		break;
	case 2:
		insertSort(a, N);
		printf("Sort massiv: ");
		output(a, N);
		break;
	case 3:
		bubbleSort(a, N);
		printf("Sort massiv: ");
		output(a, N);
		break;
	case 4:
		countSort(a, N);
		printf("Sort massiv: ");
		output(a, N);
		break;
	case 5:
		quick_sort(a, k, p);
		printf("Sort massiv: ");
		output(a, N);
		break;
	case 6:
		merge_sort(a, k, p, N);
		printf("Sort massiv: ");
		output(a, N);
		break;
	default:
		printf("Sort do not found");
	}
	system("pause");
}