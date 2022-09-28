#include <stdio.h>
#include <clocale>
#include <math.h>


int main()
{
	float x1, y1, r1, x2, y2, r2;
	printf("Введите координаты и радиус первой окружности");
	scanf("%f%f%f", &x1, &y1, &r1);
	printf("Введите координаты и радиус второй окружности");
	scanf("%f%f%f", &x2, &y2, &r2);
	setlocale(LC_CTYPE, "Russian");

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Окружности равны");
	}
	if (x1 == x2 && y1 == y2 && r1 > r2)
	{
		printf("Вторая окружность вписана впервую");
	}
	if (x1 == x2 && y1 == y2 && r1 < r2)
	{
		printf("Первая окружность вписана в первую");
	}
	if (sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == (r1 + r2))
	{
		printf("Окружности имеют одну общую точку");
	}
	if (sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2 )) >= (r1 + r2))
	{
		printf("Окружности не имеют общих точек");
	}
	return 0;
}
