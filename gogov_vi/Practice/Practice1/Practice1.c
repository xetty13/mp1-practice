#include <stdio.h>
#include <math.h>
#include <locale.h>

void main() 
{
	double dsp_m, dsp, dvp_m, dvp, wood_m, wood, h, w, d;
	double sidewm, swm, cm, dm, sm, m;
	setlocale(LC_ALL, "Russian");
	int nof;
	printf("Введите плотность ДСП(кг/м^3): ");
	scanf("%lf", &dsp_m);
	if (dsp_m < 0) {
		printf(" ОШИБКА \a \n Плотность ДСП должна быть больше 0\n");
		return;
	}
	printf("Введите плотность ДВП(кг/м^3): ");
	scanf("%lf", &dvp_m);
	if (dvp_m < 0) {
		printf(" ОШИБКА \a \n Плотность ДСП должна быть больше 0\n");
		return;
	}
	printf("Введите плотность дерева(кг/м^3): ");
	scanf("%lf", &wood_m);
	if (wood_m < 0) {
		printf(" ОШИБКА \a \n Плотность дерева должна быть больше 0\n");
		return;
	}

	dsp = dsp_m / 1000000;
	dvp = dvp_m / 1000000;
	wood = wood_m / 1000000;

	printf("Введите высоту шкафа в сантиметрах от 180 до 220: ");
	scanf("%lf", &h);
	if ((h < 180) || (h > 220)) {
		printf(" ОШИБКА \a \n Введены некорректные данные\n");
		return;
	}

	printf("Введите ширину шкафа в сантиметрах от 80 до 120: ");
	scanf("%lf", &w);
	if ((w < 80) || (w > 120)) {
		printf(" ОШИБКА \a \n Введены некорректные данные\n");
		return;
	}

	printf("Введите глубину шкафа в сантиметрах от 50 до 90: ");
	scanf("%lf", &d);
	if ((d < 50) || (d > 90)) {
		printf(" ОШИБКА \a \n Введены некорректные данные\n");
		return;
	}
	nof = h / 40;
	sidewm = dvp*h*w*0.5;
	swm = 2 * dsp* h*d*1.5;
	cm = 2 * dsp*w*d*1.5;
	dm = wood*h*w * 1;
	sm = dsp*nof*(w - 3)*d*1.5;
	m = sidewm + swm + cm + dm + sm;
	printf("Масса шкафа = %.2lf килограмм\n", m);
}
