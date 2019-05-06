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
    A.Fill();
    A.Print();
    int n;

    cout << "Remove ";
    cin >> n;
    A.Remove(n);
    A.Print();

    cout << "Add ";
    cin >> n;
    A.Add(n);
    A.Print(); 

    cout << "Find ";
    cin >> n;
    cout << A.Find(n) << endl;

    cout << "A[1] = " << *A[1] << endl;

    *A[1] = 6;
    cout << "A[1] = 6" << endl;
    A.Print();

    cout << "Sort" << endl;
    A.Sort();
    A.Print();

    cout << "Container" << endl;
    cout << "Size = ";
    cin >> size;
    Container<int, MAX_SIZE> B(size);
    B.Fill();
    B.Print();

    cout << "Remove ";
    cin >> n;
    B.Remove(n);
    B.Print();

    cout << "Add ";
    cin >> n;
    B.Add(n);
    B.Print();

    cout << "Find ";
    cin >> n;
    cout << B.Find(n) << endl;

    cout << "B[1] = " << *B[1] << endl;

    *B[1] = 6;
    cout << "B[1] = 6" << endl;
    B.Print();

    cout << "Sort" << endl;
    B.Sort();
    B.Print();
}