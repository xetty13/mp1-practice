#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

	setlocale(LC_ALL, "rus");

	float x1, x2, y1, y2, r1, r2, dl;

	printf("¬ведите x1: ");
	scanf_s("%f", &x1);

	printf("¬ведите x2: ");
	scanf_s("%f", &x2);

	printf("¬ведите y1: ");
	scanf_s("%f", &y1);

	printf("¬ведите y2: ");
	scanf_s("%f", &y2);

	printf("¬ведите r1: ");
	scanf_s("%f", &r1);

	printf("¬ведите r2: ");
	scanf_s("%f", &r2);

	dl = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (dl == r1 + r2)
	{
		printf("ќкружности касаютс€ друг друга");
		return 0;
	}

	if (dl > r1 + r2)
	{
		printf("ќкружности не касаютс€ друг друга (внешнее касание)");
		return 0;
	}

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("ќкружности совпадают");
		return 0;
	}

	if ((dl + r1 == r2) || (dl + r2 == r1))
	{
		printf("ќкружности касаютс€ (внутреннее касание)");
		return 0;
	}

	if (abs(x1 - x2) < r1 || abs(x1 - x2) < r2)
	{
		printf("ќдна окружность внутри другой");
		return 0;
	}

	printf("ќкружности имеют две общие точки");
	return 0;


}