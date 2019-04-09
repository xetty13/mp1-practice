#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
class Vector
{
	int size;
	int* elements;
public:
	Vector();
	Vector(const Vector&);
	Vector(int);
	~Vector();
	void Output();
	void Input();

	Vector operator+(const Vector&);
	Vector operator-(Vector&);
	bool operator==(const Vector&) const;
	const Vector& operator=(const Vector&);
	Vector operator+(int);
	 Vector operator-(int);
    int& operator[](int a); 
	Vector operator*(int);
	Vector& operator+=(const Vector&);
	Vector operator-=(Vector&);
	Vector operator+=(int);
	Vector operator-=(int);
	//Vector Lenght(Vector&);

	friend std::ostream& operator<<(std::ostream &, const Vector &);
};

#endif