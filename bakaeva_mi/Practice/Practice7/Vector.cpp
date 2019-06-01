#include <iostream>
#include <ctime>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
#include "Vector.h"
using namespace std;

Vector::Vector(int _size)
{
    size = _size;
    elements = new float[size];
    srand((unsigned)time(0));
    for (int i = 0; i < size; i++)
        elements[i] = static_cast <float> (rand())
        / static_cast <float> (RAND_MAX );
}

Vector::~Vector()
{
    size = 0;
    delete[]elements;
}

Vector::Vector(const Vector & tmp)
{
    size = tmp.size;
    elements = new float[size];
    for (int i = 0; i < size; i++)
        elements[i] = tmp.elements[i];
}

Vector Vector::operator+(const Vector & x)
{
    if (size != x.size)
        throw Exception_sizes("Vector sizes are not equal!");
    Vector tmp(size);
    for (int i = 0; i < size; i++)
        tmp.elements[i] = elements[i] + x.elements[i];
    return tmp;
}

void Vector::Output() const
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
        throw Exception_sizes("Vector sizes are not equal!");
    Vector res(tmp.size);
        for (int i = 0; i < size; i++)
            res.elements[i] = elements[i] - tmp.elements[i];
        return res;
}

float Vector::Scalar(Vector& V1)
{
    if(V1.size != size)
        throw Exception_sizes("Vector sizes are not equal!");
    else 
    {
        float tmp = 0;
        for (int i = 0; i < V1.size; i++)
            tmp += (V1.elements[i] * elements[i]);
        return tmp;
    }
}

double Vector::Lenght() const
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

float Vector::operator[](int a) const
{
    if ((a < 0) || (a > size))
        throw Exception_ind("Not correct index!");
    return elements[a];
}

float& Vector::operator[](int ind)
{
    if ((ind < 0) || (ind > size))
        throw Exception_ind("Not correct index!");
    return elements[ind];
}

Vector& Vector::operator+=(int a)
{
    for (int i = 0; i < size; i++)
        elements[i] += a;
    return *this;
}

Vector& Vector::operator*=(int a)
{
    for (int i = 0; i < size; i++)
        elements[i] *= a;
    return *this;
}

Vector& Vector::operator-=(int a)
{
    for (int i = 0; i < size; i++)
        elements[i] -= a;
    return *this;
}

Vector& Vector::operator+=(const Vector & tmp)
{
    if (size != tmp.size)
        throw Exception_sizes("Vector sizes are not equal!");
    for (int i = 0; i < size; i++)
        elements[i] += tmp.elements[i];
    return *this;
}

Vector& Vector::operator*=(const Vector & tmp)
{
    if (size != tmp.size)
        throw Exception_sizes("Vector sizes are not equal!");
    for (int i = 0; i < size; i++)
        elements[i] *= tmp.elements[i];
    return *this;
}

Vector& Vector::operator-=(const Vector & tmp)
{
    if (size != tmp.size)
        throw Exception_sizes("Vector sizes are not equal!");
    for (int i = 0; i < size; i++)
        elements[i] -= tmp.elements[i];
    return *this;
}

void* Vector::operator new(size_t Size)
{
    void* tmp = malloc(Size);
    return tmp;
}

void Vector::operator delete(void* tmp)
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
