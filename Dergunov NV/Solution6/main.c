#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#define REP 45
#define FILES 50000 
#define BUFFER 2048
void menu(int* method);
void Input(wchar_t** sDir);
void Output(wchar_t** filesName, ULONGLONG* filesSize, int* filesIdx, int N);
int ListDirectoryContents(const wchar_t* sDir, wchar_t** filesName, ULONGLONG* filesSize);
void bubbleSort(ULONGLONG* filesSize, int* filesIdx, int N);
void insertSort(ULONGLONG* fileSize, int* fileIdx, int n);
void Quick_Split(ULONGLONG* filesSize, int* fileIdx, int* i, int* j, int p);
void Quick_Sort(ULONGLONG* filesSize, int fileIdx, int n1, int n2);

void menu(int* method)
{
	do
	{
		printf("\n------Choose the type of sorting------\n 1. BubbleSort\n 2. InsertionSort\n "
			"3. QuickSort\n 4. Exit\n");
		scanf_s("%d", method);
	} while ((*method < 0) || (*method > 5));
}
void Input(wchar_t** sDir)
{
	char* vstring;
	*sDir = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
	vstring = (char*)malloc(BUFFER * sizeof(char));
	fgets(vstring, BUFFER, stdin);
	vstring[strlen(vstring) - 1] = '\0';
	swprintf(*sDir, BUFFER, L"%hs", vstring);
}
void Output(wchar_t** filesName, ULONGLONG* filesSize, int* filesIdx, int N)
{
	int i;
	printf("\nFolder contents:\n");
	for (i = 0; i < N; i++) {
		printf("%d. File: %S Size: %d bytes\n", i + 1, filesName[filesIdx[i]], filesSize[i]);
	}
}
int ListDirectoryContents(const wchar_t* sDir, wchar_t** filesName, ULONGLONG* filesSize)

{
	int i = 0;
	WIN32_FIND_DATA fd;

	wchar_t* sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
	wsprintf(sPath, L"%s\\*", sDir);

	HANDLE hFind = FindFirstFile(sPath, &fd);
	if (hFind == INVALID_HANDLE_VALUE) {
		FindClose(hFind);
		free(sPath);
		return -1;
	}
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (strcmp(fd.cFileName, ".") != 0 && strcmp(fd.cFileName, "..") != 0)
			{
				filesSize[i] = fd.nFileSizeLow + (fd.nFileSizeHigh * (MAXDWORD + 1));
				filesName[i] = (wchar_t*)malloc(sizeof(wchar_t) * BUFFER);
				wsprintf(sPath, L"%s\\%s", sDir, fd.cFileName);
				wsprintf(filesName[i], L"%s", sPath);
				i++;
			}
		} while (FindNextFile(hFind, &fd));
		FindClose(hFind);
		free(sPath);
		return i;
	}
	printf("net problem");
	FindClose(hFind);
	free(sPath);
	return -1;
}
void bubbleSort(ULONGLONG* filesSize, int* fileIdx, int N)
{
	int i, j, tmp = 0;
	unsigned long tmp2;
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				if (filesSize[j] > filesSize[j + 1])
				{
					tmp = fileIdx[j];
					fileIdx[j] = fileIdx[j + 1];
					fileIdx[j + 1] = tmp;
					tmp2 = filesSize[j];
					filesSize[j] = filesSize[j + 1];
					filesSize[j + 1] = tmp2;
				}
		}
	}
}
void insertSort(ULONGLONG* fileSize, int* fileIdx, int N)
{
	int i, j, tmp2;
	ULONGLONG tmp;
	for (i = 1; i < N; i++)
	{
		tmp = fileSize[i];
		tmp2 = fileIdx[i];
		j = i - 1;
		while (j >= 0 && fileSize[j] > tmp)
		{
			fileSize[j + 1] = fileSize[j];
			fileIdx[j + 1] = fileIdx[j];
			j--;
		}
		fileSize[j + 1] = tmp;
		fileIdx[j + 1] = tmp2;
	}
}
void Quick_Sort(ULONGLONG* filesSize, int fileIdx, int n1, int n2)
{
	int m;
	int i = n1; int j = n2;
	m = (n1 + n2) / 2;
	Quick_Split(filesSize, fileIdx, &i, &j, filesSize[m]);
	if (i < n2)
		Quick_Sort(filesSize, fileIdx, n2, i);
	if (j > n1)
		Quick_Sort(filesSize, fileIdx, n1, j);
}
void Quick_Split(ULONGLONG* filesSize, int* fileIdx, int* i, int* j, int p)
{
	ULONGLONG tmp;
	do
	{
		while (filesSize[*i] < p)
			(*i)++;
		while (filesSize[*j] > p)
			(*j)--;
		if (*i <= *j)
		{
			tmp = fileIdx[*i];
			fileIdx[*i] = fileIdx[*j];
			fileIdx[*j] = tmp;
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}
int main()
{
	wchar_t* filesPath, ** filesName;//массив имен
	ULONGLONG* filesSize, * tmpSizes, * copy_filesSize;;//массив размеров файлов
	int* filesIdx, * copy_filesIdx;// индексы для имен файлов
	int j = -1, i = 0;
	clock_t start;
	clock_t end;
	int method = 0, f = 0;
	filesName = (wchar_t**)malloc(FILES * sizeof(wchar_t*));
	filesSize = (ULONGLONG*)malloc(FILES * sizeof(ULONGLONG));
	copy_filesSize = (wchar_t**)malloc(FILES * sizeof(wchar_t*));
	copy_filesIdx = (wchar_t**)malloc(FILES * sizeof(wchar_t*));
	printf("------FILE MANAGER------");
	printf("\nWay to the folder: \n");
	setlocale(LC_ALL, "ru");
	while (j == -1)
	{
		Input(&filesPath);
		j = ListDirectoryContents(filesPath, filesName, filesSize);
	}
	filesIdx = (int*)malloc(j * sizeof(int));
	for (i = 0; i < j; i++)
		filesIdx[i] = i;

	Output(filesName, filesSize, filesIdx, j);
	do
	{
		//memcpy(copy_filesSize, filesSize, BUFFER);
		//memcpy(copy_filesIdx, filesIdx, BUFFER);
		menu(&method);
		if (method == 4) return;

		tmpSizes = (ULONGLONG*)malloc(j * sizeof(ULONGLONG));
		for (i = 0; i < j; i++)
			tmpSizes[i] = filesSize[i];

		printf("\nType of sort - %d.\n", method);
		start = clock();
		switch (method)
		{
		case 1://готово
			start = clock();
			bubbleSort(filesSize, filesIdx, j);
			end = clock();
			Output(filesName, filesSize, filesIdx, j);
			break;
		case 2://готово
			start = clock();
			insertSort(filesSize, filesIdx, j);
			end = clock();
			Output(filesName, filesSize, filesIdx, j);
			break;
		case 3:
			Quick_Sort(tmpSizes, filesIdx, 0, (j - 1));
			break;
			end = clock();
			Output(filesName, filesSize, filesIdx, j);

			printf("\n Time: %.4lf sec.\n", (double)(end - start) / CLOCKS_PER_SEC);

			for (i = 0; i < j; i++)
				filesIdx[i] = i;
			start = end = 0;
			free(tmpSizes);
		}
	} while (1);
}