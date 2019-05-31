#include "Vector.h"
#include <stdio.h>
#include <Windows.h>

void menu();
Vector ChoosePlus(Vector _A, Vector _B, Vector _C);
Vector ChooseMinus(Vector _A, Vector _B, Vector _C);
float ChooseScalar(Vector _A, Vector _B, Vector _C);
float ChooseAngle(Vector _A, Vector _B, Vector _C);
float ChooseLenght(Vector _A, Vector _B, Vector _C);

void main()
{
    Vector A, B, C, Res;
    int f = 1, _menu;
    float res1 = 0, res;

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
                printf("%.3f\n", res);
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

void menu()
{
    printf("\n");
    printf(" 1) Create of Vectors\n");
    printf(" 2) Delete of Vectors\n");
    printf(" 3) Output of Vectors\n");
    printf(" 4) Sum of Vectors\n");
    printf(" 5) Subtraction of Vectors\n");
    printf(" 6) Scalar product of vectors\n");
    printf(" 7) The angle between the vectors\n");
    printf(" 8) The length of the vectors\n");
    printf(" 9) Exit\n");
    printf("\n");
}

Vector ChoosePlus(Vector _A, Vector _B, Vector _C)
{
    int a, b;
    Vector tmp;
    printf("\n");
    do
    {
        printf("  Enter the vector numbers to sum : ");
        scanf("%d %d", &a, &b);
    } while (a < 0 || a > 4 || b < 0 || b > 4);
    if (a == 1 && b == 2) tmp = Sum(_A, _B);
    if (a == 1 && b == 3) tmp = Sum(_A, _C);
    if (a == 2 && b == 3) tmp = Sum(_B, _C);
    if (a == 2 && b == 1) tmp = Sum(_A, _B);
    if (a == 3 && b == 1) tmp = Sum(_A, _C);
    if (a == 3 && b == 2) tmp = Sum(_B, _C);
    if (a == 1 && b == 1) tmp = Sum(_A, _A);
    if (a == 2 && b == 2) tmp = Sum(_B, _B);
    if (a == 3 && b == 3) tmp = Sum(_C, _C);
    if (tmp.size == 0)
    {
        printf(" !!! Vector sizes are not equal! Try again\n");
        return tmp;
    }
    else return tmp;
}

Vector ChooseMinus(Vector _A, Vector _B, Vector _C)
{
    Vector tmp;
    int a, b;
    printf("\n");
    do
    {
        printf("  Enter the vector numbers to subtraction ");
        scanf("%d %d", &a, &b);
    } while (a < 0 || a > 4 || b < 0 || b > 4);
    if (a == 1 && b == 2) tmp = Minus(_A, _B);
    if (a == 1 && b == 3) tmp = Minus(_A, _C);
    if (a == 2 && b == 3) tmp = Minus(_B, _C);
    if (a == 2 && b == 1) tmp = Minus(_B, _A);
    if (a == 3 && b == 1) tmp = Minus(_C, _A);
    if (a == 3 && b == 2) tmp = Minus(_C, _B);
    if (a == 1 && b == 1) tmp = Minus(_A, _A);
    if (a == 2 && b == 2) tmp = Minus(_B, _B);
    if (a == 3 && b == 3) tmp = Minus(_C, _C);
    if (tmp.size == 0)
    {
        printf(" !!! Vector sizes are not equal! Try again\n");
        return tmp;
    }
    else return tmp;
}

float ChooseScalar(Vector _A, Vector _B, Vector _C)
{
    int a, b;
    float tmp;
    printf("\n");
    do
    {
        printf("  Enter the vector numbers to Scalar Product ");
        scanf("%d %d", &a, &b);
    } while (a < 0 || a > 4 || b < 0 || b > 4);
    if (a == 1 && b == 2) tmp = Scalar(_A, _B);
    if (a == 1 && b == 3) tmp = Scalar(_A, _C);
    if (a == 2 && b == 3) tmp = Scalar(_B, _C);
    if (a == 2 && b == 1) tmp = Scalar(_B, _A);
    if (a == 3 && b == 1) tmp = Scalar(_C, _A);
    if (a == 3 && b == 2) tmp = Scalar(_C, _B);
    if (a == 1 && b == 1) tmp = Scalar(_A, _A);
    if (a == 2 && b == 2) tmp = Scalar(_B, _B);
    if (a == 3 && b == 3) tmp = Scalar(_C, _C);
    if (tmp == ERROR)
    {
        printf(" !!! Vector sizes are not equal! Try again\n");
        return tmp;
    }
    else return tmp;
}

float ChooseAngle(Vector _A, Vector _B, Vector _C)
{
    int a, b;
    float tmp;
    printf("\n");
    do
    {
        printf("  Enter the vector numbers to The angle between the vectors ");
        scanf("%d %d", &a, &b);
    } while (a < 0 || a > 4 || b < 0 || b > 4);
    if (a == 1 && b == 2) tmp = Angle(_A, _B);
    if (a == 1 && b == 3) tmp = Angle(_A, _C);
    if (a == 2 && b == 3) tmp = Angle(_B, _C);
    if (a == 2 && b == 1) tmp = Angle(_B, _A);
    if (a == 3 && b == 1) tmp = Angle(_C, _A);
    if (a == 3 && b == 2) tmp = Angle(_C, _B);
    if (a == 1 && b == 1) tmp = Angle(_A, _A);
    if (a == 2 && b == 2) tmp = Angle(_B, _B);
    if (a == 3 && b == 3) tmp = Angle(_C, _C);
    if (tmp == ERROR)
    {
        printf(" !!! Vector sizes are not equal! Try again\n");
        return tmp;
    }
    else return tmp;
}

float ChooseLenght(Vector _A, Vector _B, Vector _C)
{
    int a;
    float tmp;
    printf("\n");
    do
    {
        printf("  Enter the vector numbers to Lenght ");
        scanf("%d", &a);
    } while ((a < 0) || (a > 4));
    if (a == 1) tmp = Lenght(_A);
    if (a == 2) tmp = Lenght(_B);
    if (a == 3) tmp = Lenght(_C);
    if (tmp == ERROR)
    {
        printf(" !!! Vector sizes are not equal! Try again\n");
        return tmp;
    }
    else return tmp;
}