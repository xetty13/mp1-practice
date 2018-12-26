#include <windows.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_LEN 2048
#define MAX_COUNT_OF_FILES 65535

int ListDirectoryContents(const wchar_t *sDir, wchar_t **fileName, ULONGLONG *filesSize)
{
    int j = 0;
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[2048];

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return 1;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            filesSize[j] = fileSize;
            fileName[j] = (wchar_t*)malloc(MAX_LEN * sizeof(wchar_t));
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(fileName[j++], L"%s", sPath);
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind); 
    return j;
}

void Input(wchar_t **sDir)
{
    char *inpstr;
    inpstr = (char*)malloc((MAX_LEN)* sizeof(char));
    *sDir = (wchar_t*)malloc((MAX_LEN)* sizeof(wchar_t)); 
    fgets(inpstr, MAX_LEN, stdin);
    inpstr[strlen(inpstr) - 1] = '\0';
    swprintf(*sDir, MAX_LEN, L"%hs", inpstr);
}

void Output(wchar_t **filesName, ULONGLONG *filesSize, int *filesIndex, int kolvo)
{
    int i;
    for (i = 0; i < kolvo; i++)
    {
        wprintf(L"File: %s size: %lld \n", filesName[filesIndex[i]], *(filesSize + filesIndex[i]));
    }
}

void Choose_sort(ULONGLONG *tmpSize, int *filesIndex, int kolvo)
{
    int i, j, tmp, ind;
    for (i = 0; i < kolvo - 1; i++)
    {
        ind = i;
        for (j = i + 1; j < kolvo; j++)
        {
            if (tmpSize[filesIndex[ind]] > tmpSize[filesIndex[j]])
                ind = j; 
        }
        tmp = filesIndex[ind];
        filesIndex[ind] = filesIndex[i];
        filesIndex[i] = tmp;
    }
}
void Insert_sort(ULONGLONG *tmpSize, int *filesIndex, int kolvo)
{
	int i, j, tmp;
    for (i = 1; i < kolvo; i++)
    {
        tmp = filesIndex[i];
        j = i - 1;
        while ((j >= 0) && (tmpSize[filesIndex[j]] > tmpSize[tmp]))
        {
            filesIndex[j + 1] = filesIndex[j];
            filesIndex[j] = tmp;
            j--;
        }
    }
}
void Bubble_sort(ULONGLONG *tmpSize, int *filesIndex, int kolvo)
{
	int i, j, tmp;
    for (i = 0; i < kolvo; i++)
    {
        for (j = 1; j < kolvo - i; j++)
        {
            if (tmpSize[filesIndex[j]] < tmpSize[filesIndex[j - 1]])
            {
                tmp = filesIndex[j];
                filesIndex[j] = filesIndex[j - 1];
                filesIndex[j - 1] = tmp;
            }
        }
    }
}
void Counting_sort(ULONGLONG *tmpSize, int *filesIndex, int kolvo)
{
	int *count = (int*)malloc(MAX_COUNT_OF_FILES * sizeof(int));
    int i, j, idx = 0, h = 0;
    for (i = 0; i < MAX_COUNT_OF_FILES; i++)
        count[i] = 0;
    for (i = 0; i < kolvo; i++)
    {
        if (tmpSize[filesIndex[i]] > MAX_COUNT_OF_FILES)
        {
            printf("File size too large\n"); 
            return;
        }
        count[tmpSize[filesIndex[i]]]++;
    }
    for (i = 0; i < MAX_COUNT_OF_FILES; i++)
    {
        if (count[i]>0)
        {
            h = 0;
            for (j = 0; j < count[i]; j++)
            {
                while (tmpSize[h] != i)
                    h++;
                filesIndex[idx++] = h++;
            }
        }
    }
    free(count);
}
void Merge(int *filesIndex, ULONGLONG *tmpSize, int ind1, int mid, int ind2) 
{
    int i, j = mid + 1, h, tmp;
    for (i = ind1; ((i < ind2) && (j <= ind2)); i++)
    {
        if (tmpSize[filesIndex[i]] > tmpSize[filesIndex[j]])
        {
            tmp = filesIndex[j];
            for (h = j; h > i; h--)
                filesIndex[h] = filesIndex[h - 1];
            filesIndex[i] = tmp;
            j++;
        }
    }  
}

void Merge_sort(ULONGLONG *tmpSize, int *filesIndex, int ind1, int ind2)
{
    int mid;
    if (ind1 >= ind2) return;
    mid = (ind1 + ind2) / 2;
    Merge_sort(filesIndex, tmpSize, ind1, mid);
    Merge_sort(filesIndex, tmpSize, mid + 1, ind2);
    Merge(filesIndex, tmpSize, ind1, mid, ind2);
}
void Quicksplit(int *filesIndex, ULONGLONG *tmpSize, int *i, int *j, ULONGLONG opora)
{
    int tmp;
    do {
        while (tmpSize[filesIndex[(*i)]] < opora)
            (*i)++; 
        while (tmpSize[filesIndex[(*j)]] > opora)
            (*j)--; 
        if ((*i) <= (*j))
        {
            tmp = filesIndex[(*i)];
            filesIndex[(*i)] = filesIndex[(*j)];
            filesIndex[(*j)] = tmp;
            (*i)++;
            (*j)--;
        } 
    } while ((*i) < (*j));
}
void Quick_sort(ULONGLONG *tmpSize, int *filesIndex, int ind1, int ind2)
{
    int mid = (ind1 + ind2) / 2;
    int i = ind1, j = ind2;
    Quicksplit(filesIndex, tmpSize, &i, &j, tmpSize[filesIndex[mid]]);
    if (j > ind1)
        Quick_sort(filesIndex, tmpSize, ind1, j);
    if (i < ind2)
        Quick_sort(filesIndex, tmpSize, i, ind2); 
}
int main()
{
    wchar_t  **fileName;
    wchar_t *path;
    ULONGLONG *filesSize, *tmpSizes;
    clock_t start, end;
    int *filesIndex;
    unsigned long inpstr;
    int  vybor, i = 0, kolvo = -1;
    float sorttime = 0.0f;
    printf("Input path\n");

    filesSize = (ULONGLONG*)malloc(MAX_LEN * sizeof(ULONGLONG)); 
	fileName = (wchar_t**)malloc((MAX_LEN)* sizeof(wchar_t*));

    while (kolvo == -1)
    {
        Input(&path);
        kolvo = ListDirectoryContents(path, fileName, filesSize);
    }
    filesIndex = (int*)malloc(kolvo * sizeof(int));
    for (i = 0; i < kolvo; i++)
        filesIndex[i] = i;
    Output(fileName, filesSize, filesIndex, kolvo);                   

    tmpSizes = (ULONGLONG*)malloc(kolvo * sizeof(ULONGLONG));           
    for (i = 0; i < kolvo; i++)                                         
        tmpSizes[i] = filesSize[i]; 
	free(filesSize);
do {
    printf("---Select sort--- \n1. Choose sort \n2. Insert sort \n3. Bubble sort \n4. Counting sort \n5. Merge sort \n6. Quick sort\n");
    printf("To exit the program, click escape ");
    scanf("%d", &vybor);
	for (i = 0; i < kolvo; i++)
		filesIndex[i] = i;
    start = clock();

    switch (vybor)
    {
    case 1:
        Choose_sort(tmpSizes, filesIndex, kolvo);
        break;
    case 2:
        Insert_sort(tmpSizes, filesIndex, kolvo);
        break;
    case 3:
        Bubble_sort(tmpSizes, filesIndex, kolvo);
        break;
    case 4:
        Counting_sort(tmpSizes, filesIndex, kolvo);
        break;
    case 5:
        Merge_sort(tmpSizes, filesIndex, 0, (kolvo - 1));
        break;
    case 6:
        Quick_sort(tmpSizes, filesIndex, 0, (kolvo - 1));
        break;
	}
        end = clock();

        sorttime = (float)(end - start) / CLOCKS_PER_SEC;
        printf("Time of sorting: %.4lf s\n", sorttime);
		if (kolvo > 0)
        Output(fileName,  tmpSizes, filesIndex,  kolvo);

    } while (vybor < 1 || vybor > 6); 
    
    free(tmpSizes);
	free(filesIndex);
}
