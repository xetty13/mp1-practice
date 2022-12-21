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
    int Flag;
    int count;
    do{
        Flag = 1;
        int i = 0;
        int j = 0;

        char* userStr = (char*)malloc(MAX_PATH * sizeof(char));
        wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
        userInput(userStr, path, hf, FindFileData);
        count = filesAmount(path, hf, FindFileData);
        char** fileNames = (char**)malloc(count * sizeof(char*));
        unsigned long* sizes = (unsigned long*)malloc(count * sizeof(unsigned long));
        hf = FindFirstFile(path, &FindFileData);
        if (hf != INVALID_HANDLE_VALUE) {
            do {
                if (wcscmp(FindFileData.cFileName, L".") != 0 && wcscmp(FindFileData.cFileName, L"..") != 0) {
                    fileNames[j] = (char*)malloc(MAX_PATH * sizeof(char));
                    wcstombs(fileNames[j], FindFileData.cFileName, MAX_PATH);
                    sizes[j] = FindFileData.nFileSizeLow;
                    j++;

                }

            } while (FindNextFile(hf, &FindFileData) != 0);
        }

        printf("\nFiles amount in the directory: %d\n\n", count);
        for (i = 0; i < count; i++) {
            printf("%s size: %d B\n", fileNames[i], sizes[i]);
        }

        do {
            unsigned long* size_copy = (unsigned long*)malloc(count * sizeof(unsigned long));
            int* index = (int*)malloc(count * sizeof(int));
            unsigned long* tmp = (unsigned long*)malloc(count * sizeof(unsigned long));
            unsigned long* itmp = (unsigned long*)malloc(count * sizeof(unsigned long));
            add(size_copy, index, sizes, count);
            switch (choice()) {
                case 1:
                    QueryPerformanceCounter(&start);
                    msort(size_copy, tmp, 0, (count - 1), index, itmp);
                    QueryPerformanceCounter(&end);
                    output(fileNames, size_copy, index, count, (end - start));
                    free(tmp);
                    free(itmp);
                    break;
                case 2:
                    QueryPerformanceCounter(&start);
                    quicksort(size_copy, 0, (count - 1), index);
                    QueryPerformanceCounter(&end);
                    output(fileNames, size_copy, index, count, (end - start));
                    break;
                case 3:
                    QueryPerformanceCounter(&start);
                    bubbleSort(size_copy, count, index, fileNames);
                    QueryPerformanceCounter(&end);
                    output(fileNames, size_copy, index, count, (end - start));
                    break;
                case 4:
                    Flag = 0;
                    break;
                case 5:
                    return 0;
                default:
                    break;
            }
            free(size_copy);
            free(index);
        } while (Flag == 1);
        free(userStr);
        for (i = 0; i < count; i++)
            free(fileNames[i]);
        free(fileNames);
        free(path);
        free(sizes);
    } while (Flag == 0);
    FindClose(hf);
    return 0;
}
