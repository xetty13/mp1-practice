#include "Vector.h"
using namespace std;

Vector::Vector()
{
	size = 0;
	elements = nullptr;
}

//Выделение памяти
Vector::Vector(int n)
{
	size = n;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}

//Копирование 
Vector::Vector(const Vector& x)
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
	if(elements != nullptr)
		delete[] elements;
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

bool Vector::operator==(const Vector& x) const
{
	if (size != x.size)
		return false;
	for (int i = 0; i < size; i++)
		if (elements[i] != x.elements[i])
			return false;
	return true;
}

Vector Vector::operator+(const Vector& x)
{
	if (size != x.size)
	{
		cout << "Error";
		return Vector();
	}
	Vector x1(size);
	for (int i = 0; i < size; i++)
		x1.elements[i] = x.elements[i] + elements[i];
	return x1;
}

const Vector& Vector::operator=(const Vector& x) 
{
	if (*this == x)
		return x;
	if (size != x.size)
	{
		delete[] elements;
		size = x.size;
		elements = new int[size];
	}
	for (int i = 0; i < size; i++)
		elements[i] = x.elements[i];
	return *this;
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

Vector Vector::operator+(int a)
{
	Vector x1(*this);
	for (int i = 0; i < size; i++)
		x1.elements[i] += a;
	return x1;
}

Vector Vector::operator-(int a)
{
	Vector x1(*this); 
	for (int i = 0; i < size; i++)
		x1.elements[i] -=  a;
	return x1;
}

Vector Vector::operator*(int a)
{
	Vector x1(size);
	for (int i = 0; i < size; i++)
		x1.elements[i] = elements[i] * a;
	return x1;
}

int& Vector::operator[](int a)
{
	if ((a < 0) || (a > size))
		cout << "Error ";
	else
		return elements[a];
}

Vector Vector::operator+=(int a)
{
	*this = *this + a;
	return *this;
}

Vector Vector::operator-=(int a)
{
	*this = *this - a;
	return *this;
}

Vector& Vector::operator+=(const Vector & x)
{
	*this = *this + x;
	return *this;
}

Vector Vector::operator-=(Vector & x)
{
	*this = *this - x;
	return *this;
}

