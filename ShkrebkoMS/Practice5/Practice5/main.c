#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubble_sort(int* arr, int n);
void merge(int* arr, int left, int mid, int right, int N);
void mergeSort(int* arr, int left, int right, int N);
void qSort(int* arr, int N);

int main()
{
	int N,i;
	int* arr;
	scanf_s("%d", &N);
	arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d", arr + i);
	}
	mergeSort(arr,0, N-1, N);
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


void bubble_sort(int* arr, int n)
{
	int i, j, tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void merge(int* arr, int left, int mid, int right, int N)
{
	int i=0, i1 = 0, i2 = 0;
	int* b = (int*)malloc(sizeof(int) * (N-left));
	while ((left + i1 < mid) && (mid + i2 <= right))
	{
		if (arr[left + i1] < arr[mid + i2])
		{
			b[i1+i2] = arr[left + i1];
			i1++;
		}
		else
		{
			b[i1+i2] = arr[mid + i2];
			i2++;
		}
	}
	while (left + i1 < mid)
	{
		b[i1+i2] = arr[left + i1];
		i1++;
	}
	while (mid + i2 < right)
	{
		b[i1+i2] = arr[mid + i2];
		
		i2++;
	}
	for (i = 0; i < (i1 + i2); i++)
	{
		arr[left + i] = b[i];
	}
	
}

void mergeSort(int* arr, int left, int right, int N)
{
	int mid ;
	if (left+1 >= right)
		return;
	mid = (left + right) / 2;
	mergeSort(arr, left, mid, N);
	mergeSort(arr, mid, right, N);
	merge(arr, left, mid, right, N);
}


//void mergeSort(int* arr, int left, int right, int N)
//{
//	int mid;
//	mid = (left + right) / 2;
//	if (left == right)
//	{
//		return;
//	}
//
//	mergeSort(arr, left, mid, N);
//	mergeSort(arr, mid + 1, right, N);
//	merge(arr, left, mid, right, N);
//}
//
//
//void merge(int* arr, int left, int mid, int right, int N)
//{
//	int i, j, k;
//	
//	i = left;
//	j = mid + 1;
//	int* m_arr = (int*)malloc(sizeof(int) * N);
//	for (k = left; k < right; k++)
//	{
//		if ((i < mid) && (j < right))
//			if (arr[i] <= arr[j])
//				m_arr[k] = arr[i++];
//			else
//				m_arr[k] = arr[j++];
//		else
//			if (i == mid)
//				m_arr[k] = arr[j++];
//			else
//				m_arr[k] = arr[i++];
//	}
//	for (i = left; i <= right; i++)
//	{
//		arr[i] = m_arr[i];
//	}
//	free(m_arr);
//}


void qSort(int* arr, int N)

{
	int i = 0, j = N - 1, tmp;
	int pivot = arr[(N - 1) / 2];
	do
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}

	} while (i <= j);
	if (j > 0)
		qSort(arr, j);
	if (i < N - 1)
		qSort(arr + i, N - i);

}