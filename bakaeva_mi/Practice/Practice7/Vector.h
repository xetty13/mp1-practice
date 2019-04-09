#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
using namespace std;

struct Vector
{
    private:
    int size;
    int *elements;

    public:
    //Function
    Vector(int);
    Vector(const Vector &);
    ~Vector();
    void menu();
    void Output();
    Vector operator*(int);
    Vector operator+(const Vector &);
    Vector operator-(const Vector &);
    int Scalar(Vector&);
    double Lenght();
    Vector operator+(int);
    int operator[](int);
    Vector operator+=(int);
    Vector operator*=(int);
    Vector operator-=(int);
    Vector operator+=(const Vector &);
    Vector operator*=(const Vector &);
    Vector operator-=(const Vector &);
    void* operatornew(size_t);
    void operatordelete(void*);

    friend ostream& operator<<(ostream &, const Vector &);
};
#endif
