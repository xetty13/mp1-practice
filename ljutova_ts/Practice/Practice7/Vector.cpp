#include "Vector.h"
#include <iostream>
using namespace std;

//Выделение памяти
Vector::Vector(int n)
{
	size = n;
	elements = new int[size];
	for (int i = 0; i < size; i++)
	elements[i] = 0;
}

//Копирование 
Vector::Vector(Vector& x)
{
	size = x.size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = x.elements[i];
}

//Деструктор
Vector::~Vector()
{
	size = 0;
	delete[]elements;
}

//Вывод
void Vector::Output()
{
	for (int i = 0; i < size; i++)
		cout << elements[i] << " " ;
}

//Ввод
void Vector::Input()
{
	for (int i = 0; i < size; i++)
		cin >> elements[i];
}

bool Vector::operator==(Vector& x)
{
	int f = 0;
	if (size == x.size)
	{
		for (int i = 0; i < size; i++)
			if (elements[i] = x.elements[i])
				f = 0;
			else {
				f = 1;
				return false;
			}
	}
	if (f == 0)
		return true;
}

Vector Vector::operator=(Vector& x)
{
	if (*this == x)
		return x;
	if (size != x.size)
	{
		delete[]elements;
		size = x.size;
		elements = new int[size];
	}
	for (int i = 0; i < size; i++)
		elements[i] = x.elements[i];
	return *this;
}

Vector Vector::operator+( Vector& x)
{
	if (size != x.size)
		cout << "Eror";
	if (size == x.size)
	{
		Vector x1(size);
		for (int i = 0; i < size; i++)
			x1.elements[i] = x.elements[i] + elements[i];
		return x1;
	}
}


Vector Vector::operator-(Vector& x)
{
	if (size != x.size)
		cout << "Error";
	{
		Vector x1(size);
		for (int i = 0; i < size; i++)
			x1.elements[i] = elements[i] - x.elements[i];
		return x1;
	}
}

ostream & operator<<(ostream & o, const Vector & x)
{
	for (int i = 0; i < x.size; i++)
		o << x.elements[i] << " ";
	return o;
};

