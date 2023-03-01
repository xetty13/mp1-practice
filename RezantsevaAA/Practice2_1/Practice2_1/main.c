#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include "cars.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct
{
	char* name;
	char* year;
} TFile;

#define MAX_PATH_LEN 300
char* getPath();
char* ReadCarFile(char* path);
void FindMaxYear(TFile* oldcar);



int main()
{
	//char* path = getPath();
	TFile car;
	FindMaxYear(&car);
	return 0;
}

char* getPath()
{
	char path[MAX_PATH_LEN];
	while (1)
	{
		printf("enter the path to file \n");
		gets(path);
		return path;
	}
}

char* ReadCarFile(char* path)
{
	FILE* file = fopen(path, "r");
	char line[255];
	//printf("File contents:\n");
	for (int i = 0; i < 6; i++)
	{
		fgets(line, 255, file);
		//printf("%s\n", line);

	}
	fclose(file);
	return line;

}


void FindMaxYear(TFile* oldcar)
{
	char* path = getPath();
	oldcar->year = "9999";
	WIN32_FIND_DATAA files_data;
	HANDLE h_file = FindFirstFileA(path, &files_data);
	FindNextFileA(h_file, &files_data);
	while (FindNextFileA(h_file, &files_data) != NULL)
	{
		if (files_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			continue;
		}
		char* year = ReadCarFile(files_data.cFileName);
		if (oldcar->year > year)
		{
			oldcar->year = year;
			oldcar->name = files_data.cFileName;
		}
	}
	FindClose(h_file);
}