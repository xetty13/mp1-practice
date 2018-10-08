#include<stdio.h>
#include<locale.h>
void main()
{
	int p1 = 950, p2 = 800, p3 = 540;
	float h, w, d, m1, m2, m3, m4, m5, M, a1 = 0.005, a2 = 0.015, a3 = 0.01;
	int n;
	setlocale(LC_ALL, "Rus");	
	printf("Введите высоту шкафа, м :");
	scanf("%f", &h);
	printf("Введите ширину шкафа, м:");
	scanf("%f", &w);
	printf("Введите глубину шкафа, м:");
	scanf("%f", &d);	
	if (1.8 <= h <= 2.2)
	{
		if (1.8 <= h <= 2)
		{
			n = 4;
		}
		else
		{
			n = 5;
		}
	}
	else
	{
		printf("Неверные данные");
	}
	if ((1.8 <= h <= 2.2) && (0.8 <= w <= 1.2) && (0.5 <= d <= 0.9))
	{
		m1 = p1 * h * w * a1;
		m2 = 2 * p2 * h * d * a2;
		m3 = 2 * p2 * w * d * a2;
		m4 = 2 * p3 * h * w * a3;
		m5 = n * p2 * w * d * a2;
		M = m1 + m2 + m3 + m4 + m5;
		printf("Масса шкафа (кг) = %f", M);
	}
	else
	{
		printf("Неверные данные");
	}
}