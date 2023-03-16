#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "triangle.h"
int main() {
	char* path = getPath();
	puts(path);
	int count_of_triangles;
	Triangle* triangles = ReadTriangleFile(path, &count_of_triangles);
	int t = 0;
	while (1)
	{
		printf("Select an operation : 1 - area, 2 - perimeter, 3 - height, 4 - type of triangle:  ");
		scanf(" %d", &t);
		for (int i = 0; i < count_of_triangles; ++i)
			if (t == 1)
				CountSquare(triangles[i]);
			else if (t == 2)
				CountPerimeter(triangles[i]);
			else if (t==3)
				Height(triangles[i]);
			else if (t==4)
				PrintTriangleType(triangles[i]);
		printf("If you want to exit, enter 0: ");
		scanf(" %d", &t);
		if (t == 0)
			break;
	}

	return 0;
}









