#include <stdio.h>
#include <locale.h>

void main() {
	double h, w, d, pDvp, pDsp, pWood, m, vZad, vBok, vKry, vDve, vPol;
	setlocale(LC_ALL, "Russian");
	printf("-------- ФИРМА \"УМЕЛЫЕ РУЧКИ\" --------\n");

	printf("Укажите высоту шкафа (в см): ");
	scanf("%lf", &h);
	if ((h < 180) || (h > 220)) {
		printf("ОШИБКА: Высота шкафа должна быть в промежутке между 180 и 220 см.");
		return;
	}

	printf("Укажите ширину шкафа (в см): ");
	scanf("%lf", &w);
	if ((w < 80) || (w > 120)) {
		printf("ОШИБКА: Ширина шкафа должна быть в промежутке между 80 и 120 см.");
		return;
	}

	printf("Укажите глубину шкафа (в см): ");
	scanf("%lf", &d);
	if ((d < 50) || (d > 90)) {
		printf("ОШИБКА: Глубина шкафа должна быть в промежутке между 50 и 90 см.");
		return;
	}

	printf("\nВведите плотность ДВП (в кг/см3): ");
	scanf("%lf", &pDvp);
	if (pDvp <= 0) {
		printf("ОШИБКА: Плотность должна быть больше 0");
		return;
	}

	printf("Введите плотность ДСП (в кг/см3): ");
	scanf("%lf", &pDsp);
	if (pDsp <= 0) {
		printf("ОШИБКА: Плотность должна быть больше 0");
		return;
	}

	printf("Введите плотность дерева (в кг/см3): ");
	scanf("%lf", &pWood);
	if (pWood <= 0) {
		printf("ОШИБКА: Плотность должна быть больше 0");
		return;
	}

	printf("Выполняю расчет...\n");

	vZad = h * w * 0.005;
	vBok = 2 * h * d * 0.015;
	vKry = 2 * w * d * 0.015;
	vDve = h * w * 0.01;
	vPol = d * (w - 0.03) * 0.015 * ((int)(h - ((int)h % 40)) / 40);
	m = vZad * pDvp + vBok * pDsp + vKry * pDsp + vDve * pWood + vPol * pDsp;
	printf("Масса шкафа: %lf кг", m);
}