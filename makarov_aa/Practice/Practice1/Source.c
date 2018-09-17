#include <stdio.h>
#include <locale.h>
#include <math.h>
void main() {
	double x1, y1, r1, x2, y2, r2, o;
	setlocale(LC_ALL, "Russian");
	scanf_s("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
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