#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "triangle.h"
#include <math.h>
using namespace std;


Triangle::Triangle()
{

}

Triangle::Triangle(Coord* vertices_)
{
    vertices[0] = vertices_[0];
    vertices[1] = vertices_[1];
    vertices[2] = vertices_[2];

}

 ostream& operator<<(ostream &output_stream, const Triangle &triangles)
{
    output_stream << "Coordinates: (" << triangles.vertices[0].x << ", " << triangles.vertices[0].y << "), (" << triangles.vertices[1].x << ", " << triangles.vertices[1].y << "), (" << triangles.vertices[2].x << ", " << triangles.vertices[2].y << ") "  <<  endl;
    return output_stream;
}

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
        Coord vertices[3];
        vertices[0] = { x1, y1 };
        vertices[1] = { x2, y2 };
        vertices[2] = { x3, y3 };

   
        triangles[i] = Triangle(vertices);
    }
    file.close();
    return n;

}


void Triangle::CountSquare() const
{
    float s = (abs(((vertices[1].x - vertices[0].x) * (vertices[2].y - vertices[0].y)) - ((vertices[2].x - vertices[0].x) * (vertices[1].y - vertices[0].y)))) / 2;
    cout << "S =  " << s << endl;
}


float* Triangle::Sides() const
{
    float sides[3];
    sides[0] = sqrt((vertices[1].x - vertices[0].x) * (vertices[1].x - vertices[0].x) +
        (vertices[1].y - vertices[0].y) * (vertices[1].y - vertices[0].y));
    sides[1] = sqrt((vertices[2].x - vertices[0].x) * (vertices[2].x - vertices[0].x) + (vertices[2].y - vertices[0].y) * (vertices[2].y - vertices[0].y));
    sides[2] = sqrt((vertices[2].x - vertices[1].x) * (vertices[2].x - vertices[1].x) + (vertices[2].y - vertices[1].y) * (vertices[2].y - vertices[1].y));

    return sides;
}


void Triangle::CountPerimeter() const
{
    float* sides = Sides();
    float p = sides[0] + sides[1] + sides[2];
    cout << "P =  " << p << endl;
}

void Triangle::Height() const
{
    float s = (abs(((vertices[1].x - vertices[0].x) * (vertices[2].y - vertices[0].y)) - ((vertices[2].x - vertices[0].x) * (vertices[1].y - vertices[0].y)))) / 2;
    float heights[3];
    float* sides = Sides();
    heights[0] = 2 * s / sides[0];
    heights[1] = 2 * s / sides[1];
    heights[2] = 2 * s / sides[2];
    cout << "H1 = " << heights[0] << "; " << "H2 = " << heights[1] << "; " << "H3 = " << heights[2] << "; " << endl;
}

 int Triangle::TriangleType() const
{
    float sides[3];
    sides[0] = sqrt((vertices[1].x - vertices[0].x) * (vertices[1].x - vertices[0].x) +
        (vertices[1].y - vertices[0].y) * (vertices[1].y - vertices[0].y));

    sides[1] = sqrt((vertices[2].x - vertices[0].x) * (vertices[2].x - vertices[0].x) +
        (vertices[2].y - vertices[0].y) * (vertices[2].y - vertices[0].y));

    sides[2] = sqrt((vertices[2].x - vertices[1].x) * (vertices[2].x - vertices[1].x) +
        (vertices[2].y - vertices[1].y) * (vertices[2].y - vertices[1].y));
    float max;
    max = sides[0];
    for (int i = 1; i < 3; i++)
    {
        if (sides[i] > max)
        {
            max = sides[i];
        }
    }

    float min;
    min = sides[0];
    for (int i = 1; i < 3; i++)
    {
        if (sides[i] < min)
        {
            min = sides[i];
        }
    }
    float sr = sides[0] + sides[1] + sides[2] - max - min;
    float eps = 0.0001;
    types t;
    if (abs(max * max - (min * min + sr * sr)) < eps)
        t = types::straight;
    else if (max * max < (min * min + sr * sr))
        t = types::sharp;
    else if (max * max > (min * min + sr * sr))
        t = types::blunt;
    return t;

}