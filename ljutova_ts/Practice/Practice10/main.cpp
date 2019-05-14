#include "Container.h" 
#include "Exception.h" 

void main()
{
	int arr1[5] = { 1, 2, 4, 7, 8 };
	double arr2[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };

	Container<int, 5> Cont1(arr1, 5);
	Container<double, 7> Cont2(arr2, 7);
	try
	{
		cout << "Container 1:" << Cont1 << endl;
		cout << "Container 2:" << Cont2 << endl;
	}
	catch (Exception e)
	{
		e.Print();
	}

	try
	{
		Cont1.Delete(2);
		cout << "Container 1 - num 2: " << Cont1 << endl;

		Cont2.Delete(2.2);
		cout << "Container 2 - num 2.2: " << Cont2 << endl;
	}
	catch (Exception e)
	{
		e.Print();
	}

	try
	{
		Cont1.Add(3);
		cout << "Container 1 + num 3: " << Cont1 << endl;

		Cont2.Add(9.9);
		cout << "Container 2 + num 9.9: " << Cont2 << endl;

	}
	catch (Exception e)
	{
		e.Print();
	}

	int *arr11[5];
	double *arr22[7];

	for (int i = 0; i < 5; i++)
		arr11[i] = &arr1[i];

	for (int i = 0; i < 7; i++)
		arr22[i] = &arr2[i];

	Container<int*, 5> Cont11(arr11, 5);
	Container<double*, 7> Cont22(arr22, 7);
	try
	{
		cout << "Container 1`:" << Cont11 << endl;
		cout << "Container 2`:" << Cont22 << endl;
	}
	catch (Exception e)
	{
		e.Print();
	}

	try
	{
		double a = 0.1;
		double *a1 = &a;

		Cont22.Add(a1);
		cout << "Container 2 + num 9.9: " << Cont22 << endl;

		int b = 9;
		int *b1 = &b;
		Cont11.Add(b1);
		cout << "Container 1 + num 3: " << Cont11 << endl;
	}
	catch (Exception e)
	{
		e.Print();
	}

	try
	{

		Cont11.Delete1(1);
		cout <<  "Container 1 - element with Index 1: " << Cont11 << endl;


		Cont22.Delete1(1);
		cout << "Container 2 - element ith Index 1: " << Cont22 << endl;
	}
	catch (Exception e)
	{
		e.Print();
	}

}
