#include <stdio.h>
#include <locale.h>

#define MAX 7
#define PROCENT 37
#define MAX_LEN 17

int barcode, count = 0, scancheck;
char barcodes[MAX][5] = { "7899" , "9730" , "4430" , "3965" , "5364" , "4828" , "7281" };
char name[MAX][MAX_LEN] = { "Сок Мультифрукт","Хлеб нарезной","Булки из Атака",
"Big Bon","Сыр с плесенью","Молоко Свежесть","Бумага Туалетная" };
int price[MAX] = { 62, 27, 19, 21, 499, 32, 52 };
int sale[MAX] = { 5, 2, 50, 10, 1, 9, 9 };
int check[MAX];
int count_check[MAX];
float sumall[MAX];


void pmenu()
{
    printf("\n");
    printf("Меню кассы:\n");
    printf("1. Сканировать товар\n");
    printf("2. Добавить в чек\n");
    printf("3. Показать чек\n");
    printf("4. Посчитать стоимость\n");
}

int searchcod(int cod)
{
    int i = -1;
    for (i = 0; i < MAX; i++) {
        if (cod == atoi(barcodes[i]))
            break;
    }
    if (i >= MAX)
        i = -1;
    return i;
}

void scancod()
{
    int i, j;
    float skid = 0.0f, k = 0.0f;
    printf("Введите штрих-код: ");
    scanf("%d", &barcode);
    i = searchcod(barcode);
    scancheck = i;
    if (i == -1)
    {
        printf("Неверный штрих-код\n");
    }
    else
    {
        skid = price[i] * (1 - (float)(sale[i] / 100.00));
        for (j = 0; j < MAX_LEN; j++)
            printf("%c", name[i][j]);
        printf("| Цена за ед. %4d | Скидка %2d%c | Цена со скидкой %.2f\n",
            price[i], sale[i], PROCENT, skid);
    }
}

void add()
{
    if (scancheck == -1)
    {
        printf("Неверный штрих-код\n ");
    }
    else
    {
        printf("\aТовар добавлен в чек.\n");
        check[scancheck] = 1;
        count_check[scancheck] += 1;
    }
}

void checkall()
{
    int i, j;
    float skid = 0.0f;
    printf("\n");
    printf("|---------|-----------------|-------------|--------|-----------------|--------|\n");
    printf("|Штрих-код|   Наименование  | Цена за ед. | Скидка | Цена со скидкой | Кол-во |\n");
    printf("|---------|-----------------|-------------|--------|-----------------|--------|\n");
    for (i = 0; i < MAX; i++)
    {
        if (check[i] == 1)
        {
            skid = price[i] * (1 - (float)(sale[i] * 0.01));
            printf("| %7s | ", barcodes[i]);
            for (j = 0; j < MAX_LEN - 1; j++)
                printf("%c", name[i][j]);
            printf("| %11d | %5d%c | %15.2f | %7d|\n", price[i], sale[i], PROCENT, skid, count_check[i]);
            j = 0;
        }
    }
    printf("|---------|-----------------|-------------|--------|-----------------|--------|\n");
    printf("\n");
    return;
}

float totalsum()
{
    int i;
    float itog = 0.0f;
    for (i = 0; i < MAX; i++)
    {
        if (check[i] == 1)
        {
            sumall[i] = (price[i] * (1 - (float)(sale[i] * 0.01))) * count_check[i];
        }
    }
    for (i = 0; i < MAX; i++)
    {
        itog += sumall[i];
    }
    printf("Общая стоимость: %.2f рублей\n", itog);
}

void main()
{
    int menu;
    setlocale(LC_ALL, "Russian");
    pmenu();
    while (1)
    {
        printf("Введите номер операции: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            scancod();
            break;
        case 2:
            add();
            break;
        case 3:
            checkall();
            break;
        case 4:
            totalsum();
            break;
        default:
            pmenu();
            break;
        }
    }
}
