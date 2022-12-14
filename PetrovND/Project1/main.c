#include <stdio.h>
#include <windows.h>
#include <profileapi.h>
#include "input.h"
#include "output.h"
#include "famount.h"
#include "sort.h"
#include "fill.h"
#include "choice.h"

WIN32_FIND_DATA FindFileData;
HANDLE hf;

int main() {
    long long start, end;
    int Flag = 1;
    int count;
    do{
        int flag = 1;
        Flag = 1;
        int i = 0;
        int j = 0;

        char* a = (char*)malloc(MAX_PATH * sizeof(char));
        wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
        userInput(a, path, hf, FindFileData);
        count = filesAmount(path, hf, FindFileData);
        char** fname = (char**)malloc(count * sizeof(char*));
        unsigned long* size = (unsigned long*)malloc(count * sizeof(unsigned long));
        hf = FindFirstFile(path, &FindFileData);
        if (hf != INVALID_HANDLE_VALUE) {
            do {
                if (wcscmp(FindFileData.cFileName, L".") != 0 && wcscmp(FindFileData.cFileName, L"..") != 0) {
                    fname[j] = (char*)malloc(MAX_PATH * sizeof(char));
                    wcstombs(fname[j], FindFileData.cFileName, MAX_PATH);
                    size[j] = FindFileData.nFileSizeLow;
                    j++;

                }

            } while (FindNextFile(hf, &FindFileData) != 0);
        }

        printf("File amount: %d\n", count);
        for (int i = 0; i < count; i++) {
            printf("%s", fname[i]);
            printf(" size: %d bit\n", size[i]);
        }

        do {
            unsigned long* size_copy = (unsigned long*)malloc(count * sizeof(unsigned long));
            int* index = (int*)malloc(count * sizeof(int));
            unsigned long* tmp = (unsigned long*)malloc(count * sizeof(unsigned long));
            unsigned long* itmp = (unsigned long*)malloc(count * sizeof(unsigned long));
            add(size_copy, index, size, count);
            switch (choice()) {
                case 1:
                    QueryPerformanceCounter(&start);
                    msort(size_copy, tmp, 0, (count - 1), index, itmp);
                    QueryPerformanceCounter(&end);
                    output(fname, size_copy, index, count, (end - start));
                    free(tmp);
                    free(itmp);
                    break;
                case 2:
                    QueryPerformanceCounter(&start);
                    quicksort(size_copy, 0, (count - 1), index);
                    QueryPerformanceCounter(&end);
                    output(fname, size_copy, index, count, (end - start));
                    break;
                case 3:
                    QueryPerformanceCounter(&start);
                    bubbleSort(size_copy, count, index, fname);
                    QueryPerformanceCounter(&end);
                    output(fname, size_copy, index, count, (end - start));
                    break;
                case 4:
                    flag = 0;
                    Flag = 0;
                    break;
                case 5:
                    return 0;
                default:
                    break;
            }
            free(size_copy);
            free(index);
        } while (flag == 1);
        free(a);
        for (int i = 0; i < count; i++)
            free(fname[i]);
        free(fname);
        free(path);
        free(size);
    } while (Flag == 0);
    FindClose(hf);
    return 0;
}
//C:\Users\nikit\Desktop\AdminPanel\.idea\libraries
//C:\Windows\Cursors