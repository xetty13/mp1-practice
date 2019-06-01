#include "Vector.h"
#include <iostream>
#include <exception>
#include <conio.h>
using namespace std;

void menu();

void main()
{
    Vector A(3), B(3), C(4), Res(3);
    double res = 0;
    float a[3] = { 1.12, 5.3, 2.41 };
    float b[3] = { 5.86, 0.32, 1.69 };
    float c[4] = { 0.23, 8.1, 23.1, 21.3 };

    A.Create(a);
    B.Create(b);
    C.Create(c);

    cout << "     Hello, it's multidimensional vector\n\n";

    cout << "  V1 = ";
    A.Output();
    cout << "  V2 = ";
    B.Output();
    cout << "  V3 = ";
    C.Output();

    cout << "\n  V3 + 5 = " << C + 5;
    cout << "\n  V1 * 5 = " << A * 5;

    res = A.Lenght();
    cout << "\n\n  |V1| = " << res;
    res = B.Lenght();
    cout << "\n  |V2| = " << res;
    res = C.Lenght();
    cout << "\n  |V3| = " << res;
    try
    {
        cout << "\n\n  V1 + V2 = ";
        cout << A + B;
        cout << "\n  V2 + V3 = ";
        cout << B + C;
    }
    catch (Exception_sizes& e)
    {
        cerr << e.what() << endl;
    }
    try
    {
        cout << "\n  V1 - V2 = ";
        cout << A - B;

        cout << "\n  (V1,V3) = ";
        res = A.Scalar(C);
    }
    catch(Exception_sizes& e)
    {
        cerr << e.what() << endl;
    }
    try 
    {
        cout << "\n  V1[2] = " << A[2];
        cout << "\n  V2[0] = " << B[0];
        cout << "\n  V3[10] = ";
        cout << C[10];
    }
    catch (Exception_ind& e)
    {
        cerr << e.what() << endl;
    }
}