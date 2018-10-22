#include <stdio.h>
#include <math.h>
void main()
{
	double h, w, d, pder, pdvp, pdsp, m1, m2, m3, m4, m5, M;
	printf ("Vvedite h, w, d");
	scanf ("%lf %lf %lf", &h, &w, &d);
	printf ("Vvedite znacheniya plotnostey dereva, DVP i DSP");
	scanf ("%lf %lf %lf", &pder, &pdvp, &pdsp);
	{
		if ((h >= 1,8) && (h <= 2,2) && (w >= 0,8) && (w <= 1,2) && (d >= 0,5) && (d <= 0,9))
		{
            m1 = (h * w * 0,005 * pdvp);
	        m2 = (h * d * 0,015 * pdsp);
	        m3 = (w * d * 0,015 * pdsp);
		    m4 = (h * w * 0,01 * pder);
		    m5 = (floor(h / 0,4) * w * d * 0,015 * pdsp);
		    M = (m1 + m2 + m3 + m4 + m5);
			printf ("Massa shkapha %lf kg", M);
		}
		else 
		{
			printf("Vvedennye dannye ne korrektny");
		}
	}
}
