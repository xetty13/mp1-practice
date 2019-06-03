#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#define BUFFER 1000 //Размер буффера
#define c 1500

void input(wchar_t **path)
{
    char *str;

    *path = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
    str = (char*)malloc(BUFFER * sizeof(char));
    printf("\n  Please, enter the path:  ");
    fgets(str, BUFFER, stdin); 
    str[strlen(str) - 1] = '\0'; //Удаление перевода строки в конце
    swprintf(*path, BUFFER, L"%hs", str); //Преобразовываем строку char  в wchar_t 
}

int ListDirectoryContetns(const wchar_t *sDir, wchar_t ***fNames, ULONGLONG **fSizes)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    int i = 0;
    wchar_t *sPath;
    sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));

    wsprintf(sPath, L"%s\\*.*", sDir);

    //Проверка на существование директории
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
        return -1; 

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
            i++;
    } while (FindNextFile(hFind, &fdFile));

    hFind = FindFirstFile(sPath, &fdFile);
    *fNames = (wchar_t**)malloc(i * sizeof(wchar_t*));
    *fSizes = (ULONGLONG*)malloc(i * sizeof(ULONGLONG));
    i = 0;

    do
    {
        //Найденный первый файл будет возвращать "."
        // Последующие файлы будут возвращать ".."
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fSize = fdFile.nFileSizeHigh;
            fSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fSize |= fdFile.nFileSizeLow;

            (*fNames)[i] = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
            (*fSizes)[i] = fSize;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf((*fNames)[i], L"%s", sPath);
            i++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    free(sPath);
    return i;
}

void choose_method(int *method)
{
    printf("\n  Choose a sorting\n");
    printf("  1) Choose sorting\n");
    printf("  2) Insert sorting\n");
    printf("  3) Bubble sorting\n");
    printf("  4) Count sorting\n");
    printf("  5) Quick sorting\n");
    printf("  6) Merge sorting\n\n");
    do
    {
        printf("  Method: ");
        scanf("%d", method);
        printf("\n");
    } while ((*method < 1) && (*method > 6));
}

void output(int *ind, int count_files, wchar_t **fNames, ULONGLONG *size)
{
    int i;
    WIN32_FIND_DATA fdFile;
    for (i = 0; i < count_files; i++)
        wprintf(L"  %s\t  %.0llf кб \n", fNames[ind[i]], ceil((float)(*(size + ind[i]) / 1024.0)));
    printf("\n\n");
}

void choose_sort(int count_files, ULONGLONG *size, int *ind)
{
    int i = 0, j = 0, k = 0, t = 0;
    ULONGLONG min;

    for (i = 0; i < count_files - 1; i++)
    {
        k = i;
        for (j = i + 1; j < count_files; j++)
            if (size[ind[k]] > size[ind[j]])
            {
                k = j;
            }
        t = ind[k];
        ind[k] = ind[i];
        ind[i] = t;
    }
}

void insert_sort(ULONGLONG *size, int count_files, int *ind)
{
    int k, i, j;
    for (i = 1; i < count_files; i++)
    {
        k = ind[i];
        j = i - 1;
        while((j >= 0) && (size[ind[j]] > size[k]))
        {
            ind[j + 1] = ind[j];
            ind[j] = k;
            j--;
        }
    }
}

void bubble_sort(ULONGLONG *size, int count_files, int *ind)
{
    int i, j, k;
    for (i = 0; i < count_files; i++)
    {
        for (j = 1; j < count_files - i; j++)
        {
            if (size[ind[j]] < size[ind[j - 1]])
            {
                k = ind[j];
                ind[j] = ind[j - 1];
                ind[j - 1] = k;
            }
        }
    }

}

int count_sort(ULONGLONG *size, int count_files, int *ind)
{
    int *count = (int*)malloc(c * sizeof(int));
    int i, j, id = 0, idel = 0;
    int del = 0, min, max, pos = 0;

    min = size[0];
    max = size[0];

    for (i = 0; i < count_files; i++)
    {
        if ((size[i]) < min)
            min = size[i];
        if ((size[i]) > max)
            max = size[i];
    }
    del = max - min + 1;
    idel = (int)del;
    for (i = 0; i < count_files; i++)
    if (size[i] > c)
        return -1;

    for (i = 0; i < idel; i++)
    {
        if (count[i]>0)
        {
            pos = 0;
            for (j = 0; j < count[i]; j++)
            {
                while (size[pos] != i)
                    pos++;
                ind[id] = pos;
                pos++;
                id++;
            }
        }
    }

    free(count);
}

void quick_split(int *ind, ULONGLONG *size, int *i, int *j, ULONGLONG p)
{
    int tmp;
    do {
        while (size[ind[(*i)]] < p)
            (*i)++;
        while (size[ind[(*j)]] > p)
            (*j)--;
        if ((*i) <= (*j))
        {
            tmp = ind[(*i)];
            ind[(*i)] = ind[(*j)];
            ind[(*j)] = tmp;
            (*i)++;
            (*j)--;
        }
    } while ((*i) < (*j));
}

void quick_sort(ULONGLONG *size, int *ind, int n1, int n2)
{
    int mid = (n1 + n2) / 2;
    int i = n1, j = n2;
    quick_split(ind, size, &i, &j, size[ind[mid]]);
    if (j > n1)
        quick_sort(size, ind, n1, j);
    if (i < n2)
        quick_sort(size, ind, i, n2);
}

void merge(ULONGLONG *size, int lb, int mid, int ub, int *ind)
{
    int i, j = mid + 1;
    int pos, tmp;
    for (i = lb; ((i < ub) && (j <= ub)); i++)
    {
        if (size[ind[i]] > size[ind[j]])
        {
            tmp = ind[j];
            for (pos = j; pos > i; pos--)
                ind[pos] = ind[pos - 1];
            ind[i] = tmp;
            j++;
        }
    }
}

void merge_sort(ULONGLONG *size, int lb, int ub, int *ind)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        merge_sort(size, lb, mid, ind);
        merge_sort(size, mid + 1, ub, ind);
        merge(size, lb, mid, ub, ind);
    }
}

void main()
{
    int ans = 0;
    wchar_t *path;
    wchar_t **fNames;
    ULONGLONG *fSizes;
    int count_files = 0;
    int method, i = 0;
    int *ind = NULL;
    clock_t begin, end;
    float time_spent = 0;
    setlocale(LC_ALL, "Russian");

    fNames = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
    fSizes = (ULONGLONG*)malloc(MAX_PATH * sizeof(ULONGLONG));

    printf("  +------------------------------------+\n");
    printf("  |\t      -FILE MANAGER-           |\n");
    printf("  +------------------------------------+\n");

    do
    {
        //Ввод пути с клавиатуры
        input(&path);
        count_files = ListDirectoryContetns(path, &fNames, &fSizes);

        if (count_files == -1)
        {
            printf("  Path not found");
            continue;
        }
        if (count_files == 0)
        {
            printf("  Folder is empty");
            continue;
        }

        printf("  Files found:  %d\n\n", count_files);

        ind = (int*)malloc(count_files * sizeof(int));
        i = 0;
        while (i != count_files)
        {
            ind[i] = i;
            i++;
        }

        choose_method(&method);

        switch (method)
        {
        case(1):
        {
            getchar();
            begin = clock();
            choose_sort(count_files, fSizes, ind);
            end = clock();
            output(ind, count_files, fNames, fSizes);
            break;
        }
        case(2):
        {
            getchar();
            begin = clock();
            insert_sort(fSizes, count_files, ind);
            end = clock();
            output(ind, count_files, fNames, fSizes);
            break;
        }
        case(3):
        {
            getchar();
            begin = clock();
            bubble_sort(fSizes, count_files, ind);
            end = clock();
            output(ind, count_files, fNames, fSizes);
            break;
        }
        case(4):
        {
            getchar();
            begin = clock();
            ans = count_sort(fSizes, count_files, ind);
            end = clock();
            if (ans == -1)
            {
                printf("  File sizes are too large for this sort, please choose another sort\n");
                break;
            }
            output(ind, count_files, fNames, fSizes);
            break;
        }
        case(5):
        {
            getchar();
            begin = clock();
            quick_sort(fSizes, ind, 0, count_files - 1);
            end = clock();
            output(ind, count_files, fNames, fSizes);
            break;
        }
        case(6):
        {
            getchar();
            begin = clock();
            merge_sort(fSizes, 0, count_files - 1, ind);
            end = clock();
            output(ind, count_files, fNames, fSizes);
            break;
        }
        }
        time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
        printf("  Sorting time: %.3f cek\n", time_spent);

        //getchar();
        free(ind);
        for (i = 0; i < count_files; i++)
            free(fNames[i]);
        free(fNames);
        free(fSizes);
    } while (1);
}