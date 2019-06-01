#include "Vector.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <conio.h>
#include <locale.h>
#include <Windows.h>
using namespace std;

void menu();

void main()
{
    Vector A(5), B(5), C(6), Res(5);
    int f = 1, _menu;
    int a;
    double res = 0;

    cout << "     Hello, it's multidimensional vector\n\n";

    cout << "  V1 = ";
    A.Output();
    cout << "  V2 = ";
    B.Output();
    cout << "  V3 = ";
    C.Output();
    cout << "  V1 = ";
    A.Output();
    cout << "  V2 = ";
    B.Output();
    cout << "  V3 = ";
    C.Output();

    cout << "  Enter the const: ";
    cin >> a;
    cout << "  V1 + const = " << A + a;
    cout << "\n  V2 + const = " << B + a;
    cout << "\n  V3 + const = " << C + a;

    cout << "  V1 * const = " << A * a;
    cout << "\n  V2 * const = " << B * a;
    cout << "\n  V3 * const = " << C * a;

    res = A.Lenght();
    cout << "\n  |V1| = " << res;
    res = B.Lenght();
    cout << "\n  |V2| = " << res;
    res = C.Lenght();
    cout << "\n  |V3| = " << res;
    try
    {
        cout << "  V1 + V2 = ";
        cout << A + B;
        cout << "  V2 + V3 = ";
        cout << B + C;
    }
    catch (Exception_sizes& e)
    {
        cerr << e.what() << endl;
    }
    try
    {
        cout << "  V1 - V2 = ";
        cout << A - B;

        res = A.Scalar(C);
        cout << "  (V1,V3) = " << res;
    }
    catch(Exception_sizes& e)
    {
        cerr << e.what() << endl;
    }
    try 
    {
        cout << "  V1[3] = " << A[3];
        cout << "\n  V2[4] = " << B[4];
        //exception
        cout << "\n  V3[10] = " << C[10];
    }
    catch (Exception_ind& e)
    {
        cerr << e.what() << endl;
    }

    system("pause");
}