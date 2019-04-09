#include "Exception.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include "Vector.h"
using namespace std;

void Vector::menu()
{
    cout << "\n         MENU\n";
    cout << " 1) Output of Vectors\n";
    cout << " 2) Multiplication by a const\n";
    cout << " 3) Sum of Vectors\n";
    cout << " 4) Subtraction of Vectors\n";
    cout << " 5) Scalar product of vectors\n";
    cout << " 6) The length of the vectors\n";
    cout << " 7) Addition with const\n";
    cout << " 8) Indexing\n";
    cout << " 9) Exit\n";
    cout << "\n";
}

Vector::Vector(int _size)
{
    size = _size;
    elements = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
        elements[i] = rand() % 10;
}

Vector::~Vector()
{
    size = 0;
    delete[]elements;
}

Vector::Vector(const Vector & tmp)
{
    size = tmp.size;
    elements = new int[size];
    for (int i = 0; i < size; i++)
        elements[i] = tmp.elements[i];
}

Vector Vector::operator+(const Vector & x)
{
    if (size != x.size)
        throw Exception("Vector sizes are not equal! Try again");
    else
    {
        Vector tmp(size);
        for (int i = 0; i < size; i++)
            tmp.elements[i] = elements[i] + x.elements[i];
        return tmp;
    }
}

void Vector::Output()
{
    cout << "( ";
    for (int i = 0; i < size; i++)
        cout << elements[i] << " ";
    cout << ")\n";
}

Vector Vector::operator*(int a)
{
    Vector tmp(size);
    for (int i = 0; i < size; i++)
        tmp.elements[i] = elements[i] * a;
    return tmp;
}

Vector Vector::operator-(const Vector & tmp)
{
    if (size != tmp.size)
        throw Exception("Vector sizes are not equal! Try again");
    else
    {
        Vector res(tmp.size);
        for (int i = 0; i < size; i++)
            res.elements[i] = elements[i] - tmp.elements[i];
        return res;
    }
}

int Vector::Scalar(Vector& V1)
{
    if(V1.size != size)
        throw Exception("Vector sizes are not equal! Try again");
    else 
    {
        int tmp = 0;
        for (int i = 0; i < V1.size; i++)
            tmp += (V1.elements[i] * elements[i]);
        return tmp;
    }
}

double Vector::Lenght()
{
    float lenght = 0;
    for (int i = 0; i < size; i++)
        lenght += elements[i] * elements[i];
    lenght = sqrt(lenght);
    return lenght;
}

Vector Vector::operator+(int a)
{
    Vector tmp(size);
    for (int i = 0; i < size; i++)
        tmp.elements[i] = elements[i] + a;
    return tmp;
}

int Vector::operator[](int a)
{
    if ((a < 0) || (a > size))
        throw Exception("Not correct index!");
    return elements[a-1];
}

Vector Vector::operator+=(int a)
{
    Vector tmp(size);
    for (int i = 0; i < size; i++)
        tmp.elements[i] += a;
    return tmp;
}

Vector Vector::operator*=(int a)
{
    Vector tmp(size);
    for (int i = 0; i < size; i++)
        tmp.elements[i] *= a;
    return tmp;
}

Vector Vector::operator-=(int a)
{
    Vector tmp(size);
    for (int i = 0; i < size; i++)
        tmp.elements[i] -= a;
    return tmp;
}

Vector Vector::operator+=(const Vector & tmp)
{
    if (size != tmp.size)
        throw Exception("Vector sizes are not equal! Try again");
    else
    {
        Vector res(tmp.size);
        for (int i = 0; i < size; i++)
            res.elements[i] += tmp.elements[i];
        return res;
    }
}

Vector Vector::operator*=(const Vector & tmp)
{
    if (size != tmp.size)
        throw Exception("Vector sizes are not equal! Try again");
    else
    {
        Vector res(tmp.size);
        for (int i = 0; i < size; i++)
            res.elements[i] *= tmp.elements[i];
        return res;
    }
}

Vector Vector::operator-=(const Vector & tmp)
{
    if (size != tmp.size)
        throw Exception("Vector sizes are not equal! Try again");
    else
    {
        Vector res(tmp.size);
        for (int i = 0; i < size; i++)
            res.elements[i] -= tmp.elements[i];
        return res;
    }
}

void* Vector::operatornew(size_t Size)
{
    void* tmp = malloc(Size);
    if (tmp == NULL)
        throw("Empty vector!");
    return tmp;
}

void Vector::operatordelete(void* tmp)
{
    delete (Vector*)tmp;
}

ostream & operator<<(ostream & os, const Vector & tmp)
{
    cout << "( ";
    for (int i = 0; i < tmp.size; i++)
        os << tmp.elements[i] << " ";
    cout << ")";
    return os;
};
