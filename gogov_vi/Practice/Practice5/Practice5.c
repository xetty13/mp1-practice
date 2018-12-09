#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define K 10

void generation(int a[], int n, int min, int max)
{
	int i;
	srand((unsigned)time(0));
	for (i = 0; i < n; i++)
		a[i] = rand() % (max - min + 1) + min;
}

void choose(int a[], int n)
{
    int i, j, min, minidx;
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

void insert(int a[], int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        tmp = a[i];
        while ((j >= 0) && (a[j] > tmp))
        {
            a[j + 1] = a[j];
            a[j--] = tmp;
        }
    }
}

void bubble(int a[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

void countingsord(int a[], int n)
{
	int *arr;
	int i, b = 0, j, max = a[N], min = a[0], k;
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	k = abs(max - min) + 1;
	arr = (int*)malloc(k * sizeof(int));
    for (i = 0; i < k; i++) 
        arr[i] = 0;
    for (i = 0; i < n; i++) 
        arr[a[i] - min]++;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < arr[i]; j++)
            a[b++] = i + min;
    }
}

void menu()
{
    printf("\n");
    printf("Вид сортировки:\n");
    printf("1.Сортировка выбором\n");
    printf("2.Сортировка вставками\n");
    printf("3.Пузырьковая сортировка\n");
    printf("4.Сортировка подсчета\n");
	printf("5.Быстрая сортировка\n");
	printf("6.Сортировка слиянием\n");
    printf("Выберите способ сортировки: ");
}

void scan(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Введите %d элемент массива: ", i);
        scanf("%d", &(a[i]));
    }
}

// Вывод Массива

void print(int a[], int n)
{
    int i;
    printf("Отсортированный массив: ");
    for (i = 0; i < n; i++)
        printf("| %d ", a[i]);
    printf("|\n");
}

// Вывод Массива Конец

// Быстрая сортировка
/*
void quicksplit(int a[], int *i, int *j, int p)
{
	int tmp;
	printf("i = %d a[i] = %d j = %d a[j] = %d p = %d\n", *i, a[*i], *j , a[*j], p);
	do
	{
		while (a[*i] < p) {
			printf("i++\n");
			(*i)++;
		}
		printf("a[i] = %d i = %d\n", a[*i], *i);
		while (a[*j] > p) {
			printf("j--\n");
			(*j)--;
		}
		printf("a[j] = %d j = %d\n", a[*j], *j);
		if (*i <= *j)
		{
			if (a[*i] > a[*j]) {
				tmp = a[*i];
				a[*i] = a[*j];
				a[*j] = tmp;
				i++;
				j--;
			}
		}
	} while (*i <= *j);
	printf("%d %d\n", a[*i], a[*j]);
	print(a, N);
	
}

void quicksort(int a[], int n1, int n2)
{
	int pidx = (n1 + n2) / 2;
	int i = n1, j = n2;
	quicksplit(a, &i, &j, a[pidx]);
	if (j > n1) 
		quicksort(a, n1, j);
	if (i < n2) 
		quicksort(a, i, n2);
}
*/
void qs(int a[], int n1, int n2)
{
	int i = n1, j = n2, x = a[(n1 + n2) / 2];
	int tmp;
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;

		if (i <= j) {
			if (a[i] > a[j]) 
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < n2)
		qs(a, i, n2);
	if (n1 < j)
		qs(a, n1, j);
}
// Быстрая сортировка конец

// Сортировка слиянием 
void merge(int a[], int l, int m, int r)
{
	int i, j, s = 0, k , *arr;
	arr = (int*)malloc(r * sizeof(int));
	i = l; 
	j = m + 1;
	for (k = 0; k < r - l + 1; k++) 
	{
		if ((j > r) || ((i <= m) && (a[i] < a[j])))
		{
			arr[k] = a[i];
			printf("IF %d I = %d J = %d R = %d\n", arr[k], i, j, r);
			i++;
		}
		else
		{
			arr[k] = a[j];
			printf("EL %d I = %d J = %d R = %d\n", arr[k], i, j, r);
			j++;
		}
	}
	for (int k = 0; k < r - l + 1; k++)
		a[l + k] = arr[k];
	free(arr);
}

void mergesort(int a[], int l, int r)
{
	int m;
	if (l >= r) return;
	m = (l + r) / 2;
	mergesort(a, l, m);
	mergesort(a, m + 1, r);
	merge(a, l, m, r);
}
// Сортировка слиянием конец

void main()
{
	int a[N];
    int men;
    setlocale(LC_ALL, "Russian");
	generation(a, N, 0, 100);
	print(a, N);
    while (1) {
        menu();
        scanf("%d", &men);
        switch (men) {
        case 1:
            choose(a, N);
            print(a, N);
            break;
        case 2:
            insert(a, N);
            print(a, N);
            break;
        case 3:
            bubble(a, N);
            print(a, N);
            break;
        case 4:
            countingsord(a, N);
            print(a, N);
            break;
		case 5:
			qs(a, 0, N - 1);
			print(a, N);
			break;
		case 6:
			mergesort(a, 0, N - 1);
			print(a, N);
			break;
        default:
            menu();
            scanf("%d", &men);
        }
    }
}