#include <stdio.h>
#include <windows.h>
#define LENGTH 50
#define N 50
int size[LENGTH];
char names[LENGTH][LENGTH];
void findfiles(CHAR* path)
{
	int i = 0;
	WIN32_FIND_DATAA files;
	HANDLE lastfile;
	lastfile = FindFirstFileA(path, &files);
	FindNextFileA(lastfile, &files);
	if (lastfile != INVALID_HANDLE_VALUE) {
		while (FindNextFileA(lastfile, &files)){
			strcpy(names[i], files.cFileName);
			size[i] = files.nFileSizeLow;
			printf("%s, %d bytes\n",names[i], size[i]);
			i++;
		}
	}
	FindClose(lastfile);
}
void main()
{
	findfiles("C:\\Киношка\\После\\*");

}
void sortMerge(int* a, int left, int mid, int right)
{
    int b[N], i=0, i1=0, i2=0;
    while ((left + i1 <= mid) && (mid + 1 + i2 <= right)) {
        if (a[left + i1] < a[mid + 1 + i2]) {
            b[i] = a[left + i1];
            i1++;
            i++;
        }
        else {
            b[i] = a[mid + 1 + i2];
            i2++;
            i++;
        }
    }
    while (left + i1 <= mid) {
        b[i] = a[left + i1];
        i1++;
        i++;
    }
    while (mid + i2 + 1 <= right) {
        b[i] = a[mid + 1 + i2];
        i2++;
        i++;
    }
    for (i = 0; i < i1 + i2 - 1; i++) {
        a[left + i] = b[i];
    }

}

void BubbleSort(int a[N])
{
	int i, j, tmp;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i - 1; j++) {
			if (a[j + 1] > a[j])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}
void qsortx(int* a, size_t low, size_t high) {
    size_t i, j;
    int tmp, pivot;

    i = low;
    j = high;

    pivot = a[(low + (high - low) / 2)];
    do {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            if (a[i] > a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            if(j > 0) {
                j--;
            }
        }
    } while (i <= j);

    if(i < high) {
        qsortx(a, i, high);
    }
    if (j > low) {
        qsortx(a, low, j);
    }
}
