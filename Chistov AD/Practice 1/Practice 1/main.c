#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*при решении данной задачи будем использовать следующие табличные значения: ДСП: 650 кг/м^3, ДВП: 800 кг/м^3, дерева 550 кг/м^3*/
int main()
{
	double h, w, d, m1, m2, m3, m4, m5, q, k = 0, M;
	printf("Enter cabinet height in cm ");
	scanf("%lf", &h);
	if ((h < 180) || (h > 220))
	{
		printf("Cabinet height value out of range");
		return 1;
	}
	printf("Enter cabinet width in cm ");
	scanf("%lf", &w);
	if ((w < 80) || (w > 120))
	{
		printf("Cabinet width is out of range ");
		return 1;
	}
	printf("Enter cabinet depth in cm ");
	scanf("%lf", &d);
	if ((d < 50) || (d > 90))
	{
		printf("Cabinet depth value out of range");
		return 1;
	}
	q = h-2;	//k=(int)(h/40.);
	while (q > 40)
	{
		q -= 40;
		k++;
	}
	
	m1 = (h * w * 0.5) * 0.8;
	m2 = (h * d * 1.5) * 0.65;
	m3 = (w * d * 1.5) * 0.65;
	m4 = (h * w * 0.5 * 2) * 0.55;
	m5 = ((w-3) *  1.5 * (d-0.5) * k) * 0.65;
	M = m1 + 2 * m2 + 2 * m3 + 2 * m4 + m5;
	printf("The weight of the cabinet is: %.3lf  kg", M/1000.);
	return 0;
}