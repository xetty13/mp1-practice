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
	PrintTriangles(triangles, count_of_triangles);
	return 0;
}














/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "triangle.h"
#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>


int main(){

	int n, m, i, j;
	int s = 0, r = 0, t = 0, p = 0, h1 = 0, h2 = 0, h3 = 0, perimetr = 0, max=0, min=0, sr=0;
	Triangle a = { 6 };

	char* path = getPath();
	puts(path);
	FILE* f = fopen(path, "r");
	if (f == NULL) {
		printf("File not found\n");
		return 1;
	}
	fscanf(f, "%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		a = get_point(f);
		printf("%d", a);
		printf("/n");

	}


	for (i = 0; i < n; i++) {
		s = (abs(((a[i][2] - a[i][0]) * (a[i][5] - a[i][1])) - ((a[i][4] - a[i][0]) * (a[i][3] - a[i][1])))) / 2;
		printf("s= %d\n", s);

		r = sqrt((a[i][2] - a[i][0]) * (a[i][2] - a[i][0]) + (a[i][3] - a[i][1]) * (a[i][3] - a[i][1]));
		t= sqrt((a[i][4] - a[i][0]) * (a[i][4] - a[i][0]) + (a[i][5] - a[i][1]) * (a[i][5] - a[i][1]));
		p= sqrt((a[i][4] - a[i][2]) * (a[i][4] - a[i][2]) + (a[i][5] - a[i][3]) * (a[i][5] - a[i][3]));
		printf("%d %d %d ", r, t, p);
		perimetr = r + t + p;
		printf("perimetr= %d\n", perimetr);


		h1 = 2 * s / r;
		h2 = 2 * s / t;
		h3 = 2 * s / p;
		printf("h1=%d, h2=%d, h3=%d ", h1, h2, h3);


		max = fmax(r, t, p);
		min = fmin(r, t, p);
		sr = r + t + p - max - min;
		if (max * max < min * min + sr * sr)
		{
			printf("osto");
		}
		else if (max * max == min * min + sr * sr)
		{
			printf("pramoy");
		}
		else if (max * max > min * min + sr * sr){
			printf("typoy");
		}
		



		s = 0;
		perimetr = 0;
		r = 0;
		t = 0;
		p = 0;

	}





	for (i = 0; i < n; i++)
		free(a[i]);
	free(a);
	fclose(f);
	return 0;
}
*/