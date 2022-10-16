#include <stdio.h>
#include <locale.h>
#define Chipboard 0.0008f
#define Fiberboard 0.0008f
#define Wood 0.0009f


#if defined(_WIN32) || defined(_WIN32_)
	#define _CRT_SECURE_NO_WARNINGS_
	#pragma warning(disable:4996)
#endif

int main()
{
	setlocale(LC_ALL, "rus");
	float h, w, d, weight, weight_back, weight_side, weight_cover, weight_door, weight_shelf;

	//Ввод данных 
	printf("Введите высоту шкафа в сантиметрах (180 <= h <= 220) : ");
	scanf("%f", &h);
	if (h > 220 || h < 180) {
		printf("Вы ввели недопустимое значение высоты");
		return 0;
	}


	printf("Введите ширину материалов в сантиметрах (80 <= w <= 120) : ");
	scanf("%f", &w);
	if (w < 80 || w > 120) {
		printf("Вы ввели недопустимое значение ширины");
		return 0;
	}

	printf("Введите глубину шкафа в сантиметрах (50 <= d <= 90) : ");
	scanf("%f", &d);
	if (d > 90 || d < 50) {
		printf("Вы ввели недопустимое значение глубины");
		return 0;
	}
	//Масса задней стенки из ДВП
	weight_back = 0.5 * w * h * Fiberboard;

	//Масса двух боковин
	weight_side = 2 * h * d * 1.5 * Chipboard;

	//Масса накладных крышек
	weight_cover = 2 * w * d * 1.5 * Wood;

	//Масса двух дверей
	weight_door = h * w * Wood;

	//Масса полок
	int n;
	n = h / 40;
	weight_shelf = (n - 1) * 1.5 * w * d * Chipboard;


	weight = weight_back + weight_cover + weight_door + weight_shelf + weight_side;
	printf("Масса шкафа в килограммах по выбранным параметрам будет составлять:  ");
	printf("%.2f", weight);


	return 0;

}