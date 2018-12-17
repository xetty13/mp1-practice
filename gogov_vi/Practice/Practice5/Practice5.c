#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define N 50 // кол-во элементов массива    
#define BUFFER 2048 
#define MAX_FILES 1000

void swapint(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
void swaplong(ULONGLONG *n1, ULONGLONG *n2)
{
    ULONGLONG tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}


int ListDirectoryContents(const wchar_t *sDir, wchar_t **fileNames, ULONGLONG *filesize)
{
    int l = 0;
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *sPath;
    sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
        return -1;

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            fileNames[l] = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
            filesize[l] = fileSize;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(fileNames[l], L"%s", sPath);
            l++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return l;
}

void generation(int a[], int n, int min, int max)
{
    int i;
    srand((unsigned)time(0));
    for (i = 0; i < n; i++)
        a[i] = rand() % (max - min + 1) + min;
}

int* choose(ULONGLONG* a ,int n)
{
    int i, j, minidx, *newId;
    ULONGLONG min, *size;
    size = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
    newId = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        newId[i] = i;
        size[i] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        min = size[i];
        minidx = i;
        for (j = i + 1; j < n; j++)
        {
            if (size[j] < min)
            {
                min = size[j];
                minidx = j;
            }
        }
        size[minidx] = size[i];
        swapint(newId + minidx, newId + i);
        size[i] = min;
    }
    free(size);
    return newId;
}

int* insert(ULONGLONG* a, int n)
{
    int i, j, *newId;
    ULONGLONG tmp, *size;
    size = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
    newId = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        newId[i] = i;
        size[i] = a[i];
    }
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        tmp = size[i];
        while ((j >= 0) && (size[j] > tmp))
        {
            size[j + 1] = size[j];
            newId[j + 1] = newId[j];
            newId[j] = i;
            size[j] = tmp;
            j--;
        }
    }
    free(size);
    return newId;
}

int* bubble(ULONGLONG* a, int n)
{
    int i, j, *newId;
    ULONGLONG tmp, *size;
    size = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
    newId = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        newId[i] = i;
        size[i] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (size[j - 1] > size[j])
            {
                tmp = size[j];
                size[j] = size[j - 1];
                size[j - 1] = tmp;
                swapint(newId + j, newId + j - 1);
            }
        }
    }
    free(size);
    return newId;
}

int* countingsort(ULONGLONG* a, int n)
{
    int *newId;
    ULONGLONG *size, *arr, k, max = a[n - 1], min = a[0];
    int i, b = 0, j;
    newId = (int*)malloc(n * sizeof(int));
	size = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
    /*for (i = 0; i < n; i++)
    {
        newId[i] = i;
    }*/
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
	k = max + min + 1; // Разность положительное число
    arr = (ULONGLONG*)malloc(k * sizeof(ULONGLONG));
    for (i = 0; i < k; i++) 
        arr[i] = 0;
    for (i = 0; i < n; i++)
    {
        arr[a[i] - min]++;
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < arr[i]; j++)
            size[b++] = i + min;
    }
	for (j = 0; j < n; j++)
		arr[j] = a[j];
	printf("\n");
	b = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if ((size[i] == arr[j]))
			{
				newId[b] = j;
				arr[j] = -1;
				b++;
				break;
			}
	}
	for (i = 0; i < n; i++)
		printf("%d|", newId[i]);
	free(arr);
	free(size);
    return newId;
}

int* quicksort(ULONGLONG* size, int n1, int n2, int n, int* id)
{
    ULONGLONG tmp;
    int i = n1, j = n2, p = size[(n1 + n2) / 2], tmp1, k;
    do {
        while (size[i] < p) i++;
        while (size[j] > p) j--;

        if (i <= j) {
            if (size[i] > size[j])
            {
                swaplong(size + i, size + j);
                swapint(id + i, id + j);
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < n2)
        id = quicksort(size, i, n2, n, id);
    if (n1 < j)
        id = quicksort(size, n1, j, n, id);
    return id;
}


// Быстрая сортировка
int* merge(ULONGLONG* a, int l, int m, int r, int* fileId)
{
    int i, j, k = 0, c;
    int *arr;
    arr = (int*)malloc((r - l + 1) * sizeof(int));
    i = l;
    j = m + 1;
    while ((i <= m) && (j <= r))
    {
        if (a[i] < a[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = a[j++];
        }
    }
    while (i <= m)
    {
        arr[k++] = a[i++];
    }
    while (j <= r)
    {
        arr[k++] = a[j++];
    }
    for (k = l; k <= r; k++)
    {
        a[k] = arr[k - l];
    }
}

int* mergesort(ULONGLONG* a, int l, int r, int* fileId)
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    mergesort(a, l, m, fileId);
	mergesort(a, m + 1, r, fileId);
	fileId = merge(a, l, m, r, fileId);
}
// Быстрая сортировка Конец

int menu()
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

void print(ULONGLONG* filesize, wchar_t **fileNames, int count_files)
{
    int i;
    for (i = 0; i < count_files; i++)
        wprintf(L"Файл: %s Размер: %lld байт\n", fileNames[i], filesize[i]);
    printf("\n");
}

void print_newId(ULONGLONG *filesize, wchar_t **fileNames, int count_files, int* newId)
{
    int i;
    system("cls");
    printf("Отсортированный список\n");
    for (i = 0; i < count_files; i++)
        wprintf(L"Файл: %s Размер: %lld байт\n", fileNames[newId[i]], filesize[newId[i]]);
    printf("\n");
}

// Вывод Массива Конец

// Ввод пути
void entpath(wchar_t* cb, char* b, int* a)
{
    printf("Укажите путь к файлам(вместо \\ пишите /)\n");
    fgets(b, BUFFER, stdin);
    b[strlen(b) - 1] = '\0';
    swprintf(cb, BUFFER, L"%hs", b);
}

// Ввод пути конец

// C:/Program Files/Git

void main()
{
    wchar_t *path;
    wchar_t **fileNames;
    int *fileId, *newId;
    int men, i, count_files;
    char e;
    clock_t begin, end;
    double time_spent;
    char* b = (char*)malloc(BUFFER);
    wchar_t* cb = (wchar_t*)malloc(BUFFER);
    ULONGLONG *filesize = (ULONGLONG*)malloc(MAX_FILES * sizeof(ULONGLONG));
    ULONGLONG* size;
    fileNames = (wchar_t**)malloc(MAX_FILES * sizeof(wchar_t*));
    setlocale(LC_ALL, "Russian");

    while (1) {
		do {
			entpath(cb, b, filesize);
			count_files = ListDirectoryContents(cb, fileNames, filesize);
			if (count_files == -1)
			{
				printf("Неверно введен путь. Попробуйте снова\n");
			}
		} while (count_files == -1);
        size = (ULONGLONG*)malloc(count_files * sizeof(ULONGLONG));
        fileId = (int*)malloc((count_files + 1) * sizeof(int));
        for (i = 0; i < count_files; i++)
        {
            fileId[i] = i;
            size[i] = filesize[i];
        }
        printf("Файлов найдено: %d\n", count_files);
        for (i = 0; i < count_files; i++)
            wprintf(L"Файл: %s Размер: %lld байт\n", fileNames[i], filesize[i]);
        menu();
        scanf("%d", &men);
        begin = clock();
        switch (men) {
        case 1:
            scanf("%c", &e);
            newId = choose(filesize, count_files);
			print_newId(filesize, fileNames, count_files, newId);
            break;
            // Готово
        case 2:
            scanf("%c", &e);
            newId = insert(filesize, count_files);
			print_newId(filesize, fileNames, count_files, newId);
            break;
            // Готово
        case 3:
            scanf("%c", &e);
            newId = bubble(filesize, count_files);
			print_newId(filesize, fileNames, count_files, newId);
            break;
            // Готово
        case 4:
            scanf("%c", &e);
            newId = countingsort(filesize, count_files);
			print_newId(filesize, fileNames, count_files, newId);
            break;
			// Готово
        case 5:
            scanf("%c", &e);
            newId = quicksort(size, 0, count_files - 1, count_files, fileId);
			print_newId(filesize, fileNames, count_files, newId);
            break;
            // Готово
        case 6:
            scanf("%c", &e);
            newId = mergesort(size, 0, count_files - 1, fileId);
			print_newId(filesize, fileNames, count_files, newId);
            break;
        default:
            entpath(cb, b, filesize);
            menu();
            scanf("%d", &men);
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Время сортировки данных: %.5lf секунд\n", time_spent);
        printf("-----------------------------------------------------------\n");
        count_files = 0;
        free(size);
    }
}