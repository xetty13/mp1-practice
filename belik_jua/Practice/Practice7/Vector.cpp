#pragma once
#include "Vector.h"
#include <iostream>
#include <math.h>
using namespace std;

Vector::Vector()
{
    size = 0;
    arr = NULL;
}

Vector::Vector(int x)
{
    size = x;
    arr = new double[x];
}

Vector::Vector(const Vector& vec)
{
    size = vec.size;
    arr = new double[vec.size];
    for (int i = 0; i < size; i++)
        arr[i] = vec.arr[i];
}

Vector::~Vector()
{
    delete[] arr;
    size = 0;
}

Vector Vector::operator+ (const Vector & tmp) const
{
    if (size != tmp.size)
        throw "Size";
    Vector res(tmp);
    for (int i = 0; i < size; i++)
        res.arr[i] += arr[i];
    return res;
}

Vector Vector::operator- (const Vector & tmp) const
{
    if (size != tmp.size)
        throw "Size";
    Vector res(*this);
    for (int i = 0; i < size; i++)
        res.arr[i] -= tmp.arr[i];
    return res;
}

double Vector::operator* (const Vector & tmp) const
{
    if (size != tmp.size)
        throw 0;
    double res = 0;
    for (int i = 0; i < size; i++)
        res += arr[i] * tmp.arr[i];
    return res;
}

Vector Vector::operator+ (double tmp) const
{
    Vector res(*this);
    for (int i = 0; i < size; i++)
        res.arr[i] += tmp;
    return res;
}

Vector Vector::operator- (double tmp) const
{
    Vector res(*this);
    for (int i = 0; i < size; i++)
        res.arr[i] -= tmp;
    return res;
}
Vector Vector::operator* (double tmp) const
{
    Vector res(*this);
    for (int i = 0; i < size; i++)
        res.arr[i] *= tmp;
    return res;
}

Vector Vector::operator= (const Vector & tmp)
{
    delete[] arr;
    size = tmp.size;
    arr = new double[size];
    for (int i = 0; i < size; i++)
        arr[i] = tmp.arr[i];
    return *this;
}

double* Vector::operator[] (int i) const
{
    if ((i < 0) || (i >= size))
        throw "No elem";
    return &(arr[i]);
}

double Vector::Lenght() const
{
    double res = 0;
    for (int i = 0; i < size; i++)
        res += arr[i] * arr[i];
    res = sqrt(res);
    return res;
}

Vector Vector::operator+= (const Vector & tmp)
{
    if (size != tmp.size)
        throw "Size";
    for (int i = 0; i < size; i++)
        arr[i] += tmp.arr[i];
    return *this;
}

Vector Vector::operator-= (const Vector & tmp)
{
    if (size != tmp.size)
        throw "Size";
    for (int i = 0; i < size; i++)
        arr[i] -= tmp.arr[i];
    return *this;
}

Vector Vector::operator+= (double tmp)
{
    for (int i = 0; i < size; i++)
        arr[i] += tmp;
    return *this;
}

Vector Vector::operator-= (double tmp)
{
    for (int i = 0; i < size; i++)
        arr[i] -= tmp;
    return *this;
}

Vector Vector::operator*= (double tmp)
{
    for (int i = 0; i < size; i++)
        arr[i] *= tmp;
    return *this;
}

void* Vector::operator new[](size_t size) 
{
    void* p = new Vector[size];
    return p;
}

void Vector::operator delete[](void *p)
{
    delete[] p;
}

void Vector::PrintVector() const
{
    if (size == 0)
        throw "Size";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl << endl;
}

void Vector::Fill()
{
    if (size == 0)
        throw "Size";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}