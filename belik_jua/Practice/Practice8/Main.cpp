#pragma once
#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
    int i;

    Matrix m1;
    Matrix m2(2, 3);
    m2.Fill();
    Matrix m3(2, 3);
    m3.Fill();
    try
    {
        m1 = m3 + m2;
        cout << "m1 = m2 + m1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    try
    {
        m1.Print();
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    try
    {
        m2.Print();
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    try
    {
        m3.Print();
    }
    catch (const char* A)
    {
        cout << A << endl;
    }


    try
    {
        m1 = m3 - m2;
        cout << "m1 = m2 - m1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    try
    {
        m1.Print();
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    try
    {
        m1 = m3 * m2;
        cout << "m1 = m2 * m1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    try
    {
        m1.Print();
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    m1 = m3 + 1.0;
    cout << "m1 = m3 + 1.0" << endl;
    try
    {
        m1.Print();
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    try
    {
        cout << "m2[1] = " << *m2[1] << endl;
        *m2[1] = 1.0;
        cout << "m2[1] = 1 = " << *m2[1] << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    cin >> i;
    return 0;
}