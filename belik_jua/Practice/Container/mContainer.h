#pragma once
#include <iostream>
using namespace std;

template <typename T, int maxsize>
class mContainer
{
private:
    T* arr;
    int n;
public:
    mContainer();
    mContainer(int x);
    mContainer(const mContainer& temp);
    ~mContainer();

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
mContainer<T, maxsize>::mContainer()
{
    n = 0;
    arr = new T*[maxsize];
}

template <typename T, int maxsize>
mContainer<T, maxsize>::mContainer(int x)
{
    n = x;
    arr = new T[maxsize];
}

template <typename T, int maxsize>
mContainer<T, maxsize>::mContainer(const mContainer& temp)
{
    n = temp.n;
    arr = new T[maxsize];
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
bool mContainer<T, maxsize>::IsFull()const
{
    return (n == maxsize);
}

template <typename T, int maxsize>
bool mContainer<T, maxsize>::IsEmpty()const
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
    try
    {
        if (this->IsFull())
            throw 2;
        n++;
        arr[n - 1] = a;
    }
    catch (int i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
}

template <typename T, int maxsize>
void mContainer<T, maxsize>::Remove(T a)
{
    try
    {
        if (this->IsEmpty())
            throw 1;
        int j = Find(a);
        if (j == -1)
            throw 3;
        arr[j] = arr[n - 1];
        n--;
    }
    catch (int i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
}

template <typename T, int maxsize>
T* mContainer<T, maxsize>::operator[](int i)
{
    try
    {
        if ((i < 0) || (i >= n))
            throw 3;
        return &(arr[i]);
    }
    catch (int i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
}

template <typename T, int maxsize>
void mContainer<T, maxsize>::Print()const
{
    try
    {
        if (this->IsEmpty())
            throw 1;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    catch (int i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
}

template <typename T, int maxsize>
void mContainer<T, maxsize>::Fill()
{
    try
    {
        if (this->IsEmpty())
            throw 1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    catch (int i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
}