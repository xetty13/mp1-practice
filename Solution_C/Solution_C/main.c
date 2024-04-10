#include "SportsmenLib.h"
#include "menu.h"
int main(int argc, char** argv) 
{
    SportsmenLib sLib;
    Sportsman n;
    Date d;
    Gender g;
    char* filename;
    char* trash[20];
    char* vid_sporta[100];
    int button = 0;
    int i = 0;
    int max = 0;
    int idx = 0;
    int count = 0;
    setlocale(LC_ALL, "ru");
    if (argc < 2)
    {
        printf("Что-то не то");
        return 1;
    }
    filename = argv[1];
    read(filename, &sLib);
    do
    {
        menu();
        scanf("%d", &button);
        switch (button)
        {
        case 1:
            write(&sLib);
            break;
        case 2:
            printf("Введите вид спорта: ");
            scanf("%s", &vid_sporta);
            for (i = 0; i < sLib.count; i++){
                if (strcmp(sLib.person[i].Sport, vid_sporta) == 0) {
                    write_sport(&sLib.person[i]);
                    printf("\n");
                }
            }
            break;
        case 3: 
            printf("Введите вид спорта: ");
            scanf("%s", &vid_sporta);
            for (i = 0; i < sLib.count; i++){
                if (strcmp(sLib.person[i].Sport, vid_sporta) == 0){
                    if (sLib.person[i].Record > max)
                    {   
                        idx = i;
                        max = sLib.person[i].Record;
                    }
                }
            }
            max = 0;
            write_sport(&sLib.person[idx]);
            printf("\n");
            break;
        }
    } while (button != 4);
    if (sLib.person != NULL)
    {
        for (i = 0; i < count; i++)
        {
            free(sLib.person[i].Name);
            free(sLib.person[i].Surname);
            free(sLib.person[i].Nation);
            free(sLib.person[i].Sport);
            free(sLib.person[i].Club);
        }
    }
    exit(1);
    return 0;
}
