#ifndef _TRIANGLE_H
#define _TRIANGLE_H
#include <string>
using namespace std;
struct Coord {
	float x, y;
};

struct Triangle {
	Coord vertices[3];
};


int read(Triangle*& triangles, const string& f);
void CountSquare(const Triangle& triangle);
void CountPerimeter(const Triangle& triangle);
float* Sides(const Triangle& triangle);
void Height(const Triangle& triangle);
void TriangleType(const Triangle& triangle);


#endif _TRIANGLE_H
