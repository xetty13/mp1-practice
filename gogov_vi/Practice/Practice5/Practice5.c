#include <stdio.h>
#include <locale.h>
#define N 5
#define K 10

void choose(int a[], int n)
{
    int i = 0, j, min, minidx, tmp;
    for (i; i < n; i++)
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
        tmp = a[i];
        a[i] = a[minidx];
        a[minidx] = tmp;
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
            a[j] = tmp;
            j--;
        }
    }
}

void buble(int a[], int n)
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
    int count[K];
    int i, b = 0, j;
    for (i = 0; i < K; i++) 
        count[i] = 0;
    //for(i = 0; i < K; i++) printf("%d", count[i]);
    for (i = 0; i < n; i++) 
        count[a[i]]++;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            a[b] = i;
            b++;
        }
    }
}

void menu()
{
    printf("\n");
    printf("Вид сортировки:\n");
    printf("1.Сортировка выбора\n");
    printf("2.Сортировка вставками\n");
    printf("3.Пузырьковая сортировка\n");
    printf("4.Сортировка подсчета\n");
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

void print(int a[], int n)
{
    int i;
    printf("Отсортированный массив: ");
    for (i = 0; i < n; i++)
        printf("| %d ", a[i]);
    printf("|\n");
}

void main()
{
    int a[N];
    int men;
    setlocale(LC_ALL, "Russian");
    scan(a, N);
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
            buble(a, N);
            print(a, N);
            break;
        case 4:
            countingsord(a, N);
            print(a, N);
            break;
        default:
            menu();
            scanf("%d", &men);
        }
    }
}