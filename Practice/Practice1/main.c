#include <stdio.h>
#include <locale.h>
#define DVP 300
#define DSP 700
#define WOOD 600

void main()
{
	float w, h, d;
	float rp, side, lid, door, shelf, tm;
	setlocale(LC_ALL, "Russian");
	printf("Для расчёта массы шкафа введите:\nВысота (180 – 220 см), ширина (80 – 120 см), глубина (50 – 90 см)\n\n");
	scanf("%f %f %f", &h, &w, &d);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90)) {
		printf("Неверные данные\n");
		return;
	}
	h /= 100;
	w /= 100;
	d /= 100;
	rp = h * w * 0.005f * DVP;
	side = 2 * h * d * 0.015f * DSP;
	lid = 2 * w * d * 0.015f * DSP;
	door = w * h * 0.01f * WOOD;
	if (h > 200)
		{shelf = 5 * w * d * 0.015f * DSP;}
	else
		{shelf = 4 * w * d * 0.015f * DSP;}
	tm = rp + side + lid + door + shelf;
	printf("\nПолная масса шкафа равна %.1f кг\n\n", tm);
}