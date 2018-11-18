#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
    double h, w, d, p1, p2, p3, m1, m2, m3, m4, m;
    setlocale (LC_ALL, "Russian");
    printf ("Введите высоту (от 1,8 до 2,2 м), ширину (от 0,8 до 1,2 м) и глубину (от 0,5 до 0,9 м) шкафа в метрах\n");
    scanf ("%lf %lf %lf", &h, &w, &d);
    if ((h < 1.8) || (h > 2.2) || (w < 0.8) || (w > 1.2) || (d < 0.5) || (d > 0.9))
    {
    printf ("Неверно введены данные");
    return;
    }
    printf ("Введите плотности ДВП, ДСП и дерева в кг/м^3\n");
    scanf ("%lf %lf %lf", &p1, &p2, &p3);
    m1 = p1 * h * w * 0.005;
    m2 = 2 * p2 * d * 0.015 * (h + w);
    m3 = p3 * h * w * 0.01;
    m4 = (h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005);
    m = m1 + m2 + m3 + m4;
    printf ("Масса шкафа - %lf", m);
}

