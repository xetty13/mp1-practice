#include <locale.h>
#include "func.h"
#define MAX 10

int main(int argc, char** argv) {
    char* filename;
    int button = 0;
    int count = 0;
    int i = 0;
    char* vid_sporta[100];
    char* shit[256];
    info n[MAX];//массив структур

    setlocale(LC_ALL, "ru");
    if (argc < 2)
    {
        printf("Некорректный аргумент");
        return 999;
    }
    filename = argv[1];
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Файл не найден\n");
        abort();
    }
    fscanf(f, "%d", &count);
    /*fgets(shit, 256, f);*/
    for (i = 0; i < count; i++) {
        read(f, &n[i]);
    }
    fclose(f);
    do {
        menu();
        scanf("%d", &button);
        switch (button) {
        case 1:
            for (i = 0; i < count; i++) {
                printf("%d. ", i + 1);
                write(&n[i]);
                printf("\n");
            }
            break;
        case 2:
            printf("Введите вид спорта:\n");
            scanf("%s", &vid_sporta);
            for (i = 0; i < count; i++) {
                if (strcmp(n[i].Sport, vid_sporta) == 0) {
                    write(&n[i]);
                    printf("\n");
                }
            }
        case 3:;               
        }
    } while (button != 4);
     exit(1);
     return 0;
}
