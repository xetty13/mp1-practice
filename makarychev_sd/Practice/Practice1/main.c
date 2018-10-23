#include <stdio.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	float h, d, w, m1, m2, m3, m4, m5, m, n, t1 = 0.005, t2 = 0.015, t3 = 0.01;
	float p1 = 900, p2 = 700, p3 = 450;
	printf("введите ширину от 0,8 до 1,2 метров \n");
	scanf("%f", &w);
	printf("введите глубину от 0,5 до 0,9 метров \n");
	scanf("%f", &d);
	printf("введите высоту от 1,8 до 2,2 метров \n");
	scanf("%f", &h);
	if ((w <= 0.8) || (w >= 1.2) || (d <= 0.5) || (d >= 0.9) || (h <= 1.8) || (h>= 2.2))
	{
		printf("неверные данные \n");
		return;
	}
	if (1.8 <= h < 2.0)
	{
		n = 4;
	}
	else if (2.0 <= h <= 2.2)
	{
		n = 5;
	}
	m1 = p1 * h * w * t1;
	m2 = 2 * p2 * d * t2 * (h + w);
	m3 = p3 * h * w * t3;
	m4 = n * p2 * d * w * t2;
	m = m1 + m2 + m3 + m4;
	printf("%f \n", m);
}
