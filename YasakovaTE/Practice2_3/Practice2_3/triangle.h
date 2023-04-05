#ifndef FILM_H

#define FILM_H
#include <string>
using namespace std;


class Coord
{
public:
	float x, y;
	Coord();
	Coord(float a, float b);

};


class Triangle
{
private:
	Coord vertices[3];
public:
	Triangle();
	Triangle(Coord* vertices_);

	void CountSquare();
	void CountPerimeter();
	float* Sides();
	void Height();
	void TriangleType();
};

int read(Triangle*& triangles, const string& f);
#endif