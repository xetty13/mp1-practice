#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	float h, w, d, m; // Параметры шкафа
	float densityDSP, densityDVP, densityTree; // Плотность материалов
	float wall, sides, doors, lids, shelfs; // Части шкафа
	setlocale(LC_ALL, "Russian");

	printf("Введите высоту (от 180 до 220 см), ширину (от 80 до 130 см), глубину (от 50 до 90 см) шкафа в см: ");
	scanf("%f %f %f", &h, &w, &d);

	if ((h < 180.0) || (h > 220.0) || (w < 80.0) || (w > 130.0) || (d < 50.0) || (d > 90.0))
	{
		printf("Введены неверные параметры шкафа. Проверьте данные.\n");
		return;
	}

	printf("Введите плотность ДСП, ДВП и дерева в кг/м^3: ");
	scanf("%f %f %f", &densityDSP, &densityDVP, &densityTree);

	if ((densityDSP <= 0) || (densityDVP <= 0) || (densityTree <= 0))
	{
		printf("Введены неверные параметры шкафа. Проверьте данные.\n");
		return;
	}

	h = h / 100.0f;
	w = w / 100.0f;
	d = d / 100.0f;

	wall = h * w * (5 / 1000.0f) * densityDVP;
	sides = 2 * h * d * (15 / 1000.0f) * densityDSP;
	lids = 2 * w * d * (15 / 1000.0f) * densityDSP;
	doors =  h * w * (1 / 100.0f) * densityTree;
	shelfs = floor(h / 0.4) * w * d * (1 / 1000.0f) * densityDSP;

	m = wall + sides + lids + doors + shelfs;
	printf("Масса шкафа в кг равна %.3f\n", m);
}