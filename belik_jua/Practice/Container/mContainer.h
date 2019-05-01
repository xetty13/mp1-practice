#pragma once

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

    bool IsFull();
    bool IsEmpty();

    int Find(T a)const;
    void Add(T a);
    void Remove(T a);
    T& operator[](int i);

    void Print()const;
    void Fill();
};