#include "Vector.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define ERROR 777777

menu()
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

Vector Constructor(int _size)
{
    Vector V;
    int i;
    V.size = _size;
    V.elements = (int*)malloc(sizeof(int) * V.size);

    for (i = 0; i < _size; i++)
    {
        V.elements[i] = 0;
    }
    return V;
}

Vector Create()
{
    Vector V;
    int i, _size;

    printf("\n");
    do
    {
        printf("  Enter size ( 1 - ...) : ");
        scanf("%d", &_size);
    } while (_size < 1);

    V.size = _size;
    V.elements = (int*)malloc(sizeof(int) * V.size);

    for (i = 0; i < _size; i++)
    {
        V.elements[i] = rand() % 20 - 10;
    }
    //printf("  Vector create\n");
    return V;
};

void Delete(Vector _V)
{
    _V.size = 0;
    free(_V.elements);
    printf("\nVector delete\n");
};

void Output(Vector V)
{
    int i;
    printf("( ");
    for (i = 0; i < V.size; i++)
        printf("%d ", V.elements[i]);
    printf(")\n");
};

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

int ChooseScalar(Vector _A, Vector _B, Vector _C)
{
    int a, b, tmp;
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

Vector Sum(Vector V1, Vector V2)
{
    Vector tmp;
    int i;

    if (V1.size == V2.size)
    {
        tmp = Constructor(V1.size);
        for (i = 0; i < V1.size; i++)
            tmp.elements[i] = V1.elements[i] + V2.elements[i];
        return tmp;
    }
    else
    {
        tmp = Constructor(0);
        return tmp;
    }
}

Vector Minus(Vector V1, Vector V2)
{
    Vector tmp;
    int i;

    if (V1.size == V2.size)
    {
        tmp = Constructor(V1.size);
        for (i = 0; i < V1.size; i++)
            tmp.elements[i] = V1.elements[i] - V2.elements[i];
        return tmp;
    }
    else
    {
        tmp = Constructor(0);
        return tmp;
    }
}

int Scalar(Vector V1, Vector V2)
{
    int i, tmp = 0;

    if (V1.size == V2.size)
    {
        for (i = 0; i < V1.size; i++)
            tmp += (V1.elements[i] * V2.elements[i]);
        return tmp;
    }
    else
    {
        tmp = ERROR;
        return tmp;
    }
}

float Lenght(Vector V1)
{
    float lenght = 0;
    int i;

        for (i = 0; i < V1.size; i++)
            lenght += V1.elements[i] * V1.elements[i];
        lenght = sqrt(lenght);
        return lenght;
}

float Angle(Vector V1, Vector V2)
{
    float angle = 0, _lenght1 = 0, _lenght2 = 0;
    int i, _scalar = 0;

    if (V1.size == V2.size)
    {
        _lenght1 = Lenght(V1);
        _lenght2 = Lenght(V2);
        _scalar = Scalar(V1, V2);
        angle = ((acos(_scalar / (_lenght1 * _lenght2)) * 180) / 3.14);
        if (angle > 90) angle = 180 - angle;
        return angle;
    }
    else
    {
        angle = ERROR;
        return angle;
    }
}


