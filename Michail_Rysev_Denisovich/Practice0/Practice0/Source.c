#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	float x1, y1, r1;
	float x2, y2, r2;
	float d;
	
	printf("Введите координаты центра и радиус первой окржности: ");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Введите координаты центра и радиус второй окружности: ");
	scanf("%f %f %f", &x2, &y2, &r2);
	
	d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	if (d == 0) {
		if (r2 == r1) printf("Окружности совпадают ");
		else printf("Одна окружность лежит внутри другой ");
	}

	else if (d < abs(r1 - r2))
		printf("Одна окружность лежит внутри другой ");

	else if (d == abs(r1 - r2))
		printf("Окружности касаются друг друга изнутри ");

	else if (d > abs(r1 - r2) && d < r1 + r2)
		printf("Окружности пересекаются ");

	else if (d == r1 + r2)
		printf("Окружности касаются друг друга снаружи ");

	else
		printf("Окружности лежат разделно друг от друга ");

	return 0;
}