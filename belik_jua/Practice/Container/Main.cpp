#include "Container.h"
#include "mContainer.h"
#include <iostream>
using namespace std;
#define MAX_SIZE 10

void main()
{
    cout << "mContainer" << endl;
    int size;
    cout << "Size = ";
    cin >> size;
    mContainer<int, MAX_SIZE> A(size);
    try
    {
        A.Fill();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        A.Print();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    int n;

    cout << "Remove ";
    cin >> n;
    try
    {
        A.Remove(n);
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        A.Print();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }

    cout << "Add ";
    cin >> n;
    try
    {
        A.Add(n);
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        A.Print();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }

    cout << "Find ";
    cin >> n;
    cout << A.Find(n) << endl;

    try
    {
        cout << "A[1] = " << *A[1] << endl;
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        *A[1] = 6;
        cout << "A[1] = 6" << endl;
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        A.Print();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }

    cout << "Container" << endl;
    cout << "Size = ";
    cin >> size;
    Container<int, MAX_SIZE> B(size);
    try
    {
        B.Fill();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        B.Print();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }

    cout << "Remove ";
    cin >> n;
    try
    {
        B.Remove(n);
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        B.Print();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }

    cout << "Add ";
    cin >> n;
    try
    {
        B.Add(n);
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        B.Print();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }

    cout << "Find ";
    cin >> n;
    cout << B.Find(n) << endl;

    try
    {
        cout << "B[1] = " << *B[1] << endl;
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }

    try
    {
        *B[1] = 6;
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    cout << "B[1] = 6" << endl;
    try
    {
        B.Print();
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
}