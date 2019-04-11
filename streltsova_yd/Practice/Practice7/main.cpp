#include "Vector.h"
#include <iostream>
using namespace std;
void main()
{
    Vector A(5), B(5), C(3), D;
    cout << "Enter the coordinates of vector A of dimension 5" << endl;
    A.Add();
    cout << "Enter the coordinates of vector B of dimension 5" << endl;
    B.Add();
    cout << "Enter the coordinates of vector C of dimension 3" << endl;
    C.Add();
    cout << "A + B = ";
    try
    {
        D = A + B;
        D.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A + C = ";
    try
    {
        D = A + C;
        D.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A - B = ";
    try
    {
        D = A - B;
        D.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A - C = ";
    try
    {
        D = A - C;
        D.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A + 5 = ";
    D = A + 5;
    try
    {
        D.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A - 5 = ";
    D = A - 5;
    try
    {
        D.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A * 5 = ";
    D = A * 5;
    try
    {
        D.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A * B = ";
    try
    {
        double d = A * B;
        cout << d << endl;
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A * C = ";
    try
    {
        double d = A * C;
        cout << d << endl;
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A += B" << endl << "A = ";
    try
    {
        A += B;
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A += C" << endl << "A = ";
    try
    {
        A += C;
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A -= B" << endl << "A = ";
    try
    {
        A -= B;
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A -= C" << endl << "A = ";
    try
    {
        A -= C;
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A += 5" << endl << "A = ";
    A += 5;
    try
    {
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A -= 5" << endl << "A = ";
    A -= 5;
    try
    {
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A *= 5" << endl << "A = ";
    A *= 5;
    try
    {
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A = B" << endl << "A = ";
    try
    {
        A = B;
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A = C" << endl << "A = ";
    try
    {
        A = C;
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    }
    cout << "A.x[0] = 3" << endl << "A = ";
    try
    {
        A.x[0] = 3;
        A.Print();
    }
    catch(const char* a)
    {
        cout << a << endl;
    } 
    cout << "a = A.x[1] = " << A.x[1] << endl;
    cout << "Length(A) = " << A.Length() << endl;
}