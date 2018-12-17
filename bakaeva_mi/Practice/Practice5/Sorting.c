#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

//#define MAX_PATH 800 //Количество файлов в папке
#define N 50 //Размер массива
#define BUFFER 1000 //Размер буффера

void input(wchar_t **path) //Массив куда будет записана директория
{
    char *str; //Создадим указатель
    int k = 0, i = 0;

    *path = (wchar_t*)malloc(BUFFER * sizeof(wchar_t)); //выделение памяти для пути
    str = (char*)malloc(BUFFER * sizeof(char));
    printf("Enter the path");
    fgets(str, BUFFER, stdin);   //СПРОСИТЬ МАКСИМА
   // str[strlen(str) - 1] = '\0';
    swprintf(*path, BUFFER, L"%hs", str);
}

int ListDirectoryContetns(const wchar_t *sDir, int **fNames)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = FindFirstFile("C:\\*", &fdFile);
    int i = 0;

    wchar_t sPath[2048];

    wsprintf(sPath, L"%s\\*.*", sDir); //sPath - куда попала преобразованная строка, маска, указатель на введенную строку

    hFind = FindFirstFile(sPath, &fdFile);

    //Проверка на существование директории
    if (hFind == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return -1;
    }

    do
    {
        //Найденный первый файл будет возвращать "."
        // Последующие файлы будут возвращать ".."
        /*if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            //Создадим путь к файлуб используя переданный в [sDir] и имя файла, которое мы только что нашли
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(fNames[i], L"%s", sPath);
            //Является ли объект файлом или папкой?
            if (fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
            {
                wprintf(L"Directory: %s\n", sPath);
                ListDirectoryContetns(sPath, fNames); //Рекурсия
            }
            else
            {
                wprintf(L"File: %s\n", sPath);
            }*/

        strcpy(fNames[i], fdFile.cFileName);
        puts(fNames[i]);
            i++;
    }while (FindNextFile(hFind, &fdFile)); //Поиск следующего файла
    FindClose(hFind);
    return i;
    FindClose(hFind);

}

void start()
{
    //choose_method();

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
    long *fSizes;
    int count_files = 0;

    fNames = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
    fSizes = (long*)malloc(MAX_PATH * sizeof(long));

    printf("\tFILE MANAGER\n\n");
    // start(&path, path, fNames, fSizes);

     //Ввод пути с клавиатуры
    input(&path);
    //Передаем в функцию записи имен и рзмеров введенную директорию и массив с именами и размерами
    //count_files = ListDirectoryContents(&(path[0]), &fNames);

    WIN32_FIND_DATA fdFile;
    HANDLE hFind = FindFirstFile("C:\\*", &fdFile);
    int i = 0;

    //wchar_t sPath[2048];

    //wsprintf(sPath, L"%s\\*.*", path); //sPath - куда попала преобразованная строка, маска, указатель на введенную строку

    //hFind = FindFirstFile(sPath, &fdFile);

    //Проверка на существование директории
    if (hFind == INVALID_HANDLE_VALUE)
    {
       puts(L"Path not found");
        do
        {
            strcpy(fNames[i], fdFile.cFileName);
           // puts(fNames[i]);
            i++;
        } while (FindNextFile(hFind, &fdFile)); //Поиск следующего файла
        FindClose(hFind);

        printf("%d", i); //Вывод количества найденных файлов

        do
        {
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
}