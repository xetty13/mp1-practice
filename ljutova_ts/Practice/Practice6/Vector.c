#include "Vector.h" 

//Выделение памяти под вектор 
Vector Create(int n)
{
	Vector x;
	int i;
	x.size = n;
	x.V = (float*)malloc(sizeof(float)*x.size);
	for (i = 0; i < n; i++)
		x.V[i] = 0;
	printf("Vector is create");
	return x;
}

//Заполнение 
Vector fill()
{
	Vector x;
	int i, n;
	printf("Enter size of your vector:");
	scanf("%d", &n);
	x.size = n;
	x.V = (float*)malloc(sizeof(float)*x.size);
	printf("Enter coordinats of your vector:");
	for (i = 0; i < x.size; i++)
	{
		scanf("%d", x.V[i]);
	}
	printf("Vector fill");
	return x;
}

//Удаление 
void Delete(Vector* x)
{
	free(x->V);
	printf("Vector is delete \n");
}

//Суммирование 
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


//Вычитание 
Vector Sub(Vector V1, Vector V2)
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

//Скалярное произведение 
Vector scalar(Vector V1, Vector V2)
{
	int i;
	Vector sc;
	sc = Create(V1.size);
	if (V1.size == V2.size)
	{
		for (i = 0; i < V1.size; i++)
		{
			sc.V[i] = V1.V[i] * V2.V[i];
		}
		printf("scalar");
		return sc;
	}
	else
	{
		printf("Error. Different sizes");
		return sc;
	}
}

//Длина вектора
int Length(Vector V)
{
	int i, l;

	for (i = 0; i < V.size; i++)
		l += V.V[i] * V.V[i];
	l = sqrt(l);
	return l;
}


//Вывод 
Vector Output(Vector x)
{
	int i;
	if (x.size == 0)
		printf("Vector without coordinate");
	else
	{
		for (i = 0; i < x.size; i++)
			printf("%d", x.V[i]);
	}
}