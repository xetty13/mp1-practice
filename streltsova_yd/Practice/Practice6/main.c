#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
void main()
{
Vector *A, *B, *C, *D;
int n = 5;
double s, a, l;
A = Create(n);
B = Create(n);
Add(A);
Print(A);
Add(B);
Print(B);
C = Sum(A, B);
Print(C);
D = Diff(A, B);
Print(D);
s = Scalar(A, B);
a = Angle(A, B);
l = Length(A);
Delete(A);
Delete(B);
Delete(C);
Delete(D);
scanf("%d", &n);
}

