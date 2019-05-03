#include "Container.h"
#include "mContainer.h"
#include <iostream>
using namespace std;
#define MAX_SIZE 10

void main()
{
    int size;
    cout << "Size = ";
    cin >> size;
    mContainer<int, MAX_SIZE> A(size);
    try
    {
        A.Fill();
    }
    catch (char* ER)
    {
        cout << ER;
    }
    try
    {
        A.Print();
    }
    catch (char* ER)
    {
        cout << ER;
    }
    int n;

    cout << "Remove ";
    cin >> n;
    try
    {
        A.Remove(n);
    }
    catch (char* ER)
    {
        cout << ER;
    }
    try
    {
        A.Print();
    }
    catch (char* ER)
    {
        cout << ER;
    }

    cout << "Add ";
    cin >> n;
    try
    {
        A.Add(n);
    }
    catch (char* ER)
    {
        cout << ER;
    }
    try 
    { 
        A.Print(); 
    }
    catch (char* ER)
    {
        cout << ER;
    }

    cout << "Find ";
    cin >> n;
    try
    {
        cout << A.Find(n);
    }
    catch (char* ER)
    {
        cout << ER;
    }

    try
    {
        cout << "A[1] = " << *A[1];
    }
    catch (char* ER)
    {
        cout << ER;
    }

    try
    {
        *A[1] = 6;
        cout << "A[1] = 6" << endl;
    }
    catch (char* ER)
    {
        cout << ER;
    }
    try
    {
        A.Print();
    }
    catch (char* ER)
    {
        cout << ER;
    }
    cin >> n;
}