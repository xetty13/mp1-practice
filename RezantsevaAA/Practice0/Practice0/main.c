#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	float x1, y1, r1, x2, y2, r2, d;
	printf("Enter the coordinates of the center of circle number 1 and its radius");
	scanf(" %f %f %f", &x1, &y1, &r1);
	printf("Enter the coordinates of the center of circle number 2 and its radius");
	scanf(" %f %f %f", &x2, &y2, &r2);
	d = sqrt(x2 * x2 - 2 * x2 * x1 + x1 * x1 + y2 * y2 - 2 * y1 * y2 + y1 * y1);
	if (d > r1 + r2)
	{
		printf("Circles do not touch");
	}
	else if (d < abs(r1 - r2))
	{
		printf("The small circle is inside the big one.");
	}
	else if ((r1 == r2) && (d == 0))
	{
		printf("Circles match");
	}
	else if (d == abs(r1 - r2))
	{
		printf("Internal tangency of circles");
	}
	else if ((abs(r1 - r2) < d) && (d < r1 + r2))
	{
		printf("Circles intersect");
	}
	else if (d == r1 + r2)
	{
		printf("External tangency of circles");
	}
	return 0;
}