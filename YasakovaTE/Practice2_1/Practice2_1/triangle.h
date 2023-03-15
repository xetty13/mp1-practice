#ifndef _TRIANGLE_H
#define _TRIANGLE_H

typedef struct {
	int x, y;
}Coord;

typedef struct {
	Coord vertices[3]; 
}Triangle;


char* read_string(FILE* stream);
char* getPath();
Triangle* ReadTriangleFile(char* file_path, int* number_of_triangles);
Triangle ReadTriangleEntity(FILE* file);
void PrintTriangles(Triangle* triangles, int count_of_triangles);
float CountSquare(Triangle triangle);
float CountPerimeter(Triangle triangle);
float* Sides(Triangle triangle);
float* Height(Triangle triangle, float s);
void PrintTriangleType(Triangle triangle);


#endif _TRIANGLE_H