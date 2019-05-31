#include "Vector.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define ERROR 777777

Vector Constructor(int _size)
{
    Vector V;
    int i;
    V.size = _size;
    V.elements = (float*)malloc(sizeof(float) * V.size);

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
    V.elements = (float*)malloc(sizeof(float) * V.size);

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
        printf("%.3f ", V.elements[i]);
    printf(")\n");
};

Vector Sum(Vector V1, Vector V2)
{
    Vector tmp;
    int i;

    if (V1.size != V2.size)
    {
        tmp = Constructor(0);
        return tmp;
    }
    tmp = Constructor(V1.size);
    for (i = 0; i < V1.size; i++)
        tmp.elements[i] = V1.elements[i] + V2.elements[i];
    return tmp;
}

Vector Minus(Vector V1, Vector V2)
{
    Vector tmp;
    int i;

    if (V1.size != V2.size)
    {
        tmp = Constructor(0);
        return tmp;
    }
    tmp = Constructor(V1.size);
    for (i = 0; i < V1.size; i++)
        tmp.elements[i] = V1.elements[i] - V2.elements[i];
    return tmp;

}

float Scalar(Vector V1, Vector V2)
{
    int i;
    float tmp = 0;

    if (V1.size != V2.size)
    {
        tmp = ERROR;
        return tmp;
    }
    for (i = 0; i < V1.size; i++)
        tmp += (V1.elements[i] * V2.elements[i]);
    return tmp;
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
    float _scalar = 0;

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


