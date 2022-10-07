#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>


int main()
{
	setlocale(LC_CTYPE, "Russian");
	float xc1, yc1, xc2, yc2, xr1, yr1,xr2,yr2,r1,r2,sc,d;
	printf("Enter the coordinates of the center of the first circle: ");
	scanf("%f %f", &xc1, &yc1);
	printf("Enter the coordinates of the center of the second circle: ");
	scanf("%f %f", &xc2, &yc2);
	printf("Enter the coordinates of the radius of the first circle: ");
	scanf("%f %f", &xr1, &yr1);
	printf("Enter the coordinates of the radius of the second circle: ");
	scanf("%f %f", &xr2, &yr2);
	r1 = sqrt(pow(xr1 - xc1, 2) + pow(yc1 - yr1, 2));
	r2 = sqrt(pow(xr2 - xc2, 2) + pow(yr2 - yc2, 2));
	sc = sqrt(pow(xc2 - xc1, 2) + pow(yc2 - yc1, 2));
	d = sc - (r1 + r2);

	if (sc == 0 && r1 == r2)
	{
		printf("the circles are congruent");
	}

	else if (d== 0)
	{
		printf("the circles are touching");
	}

	else if (d > 0)
	{
		printf("The circles are distant from each other");
	}

	else if (sc < abs(r1 - r2))
	{
		printf("One circle inside another");
	}

	else if (sc == abs(r1-r2))
	{
		printf("The circles have one common point");
	}
	else 
	{
		printf("The circles intersect at two points");
	}
	getchar();
	return 0;
}