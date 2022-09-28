#include <stdio.h>
#include <math.h>

int main()
{
	float x1, y1, r1, x2, y2, r2, L;
	printf("Insert first circle's metrics (coordinates and radius)");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Insert first circle's metrics (coordinates and radius)");
	scanf("%f %f %f", &x2, &y2, &r2);

	L = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	if (x1 == x2 && y1 == y2)
	{
		if (r1 == r2)
		{
			printf("Circles are equal");
			return 0;
		}
		else
		{
			printf("Circles are concentric");
			return 0;
		}
	}

	if (L > r1 + r2)
	{
		printf("Circles don't collide and arent'situated inside each other");
		return 0;
	}

	if (L == r1 + r2)
	{
		printf("Circles have 1 point of collision and arent'situated inside each other");
		return 0;
	}

	if (L < r1 + r2)
	{
		if (L < r1 || L < r2)
		{
			if (r1 == L - r2 || r2 == L - r1)
			{
				printf("Circles have 1 point of collision while one of them is inside of another");
				return 0;
			}
		}
		else
		{
			printf("Circles have 2 points of collision and arent'situated inside each other");
			return 0;
		}
	}
	
}

/*
 Две окружности задаются координатами центра и радиуса. Определите взаимное расположение этих окружностей.

*/
