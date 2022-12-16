#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	float cx1, cx2, r1, cy1, cy2, r2, d;
	printf("введите координаты первой окружности (x, y, r):");
	scanf_s("%f %f %f", &cx1, &cy1, &r1);
	printf("введите координаты второй окружности (x, y, r):");
	scanf_s("%f %f %f", &cx2, &cy2, &r2);
	d = sqrt((cx1 - cx2) * (cx1 - cx2) + (cy1 - cy2) * (cy1 - cy2));
	

	if (d > (r1 + r2)) {
		printf("Круги не пересекаются"); //4
		return 0;
	}

	if (d < abs(r1 - r2) && (d >= 0)) {
		printf("Круги не пересекаются (внутри)"); //1
		return 0;
	}

	if ((d < r1 + r2) && (d > abs(r1 - r2))) {
		printf("окружности пересекаются в двух точках"); //3
		return 0;
	}

	if (d == r1 + r2) {
		printf("Окружности пересекаются в одной точке (снаружи)"); //2
		return 0;
	}

	if (d == abs(r1 - r2)) {
		printf("Окружности пересекаются в одной точке (внутри)"); //5
		return 0;
	}
	return 0;
}