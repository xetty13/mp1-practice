#pragma once

class Matrix
{
private:
    double *matr;
    int x, y;
public:
    Matrix();
    Matrix(int _x, int _y);
    Matrix(double *_matr, int _x, int _y);
    Matrix(const Matrix& m);
    ~Matrix();
    Matrix operator+ (const Matrix& m) const;
    Matrix operator- (const Matrix& m) const;
    Matrix operator* (const Matrix& m) const;
    Matrix operator+ (double a) const;
    Matrix operator- (double a) const;
    Matrix operator* (double a) const;
    double* operator[] (int a) const;

    void Print() const;
    Matrix& operator= (const Matrix& m);
    bool operator== (const Matrix& m) const;
    void Fill();
};
