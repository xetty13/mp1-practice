#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#define BUFFER 1000 //Размер буффера

void input(wchar_t **path) //Массив куда будет записана директория
{
    char *str; //Сюда принимаем строку в char
    int k = 0, i = 0;

    *path = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
    str = (char*)malloc(BUFFER * sizeof(char));
    printf("Enter the path  ");
    fgets(str, BUFFER, stdin);   //Ввод строки до enter
    str[strlen(str) - 1] = '\0'; //Удаление перевода строки в конце
    swprintf(*path, BUFFER, L"%hs", str); //Преобразовываем строку char  в wchar_t 
}

int ListDirectoryContetns(const wchar_t *sDir, wchar_t ***fNames, ULONGLONG **fSizes)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    int i = 0;
    wchar_t *sPath;
    sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));

    hFind = FindFirstFile(sPath, &fdFile);
    wsprintf(sPath, L"%s\\*.*", sDir);
    //Проверка на существование директории
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
        return -1; //Path not found

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
            i++;
    } while (FindNextFile(hFind, &fdFile));

    *fNames = (wchar_t**)malloc(i * sizeof(wchar_t*));
    *fSizes = (ULONGLONG*)malloc(i * sizeof(ULONGLONG));

    do
    {
        //Найденный первый файл будет возвращать "."
        // Последующие файлы будут возвращать ".."
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fSize = fdFile.nFileSizeHigh;
            fSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fSize |= fdFile.nFileSizeLow;

            (*fNames)[i] = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
            (*fSizes)[i] = fSize;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf((*fNames)[i], L"%s", sPath);
            i++;
        }
    } while (FindNextFile(hFind, &fdFile)); //Поиск следующего файла
    return i;
    FindClose(hFind);
    free(sPath);
}

void choose_method(int *method)
{
    printf("\nChoose a sorting\n");
    printf("  1) Choose sorting\n");
    printf("  2) Insert sorting\n");
    printf("  3) Bubble sorting\n");
    printf("  4) Count sorting\n");
    printf("  5) Quick sorting\n");
    printf("  6) Merge sorting\n\n");
    scanf("%d", method);
}

void output(int *ind, int count_files, wchar_t **fNames, ULONGLONG *size)
{
    int i, j;
    WIN32_FIND_DATA fdFile;
    for (i = 0; i < count_files; i++)
        printf(L"%s        %lld\n", fNames[ind[i]], *(size + ind[i]));
    printf("\n\n");
}

void choose_sort(int count_files, ULONGLONG *size, int *ind)
{
    int i = 0, j = 0, k = 0, t = 0;
    long min;

    for (i = 0; i < count_files; i++)
    {
        k = i;
        min = size[i];
        for (j = i + 1; j < count_files; j++)
            if (size[j] < min)
            {
                k = j;
                min = size[j];
            }
        t = ind[k];
        ind[k] = ind[i];
        ind[i] = t;
    }
}

void start()
{
   /* switch ()
    {
    case(1):
    case(2):
    }
    time();*/
}

int main()
{
    char answer;
    wchar_t *path;
    wchar_t **fNames;
    ULONGLONG *fSizes;
    int count_files = 0;
    int method, i = 0;
    int *index;
    setlocale(LC_ALL, "Russian");

    fNames = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
    fSizes = (ULONGLONG*)malloc(MAX_PATH * sizeof(ULONGLONG));

    printf("\tFILE MANAGER\n\n");
    // start(&path, path, fNames, fSizes);

    do
    {
     //Ввод пути с клавиатуры
    input(&path);
    count_files = ListDirectoryContetns(path, &fNames, &fSizes);

    printf("Files found:  %d\n\n", count_files); //Вывод количества найденных файлов
    index = (int*)malloc(BUFFER * sizeof(int));

    for (i = 0; i < count_files; i++)
        index[i] = i;

    choose_method(&method);

    switch (method)
    {
    case(1):
    {
        choose_sort(count_files, fSizes, index);
        output(index, count_files, fNames, fSizes);
    }
    }

            printf("Start over? ( y or n )");
            scanf("%c", &answer);
            switch (answer)
            {
            case('y') : start();
            case('n') : break;
            }
        } while (answer != 'n');

        system("pause");
}