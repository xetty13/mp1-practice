#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <omp.h>
#define REP 45
#define FILES 50000 
#define BUFFER 2048
void menu(int* method);
void Input(wchar_t** sDir);
void Output(wchar_t** filesName, ULONGLONG* filesSize, int* filesIdx, int N);
int ListDirectoryContents(const wchar_t* sDir, wchar_t** filesName, ULONGLONG* filesSize);
void bubbleSort(ULONGLONG* filesSize, int* filesIdx, int N);
void insertSort(ULONGLONG* fileSize, int* fileIdx, int n);
void quickSort(ULONGLONG* filesSize, int fileIdx, int n1, int n2);

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
void insertSort(ULONGLONG* filesSize, int* fileIdx, int N)
{
	int i, j, tmp2;
	ULONGLONG tmp;
	for (i = 1; i < N; i++)
	{
		tmp = filesSize[i];
		tmp2 = fileIdx[i];
		j = i - 1;
		while (j >= 0 && filesSize[j] > tmp)
		{
			filesSize[j + 1] = filesSize[j];
			fileIdx[j + 1] = fileIdx[j];
			j--;
		}
		filesSize[j + 1] = tmp;
		fileIdx[j + 1] = tmp2;
	}
}
void quickSort(ULONGLONG* filesSize, int* fileIdx, int left, int right) {
	int i = left, j = right;
	unsigned long long pivot = filesSize[(left + right) / 2];
	while (i <= j) {
		while (filesSize[i] < pivot) {
			i++;
		}
		while (filesSize[j] > pivot) {
			j--;
		}
		if (i <= j) {
			unsigned long long temp = filesSize[i];
			filesSize[i] = filesSize[j];
			filesSize[j] = temp;
			wchar_t* temp2 = fileIdx[i];
			fileIdx[i] = fileIdx[j];
			fileIdx[j] = temp2;
			i++;
			j--;
		}
	}
	if (left < j) {
		quickSort(filesSize, fileIdx, left, j);
	}
	if (i < right) {
		quickSort(filesSize, fileIdx, i, right);
	}
}

int main()
{
	wchar_t* filesPath, ** filesName;//������ ����
	ULONGLONG* filesSize, * tmpSizes, * copy_filesSize;;//������ �������� ������
	int* filesIdx, * copy_filesIdx;// ������� ��� ���� ������
	int j = -1, i = 0;

	double start, end;

	int method = 0, f = 0;
	filesName = (wchar_t**)malloc(FILES * sizeof(wchar_t*));
	filesSize = (ULONGLONG*)malloc(FILES * sizeof(ULONGLONG));
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
		menu(&method);
		if (method == 4) return 0;

		tmpSizes = (ULONGLONG*)malloc(j * sizeof(ULONGLONG));
		for (i = 0; i < j; i++)
			tmpSizes[i] = filesSize[i];

		printf("\nType of sort - %d.\n", method);
		switch (method)
		{
		case 1://������
			start = omp_get_wtime();
			bubbleSort(filesSize, filesIdx, j);
			end = omp_get_wtime();
			Output(filesName, filesSize, filesIdx, j);
			break;
		case 2://������
			start = omp_get_wtime();
			insertSort(filesSize, filesIdx, j);
			end = omp_get_wtime();
			Output(filesName, filesSize, filesIdx, j);
			break;
		case 3://������
			start = omp_get_wtime();
			quickSort(filesSize, filesIdx, 0, (j - 1));
			end = omp_get_wtime();
			Output(filesName, filesSize, filesIdx, j);
			break;
		}
		printf("\nTime: %5.15lf ��� \n", end - start);


	} while (method != 4);
}