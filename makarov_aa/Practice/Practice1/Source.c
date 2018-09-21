#include <stdio.h>
#include <locale.h>
#include <math.h>
void main() {
	double x1, y1, r1, x2, y2, r2, o;
	setlocale(LC_ALL, "Russian");
	printf_s("Введите х координату центра первой окружности \n");
	scanf_s("%lf",&x1);
	printf_s("Введите у координату центра первой окружности \n");
	scanf_s("%lf",&y1);
	printf_s("Введите радиус первой окружности \n");
	scanf_s("%lf",&r1);
	printf_s("Введите х координату центра второй окружности \n");
	scanf_s("%lf", &x2);
	printf_s("Введите у координату центра второй окружности \n");
	scanf_s("%lf", &y2);
	printf_s("Введите радиус второй окружности \n");
	scanf_s("%lf", &r2);
	o = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if ((r1 == r2) && (x1 == x2) && (y1 == y2))
	{
		printf("Совпадают");
		return;
	}
	if ((r2 < r1) && (o + r2 < r1) || (r1 < r2) && (o + r1 < r2))
	{
		printf("Одна окружность в другой без касания");
		return;
	}
	if ((r2 < r1) && (o + r2 == r1) || (r1 < r2) && (o + r1 == r2))
	{
		printf("Одна касается другой изнутри");
		return;
	}
	if (o < r1 + r2)
	{
		printf("Пересекаются");
		return;
	}
	if (o == r1 + r2)
	{
		printf("Касаются снаружи");
		return;
	}
	if (o > r1 + r2)
	{
		printf("Не пересекаются");
		return;
	}
}