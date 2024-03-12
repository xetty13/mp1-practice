#include <iostream>
#include <exception>
#include "header.h"

TVector::TVector()
{
    this->n = 0;
    this->x = nullptr;

}

TVector::TVector(int n)
{
    this->n = n;
    this->x = new double[this->n];
}

TVector::TVector(const TVector& V)
{
    this->n = V.n;
    this->x = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->x[i] = V.x[i];
    }
}

TVector::~TVector()
{
    delete[] this->x;
}

TVector TVector::operator+(const TVector& V)
{
    if (this->n != V.n)
    {
        throw std::exception("Diff len");
    }
    TVector res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.x[i] = this->x[i] + V.x[i];
    }
    return res;
}

TVector TVector::operator-(const TVector& V)
{
    if (this->n != V.n)
    {
        throw std::exception("Diff len");
    }
    TVector res(this->n);
    for (int i = 0; i < this->n; i++)
    {
        res.x[i] = this->x[i] - V.x[i];
    }
    return res;
}

TVector& TVector::operator=(const TVector& V)
{
    n = V.n;
    for (int i = 0; i < this->n; i++)
    {
        x[i] = V.x[i];
    }
    return *this;
}

double TVector::operator*(const TVector& V)
{
    if (this->n != V.n)
    {
        throw std::exception("Diff len");
    }
    double res = 0;
    for (int i = 0; i < V.n; i++)
    {
        res += this->x[i] * V.x[i];
    }
    return res;
}

std::istream& operator>>(std::istream& in, TVector& V)
{
    std::cout << "Input n: ";
    in >> V.n;
    std::cout << "Input x: ";
    if (V.x != nullptr)
    {
        delete[] V.x;
    };
    V.x = new double[V.n];
    for (int i = 0; i < V.n; i++)
    {
        in >> V.x[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const TVector& V)
{
    for (int i = 0; i < V.n; i++)
    {
        out << V.x[i] << " ";
    }
    return out;
}



