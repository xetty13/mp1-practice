#include "input.h"
#include <windows.h>

void userInput(char** a, wchar_t** path, HANDLE hf, WIN32_FIND_DATA FindFileData) {
    do {
        printf("Enter the open path of the directory with the files: \n");
        scanf("%s", a);
        strcat(a, "\\*.*");
        mbstowcs(path, a, strlen(a) + 1);
        hf = FindFirstFileW(path, &FindFileData);

    } while (hf == INVALID_HANDLE_VALUE);
    printf("Your path: %s \n", a);
}