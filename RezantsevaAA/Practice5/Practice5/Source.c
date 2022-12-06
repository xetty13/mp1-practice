#define _CRT_SECURE_NO_WARNINGS
//#include <windows.h>
#include <stdio.h>
//#define N 10
void scan(int* a);
void output(int* a);
void QuikSort(int* a);
void BubbleSort(int* a);
void InsertSort(int* a);
int main()
{
	long N = 10;
	int arr[10];
	int mode;
	scan(arr, N);
	printf(" Choose sorting method: 1 - quik sort, 2 - baubble sort, 3 - insertion sort ");
	scanf("%d", &mode);
	switch (mode)
	{

	case 1:
	{
		QuikSort(arr,N);
		output(arr, N);
		break;
	}
	case 2:
	{
		BubbleSort(arr, N);
		output(arr, N);
		break;
	}
	case 3:
	{
		InsertSort(arr, N);
		output(arr, N);
		break;
	}
	}

}
void scan(int* a, long N)
{
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &(a[i]));
	}
}
void output(int* a, long N)
{
	for (int i = 0; i < N; i++)
	{
		printf(" %d", a[i]);
	}
}
void QuikSort(int* a, long N)
{
	int tmp, i = 0, j = N - 1, mid = (i + j) / 2;
	int pivot = a[mid];
	while (i <= j)
	{
		while (a[i] < pivot)
		{
			i++;
		}
		while (a[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if (j > 0)
	{
		QuikSort(a, j + 1);
	}
	if (i < N - 1)
	{
		QuikSort(a + i, N - i - 1);
	}
}
void BubbleSort(int* a, long N)
{
	int i, j, tmp;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			if (a[j + 1] < a[j])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}
void InsertSort(int* a, long N)
{
	int i, j, tmp;
	for (i = 0; i < N; i++)
	{
		tmp = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}