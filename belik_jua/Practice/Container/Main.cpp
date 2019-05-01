#include "Container.h"
#include "mContainer.h"
#include <iostream>
using namespace std;
#define MAX_SIZE 10

void main()
{
    Container<int, MAX_SIZE> A = Container<int, MAX_SIZE>(5);
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
}