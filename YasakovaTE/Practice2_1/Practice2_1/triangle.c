#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "triangle.h"
#include <stdlib.h>
#include <math.h>
char* read_string(FILE* stream)
{
    int buffer_size = 16;
    int buffer_size_divizer = 1;
    int offset = 0;
    int additional_length;

    char* buffer = (char*)malloc(buffer_size);
    if (buffer == NULL) {
        return NULL;
    }
    buffer[0] = '\0';

    while (1) {
        if (fgets(buffer + offset, buffer_size / buffer_size_divizer, stream) == NULL) {
            free(buffer);
            return NULL;
        }
        else {
            additional_length = strlen(buffer + offset);
            if (buffer[offset + additional_length - 1] != '\n') {
           
                buffer_size *= 2;
       
                buffer = (char*)realloc(buffer, buffer_size);

                offset += additional_length;
                buffer_size_divizer = 2;
            }
            else {
                buffer[offset + additional_length - 1] = '\0';
                break;
            }
        }
    }
    return buffer;
}

char* getPath()
{
    char* file_path;
    while (1) {
        printf("Enter the path to file : ");
        file_path = read_string(stdin);
        if (file_path != NULL)
            break;
    }
    return file_path;
}




Triangle* ReadTriangleFile(char* file_path, int* number_of_triangles)
{
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("\nRead file error.\n");
    }
    Triangle* triangles = (Triangle*)malloc(sizeof(Triangle));
    *number_of_triangles = 1;

    while (1) {
        Triangle current_triangle = ReadTriangleEntity(file);
        triangles[*number_of_triangles - 1] = current_triangle;
        if (read_string(file) == NULL) {
            break;
        }
        else {
            triangles = (Triangle*)realloc(triangles, (*number_of_triangles + 1) * sizeof(Triangle));
            *number_of_triangles += 1;
        }
    }
    fclose(file);
    return triangles;
}



Triangle ReadTriangleEntity(FILE* file)
{
    float x1= atoi(read_string(file));
    float y1 = atoi(read_string(file));
    float x2 = atoi(read_string(file));
    float y2 = atoi(read_string(file));
    float x3 = atoi(read_string(file));
    float y3 = atoi(read_string(file));

    Coord c1 = { x1, y1 };
    Coord c2 = { x2, y2 };
    Coord c3 = { x3, y3 };

    Triangle triangle = { {c1, c2, c3} };
    return triangle;
}


float CountSquare(Triangle triangle)
{
    float s = (abs(((triangle.vertices[1].x - triangle.vertices[0].x) * (triangle.vertices[2].y - triangle.vertices[0].y)) - ((triangle.vertices[2].x - triangle.vertices[0].x) * (triangle.vertices[1].y - triangle.vertices[0].y)))) / 2;
    printf("S = %f \n", s);
}


float* Sides(Triangle triangle)
{
    float sides[3];
    sides[0] = sqrt((triangle.vertices[1].x - triangle.vertices[0].x) * (triangle.vertices[1].x - triangle.vertices[0].x) + (triangle.vertices[1].y - triangle.vertices[0].y) * (triangle.vertices[1].y - triangle.vertices[0].y));
    sides[1] = sqrt((triangle.vertices[2].x - triangle.vertices[0].x) * (triangle.vertices[2].x - triangle.vertices[0].x) + (triangle.vertices[2].y - triangle.vertices[0].y) * (triangle.vertices[2].y - triangle.vertices[0].y));
    sides[2] = sqrt((triangle.vertices[2].x - triangle.vertices[1].x) * (triangle.vertices[2].x - triangle.vertices[1].x) + (triangle.vertices[2].y - triangle.vertices[1].y) * (triangle.vertices[2].y - triangle.vertices[1].y));

    return sides;
}


float CountPerimeter(Triangle triangle)
{
    float* sides = Sides(triangle);
    float p = sides[0] + sides[1] + sides[2];
    printf("P = %f \n", p);
}

float* Height(Triangle triangle)
{
    float s = (abs(((triangle.vertices[1].x - triangle.vertices[0].x) * (triangle.vertices[2].y - triangle.vertices[0].y)) - ((triangle.vertices[2].x - triangle.vertices[0].x) * (triangle.vertices[1].y - triangle.vertices[0].y)))) / 2;
    float heights[3];
    float* sides = Sides(triangle);
    heights[0] = 2 * s / sides[0];
    heights[1] = 2 * s / sides[1];
    heights[2] = 2 * s / sides[2];
    printf("H1 = %f, H2 = %f, H3 = %f \n", heights[0], heights[1], heights[2]);
}

void PrintTriangleType(Triangle triangle)
{
    float* sides = Sides(triangle);
    float max = fmax(sides[0], sides[1], sides[2]);
    float min = fmin(sides[0], sides[1], sides[2]);
    float sr = sides[0] + sides[1] + sides[2] - max - min;
    if (max * max < (min * min + sr * sr))
        printf("The triangle is sharp \n");
    else if (max * max == (min * min + sr * sr))
        printf("The triangle is straight \n");
    else if (max * max > (min * min + sr * sr)) 
        printf("The triangle is blunt \n");

}



