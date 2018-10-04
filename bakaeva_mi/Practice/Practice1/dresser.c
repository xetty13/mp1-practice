#include <locale.h>
#include <stdio.h>
#include <math.h>
void main() {
    setlocale(LC_ALL, "Russian");
    double w, h, d, dcp, dvp, der, m1, m2, m3, m4, m5, m ;

    printf(" Введите высоту (180см - 220см), ширину (80см - 120см) и глубину (50см - 90см) шкафа \n");
    scanf(" %lf %lf %lf", &h, &w, &d);

    if ((h < 180) || (h > 220)) 
    {
        printf(" Данные некорректны ");
        return;
    }

    if ((w < 80) || (w > 120))
    {
        printf(" Данные некорректны ");
        return;
    }

    if ((d < 50) || (d > 90))
    {
        printf(" Данные некорректны ");
        return;
    }

    printf(" Введите плотность ДСП, ДВП и плотность дерева ( кг/м3 ) \n");
    scanf("%lf %lf %lf", &dcp, &dvp, &der);

    if ((dcp < 0) || (dvp < 0) || (der < 0))
    {
        printf(" Данные некорректны ");
        return;
    }

    m1 = (h * w * 5 * dvp) / 10000000;          //Задняя стенка
    m2 = (2 * dcp * h * d * 15) / 10000000;     //Две боковины
    m3 = (2 * dcp * w * d * 15) / 10000000;     //Верхняя и нижняя крышки
    m4 = (h * w * 1 * der) / 1000000;           //Двери
    m5 = (floor(h / 40) * dcp * (w - 3) * d * 15) / 10000000;    //Полки

    m = m1 + m2 + m3 + m4 + m5;

    printf(" Масса шкафа = %.2lf кг \n", m);
    return;
}