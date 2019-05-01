#include "Container.h"
#include <iostream>
using namespace std;

template <typename T, int maxsize>
Container<T, maxsize>::Container()
{
    n = 0;
    arr = NULL;
}

template <typename T, int maxsize>
Container<T, maxsize>::Container(int x)
{
    n = x;
    arr = new T*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new T;
    }
}

template <typename T, int maxsize>
Container<T, maxsize>::Container(const Container& temp)
{
    n = temp.n;
    arr = new T*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new T;
        (*arr[i]) = temp.*arr[i];
    }
}

template <typename T, int maxsize>
Container<T, maxsize>::~Container()
{
    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }
    delete arr;
    n = 0;
}

template <typename T, int maxsize>
bool Container<T, maxsize>::IsFull()
{
    ruturn(n == maxsize);
}

template <typename T, int maxsize>
bool Container<T, maxsize>::IsEmpty()
{
    return (n == 0);
}

template <typename T, int maxsize>
int Container<T, maxsize>::Find(T a)const
{
    for (int i = 0; i < n; i++)
        if (*(arr[i]) == a)
            return i;
    return -1;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Add(T a)
{
    if (*this->IsFull())
        throw "Container is full";
    T** tmp = new T*[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new T;
        *(tmp[i]) = *(arr[i]);
        delete arr[i];
    }
    delete arr;
    n++;
    arr = new T*[n];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = new T;
        *(arr[i]) = *(tmp[i]);
        delete tmp[i];
    }
    delete tmp;
    *(arr[n - 1]) = a;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Remove(T a)
{
    if (*this->IsEmpty())
        throw "Container is empty";
    int j = Find(a);
    if (j == -1)
        throw "No elem";
    T** tmp = new T*[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != j)
        {
            tmp[i] = new T;
            *(tmp[k++]) = *(arr[i]);
            delete arr[i];
        }
    }
    delete arr;
    n--;
    arr = new T*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new T;
        *(arr[i]) = *(tmp[i]);
        delete tmp[i];
    }
    delete tmp;
}

template <typename T, int maxsize>
T& Container<T, maxsize>::operator[](int i)
{
    if ((i < 0) || (i > n))
        throw "No elem";
    return arr[i];
}

template <typename T, int maxsize>
void Container<T, maxsize>::Print()const
{
    if (*this->IsEmpty())
        throw "Container is empty";
    for (int i = 0; i < n; i++)
    {
        cout << *(arr[i]) << " ";
    }
    cout << endl;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Fill()
{
    if (*this->IsEmpty())
        throw "Container is empty";
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr[i]);
    }
}