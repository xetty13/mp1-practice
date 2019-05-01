#include "mContainer.h"
#include <iostream>
using namespace std;

template <typename T, int maxsize>
mContainer<T, maxsize>::mContainer()
{
    n = 0;
    arr = NULL;
}

template <typename T, int maxsize>
mContainer<T, maxsize>::mContainer(int x)
{
    n = x;
    arr = new T[n];
}

template <typename T, int maxsize>
mContainer<T, maxsize>::mContainer(const mContainer& temp)
{
    n = temp.n;
    arr = new T[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp.arr[i];
    }
}

template <typename T, int maxsize>
mContainer<T, maxsize>::~mContainer()
{
    delete arr;
    n = 0;
}

template <typename T, int maxsize>
bool mContainer<T, maxsize>::IsFull()
{
    ruturn(n == maxsize);
}

template <typename T, int maxsize>
bool mContainer<T, maxsize>::IsEmpty()
{
    return (n == 0);
}

template <typename T, int maxsize>
int mContainer<T, maxsize>::Find(T a)const
{
    for (int i = 0; i < n; i++)
        if (arr[i] == a)
            return i;
    return -1;
}

template <typename T, int maxsize>
void mContainer<T, maxsize>::Add(T a)
{
    if (*this->IsFull())
        throw "Container is full";
    T* tmp = new T[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = arr[i];
    }
    delete arr;
    n++;
    arr = new T[n];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = tmp[i];
    }
    delete tmp;
    arr[n - 1] = a;
}

template <typename T, int maxsize>
void mContainer<T, maxsize>::Remove(T a)
{
    if (*this->IsEmpty())
        throw "Container is empty";
    int j = Find(a);
    if (j == -1)
        throw "No elem";
    T* tmp = new T[n - 1];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != j)
            tmp[k++] = arr[i];
    }
    delete arr;
    n--;
    arr = new T[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = tmp[i];
    }
    delete tmp;
}

template <typename T, int maxsize>
T& mContainer<T, maxsize>::operator[](int i)
{
    if ((i < 0) || (i > n))
        throw "No elem";
    return &(arr[i]);
}

template <typename T, int maxsize>
void mContainer<T, maxsize>::Print()const
{
    if (*this->IsEmpty())
        throw "Container is empty";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T, int maxsize>
void mContainer<T, maxsize>::Fill()
{
    if (*this->IsEmpty())
        throw "Container is empty";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}