#include <stdio.h>

void pick(int a[], int n)
{
	int i = 0;
	int t, j, min, minidx;
	for (; i < n; i++)
	{
		int min = a[i];
		int minidx = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				minidx = j;
			}
			t = a[i];
			a[i] = a[minidx];
			a[minidx] = t;
		}
	}
}

void paste(int a[], int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		j = i - 1;;
		tmp = a[i];
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j+1] = a[j];
			a[j] = tmp;
			j--;
		}
	}
}

void main()
{
	int i;
	int b[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &b[i]);
	}
	paste(b, 5);
	for (i = 0; i < 5; i++)
	{
		printf("%d", b[i]);
	}

}