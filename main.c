#include <stdio.h>
#include <locale.h>

void main()
{
	double w, h, d, dsp, dvp, wood;
	double rp, side, lid, door, shelf, tm;
	setlocale(LC_ALL, "Russian");
	printf("Высота, ширина, глубина (в сантиметрах),\nПлотность ДСП, ДВП, дерева в кг/см^3\n\n");
	scanf("%lf %lf %lf %lf %lf %lf", &h, &w, &d, &dsp, &dvp, &wood);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90) || (dsp < 0) || (dvp < 0) || (wood < 0)) {
		printf("Некорректный ввод\n");
		return;
	}
	rp = h * w * 0.5 * dvp;
	side = 2 * h * w * 1.5 * dsp;
	lid = 2 * w * d * 1.5 * dsp;
	door = w * h * wood;
	if (h > 200)
		{shelf = 4 * w * d * 1.5 * dsp;}
	else
		{ shelf = 3 * w * d * 1.5 * dsp; }
	tm = rp + side + lid + door + shelf;
	printf("\nПолная масса шкафа равна %lf\n\n", tm);
}