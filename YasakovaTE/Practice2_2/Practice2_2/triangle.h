#ifndef _TRIANGLE_H
#define _TRIANGLE_H
#include <string>
using namespace std;
struct Coord {
	float x, y;
};

struct Triangle {
	Coord vertices[3];
	void CountSquare();
	void CountPerimeter();
	float* Sides();
	void Height();
	void TriangleType();

};


int read(Triangle*& triangles, const string& f);


#endif _TRIANGLE_H
