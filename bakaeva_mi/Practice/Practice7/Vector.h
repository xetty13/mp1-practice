#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
using namespace std;

struct Vector
{
    private:
    int size;
    float *elements;

    public:
    //Function
    Vector(int);
    Vector(const Vector &);
    ~Vector();
    void Output() const;
    Vector operator*(int);
    Vector operator+(const Vector &);
    Vector operator-(const Vector &);
    float Scalar(Vector&);
    double Lenght() const;
    Vector operator+(int);
    float operator[](int) const;
    float& operator[](int);
    Vector& operator+=(int);
    Vector& operator*=(int);
    Vector& operator-=(int);
    Vector& operator+=(const Vector &);
    Vector& operator*=(const Vector &);
    Vector& operator-=(const Vector &);
    void* operator new(size_t);
    void operator delete(void*);

    friend ostream& operator<<(ostream &, const Vector &);

    //Exceptions
    class Exception_sizes : exception
    {
    private:
       const string mes;
    public:
        Exception_sizes(string e)
            : mes(e)
        {
        }
        const char* what() const { return mes.c_str(); }
    };

    class Exception_ind : exception
    {
    private:
        const string mes;
    public:
        Exception_ind(string e)
            : mes(e)
        {
        }
        const char* what() const { return mes.c_str(); }
    };
};
#endif
