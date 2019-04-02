#include "Vector.h" 

//Выделяем память под вектор 
Vector Create(int n)
{
	Vector x;
	x.size = n;
	x.V = (float*)malloc(sizeof(float)*x.size);
	printf("Vector is create");
	return x;
}

//Заполняем 
Vector fill()
{
	Vector x;
	int n, i;
		printf("Enter size of your vector:");
		scanf("%d", &n);
	x.size = n;
	x.V = (float*)malloc(sizeof(float)*x.size);
	
	for (i = 0; i < n; i++)
	{
		printf("Enter coordinats of your vector");
		scanf("%d",x.V[i]);
	}
	return x;
}

//Удаление
void Delete(Vector* x)
{
	free(x->V);
	printf("Vector is delete \n");
}

Vector Sum(Vector V1, Vector V2)
{
	Vector s;
	int i;
	s = Create(V1.size);
	if (V1.size == V2.size)
	{
		for (i = 0; i < V1.size; i++)
		{
			s.V[i] = V1.V[i] + V2.V[i];
		}
		printf("Sum");
		return s;
	}
	else
	{
		printf("Error. Different sizes");
		return s;
	}
}

Vector Minus(Vector V1, Vector V2)
{
	Vector m;
	int i;
	m = Create(V1.size);
	if (V1.size == V2.size)
	{
		for (i = 0; i < V1.size; i++)
		{
			m.V[i] = V1.V[i] - V2.V[i];
		}
		printf("Minus");
		return m;
	}
	else
	{
		printf("Error. Different sizes");
		return m;
	}
}

Vector Output(Vector x)
{
	int i;
	if (x.size == 0)
		printf("Vector without coordinate");
	else
	{
		for (i = 0; i < x.size; i++)
			printf("%d", x.V);
	}
}

