#include <stdio.h>
#include <math.h>
void main()
{
	double h, w, d, pder, pdvp, pdsp, m1, m2, m3, m4, m5, M;
	printf ("Vvedite h, w, d");
	scanf ("%lf %lf %lf", &h, &w, &d);
	printf ("Vvedite znacheniya plotnostey dereva, DVP i DSP");  //* plotnost ukazyvat v kg\sm^3
	scanf ("%lf %lf %lf", &pder, &pdvp, &pdsp);
	{
		if ((h >= 180) && (h <= 220) && (w >= 80) && (w <= 120) && (d >= 50) && (d <= 90))
			{
				m1 = (h * w * 0,5 * pdvp);
		        m2 = (h * d * 1,5 * pdsp);
		        m3 = (w * d * 1,5 * pdsp);
		        m4 = (h * w * 1 * pder);
		        m5 = (floor(h / 40) * w * d * 1,5 * pdsp);
			    M = (m1 + m2 + m3 + m4 + m5);
				printf ("Massa shkapha %lf kg", M);
		}
		else 
		{
			printf("Vvedennye dannye ne korrektny");
		}
	}
}