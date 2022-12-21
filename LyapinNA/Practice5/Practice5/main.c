#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <tchar.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <stdlib.h>
#include <synchapi.h>
#include "SORT.h"
#define MAX_PATH 260
#define SEARCH_MASK "/*"
char* COPYPATH;


struct FILE_INFO {
	wchar_t fName[MAX_PATH];
	unsigned long long int fSizeL;
	unsigned long long int fSizeH;
}FILES[100000], * P;



long long int a[10000];

int filesearch(char* path, long long int* SORT_SIZE);



void main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Rus");
	//COPYPATH = (char*)malloc(MAX_PATH * sizeof(char));


	int choose;
	printf("Hello, choose your sort metod: ");
	scanf_s("%d", &choose);
	getchar();
	while ((choose != 1) && (choose != 2) && (choose != 3)) {
		printf("Hello, choose your sort metod: ");
		scanf_s("%d", &choose);
		getchar();
	}



	char ENTERED_PATH[MAX_PATH];
	printf("\nEnter your path:\t");
	gets(ENTERED_PATH);
	strcat_s(&ENTERED_PATH, MAX_PATH, SEARCH_MASK);
	puts(&ENTERED_PATH);

	int COUNT = filesearch(ENTERED_PATH, a);

	clock_t start = clock();
	switch (choose) {
	case 1: sorto(a, COUNT); break;
	case 2: insert_sort(a, COUNT); break;
	case 3: fastsort(a, 0, COUNT - 1); break;
	}
	clock_t end = clock();
	long double time = 0.0;
	time += (double)(end - start) / CLOCKS_PER_SEC;



	int indx[10000];
	for (int i = 0; i < COUNT; i++) {
		for (int k = 0; k < COUNT; k++) {
			if (a[i] == FILES[k].fSizeL)
				indx[i] = k;
		}
	}



	for (int i = 0; i < COUNT; i++) {
		printf("%lld \t", a[i]);
		int l = indx[i];
		printf("%s \n", FILES[l].fName);
	}

	printf("\n\nЧисло элементов: %d \nВремя выполнения сортировки: %Lf", COUNT, time);


}



int filesearch(char* path, long long int* SORT_SIZE) {
	int count = 0;
	WIN32_FIND_DATA DATA;
	HANDLE hFind;
	hFind = FindFirstFile(path, &DATA);
	int i = 0;
	while (FindNextFile(hFind, &DATA) != 0) {
		if ((DATA.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY) || (strcmp(DATA.cFileName, "..") == 0))
			continue;


		P = &FILES[i];
		P->fSizeL = DATA.nFileSizeLow;
		P->fSizeH = DATA.nFileSizeHigh;
		strcpy_s(P->fName, MAX_PATH, DATA.cFileName);
		i++;
		count++;
	}
	printf("%d \n", count);
	//long long int* p = SORT_SIZE;
	//p = (long long int*)(malloc(count * sizeof(long long int)));

	for (int k = 0; k < count; k++) {
		SORT_SIZE[k] = FILES[k].fSizeL;
		//printf("%lld \t", SORT_SIZE[i]);
	}

	return count;
}