#include "Vector.h"
#include <stdio.h>
#include <Windows.h>

void main()
{
    Vector A, B, C, Res;
    int f = 1, _menu, res;
    float res1 = 0;

    printf("     Hello, it's multidimensional vector\n");
    menu();
    
    A = Create();
    printf("  V1 = ");
    Output(A);
    B = Create();
    printf("  V2 = ");
    Output(B);
    C = Create();
    printf("  V3 = ");
    Output(C);
   
    while (f == 1)
    {
        do
        {
            printf("\n");
            printf("  Select options (1 - 10): ");
            scanf("%d", &_menu);
        } while ((_menu >= 9) && (_menu <= 1));
        switch (_menu)
        {
        case(1):
        {
            A = Create();
            printf("  V1 = ");
            Output(A);
            B = Create();
            printf("  V2 = ");
            Output(B);
            C = Create();
            printf("  V3 = ");
            Output(C);
            break;
        }
        case(2):
        {
            Delete(A);
            Delete(B);
            Delete(C);
            break;
        }
        case(3):
        {
            printf("  V1 = ");
            Output(A);
            printf("  V2 = ");
            Output(B);
            printf("  V3 = ");
            Output(C);
            break;
        }
        case(4):
        {
            Res = ChoosePlus(A, B, C);
            if (Res.size != 0)
            {
                printf("  Res = ");
                Output(Res);
            }
            break;
        }
        case(5): {
            Res = ChooseMinus(A, B, C);
            if (Res.size != 0)
            {
                printf("  Res = ");
                Output(Res);
            }
            break;
        }
        case(6):
        {
            res = ChooseScalar(A, B, C);
            if (res != 777777)
            {
                printf("  Res = ");
                printf("%d\n", res);
            }
            break;
        }
        case(7):
        {
            res1 = ChooseAngle(A, B, C);
            if (res1 != 777777)
            {
                printf("  Res = ");
                printf("%.03f degree\n", res1);
            }
            break;
        }
        case(8):
        {
            res1 = ChooseLenght(A, B, C);
            if (res1 != 777777)
            {
                printf("  Res = ");
                printf("%.03f\n", res1);
            }
            break;
        }
        case(9): 
        {
            f = 0;
            printf("  Goodbay;)\n");
        };
        }
    }
}