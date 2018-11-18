#include <stdio.h>
#include <math.h>
void main()
{
    double h, w, d, p1, p2, p3, m1, m2, m3, m4, m;
    printf ("Enter the height (from 1,8 to 2,2 m), width (from 0,8 to 1,2 m) and depth (from 0,5 to 0,9 m) of the Cabinet in meters\n");
    scanf ("%lf %lf %lf", &h, &w, &d);
    if ((h < 1.8) || (h > 2.2) || (w < 0.8) || (w > 1.2) || (d < 0.5) || (d > 0.9))
    {
        printf ("Incorrect data");
        return;
    }
    printf ("Enter the density of fiberboard, chipboard and wood in kg / m^3\n");
    scanf ("%lf %lf %lf", &p1, &p2, &p3);
    m1 = p1 * h * w * 0.005;
    m2 = 2 * p2 * d * 0.015 * (h + w);
    m3 = p3 * h * w * 0.01;
    m4 = (h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005);
    m = m1 + m2 + m3 + m4;
    printf ("Cabinet weight - %lf", m);
}
