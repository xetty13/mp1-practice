#include <stdio.h>
int main()
{
	double h, w, d, bw, sw, uw, shelves, doors, m;
	int n = 0;
	printf("enter height, width, depth (in cm): ");
	scanf_s("%lf %lf %lf", &h, &w, &d);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
	{
		printf("error");
		return 1;
	}
	while (h >= 40)
	{
		h = h - 40;
		n++;
	}
	h = h * 0.01;
	w = w * 0.01;
	d = d * 0.01;
	bw = h * w * 0.005 * 800;
	sw = h * d * 0.015 * 650 * 2;
	uw = w * d * 0.015 * 650 * 2;
	doors = h * w * 0.01 * 550;
	shelves = d * (w - 0.015 - 0.015) * 0.015 * 650 * n;
	m = bw + sw + uw + doors + shelves;
	printf("mass of wardrobe = %lf", m, "kg\n");
	return 0;
}