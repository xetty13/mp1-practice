#pragma once

class Vector
{
private:
    int size;
    double *arr;
public:
    Vector();
    Vector(int x);
    Vector(const Vector& vec);
    ~Vector();

    Vector operator+ (const Vector & tmp) const;
    Vector operator- (const Vector & tmp) const;
    double operator* (const Vector & tmp) const;
    Vector operator+ (double tmp) const;
    Vector operator- (double tmp) const;
    Vector operator* (double tmp) const;
    Vector& operator= (const Vector & tmp);
    double* operator[] (int i) const;
    double Lenght() const;
    Vector& operator+= (const Vector & tmp);
    Vector& operator-= (const Vector & tmp);
    Vector& operator+= (double tmp);
    Vector& operator-= (double tmp);
    Vector& operator*= (double tmp);
    void *operator new[](size_t size);
    void operator delete[] (void *p);

    void PrintVector() const;
    void Fill();
    bool operator==(const Vector & tmp) const;
};