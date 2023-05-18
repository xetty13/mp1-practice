#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "outlet.h"

char* start() {
    char* path = (char*)malloc(_MAX_PATH * sizeof(char));//выделение памяти под путь
    do {
        printf("Enter path\n");
        scanf("%s", path);//считываем у пользователя строку
        FILE* fp = fopen(path, "r"); //буквально открываем файл на чтение
        if (fp == NULL) { //если пользователь ввёл неверный путь, то fp(указатель) будет указывать на NULL
            printf("Wrong path!!!\n"); //соответственно пишем что не верный путь
        }
        else {//иначе, если путь к файлу верный, мы закрываем файл и возвращаем строку с путём
            fclose(fp);
            return path;
        }
    } while (1);
}

int count(char* path) {
    int count = 0; //исходное количество торговых точек
    char* s = (char*)malloc(512 * sizeof(char)); //строка, которую мы будем получать при чтении файла
    FILE* file = fopen(path, "r"); //открываем файл
    while (1) {
        if (fgets(s, 512, file) != NULL) {// если строки существуют мы их считываем
            if (strcmp(s, "\n") != 0) { 
                count++;
            }
        }
        else {
            break;
        }
    }
    fclose(file);//закрываем файл и освобождаем памить из под строки(т.к она была динамической)
    free(s);
    return count;
}

int countSubs(char* string, char* sub) {//подсчитывает подстроки в строке, нужна для подсчёта рабочих дней
    int l = strlen(sub);
    int n = 0;
    while ((string = strstr(string, sub)) != NULL) {
        ++n;
        string += l;
    }
    return (n + 1) / 3;
}

void daysCount(char* path, int count, outlet* outlets) {//считает количество дней и записывает это значение каждому магазину в поле workingDaysCount
    char* token;
    char delim[] = ";\n";
    int i = 0, j = 0;//счётчики
    FILE* file = fopen(path, "r");
    char str[512];
    while (1) {
        if (fgets(str, 512, file) != NULL) {
            for (token = strtok(str, delim); token; token = strtok(NULL, delim)) {
                switch (i) {
                case 5:
                    outlets[j].working_days.workingDaysCount = countSubs(token, ",");//записываем количество дней
                    i = -1;
                    j++;
                    break;
                }
                i++;
            }
        }
        else {
            break;
        }
    }
    fclose(file);
}

outlet* allocateMemory(int outletCount, char* path) {//выделение памяти
    outlet* retail_outlets = malloc(sizeof(outlet) * outletCount);
    if (retail_outlets == NULL) {
        perror("Ошибка выделения памяти");
        return NULL;
    }

    for (int i = 0; i < outletCount; i++) {
        daysCount(path, outletCount, retail_outlets);
        // Выделение памяти для имени магазина
        retail_outlets[i].name = malloc(sizeof(char) * 100); // Предполагаем максимальную длину имени 100 символов
        retail_outlets[i].specialization = malloc(sizeof(char) * 100);

        // Выделение памяти для названия улицы
        retail_outlets[i].address.street = malloc(sizeof(char) * 100); // Предполагаем максимальную длину названия улицы 100 символов

        // Выделение памяти для массива рабочих дней
        retail_outlets[i].working_days.days = malloc(sizeof(Day) *
            retail_outlets[i].working_days.workingDaysCount);

        // Выделение памяти для массивов времени открытия и закрытия
        retail_outlets[i].working_days.opens = malloc(sizeof(Time) *
            retail_outlets[i].working_days.workingDaysCount);
        retail_outlets[i].working_days.closes = malloc(sizeof(Time) *
            retail_outlets[i].working_days.workingDaysCount);
    }

    return retail_outlets;
}

void readDataFromFile(outlet* retail_outlets, char* path, int count) {//считывает данные из файла и записывает в элементы массива retail_outlets
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    char line[512];
    int outletIndex = 0;

    while (fgets(line, 512, file) != NULL) {
        if (line[0] == '\n') {
            continue; // игнорируем пустые строки(\n)
        }
        char* token;
        token = strtok(line, ";");
        strcpy(retail_outlets[outletIndex].name, token);

        token = strtok(NULL, ";");
        strcpy(retail_outlets[outletIndex].address.street, token);

        token = strtok(NULL, ";");
        retail_outlets[outletIndex].address.house_number = atoi(token);

        token = strtok(NULL, ";");
        retail_outlets[outletIndex].phone_number = atoi(token);

        token = strtok(NULL, ";");
        strcpy(retail_outlets[outletIndex].specialization, token);

        token = strtok(NULL, ",");
        int i = 0;

        while (token != NULL) {
            // Обработка данных для каждого дня
            Day currentDay;
            Time opens, closes;

            if (strcmp(token, "Monday") == 0)
                currentDay = Monday;
            else if (strcmp(token, "Tuesday") == 0)
                currentDay = Tuesday;
            else if (strcmp(token, "Wednesday") == 0)
                currentDay = Wednesday;
            else if (strcmp(token, "Thursday") == 0)
                currentDay = Thursday;
            else if (strcmp(token, "Friday") == 0)
                currentDay = Friday;
            else if (strcmp(token, "Saturday") == 0)
                currentDay = Saturday;
            else if (strcmp(token, "Sunday") == 0)
                currentDay = Sunday;

            token = strtok(NULL, ":");
            opens.hour = atoi(token);
            token = strtok(NULL, ",");
            opens.minute = atoi(token);

            token = strtok(NULL, ":");
            closes.hour = atoi(token);
            token = strtok(NULL, ",");
            closes.minute = atoi(token);

            // Запись данных в массивы структуры
            retail_outlets[outletIndex].working_days.days[i] = currentDay;
            retail_outlets[outletIndex].working_days.opens[i] = opens;
            retail_outlets[outletIndex].working_days.closes[i] = closes;

            i++;

            token = strtok(NULL, ",");
        }

        outletIndex++;
    }

    fclose(file);
}

void memoryFree(outlet* retail_outlets, int count) {
    int i;
    for (i = 0; i < count; i++) {
        free(retail_outlets[i].name);
        free(retail_outlets[i].specialization);
        free(retail_outlets[i].address.street);
        free(retail_outlets[i].working_days.days);
        free(retail_outlets[i].working_days.opens);
        free(retail_outlets[i].working_days.closes);
    }
    free(retail_outlets);
}

void print(outlet* retail_outlets, int index) {//стандартный вывод элемента массива retail_outlets(т.е торговой точки)
    int i;
    const char* dayNames[] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
    printf("________________________________\n");
    printf("%s\n", retail_outlets[index].name);
    printf("Adress: %d, %s\n", retail_outlets[index].address.house_number, retail_outlets[index].address.street);
    printf("Telephone: %d\n", retail_outlets[index].phone_number);
    printf("Specialization: %s\n", retail_outlets[index].specialization);
    printf("Working schedule:\n");
    for (i = 0; i < retail_outlets[index].working_days.workingDaysCount; i++) {
        printf("%s: %02d:%02d - %02d:%02d\n",
            dayNames[retail_outlets[index].working_days.days[i]],
            retail_outlets[index].working_days.opens[i].hour,
            retail_outlets[index].working_days.opens[i].minute,
            retail_outlets[index].working_days.closes[i].hour,
            retail_outlets[index].working_days.closes[i].minute);
    }
}

void all_time(outlet* retail_outlets, int count) {//вывод круглосуточных магазинов
    int i, j;
    printf("24/7 Shops:\n");
    for (i = 0; i < count; i++) {//перебираем все магазины, если какой-то соответствует условию, то пишем его
        int altm = 0;
        for (j = 0; j < retail_outlets[i].working_days.workingDaysCount; j++) {
            if (retail_outlets[i].working_days.opens[j].hour == retail_outlets[i].working_days.closes[j].hour &&
                retail_outlets[i].working_days.opens[j].minute == retail_outlets[i].working_days.closes[j].minute) {//круглосуточным магазином будем считать тот, у которого время открытия и время закрытия равны
                altm++;
            }
        }
        if (retail_outlets[i].working_days.workingDaysCount == altm)
            print(retail_outlets, i);
    }
}