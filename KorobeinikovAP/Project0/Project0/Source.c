#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus"); 
	float x1, x2, y1, y2, R1, R2, S;
	printf("Введите координату х1 ");
	scanf("%f", &x1);
	printf("Введите координату y1 ");
	scanf("%f", &y1);
	printf("Введите координату х2 ");
	scanf("%f", &x2);
	printf("Введите координату y2 ");
	scanf("%f", &y2);
	printf("Введите R1, чтобы R1>R2 ");
	scanf("%f", &R1);
	printf("Введите R2 ");
	scanf("%f", &R2);
	S = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (S > R1 + R2) {
		printf("Окружности не пересекаются ");
		return 0;
	}
	if (S == R1 + R2) {
		printf("Внешнее касание окружностей ");
		return 0;
	}
	if ((S < R1 + R2) && (S > (R1 - R2))) {
		printf("Окружности пересекаются ");
		return 0;
	}
	if ((S == (R1 - R2)) && (x1 != x2)) {
		printf("Внутреннее касание окружностей ");
		return 0;
	}
	if ((S == 0) && (R1 == R2)) {
		printf("Окружности совпадают ");
		return 0;
	}
	printf("Вторая окружность лежит внутри первой ");
	return 0;
}