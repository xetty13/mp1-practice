#include <stdio.h> 
#include <math.h> 
#include <locale.h> 

void main()
{ 
	float dsp, dvp, der; // ДСП,ДВП,плотность дерева в м3
	float h, w, d; // вводимые пользователем данные: высота, ширина, глубина
	float mz, mb, mk, md, mp, m;//суммы
	float t1, t2, t3, t4;// толщина
	t1 = 0.005f;
	t2 = 0.015f;
	t3 = 0.015f;
	t4 = 0.01f;
        setlocale (LC_ALL, "Russian"); 

	printf ("Введите высоту в метрах\n"); 
	scanf ("%f", &h); 
	printf ("Введите ширину\n"); 
	scanf ("%f", &w); 
	printf ("Введите глубину\n"); 
        scanf ("%f", &d); 
	printf ("Введите дсп\n"); 
	scanf ("%f", &dsp); 
	printf ("Введите двп\n"); 
	scanf ("%f", &dvp); 
	printf ("Введите плотность дерева\n"); 
	scanf ("%f", &der); 
	if ((1.8 < h) && (h < 2.2) && (0.8 < w) && (w < 1.2) && (0.5 < d) && (d < 0.9))
	{
	  mz = h * w * t1 * dvp;
	  mb = 2 * h * d * t2 * dsp;
	  mk = 2 * dsp * w * d * t3;
	  md = h * w * t4 * der;
	  mp = dsp * ((int)((h - 2 * 0.015) / (0.4 + 0.015))) * (w - 2 * 0.015) * (d - 0.005);
	  m = (mz + mb + mk + md + mp) / 100;
	  printf ("Масса шкафа %0.f кг\n",m);
	}
	else 
	   printf ("Введенные значения не соответствуют должным");
}

