#pragma once
#include <iostream>
using namespace std;

template <typename T, int maxsize>
class Container
{
private:
    T** arr;
    int n;
public:
    Container();
    Container(int x);
    Container(const Container& temp);
    ~Container();

    bool IsFull()const;
    bool IsEmpty()const;

    int Find(T a)const;
    void Add(T a);
    void Remove(T a);
    T* operator[](int i);

    void Print()const;
    void Fill();
};

template <typename T, int maxsize>
Container<T, maxsize>::Container()
{
    n = 0;
    arr = new T*[maxsize];
}

template <typename T, int maxsize>
Container<T, maxsize>::Container(int x)
{
    n = x;
    arr = new T*[maxsize];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new T;
    }
}

template <typename T, int maxsize>
Container<T, maxsize>::Container(const Container& temp)
{
    n = temp.n;
    arr = new T*[maxsize];
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
bool Container<T, maxsize>::IsFull()const
{
    return (n == maxsize);
}

template <typename T, int maxsize>
bool Container<T, maxsize>::IsEmpty()const
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
    if (this->IsFull())
        throw "Container is full";
    n++;
    arr[n - 1] = new T;
    *arr[n - 1] = a;
}

template <typename T, int maxsize>
void Container<T, maxsize>::Remove(T a)
{
    if (this->IsEmpty())
        throw "Container is empty";
    int j = Find(a);
    if (j == -1)
        throw "No elem";
    *arr[j] = *arr[n - 1];
    delete arr[n - 1];
    n--;
}

template <typename T, int maxsize>
T* Container<T, maxsize>::operator[](int i)
{
    if ((i < 0) || (i > n))
        throw "No elem";
    return arr[i];
}

template <typename T, int maxsize>
void Container<T, maxsize>::Print()const
{
    if ((*this).IsEmpty())
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
    if ((*this).IsEmpty())
        throw "Container is empty";
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr[i]);
    }
}