#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define BUFFER 2048
#define FMAX 1000
#define MAX_SIZE 10000
void Input_path(wchar_t **sDir)                                       
{
    char *path;
    *sDir = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
    path = (char*)malloc(BUFFER * sizeof(char));
    printf ("Enter the path to the directory\n");
    fgets (path, BUFFER, stdin);
    path[strlen(path) - 1] = '\0';                    
    swprintf (*sDir, BUFFER, L"%hs", path);
}
int List_Directory_Contents(const wchar_t *sDir, wchar_t **fName, ULONGLONG *fSize)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *sPath;
    unsigned long i = 0;
    sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s].\n Try again: ", sDir);
        return -1;
    }
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            fSize[i] = fileSize;
            fName[i] = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
            wsprintf(fName[i++], L"%s\\%s", sDir, fdFile.cFileName);
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return i;
}
void Output_Directory(wchar_t **fName, ULONGLONG *fSize, unsigned long *ind, unsigned long n)
{
    unsigned long i;
    printf("\n List Directory Contents:\n");
    printf("\n");
    if (n == 0)
        printf ("Empty directory\n");
    for (i = 0; i < n; i++)
        wprintf(L" File: %s Size: %lld bytes\n", fName[ind[i]], fSize[ind[i]]);
}
void Menu()
{
    printf("\n");
    printf ("Menu\n");
    printf ("Enter a number to select a command\n");
    printf("\n");
    printf("1 - Selection sort\n");
    printf("2 - Insertion sort\n");
    printf("3 - Bubble sort\n");
    printf("4 - Counting sort\n");
    printf("5 - Quick sort\n");
    printf("6 - Merge sort\n");
    printf("7 - Exit the program\n");
}
void Selection_sort(ULONGLONG *a, unsigned long *b, int n)
{
    int i = 0, j, minind, tmp;
    for (i; i < n; i++)
    {
        minind = i;
        for (j = i + 1; j < n; j++)
            if (a[b[j]] < a[b[minind]])
                minind = j;
        tmp = b[minind];
        b[minind] = b[i];
        b[i] = tmp;
    }
}
void Insertion_sort(ULONGLONG *a, unsigned long *b, int n)
{
    int i = 1, j, tmp;
    for (i; i < n; i++)
    {
        j = i - 1;
        tmp = b[i];
        while ((j >= 0) && (a[b[j]] > a[tmp]))
        {
            b[j + 1] = b[j];
            b[j--] = tmp;
        }
    }
}
void Bubble_sort(ULONGLONG *a, unsigned long *b, int n)
{
    int i = 0, j, tmp;
    for (i; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
            if (a[b[j - 1]] > a[b[j]])
            {
                tmp = b[j];
                b[j] = b[j - 1];
                b[j - 1] = tmp;
            }
    }
}
int Counting_sort (ULONGLONG *a, unsigned long *b, int n)
{
    int *count = (int*)malloc(MAX_SIZE * sizeof(int));
    int i = 0, j, ind = 0, h;
    for (i; i < MAX_SIZE; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        if (a[i] <= MAX_SIZE)
            count[a[b[i]]]++;
        else
        {
            printf ("File size too large\n");
            return 1;
        }
    for (i = 0; i < MAX_SIZE; i++)
        if (count[i] > 0)
        {
            h = 0;
            for (j = 0; j < count[i]; j++)
            {
                while (a[h] != i)
                    h++;
                b[ind++] = h++;
            }
        }
        free (count);
        return 0;
}
void Quick_sort (ULONGLONG *a, unsigned long *b, int left, int right)
{
    int i = left, j = right, x = a[b[(left + right) / 2]], tmp;
    do {
        while (a[b[i]] < x) i++;
        while (a[b[j]] > x) j--;
        if(i <= j)
        {
            if (a[b[i]] > a[b[j]]) 
            {
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
            i++;
            j--;
        }
    }while (i <= j);
    if (i < right)
        Quick_sort(a, b, i, right);
    if (left < j)
        Quick_sort(a, b, left, j);
}
void Merge(ULONGLONG *a, unsigned long *b, int left, int mid, int right) 
{
    int i, j = mid + 1, h, tmp;
    for (i = left; ((i < right) && (j <= right)); i++)
    {
        if (a[b[i]] > a[b[j]])
        {
            tmp = b[j];
            for (h = j; h > i; h--)
                b[h] = b[h - 1];
            b[i] = tmp;
            j++;
        }
    }
    
}
void Merge_sort(ULONGLONG *a, unsigned long *b, int left, int right)
{
    int mid;
    if (left >= right) return;
    mid = (left + right) / 2;
    Merge_sort(a, b, left, mid);
    Merge_sort(a, b, mid + 1, right);
    Merge(a, b, left, mid, right);
}
void main()
{
    clock_t start, end;
    float time = 0.0f;
    int f = 0;
    unsigned long *ind;
    wchar_t *path, **fName;
    ULONGLONG *fSize;
    unsigned long i = 0, count = -1, mode;
    fName = (wchar_t**)malloc(FMAX * sizeof(wchar_t*));
    fSize = (ULONGLONG*)malloc(FMAX * sizeof(ULONGLONG));
    printf ("          File Manager\n");
    printf ("\n");
    while (count == -1)
    {
        Input_path(&path);
        count = List_Directory_Contents(path, fName, fSize);
    }
    ind = (unsigned long*)malloc(count * sizeof(unsigned long));
    for (i; i < count; i++)
        ind[i] = i;
    Output_Directory(fName, fSize, ind, count);
    Menu();
    do
    {
        f = 0;
        do
        {
            scanf ("%d", &mode);
        }while ((mode != 1) && (mode != 2) && (mode != 3) && (mode != 4) && (mode != 5) && (mode != 6) && (mode != 7) && (mode != 8));
        switch (mode)
        {
    case 1:
        start = clock();
        Selection_sort (fSize, ind, count);
        end = clock();
        break;
    case 2:
        start = clock();
        Insertion_sort (fSize, ind, count);
        end = clock();
        break;
    case 3:
        start = clock();
        Bubble_sort (fSize, ind, count);
        end = clock();
        break;
    case 4:
        start = clock();
        f = Counting_sort (fSize, ind, count);
        end = clock();
        break;
    case 5:
        start = clock();
        Quick_sort (fSize, ind, 0, count - 1);
        end = clock();
        break;
    case 6:
        start = clock();
        Merge_sort (fSize, ind, 0, count - 1);
        end = clock();
        }
        time = (double)(end - start) / CLOCKS_PER_SEC;
        if (f == 0)
        {
            Output_Directory(fName, fSize, ind, count);
            printf("\n Time: %.6lf sec.\n", time);
        }
        for (i = 0; i < count; i++)         
            ind[i] = i;
        start = end = 0;
    } while (mode != 7);
    free(fName);
    free(fSize);
    free(ind);
}
