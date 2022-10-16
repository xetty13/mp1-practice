#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	double x1, dl, x2, y1, y2, r1, r2;

	setlocale(LC_ALL, "Russian");
	printf("Input x1: ");
	scanf_s("%lf", &x1);

	printf("Input y1: ");
	scanf_s("%lf", &y1);

	printf("Input r1: ");
	scanf_s("%lf", &r1);

	printf("Input x2: ");
	scanf_s("%lf", &x2);

	printf("Input y2: ");
	scanf_s("%lf", &y2);

	printf("Input r2: ");
	scanf_s("%lf", &r2);


	dl = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (dl == r1 + r2)
	{
		printf("Окружности касаются");
		return;
	}

	if (dl >= r1 + r2)
	{
		printf("Окружности не имеют общих точек");
		return;
	}

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Окружности совпадают");
		return;
	}

	if ((sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) < (r1 - r2)) || (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) > (r1 - r2))) {

		printf("Одна окружность внутри второй, не пересекаются");
		return 0;
	}
	if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == (r2 - r1)) {
		printf("Одна окружность касается внутри второй");
		return 0;
	}
	if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) > (r1 + r2)) {
		printf("Окружности не пересекаются");
		return 0;
	}
	if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) < (r2 + r1) && (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) > (r1 - r2))){
		printf("Окружности пересекаются в 2 точках");
		return 0;
	}

	printf("Вы нашли баг в программе, напишите нам пожалуйста :( ");
	return 0;
}