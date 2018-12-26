#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
    double h, w, d, dvp, dsp, wood, back, side, top, door, shelf, M;
    int n;

    setlocale(LC_ALL, "Russian");

    printf("Введите высоту, ширину и глубину шкафа в см\n");
    scanf("%lf%lf%lf",&h,&w,&d);
    printf("Введите плотность двп, дсп и дерева в кг/м^3\n");
    scanf("%lf%lf%lf",&dvp,&dsp,&wood);
    
    if ((dvp < 0) || (dsp < 0) || (wood < 0) || (h < 180) || (h > 220) || (d < 50) || (d > 90) || (w < 80) || (w > 120))
    {
        printf("Ошибка ввода\n");
        return;
    }

    h = h / 100;
    w = w / 100;
    d = d / 100;

    n = floor((h - 2 * 0.015) / (0.4 + 0.015));
    
    back = (h * w * 0.5 * dvp);
    side = (2 * h * d* 1.5 * dsp);
    top = (2 * w * d * 1.5 * dsp);
    door = (h * w * 1 * wood);
    shelf = (n * (d - 0.5) * (w - 2 * 1.5) * 1.5 * dsp);

    M = (back + side + top + door + shelf);
    printf("Масса шкафа: %lfкг\n",M);
}