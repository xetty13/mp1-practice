#include <stdio.h>

void main()
{
    double h = 0, w = 0, d = 0, m = 0, dvp, dsp, der;
    int p = 0;

    printf("180 < h < 200, h = \n");
    while ((h > 200) || (h < 180))
        scanf("%lf", &h);
    h = h * 0.01;
    printf("80 < w < 120, w = \n");
    while ((w > 120) || (w < 80))
        scanf("%lf", &w);
    w = w * 0.01;
    printf("50 < d < 90, d = \n");
    while ((d > 90) || (d < 50))
        scanf("%lf", &d);
    d = d * 0.01;

    printf("density dvp \n");
    scanf("%lf", &dvp);
    printf("density dsp \n");
    scanf("%lf", &dsp);
    printf("density wood \n");
    scanf("%lf", &der);
    dvp = 0.5 * dvp;
    dsp = 1.5 * dsp;
    der = 1 * der;

    m = (dvp * (h - 2 * 0.015) * w) + 2 * (dsp * (h - 2 * 0.015) * (d - 0.005)) + 2 * (dsp * w * d) + (der * (h - 2 * 0.015) * w); 
    p = (int)(h * 100 / 40) - 1;
    m = m + dsp * (w - 2 * 0.015) * (d - 0.005) * p;
    printf("massa = %lf kg", m);
}