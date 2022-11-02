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

	if ((d == 0) && (r1 == r2)) {
		printf("окружности касаютс€");
		return 0;
	}

	if (d > (r1 + r2)) {
		printf(" руги не пересекаютс€");
		return 0;
	}

	if (d < abs(r1 - r2) && (d > 0)) {
		printf(" руги не пересекаютс€ (внутри)");
		return 0;
	}

	if ((d < r1 + r2) && (d > abs(r1 - r2))) {
		printf("окружности пересекаютс€ в двух точках");
		return 0;
	}

	if (d == r1 + r2) {
		printf("ќкружности пересекаютс€ в одной точке (снаружи)");
		return 0;
	}

	if (d == abs(r1 - r2)) {
		printf("ќкружности пересекаютс€ в одной точке (внутри)");
		return 0;
	}
	return 0;
}