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
	printf("Input a path : \n");

	scanf("%s", a);
	strcat(a, "*.*");

	int len = strlen(a);
	MultiByteToWideChar(0, 0, a, len + 1 ,0 ,len+1 );
	
	wprintf(a);
	
	printf("What \n");
	setlocale(LC_ALL, "rus");
	WIN32_FIND_DATA names[1000];
	WIN32_FIND_DATA fdata;
	HANDLE hfile = FindFirstFile(a, &fdata);
	int i = 0;
	DWORD A[20]; 

	
	do {
		names[i] = fdata;
		

		printf("Name:    ");
		
		wprintf(names[i].cFileName);
		printf(" %10c    Size (bites): %u        ", ' ', names[i].nFileSizeLow);
		time_t *time1 = filetime_to_timet(names[i].ftCreationTime);
		printf("%10c Created time:  %s     \n", ' ', ctime(&time1));
		i++;
	} while (FindNextFile(hfile, &fdata) != NULL);
	


	
	
	FindClose(hfile);
	printf("\n END \n");
	

	return 0;
}

