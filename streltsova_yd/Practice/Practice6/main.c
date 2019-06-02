#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
void main()
{
    Vector* A, * B, * C, * D;
    int n1 = 5, n2 = 3;
    float s, a, l;
    A = Create(n1);
    B = Create(n1);
    D = Create(n2);
    Add(A);
    Print(A);
    Add(B);
    Print(B);
    Add(D);
    Print(D);
    C = Sum(A, D);
    C = Sum(A, B);
    Print(C);
    C = Diff(A, B);
    Print(C);
    s = Scalar(A, B);
    a = Angle(A, B);
    l = Length(A);
    printf("Scalar product = %f\n", s);
    printf("Angle = %f\n", a);
    printf("Length = %f\n", l);
    Delete(A);
    Delete(B);
    Delete(C);
    Delete(D);
}
