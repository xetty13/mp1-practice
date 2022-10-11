#include <stdio.h>

int main() {
	float h, d, w;
	float dvp = 0.05, dsp = 0.15; // 800 kg/m3 550 kg/m3

	printf("Enter the height, width and depth of the cabinet ");
	scanf_s("%f %f %f", &h, &w, &d);

	if (h < 180 || h > 220 || d < 50 || d > 90 || w < 80 || w > 120) {
		printf("Incorrect data entered\n");
		printf("h in [180, 220], w in [80, 120], d in [50, 90]");
		return 0;
	}

	int k = h / 40; // кол-во полок
	float m1 = k * d * w * dsp * 0.55; //масса всех полок

	float m2 = h * w * dvp * 0.8; //масса задней стенки

	float m3 = 2 * h * d * dsp * 0.55; //масса боковин

	float m4 = 2 * w * d * dsp * 0.55; //масса верхней и нижней накладок

	float m5 = w * h * 1.5; //допустим плотность древисина равна 1500 кг/м3

	float m = (m1 + m2 + m3 + m4 + m5) / 1000;

	printf("%f", m);
	printf(" kg ");

	return 0;
}