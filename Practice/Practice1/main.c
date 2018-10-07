#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	float h,w,d;//h-высота w-ширина d-глубина
	float DVP, DSP, drev;
	float zad, bok, krish, dveri, polki;
	double kol;//количество полок
	setlocale(LC_ALL, "Russian");
	printf("Введите высоту, ширину, глубину\n");
	scanf("%f %f %f", &h, &w, &d);
	if ((h < 180) || (h > 220)){
		printf("Неправильная высота\n");
		return;}
	if ((d < 50) || (d > 90)){
		printf("Неправильная глубина\n");
		return;}
	if ((w < 80) && (w > 120)){
		printf("Неправильная ширина\n");
		return;}
	printf("Введите плотности ДВП, ДСП, дерева\n");
	scanf("%f %f %f", &DVP, &DSP, &drev);
	if ((DVP <= 0) || (DSP <= 0) || (drev <= 0)){
		printf("Неправильная плотность\n");
		return;}
	kol= floor(h / 40);
	zad=h * w * DVP * 0.5f;
	bok=2.0f * DSP * h * d * 1.5f;
	krish=2.0f * DSP * w * d *1.5f;
	dveri=drev * h * w * 2.0f;
	polki=kol * d * w * drev;
	printf("Масса шкафа равна %.0f\n", zad + bok + krish + dveri + polki);
}