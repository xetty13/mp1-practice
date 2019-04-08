
#include <iostream>
class Vector
{
	int size;
	int* elements;
public:
	Vector();
	Vector(Vector&);
	Vector(int);
	~Vector();
	void Output();
	void Input();

	Vector operator=(Vector&);
	Vector operator+(Vector&);
	Vector operator-(Vector&);
	/* bool operator==(Vector&);
	int operator[](Vector&); */
	friend ostream& operator<<(ostream &, const Vector &);
};
