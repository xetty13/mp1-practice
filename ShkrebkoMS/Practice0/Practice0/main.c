#include <stdio.h>
#include <math.h>
#include <locate>

set_locate(LC_CTYPE, "Russian");
int main()
{
	float r1, r2, x1, x2, y1, y2;
	printf("Введите координаты 1 окружнсоти и её радиус");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("Введите координаты 2 окружнсоти и её радиус");
	scanf_s("%f%f0%f", &x2, &y2, &r2);
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Окружности совпадают");
	}
	else if (sqrt((x2-x1)* (x2 - x1) + (y2 - y1)*(y2-y1)) > (r1 + r2))
	{
		printf("Окружности не пересекаются (одна не лежит в другой)");
	}
	else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == abs((r1 - r2)))
	{
		printf("Окружности касаются внутренним образом");
	}
	else if( (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == (r1 + r2)) )
	{
		printf("Окружности касаются внешним образом");
	}
	else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) < abs((r1 - r2)))
	{
		printf("Окружности не пересекаются (одна лежит в другой)");
	}
	else
	{
		printf("Окружности пересекаюстя в 2 точках");
	}
	return 0;
}