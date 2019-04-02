#pragma once

typedef struct
{
    int size;
    int* elements;
}Vector;

menu();
Vector Constructor(int _size);
Vector Create();
void Delete(Vector _V);
void Output(Vector V);
Vector ChoosePlus(Vector _A, Vector _B, Vector _C);
Vector ChooseMinus(Vector _A, Vector _B, Vector _C);
int ChooseScalar(Vector _A, Vector _B, Vector _C);
float ChooseAngle(Vector _A, Vector _B, Vector _C);
float ChooseLenght(Vector _A, Vector _B, Vector _C);
Vector Sum(Vector V1, Vector V2);
Vector Minus(Vector V1, Vector V2);
int Scalar(Vector V1, Vector V2);
float Angle(Vector V1, Vector V2);
float Lenght(Vector V1);