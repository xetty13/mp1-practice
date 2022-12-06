#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <corecrt_wstring.h>

#include <stdint.h> // для int64_t
#include <inttypes.h> // для правильного вывода int64_t в printf

#ifdef _WIN32

#define WINVER 0x0501
#define _WIN32_WINNT WINVER

#include <windows.h>
#include <sys\stat.h>
#endif
#define N 100
typedef unsigned long long ull;
typedef long long ll;




void choice(int a[])
{
	int min, idx, i, j, tmp;
	for (i = 0; i < N; i++)
	{
		min = a[i];
		idx = i;
		for (j = i + 1; j < N; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				idx = j;
			}
		}
		tmp = a[idx];
		a[idx] = a[i];
		a[i] = tmp;
	}
}



void insert(int a[])
{
	int i, j, tmp;
	for (i = 0; i < N; i++)
	{
		tmp = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j] = tmp;
	}
}


void merge_sort(int a[])
{
	merge_sort_lr(a, 0, N - 1, N);
}

void merge_sort_lr(int a[], int l, int r)
{
	int mid;
	if (l >= r)
		return;
	mid = l + (r - l) / 2;
	merge_sort_lr(a, l, mid);
	merge_sort_lr(a, mid + 1, r);
	merge(a, l, mid, r, N);
}

void merge(int a[], int l, int mid, int r)
{
	int i, j, k;
	int c[N];
	i = l;
	j = mid + 1;
	k = 0;
	while ((i < mid + 1) && (i <= r))
	{
		if (a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	}
	while (i < mid + 1)
	{
		c[k++] = a[i++];
		while (j <= r)
		{
			c[k++] = a[j++];
		}
	}
	for (i = 0; i < k; i++)
	{
		a[l + i] = c[i];
	}
	
}



int64_t getFileSize(char file_name) {
	int64_t _file_size = 0;
	HANDLE hFile;
	hFile = CreateFile(TEXT(file_name), GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		_file_size = -1;
	}
	else {
		LARGE_INTEGER u_winFsz;
		GetFileSizeEx(hFile, &u_winFsz);
		CloseHandle(hFile);
		_file_size = u_winFsz.QuadPart;
	}
	return _file_size;
}



int main() {

	int  i;
	char* file_name;
	FILE* fp;
	fp = fopen("D:\test\List", "r");
	for (i = 0; i < N; i++)
	{
		fscanf(fp, "%s", &file_name);
		printf("%s", file_name);
		int64_t file_size = getFileSize(file_name);
		printf("File size: %" PRId64 "\n", file_size);
	}

	return 0;
}