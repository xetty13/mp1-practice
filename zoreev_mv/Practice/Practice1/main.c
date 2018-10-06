#include <stdio.h>
#include <locale.h>
#include <math.h>
void main() {
	setlocale(LC_ALL, "Russian");
	double h, w, d, dvp, dsp, wood, back, side, top, door, shelf, M;
	int n; //Количество полок

	printf("Введите высоту, ширину и глубину шкафа в см\n");
	scanf("%lf%lf%lf",&h,&w,&d);
	printf("Введите плотность двп, дсп и дерева в кг/м^3\n");
	scanf("%lf%lf%lf",&dvp,&dsp,&wood);
	
	if ((dvp < 0) || (dsp < 0) || (wood < 0) || (h < 180) || (h > 220) || (d < 50) || (d > 90) || (w < 80) || (w > 120)) {
		printf("Ошибка ввода\n");
		return;
	}

	n = floor(h / 40); //Щитаем что 40см это расстояние между верхними плоскостями полок, таким образом при высоте кратной 40 верхняя полка будет касаться верхней крышки
	
	back = (h * w * 0.5 * dvp);
	side = (2 * h * d* 1.5 * dsp);
	top = (2 * w * d * 1.5 * dsp);
	door = (h * w * 1 * wood);
	shelf = (n * d * (w-3) * 1.5 * dsp); //Вычитаем 3см т.к боковины не накладные, а значит полки будут уже

	M = (back + side + top + door + shelf) / 1000000;  //Делим на миллион т.к плотность бралась кг/м^3, а размеры брались в см
	printf("Масса шкафа: %lfкг\n",M);
}
