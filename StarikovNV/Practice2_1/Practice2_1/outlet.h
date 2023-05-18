#ifndef _OUTLET_H
#define _OUTLET_H

typedef enum {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
} Day;

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char* street;
    int house_number;
} address;

// структура для хранения рабочих дней магазина
typedef struct {
    Day* days;
    Time* opens;
    Time* closes;
    int workingDaysCount;
} workingDays;

// структура для хранения сведений о торговой точке
typedef struct {
    char* name;
    address address;
    int phone_number;
    char* specialization;
    workingDays working_days;
} outlet;

int count(char* path);
outlet* allocateMemory(int outletCount, char* path);
char* start();
void readDataFromFile(outlet* retail_outlets, char* path, int count);
void all_time(outlet* retail_outlets, int count);
void memoryFree(outlet* retail_outlets, int count);
#endif // !_OUTLET_H
