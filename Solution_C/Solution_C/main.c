#include <locale.h>
#include "func.h"
#define MAX 10

int main(int argc, char** argv) {
    char* filename;
    int button = 0;
    int count = 0;
    int i = 0;
    char* vid_sporta[100];
    char* trash[256];
    setlocale(LC_ALL, "ru");
    if (argc < 2)
    {
        printf("������������ ��������");
        return 999;
    }
    filename = argv[1];
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("���� �� ������\n");
        abort();
    }
    fscanf(f, "%d", &count);
    /*fgets(trash, 256, f);*/
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
            printf("������� ��� ������:\n");
            scanf("%s", &vid_sporta);
            for (i = 0; i < count; i++) {
                if (strcmp(n[i].Sport, vid_sporta) == 0) {
                    write(&n[i]);
                    printf("\n");
                }
            }
            break;
        case 3:;               
        }
    } while (button != 4);
    for (i = 0; i < count; i++) {
        free(n[i].Name);
        free(n[i].Surname);
        free(n[i].Gender);
        free(n[i].DateOfBirth);
        free(n[i].Nation);
        free(n[i].Sport);
        free(n[i].Club);

    }
     exit(1);
     return 0;
}
