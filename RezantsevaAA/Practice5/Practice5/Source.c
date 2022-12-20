#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <profileapi.h>
#include <malloc.h>

#define MAX_PATH_LEN 100
char* getPath();
void getFiles(char* path, struct file* files);
int getCountOfFiles(char* path);
int* getlensFileNames(char* path, int count_files);

void QuickSort(struct file* files, int size);
void BubbleSort(struct file* files, int len);
void InsertSort(struct file* files, int len);

void print_files(struct file* files, int len);
struct file* cpy_arr(struct file* files, int len, int* lensNames);
void sortFiles(struct file* files, int len, int* lensNames);

struct file
{
    char* name;
    int size;
};

int main()
=======
#include<tchar.h>
#include<strsafe.h>
#include<time.h>
int size = 0;
void QuickSort(WIN32_FIND_DATA arr[], int left, int right);
void BubbleSort(WIN32_FIND_DATA arr[]);
void InsertSort(WIN32_FIND_DATA arr[]);
int main() {
	int left = 0;
	int right = size - 1;
	TCHAR path[100];
	StringCbGets(path, 100);
	_tprintf(TEXT("\nTarget directory is %s\n\n"), path);
	WIN32_FIND_DATA ffd;
	TCHAR szDir[MAX_PATH];
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;
	printf_s("Please: Enter the path: ");
	StringCchCopy(szDir, MAX_PATH, path);
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));
	hFind = FindFirstFile(szDir, &ffd);
	if (INVALID_HANDLE_VALUE == hFind)
	{
		printf("Error in FindFirstFile\n");
		return -1;
	}
	WIN32_FIND_DATA arr[200];
	WIN32_FIND_DATA a[200];
	printf_s("There is your files:\n");
	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			_tprintf(TEXT(" %s <DIR>\n"), ffd.cFileName);
		}
		else
		{
			_tprintf(TEXT(" %s %ld bytes\n"), ffd.cFileName, ffd.nFileSizeLow);
			a[size++] = ffd;
		}
	} while (FindNextFile(hFind, &ffd) != 0);
	int choose;
	while (TRUE)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] = a[i];
		}
		choose = 0;
		printf("Choose sort:\n1-InsertionSort\n2-QuickSort\n3-BubbleSort\n");
		do {
			printf("Input correct data:");
			scanf_s("%d", &choose);
		} while (choose > 2 || choose < 1);
		long double time_spent = 0.0;
		clock_t begin;
		clock_t end;
		switch (choose)
		{
		case 1:
			begin = clock();
			InsertSort(arr);
			end = clock();
			time_spent += (long double)(end - begin) / CLOCKS_PER_SEC;
			printf(" InsertSort took %.20llf seconds \n", time_spent);
			break;
		case 2:
			begin = clock();
			QuickSort(arr,left,right);
			end = clock();
			time_spent += (long double)(end - begin) / CLOCKS_PER_SEC;
			printf("QuickSort took %.20llf seconds \n", time_spent);
			break;
		case 3:
			begin = clock();
			BubbleSort(arr);
			end = clock();
			time_spent += (long double)(end - begin) / CLOCKS_PER_SEC;
			printf("BubbleSort took %.20llf seconds\n", time_spent);
			break;
		}
		for (int i = 0; i < size; ++i)
		{
			_tprintf(TEXT(" %s %ld bytes\n"), arr[i].cFileName, arr[i].nFileSizeLow);
		}
		getchar();
		printf("Do you want to choose sort? 1-Yes 2-No\n");
		int kk;
		scanf_s("%d", &kk);
		if (kk == 2)
			return 0;
	}
	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES)
	{
		printf("GetLastError\n");
		return -1;
	}
	FindClose(hFind);
}
void QuickSort(WIN32_FIND_DATA arr[], int left, int right) {
	int i = left;
	int j = right;
	WIN32_FIND_DATA pivot = arr[left + (rand() % (right - left))];
	WIN32_FIND_DATA temp;
	while (i <= j) {
		while (arr[i].nFileSizeLow < pivot.nFileSizeLow)
			i++;
		while (arr[j].nFileSizeLow > pivot.nFileSizeLow)
			j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (j > left)
		QuickSort(arr, left, j);
	if (i < right)
		QuickSort(arr, i, right);
}
void BubbleSort(WIN32_FIND_DATA arr[])
{
	int n = size;
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (arr[j + 1].nFileSizeLow < arr[j].nFileSizeLow)
			{
				tmp = arr[j + 1].nFileSizeLow;
				arr[j + 1].nFileSizeLow = arr[j].nFileSizeLow;
				arr[j].nFileSizeLow = tmp;
			}
		}
	}
}
void InsertSort(WIN32_FIND_DATA arr[])
>>>>>>> 30ef0c0f6dc6eff852ad6608a70305e37c435aff
{
    struct file* files;
    char path[MAX_PATH_LEN];
    int count_files;
    int* lensNames;
    int i;

    strcpy(path, getPath());
    count_files = getCountOfFiles(path); // counting the number of files
    lensNames = getlensFileNames(path, count_files); // counting the length of file names

    files = (struct file*)malloc(count_files * sizeof(struct file)); //memory allocation
    for (i = 0; i < count_files; i++)
    {
        files[i].name = (char*)malloc((lensNames[i] + 1) * sizeof(char));
    }
    getFiles(path, files);
    sortFiles(files, count_files, lensNames);
    return 0;
}


void sortFiles(struct file* files, int count_files, int* lensNames)
{
    struct file* copy;
    char sort_selection[100] = "";
    char sortEnough[100] = "";
    int i;
    int enough = 1;
    long long time1;
    long long time2;

    while (enough)
    {

        copy = cpy_arr(files, count_files, lensNames);
        printf("\nChoose sort: \n1-Bubble Sort\n2-Insertion Sort\n3-Quick Sort\n");
        do
        {
            gets(sort_selection);

            if ((strcmp(sort_selection, "1") != 0) && (strcmp(sort_selection, "2") != 0) && (strcmp(sort_selection, "3") != 0))
            {
                printf("incorrest data, please enter 1 - if you want to use a Bubble Sort, 2 - Insertion Sort, 3 - Quick Sort:\n");
            }
        } while ((strcmp(sort_selection, "1") != 0) && (strcmp(sort_selection, "2") != 0) && (strcmp(sort_selection, "3") != 0));

        if (strcmp(sort_selection, "1") == 0)
        {
            QueryPerformanceCounter(&time1);
            BubbleSort(copy, count_files);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory\n");
            print_files(copy, count_files);
        }
        else if (strcmp(sort_selection, "2") == 0)
        {
            QueryPerformanceCounter(&time1);
            InsertSort(copy, count_files);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory\n");
            print_files(copy, count_files);
        }
        else
        {
            QueryPerformanceCounter(&time1);
            QuickSort(copy, count_files);
            QueryPerformanceCounter(&time2);
            printf("\nThis is sorted list of your files in this directory (sorted by quick_sort)\n");
            print_files(copy, count_files);
        }
        printf("it took  %lld milliseconds to sort\n\n", time2 - time1);
        printf("If you want to sort again this directory -- enter 'yes', else - enter 'no'\n");

        do
        {
            gets(sortEnough);

            if ((strcmp(sortEnough, "yes") != 0) && (strcmp(sortEnough, "no") != 0)) {
                printf("incorrest data, please enter only 'yes' or 'no'\n");
            }
        } while ((strcmp(sortEnough, "yes") != 0) && (strcmp(sortEnough, "no") != 0));

        if (strcmp(sortEnough, "no") == 0)
        {
            enough = 0;
        }

        // freeing memory
        for (i = 0; i < count_files; i++)
        {
            free(copy[i].name);
        }
        free(copy);
    }
}

char* getPath() {
    char path[MAX_PATH_LEN];
    while (TRUE)
    {
        printf("enter the path to directory\n");
        gets(path);

        strcat(path, "//*");

        if (checkPath(path))
        {
            return path;

        }
        else
        {
            printf("Path is incorrect\n Try again, don't give up!!!\n");
        }
    }
}


int checkPath(char* path)
{
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);
    if (h_file == INVALID_HANDLE_VALUE)
    {
        return 0;
    }
    return 1;
}

struct file* cpy_arr(struct file* files, int len, int* lensNames) //copying so as not to change the original data
{
    int i;
    struct file* copy_files;
    copy_files = (struct file*)malloc(len * sizeof(struct file));
    for (i = 0; i < len; i++) //memory allocation for strings
    {
        copy_files[i].name = (char*)malloc((lensNames[i] + 1) * sizeof(char));
    }
    for (i = 0; i < len; i++) //filling in the nameand size of the files
    {
        strcpy(copy_files[i].name, files[i].name);
        copy_files[i].size = files[i].size;
    }

    return copy_files;
}

int getCountOfFiles(char* path)
{
    int count = 0;
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);

    while (FindNextFileA(h_file, &files_data) != NULL)
    {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            continue;
        }
        count++;
    }
    FindClose(h_file);

    return count;
}

int* getlensFileNames(char* path, int count_files) //finding the length of a string to allocate memory
{
    int* lens = (int*)malloc(count_files * sizeof(int));
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);

    int i = 0;
    while (FindNextFileA(h_file, &files_data) != NULL)
    {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            continue;
        }
        lens[i] = strlen(files_data.cFileName);
        i++;
    }
    FindClose(h_file);

    return lens;
}

void getFiles(char* path, struct file* files) //filling
{
    WIN32_FIND_DATAA files_data;
    HANDLE h_file = FindFirstFileA(path, &files_data);

    FindNextFileA(h_file, &files_data);

    int i = 0;
    printf("\nList of files as they are located in the directory:\n");
    while (FindNextFileA(h_file, &files_data) != NULL)
    {
        if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            continue;
        }
        printf("%s       ", files_data.cFileName);
        strcpy(files[i].name, files_data.cFileName);
        printf("%d\n", files_data.nFileSizeLow);
        files[i].size = files_data.nFileSizeLow;

        i++;
    }
    FindClose(h_file);

}

void print_files(struct file* files, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%s   %d\n", files[i].name, files[i].size);
    }
}



void InsertSort(struct file* files, int len)
{
    struct file tmp;
    tmp.name = "";
    tmp.size = 0;
    int i, j, tmp1, tmp2;
    for (i = 1; i < len; i++)
    {
        tmp.name = "111";
        tmp.size = -1;
        tmp1 = files[i].size;
        j = i - 1;
        while ((j >= 0) && (files[j].size > tmp1))
        {
            tmp2 = files[j + 1].size;
            files[j + 1].size = files[j].size;
            files[j].size = tmp2;
            j--;
        }

    }
}


void BubbleSort(struct file* files, int len)
{
    int i, j;
    struct file tmp;
    tmp.name = "";
    tmp.size = 0;

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            tmp.name = "111";
            tmp.size = -1;
            if (files[j + 1].size < files[j].size)
            {
                tmp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = tmp;
            }
        }
    }

}


void QuickSort(struct file* files, int size)
{
    int i = 0;
    int j = size - 1;
    struct file tmp;
    tmp.name = "111";
    tmp.size = -1;
    int mid = files[size / 2].size;
    do
    {
        while (files[i].size < mid)
        {
            i++;
        }

        while (files[j].size > mid)
        {
            j--;
        }

        if (i <= j)
        {
            tmp = files[i];
            files[i] = files[j];
            files[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
    {
        QuickSort(files, j + 1);
    }
    if (i < size)
    {
        QuickSort(&files[i], size - i);
    }
}