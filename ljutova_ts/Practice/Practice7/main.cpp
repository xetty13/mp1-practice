#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
	Vector v1(3), v2(3);
	cout << " Enter coordinats" << " V1 = " << endl;
	v1.Input();
	cout << "Coordinates of your vector: ";
	v1.Output();
	cout << endl;

	cout << " Enter coordinates" << " V2 = " << endl;
	v2.Input();
	cout << "Coordinates of your vector: ";
		v2.Output();
		cout << endl;

		cout << "Addition of this vector: ";
		cout << " V1 + V2 = " << v1 + v2;

		cout << "Subtraction of this vector: ";
		cout << " V1 - V2 = " << v1 - v2;
}
