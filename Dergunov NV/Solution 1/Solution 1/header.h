#pragma once

#include <iostream>
#include <fstream>

struct TVector
{
    int n;
    double* x;

    TVector();
    TVector(int n);
    TVector(const TVector&);
    ~TVector();

    TVector operator+(const TVector&);
    TVector operator-(const TVector&);
    double operator*(const TVector&);
    const TVector& operator=(const TVector&);
    friend std::ofstream& operator<<(std::ofstream& out, const TVector& V)
    {
        out << "Vector: ";
        for (int i = 0; i < V.n; i++)
        {
            out << V.x[i] << " ";
        }
        out << std::endl;
        return out;
    }
    friend std::ifstream& operator<<(std::ifstream& in, TVector& V)
    {
        in >> V.n;
        if (V.x != nullptr)
        {
            delete[] V.x;
        }
        V.x = new double[V.n];
        for (int i = 0; i < V.n; i++)
        {
            in >> V.x[i];
        }
        return in;
    }
};

std::istream& operator>>(std::istream& in, TVector& V);
std::ostream& operator<<(std::ostream& out, const TVector& V);