#ifndef _TRIANGLE_H
#define _TRIANGLE_H

struct Coord {
	float x, y;
};

struct Triangle {
	Coord vertices[3];
};


int read(Triangle*& triangles, char* f);
void CountSquare(Triangle triangle);
void CountPerimeter(Triangle triangle);
float* Sides(Triangle triangle);
void Height(Triangle triangle);
void PrintTriangleType(Triangle triangle);


#endif _TRIANGLE_H
