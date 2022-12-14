#include "famount.h"
#include <Windows.h>

int filesAmount(wchar_t** path, HANDLE hf, WIN32_FIND_DATA FindFileData) {
    int count = 0;
    hf = FindFirstFile(path, &FindFileData);
    if (hf != INVALID_HANDLE_VALUE) {
        do {
            if (wcscmp(FindFileData.cFileName, L".") != 0 && wcscmp(FindFileData.cFileName, L"..") != 0) {
                count++;
            }

        } while (FindNextFile(hf, &FindFileData) != 0);
    }
    return count;
}