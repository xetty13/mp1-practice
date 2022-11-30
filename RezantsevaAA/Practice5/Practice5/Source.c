#define _CRT_SECURE_NO_WARNINGS
//#include <windows.h>
#include <stdio.h>
#define N 10
void scan(float* a);
void output(float* a);
void QuikSort(float* a);
void BubbleSort(float* a);
void InsertSort(float* a);
int main()
{
	float arr[N];
	int mode;
	scan(arr);
	printf(" Choose sorting method: 1 - quik sort, 2 - baubble sort, 3 - insertion sort ");
	scanf("%d", &mode);
	switch (mode)
	{

	case 1:
	{
		QuikSort(arr);
		output(arr);
		break;
	}
	case 2:
	{
		BubbleSort(arr);
		output(arr);
		break;
	}
	case 3:
	{
		InsertSort(arr);
		output(arr);
		break;
	}
	}

}
void scan(float* a)
{
	for (int i = 0; i < N; i++)
	{
		scanf(" %f", &(a[i]));
	}
}
void output(float* a)
{
	for (int i = 0; i < N; i++)
	{
		printf(" %d", a[i]);
	}
}
void QuikSort(float* a)
{
	int tmp, i = 0, j = N - 1, mid = (i + j) / 2;
	float pivot = a[mid];
	while (i > j)
	{
		while (a[i] < pivot)
		{
			i++;
		}
		while (a[j] > pivot)
		{
			j++;
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
		QuikSort(a, j);
	}
	if (i < N - 1)
	{
		QuikSort(a + i, N - 1 - i);
	}
}
void BubbleSort(float* a)
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
void InsertSort(float* a)
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
		a[j] = tmp;
	}
}