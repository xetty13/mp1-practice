#include <stdio.h>
#include <math.h>
void main() {
    double w, h, d, dcp, dvp, der, m1, m2, m3, m4, m5, m ;

    printf(" Vvedite visotu (180sm - 220sm), shirinu (80sm - 120sm) i glubinu (50sm - 90sm) shkafa \n");
    scanf(" %lf %lf %lf", &h, &w, &d);

    if ((h < 180) || (h > 220)) 
    {
        printf(" Error - nekorrektni vvod ");
        return;
    }

    if ((w < 80) || (w > 120))
    {
        printf(" Error - nekorrektni vvod ");
        return;
    }

    if ((d < 50) || (d > 90))
    {
        printf(" Error - nekorrektni vvod ");
        return;
    }

    printf(" Vvedite plotnost DSP, DVP i plotnost dereva ( kg/m3 ) \n");
    scanf("%lf %lf %lf", &dcp, &dvp, &der);

    if ((dcp < 0) || (dvp < 0) || (der < 0))
    {
        printf(" Error - nekorrektni vvod ");
        return;
    }

    m1 = (h * w * 5 * dvp) / 10000000;          //Zadnia stenka
    m2 = (2 * dcp * h * d * 15) / 10000000;     //Bokovini
    m3 = (2 * dcp * w * d * 15) / 10000000;     //Verh i niz
    m4 = (h * w * 1 * der) / 1000000;           //Dveri
    m5 = (floor(h / 40) * dcp * (w - 3) * d * 15) / 10000000;    //Polki

    m = m1 + m2 + m3 + m4 + m5;

    printf(" Massa shkafa = %.2lf kg \n", m);
    return;
}