#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	float x1, y1, r1, x2, y2, r2, d;
	printf("Введите координаты центра и радиус окружности номер 1: ");
	scanf(" %f %f %f", &x1, &y1, &r1);
	printf("Введите координаты центра и радиус окружности номер 2: ");
	scanf(" %f %f %f", &x2, &y2, &r2);
	d = sqrt(x2 * x2 - 2 * x2 * x1 + x1 * x1 + y2 * y2 - 2 * y1 * y2 + y1 * y1);
	if (d > r1 + r2)
	{
		printf("Окружности не касаются.");
	}
	else if ((r1 == r2) && (d == 0))
	{
		printf("Окружности совпадают.");
	}
	else if (d < abs(r1 - r2))
	{
		printf("Окружность с меньшим радиусом лежит внутри большой.");
	}
	else if (d == abs(r1 - r2))
	{
		printf("Внутреннее касание окружностей.");
	}
	else if (d == r1 + r2)
	{
		printf("Внешнее касание окружностей.");
	}
	else if ((abs(r1 - r2) < d) && (d < r1 + r2))
	{
		printf("Окружности пересекаются.");
	}
	return 0;
}