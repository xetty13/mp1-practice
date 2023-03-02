#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WIN32_FIND_DATA names[MAX_PATH];
WIN32_FIND_DATA File;
HANDLE hfile;

void input() {
	char* a = (char*)malloc(MAX_PATH);
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));

	do {
		printf("Enter the open path of the directory with the files: \n");
		//translating the path to wchar_t
		scanf("%s", a);
		strcat(a, "\\*.*");
		mbstowcs(path, a, strlen(a) + 1);
		hfile = FindFirstFileW(path, &File);

	} while (hfile == INVALID_HANDLE_VALUE);
	printf("Your path: %s \n", a);
}

