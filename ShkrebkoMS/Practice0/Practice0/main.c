#include <stdio.h>
#include <math.h>



int main()
{
	float r1, r2, x1, x2, y1, y2,CircleCenterDistance;
	printf("Enter the coordinates of the first circle and its radius");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("Enter the coordinates of the second circle and its radius");
	scanf_s("%f%f0%f", &x2, &y2, &r2);
	CircleCenterDistance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Circle coincide"); //Окружности совпадают
	}
	else if (CircleCenterDistance > (r1 + r2))
	{
		printf("Circles do not intersect (one does not lie in the other)"); //Окружности не пересекаются (одна не лежит в другой)
	}
	else if (CircleCenterDistance == abs((r1 - r2)))
	{
		printf("The circles touch internally");  //Окружности касаются внутренним образом
	}
	else if( (CircleCenterDistance == (r1 + r2)) )
	{
		printf("The circles touch externally");  //Окружности касаются внешним образом
	}
	else if (CircleCenterDistance < abs((r1 - r2)))
	{
		printf("Circles do not intersect (one lies in the other)");//Окружности не пересекаются (одна лежит в другой)
	}
	else
	{
		printf("Circles intersect");//Окружности пересекаюстя
	}
	return 0;
}