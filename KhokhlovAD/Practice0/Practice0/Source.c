#include <stdio.h>
#include <math.h>
int main()
{
	int x1, x2, y1, y2, r1, r2, max, min;
	float d;
	printf("x1=");
	scanf_s("%d", &x1);
	printf("y1=");
	scanf_s("%d", &y1);
	printf("r1=");
	scanf_s("%d", &r1);
	printf("x2=");
	scanf_s("%d", &x2);
	printf("y2=");
	scanf_s("%d", &y2);
	printf("r2=");
	scanf_s("%d", &r2);
	if (r1>r2)
	{
		max = r1;
		min = r2;
	}
	else
	{
		max = r2;
		min = r1;
	}
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (d>(r1+r2))
	{
		printf("1");   //не пересекаются
	}
	else if (d == (r1+r2))
	{
		printf("2");   //внешнее косание
	}
	else if ((d<(r1+r2))&&(d>max))
	{
		printf("3");   //пересекаются
	}
	else if (d==(max-min))
	{
		printf("4");   //внутреннее косание
	}
	else if (d<(max-min))
	{
		printf("5");  // одна окружность внутри другой и не косаются
	}
	else	printf("6"); //окружности совпадают
}