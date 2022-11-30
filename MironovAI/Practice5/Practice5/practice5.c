#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <wincon.h>
#include <string.h>

#define ull unsigned long long

void insert_sort(int a[], int n[]);
void bubble_sort(int a[], int n[]);
void merge(int a[], int l, int r, int m);
void merge_sort(int a[], int n);


time_t filetime_to_timet(const FILETIME ft)
{
	ULARGE_INTEGER ll;
	ll.LowPart = ft.dwLowDateTime;
	ll.HighPart = ft.dwHighDateTime;
	return ll.QuadPart / 10000000ULL - 11644473600ULL;
}





int main() {

	char* a = (char*)malloc(MAX_PATH-3);
	char* a1 = (char*)malloc(MAX_PATH);
	printf("Input a closed path: \n");	
	printf("Be careful. If did not input a path like this: 'C:\\...\\...\\', you can have a problems \n");
    
	//Подготовка пути и перевод в wchar_t
	scanf("%s", a);
	strcat(a, "*.*");
	wchar_t *path = (wchar_t*)malloc(MAX_PATH*sizeof(wchar_t));
	mbstowcs(path, a, strlen(a) + 1);
	
	
	setlocale(LC_ALL, "rus");
	WIN32_FIND_DATA names[1000];
	WIN32_FIND_DATA fdata;
	HANDLE hfile = FindFirstFile(path, &fdata);
	int i = 0;
	DWORD A[20]; 

	printf("Your path : %s \n", a);
	printf("Data in your directory: \n");
	do {
		names[i] = fdata;
		//File name
		printf("Name:    ");
		wprintf(names[i].cFileName);
		//File size
		printf(" %10c    Size (bites): %u        ", ' ', names[i].nFileSizeLow);
		//File creation time
		time_t *time1 = filetime_to_timet(names[i].ftCreationTime);
		printf("%10c Created time:  %s     \n", ' ', ctime(&time1));
		i++;
	} while (FindNextFile(hfile, &fdata) != NULL);
	
	printf("\n !!!     I hope you knows that a folders is a links, they have no size. You need to input right path if u want to know size of folders.  !!!\n");


	//Input user data
	char sr;
	printf("Input a sorted method: \n Input 1 for  insert sort \n Input 2 for bubble sort \n Input 3 for merge sort \n ");
	do {
		scanf("%c", &sr);
	} while ((sr != '1') && (sr != '2') && (sr != '3'));
	
	char wsr;
	printf("What i need to sort? \n Input 1 for sort memory \n Input 2 for sort creation time \n Input 3 for sort file names");
	do {
		scanf("%c", &wsr);
	} while ((wsr != '1') && (wsr != '2') && (wsr != '3'));


	switch (sr) {
	case 1:
		switch (wsr) {
		case 1:
		case 2:
		case 3:
		}
	case 2:
		switch (wsr) {
		case 1:
		case 2:
		case 3:
		}
	case 3:
		switch (wsr) {
		case 1:
		case 2:
		case 3:
		}

	}

	FindClose(hfile);
	printf("\n END \n");
	return 0;
}

