#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <clocale>


int main()
{
	SetLocale(LC_CTYPE, "Russian");
	float xc1, yc1, xc2, yc2, xr1, yr1,xr2,yr2,s,r1,r2;
	printf("Введите координаты центра первой окружности: ");
	scanf("&f &f", &xc1, &yc1);
	printf("Введите координаты центра второй окружности: ");
	scanf("&f &f", &xc2, &yc2);
	printf("Введите координаты радиуса первой окружности: ");
	scanf("&f &f", &xc1, &yc1);
	printf("Введите координаты радиуса второй окружности: ");
	scanf("&f &f", &xc2, &yc2);
	s = sqrt(pow(xr2 - xr1, 2) + pow(yr2 - yr1, 2));
	r1 = sqrt(pow(xr1 - xc1, 2) + pow(yc1 - yr1, 2));
	r2 = sqrt(pow(xr2 - xc2, 2) + pow(yr2 - yc2, 2));

	if (xc1 == xc2 && yc1 == yc2)
	{
		printf("Окружности совпадают");
	}

	if (s == 0)
	{
		printf("Окружности соприкасаются");
	}

	if (s > 0)
	{
		printf("Окружности удалены друг от друга");
	}

	if (xc1 == xc2 && yc1 == yc2 && abs(r1 - r2) > 0)
	{
		printf("Одна окружность внутри другой");
	}

	if ()
	{
		printf("Окружности имеют одну общую точку");
	}
	else
	{
		printf("Окружности пересекаются в двух точках");
	}
	return 0;
}