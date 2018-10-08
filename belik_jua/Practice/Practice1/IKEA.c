#include <stdio.h>

void main()
{
	double h = 0, w = 0, d = 0, m, dvp, dsp, der;
	int p = 0;

	printf("180 < h < 200, h =/n");
	while ((h > 200) || (h < 180))
		scanf("%lf", &h);
	printf("80 < w < 120, w =/n");
	while ((w > 120) || (w < 80))
		scanf("%lf", &w);
	printf("50 < d < 90, d =/n");
	while ((d > 90) || (d < 50))
		scanf("%lf", &d);

	dvp = 0.5 * 0.00082;
	dsp = 1.5 * 0.00065;
	der = 0.0008;
	m = (dvp * h * w) + 2 * (dsp * h * d) + 2 * (dsp * w * d) + (der * h * w);
	while (h > 79.0)
	{
		h = h - 40.0;
		p++;
	}
	m = m + dsp * w * d * p;
	printf("massa = %lf", m);
}