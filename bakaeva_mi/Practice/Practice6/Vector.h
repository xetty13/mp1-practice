#pragma once

typedef struct
{
    int size;
    float* elements;
}Vector;

Vector Constructor(int _size);
Vector Create();
void Delete(Vector _V);
void Output(Vector V);
Vector Sum(Vector V1, Vector V2);
Vector Minus(Vector V1, Vector V2);
float Scalar(Vector V1, Vector V2);
float Angle(Vector V1, Vector V2);
float Lenght(Vector V1);