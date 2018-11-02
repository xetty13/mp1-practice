#include <locale.h>
#include <math.h>
#include <stdio.h>

void main() 
{
	float h, w, d, VZad, VBok, VKrish, VDver, VPolk, Massa, pDSP, pDVP, pDer;
	setlocale(LC_ALL, "Russian");
	printf("Добро пожаловать в РасчетчикМассы v1.0.\n Надеемся, что Вы ознакомились с предельными значениями размеров габаритов Вашего будущего шкафа.\n");
	printf("Введите высоту шкафа в м\n");
	scanf("%f", &h);
	if ((h < 1.8) || (h > 2.2)) 
	{
		printf("Введена неверная высота");
		return;
	}
	printf("Введите ширину шкафа в м\n");
	scanf("%f", &w);
	if ((w < 0.8) || (w > 1.2)) 
	{
		printf("Введена неверная ширина");
		return;
	}
	printf("Введите глубину шкафа в м\n");
	scanf("%f", &d);
	if ((d < 0.5) || (d > 0.9)) 
	{
		printf("Введена неверная глубина");
		return;
	}
	printf("Введите плотности ДСП, ДВП и дерева по очереди через пробел(в кг/м^3)\n");
	scanf("%f %f %f", &pDSP, &pDVP, &pDer);
	if ((pDSP <= 0) || (pDVP <= 0) || (pDer <= 0)) 
	{
		printf("Одно из введенных значений плотности неверно. Повторите ввод данных");
		return;
	}
	VZad = w * h * 0.005;
	VBok = 2.0 * h * d * 0.015;
	VKrish = 2.0f * w * d * 0.015;
	VDver = w * h * 1.0;
	VPolk = floor((h - 2 * 0.015) / (0.4 + 0.015)) * (w - 2 * 0.015) * (d - 0.005);
	Massa = VZad * pDVP + VBok * pDSP + VKrish * pDSP + VDver * pDer + VPolk * pDSP;
	printf("Масса вашего шкафа равна %.2f кг\n", Massa);
}