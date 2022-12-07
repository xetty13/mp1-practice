#include <stdio.h>
#include <windows.h>
#define LENGTH 50
int size[LENGTH];
char names[LENGTH][LENGTH];
CHAR path[MAX_PATH];
void findfiles(CHAR* path);
void merge(int* a, int left, int mid, int right);
void mergeSort(int* a, int left, int right);
void BubbleSort(int a[LENGTH]);
void qsortx(int* a, size_t low, size_t high);

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
    printf("Enter directoria:");
    scanf("%s", &path);
    findfiles(path);

}
void merge(int* a, int left, int mid, int right)
{
    int i=0, i1=0, i2=0;
    int* b = (int*)malloc(sizeof(int) * (N - left));
    while ((left + i1 < mid) && (mid + i2 <= right)) {
        if (a[left + i1] < a[mid + i2]) {
            b[i1+i2] = a[left + i1];
            i1++;
        }
        else {
            b[i1+i2] = a[mid + i2];
            i2++;
        }
    }
    while (left + i1 < mid) {
        b[i1+i2] = a[left + i1];
        i1++;
    }
    while (mid + i2 < right) {
        b[i1+i2] = a[mid + i2];
        i2++;
    }
    for (i = 0; i < i1 + i2; i++) {
        a[left + i] = b[i];
    }

}
void mergeSort(int* a, int left, int right)
{
    int mid;
    if (left >= right)
        return;
    mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a, left, mid, right);
}
void BubbleSort(int a[LENGTH])
{
	int i, j, tmp;
    for (i = 0; i < LENGTH; i++) {
        for (j = 0; j < LENGTH - i - 1; j++) {
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


/* for (i = 0; i < LENGTH; i++) {
    for (i1 = 0; i < LENGTH; i1++) {
        if b[i] == size[i1]{
            print("% %",names[i1],b[i]);
        i++; }
        else {
            i1++;
        }
    }
}*/