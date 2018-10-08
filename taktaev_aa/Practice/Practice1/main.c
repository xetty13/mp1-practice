#include <locale.h>
#include <math.h>
#include <stdio.h>

void main() 
{
	float h, w, d, VZad, VBok, VKrish, VDver, VPolk, Massa, pDSP, pDVP, pDer;
	setlocale(LC_ALL, "Russian");
	printf("Добро пожаловать в РасчетчикМассы v1.0.\n Надеемся, что Вы ознакомились с предельными значениями размеров габаритов Вашего будущего шкафа.\n");
	printf("Введите высоту шкафа в см\n");
	scanf("%f", &h);
	if ((h < 180) || (h > 220)) 
	{
		printf("Введена неверная высота");
		return;
	}
	printf("Введите ширину шкафа в см\n");
	scanf("%f", &w);
	if ((w < 80) || (w > 120)) 
	{
		printf("Введена неверная ширина");
		return;
	}
	printf("Введите глубину шкафа в см\n");
	scanf("%f", &d);
	if ((d < 50) || (d > 90)) 
	{
		printf("Введена неверная глубина");
		return;
	}
	printf("Введите плотности ДСП, ДВП и дерева по очереди через пробел(в г/см^3)\n");
	scanf("%f %f %f", &pDSP, &pDVP, &pDer);
	if ((pDSP <= 0) || (pDVP <= 0) || (pDer <= 0)) 
	{
		printf("Одно из введенных значений плотности неверно. Повторите ввод данных");
		return;
	}
	VZad = w * h * 0.5;
	VBok = 2.0f * h * d * 1.5;
	VKrish = 2.0f * w * d * 1.5;
	VDver = w * h * 1.0f;
	VPolk = (w - 1.5 * 2.0f) * d * floor(h / 40) * 1.5; //выражение в скобках показывает, что полки находятся между двумя боковинами шкафа. 1.5 см - это предположительная толщина полки(в задании она не дана)
	Massa = (VZad * pDVP + VBok * pDSP + VKrish * pDSP + VDver * pDer + VPolk * pDSP) / 1000;
	printf("Масса вашего шкафа равна %.2f кг\n", Massa);
	
}