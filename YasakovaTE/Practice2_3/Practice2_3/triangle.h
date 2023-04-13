#ifndef _TRIANGLE_H
#define _TRIANGLE_H
#include <string>
#include <iostream>
using namespace std;

struct Coord {
	float x, y;
};


class Triangle
{
private:
	Coord vertices[3];
public:
	Triangle();
	Triangle(Coord* vertices_);

	void CountSquare() const;
	void CountPerimeter() const;
	float* Sides() const;
	void Height() const;
	int TriangleType() const;
	friend std::ostream& operator<<(ostream& output_stream, const Triangle& triangles);
	
};
enum types
{
	straight,
	sharp,
	blunt

};
int read(Triangle*& triangles, const string& f);
#endif _TRIANGLE_H