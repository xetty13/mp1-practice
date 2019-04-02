#pragma once
#include <stdio.h> 

typedef struct
{
	int size;
	int *V;
}Vector;

Vector Create(int n);
Vector fill();
void Delete(Vector* x);
Vector Sum(Vector V1, Vector V2);
Vector Minus(Vector V1, Vector V2);
Vector Output(Vector x);
