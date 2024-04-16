#include "SportsmenLib.h"
#include "menu.h"
int main(int argc, char** argv) 
{
    SportsmenLib sLib;
    Sportsman n;
    Date d;
    Gender g;
    char* filename;
    char* vid_sporta[100];
    int button = 0;
    int test = 0;
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
            without_sort(&sLib, vid_sporta);
            break;
         case 3: 
            printf("Введите вид спорта: ");
            scanf("%s", &vid_sporta);
            test = sort(&sLib, vid_sporta);
            write_sport(&sLib.person[test]);
            printf("\n");
            break;
        }
    } while (button != 4);
    if (sLib.person != NULL)
    {
        free_mem(&sLib);
    }
    exit(1);
    return 0;
}
