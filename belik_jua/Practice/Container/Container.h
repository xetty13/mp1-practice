#pragma once

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

    bool IsFull();
    bool IsEmpty();

    int Find(T a)const;
    void Add(T a);
    void Remove(T a);
    T& operator[](int i);

    void Print()const;
    void Fill();
};
