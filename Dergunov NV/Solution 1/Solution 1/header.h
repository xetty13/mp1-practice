#pragma once

#include <iostream>

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
};

std::istream& operator>>(std::istream& in, TVector& V);
std::ostream& operator<<(std::ostream& out, const TVector& V);
std::ifstream& operator>>(std::ifstream& in, TVector& V);
std::ofstream& operator<<(std::ofstream& out, const TVector& V);