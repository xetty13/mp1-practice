#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "triangle.h"
#include <math.h>
using namespace std;


int read(Triangle*& triangles, const string& f)
{
    fstream file;
    file.open(f);
    if (!file.is_open())
        throw "File open error";
    int n;
    file >> n;
    triangles = new Triangle[n];
    for (int i = 0; i < n; i++) {
        float x1, x2, x3, y1, y2, y3;
	    file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	    Coord c1 = { x1, y1 };
	    Coord c2 = { x2, y2 };
	    Coord c3 = { x3, y3 };

        triangles[i] = { {c1, c2, c3} };
    }
    file.close();
	return n;

}


void CountSquare(const Triangle& triangle)
{
    float s = (abs(((triangle.vertices[1].x - triangle.vertices[0].x) * (triangle.vertices[2].y - triangle.vertices[0].y)) - ((triangle.vertices[2].x - triangle.vertices[0].x) * (triangle.vertices[1].y - triangle.vertices[0].y)))) / 2;
    cout <<"S =  " << s << endl;
}


float* Sides(const Triangle& triangle)
{
    float sides[3];
    sides[0] = sqrt((triangle.vertices[1].x - triangle.vertices[0].x) * (triangle.vertices[1].x - triangle.vertices[0].x) + (triangle.vertices[1].y - triangle.vertices[0].y) * (triangle.vertices[1].y - triangle.vertices[0].y));
    sides[1] = sqrt((triangle.vertices[2].x - triangle.vertices[0].x) * (triangle.vertices[2].x - triangle.vertices[0].x) + (triangle.vertices[2].y - triangle.vertices[0].y) * (triangle.vertices[2].y - triangle.vertices[0].y));
    sides[2] = sqrt((triangle.vertices[2].x - triangle.vertices[1].x) * (triangle.vertices[2].x - triangle.vertices[1].x) + (triangle.vertices[2].y - triangle.vertices[1].y) * (triangle.vertices[2].y - triangle.vertices[1].y));

    return sides;
}


void CountPerimeter(const Triangle& triangle)
{
    float* sides = Sides(triangle);
    float p = sides[0] + sides[1] + sides[2];
    cout << "P =  " << p << endl;
}

void Height(const Triangle& triangle)
{
    float s = (abs(((triangle.vertices[1].x - triangle.vertices[0].x) * (triangle.vertices[2].y - triangle.vertices[0].y)) - ((triangle.vertices[2].x - triangle.vertices[0].x) * (triangle.vertices[1].y - triangle.vertices[0].y)))) / 2;
    float heights[3];
    float* sides = Sides(triangle);
    heights[0] = 2 * s / sides[0];
    heights[1] = 2 * s / sides[1];
    heights[2] = 2 * s / sides[2];
    cout << "H1 = " << heights[0] << "; " << "H2 = " << heights[1] << "; " << "H3 = " << heights[2] << "; " <<  endl;
}

void TriangleType(const Triangle& triangle)
{
    float* sides = Sides(triangle);
    int max;
    max = sides[0];
    for (int i = 0; i < 3; i++)
    {
        if (sides[i] > max)
        {
            max = sides[i];
        }
    }

    int min;
    min = sides[0];
    for (int i = 0; i < 3; i++)
    {
        if (sides[i] <min)
        {
            min = sides[i];
        }
    }
    float sr = sides[0] + sides[1] + sides[2] - max - min;
    if (max * max < (min * min + sr * sr))

        cout << "The triangle is sharp"<< endl;
    else if (max * max == (min * min + sr * sr))
        cout << "The triangle is straight" << endl;
    else if (max * max > (min * min + sr * sr))
        cout << "The triangle is blunt" << endl;

}
