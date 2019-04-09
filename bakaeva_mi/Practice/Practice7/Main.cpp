#include "Vector.h"
#include "Exception.h"
#include <iostream>
#include "conio.h"
using namespace std;

void main()
{
    Vector A(5), B(5), C(6), Res(5);
    int f = 1, _menu;
    int a;
    double res = 0;

    cout << "     Hello, it's multidimensional vector\n\n";

    try
    {
        cout << "  V1 = ";
        A.Output();
        cout << "  V2 = ";
        B.Output();
        cout << "  V3 = ";
        C.Output();

        A.menu();
        while (f == 1)
        {
            do
            {
                cout << "\n";
                cout << endl;
                cout << "  Select options (1 - 10): ";
                cin >> _menu;
                cout << endl;
            } while ((_menu >= 9) && (_menu <= 1));
            switch (_menu)
            {
            case(1):
            {
                cout << "  V1 = ";
                A.Output();
                cout << "  V2 = ";
                B.Output();
                cout << "  V3 = ";
                C.Output();
                break;
            }
            case(2):
            {
                cout << "  Enter the const: ";
                cin >> a;
                cout << "  V1 * const = " << A * a;
                cout << "\n  V2 * const = " << B * a;
                cout << "\n  V3 * const = " << C * a;
                break;
            }
            case(3):
            {
                cout << "  V1 + V2 = ";
                cout << A + B;
                break;
            }
            case(4):
            {
                cout << "  V1 - V2 = ";
                cout << A - B;
                break;
            }
            case(5): {
                res = A.Scalar(B);
                cout << "  (V1,V2) = " << res;
                break;
            }
            case(6):
            {
                res = A.Lenght();
                cout << "\n  |V1| = " << res;
                res = B.Lenght();
                cout << "\n  |V2| = " << res;
                res = C.Lenght();
                cout << "\n  |V3| = " << res;
                break;
            }
            case(7):
            {
                cout << "  Enter the const: ";
                cin >> a;
                cout << "  V1 + const = " << A + a;
                cout << "\n  V2 + const = " << B + a;
                cout << "\n  V3 + const = " << C + a;
                break;
            }
            case(8):
            {
                cout << "  Enter the number: ";
                cin >> a;
                cout << "  V1[" << a << "] = " << A[a];
                cout << "\n  V2[" << a << "] = " << B[a];
                cout << "\n  V3[" << a << "] = " << C[a];
                break;
            }
            case(9):
            {
                f = 0;
                cout << "  Goodbay;)\n";
            };
            }
        }
    }
    catch (Exception exp)
    {
        exp.Print();
    }
}