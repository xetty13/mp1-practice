#include <stdio.h>
#include <locale.h>

void main() {

	setlocale(LC_ALL, "rus");
	float h, w, d; // 180 <= h, w <= 220 sm, 50 <= d <= 90 sm
	float th_DSP = 0.015, th_DVP = 0.005, th_door = 0.010; // mm
	float back_wall, side_wall, cap, doors, shelves;
	float q_tree = 900.0, q_DSP = 800.0, q_DVP = 800.0; // kg / m^3
	
	printf("Input h, w, d: \n");
	printf("(180 <= h, w <= 220 sm, 50 <= d <= 90 sm)\n");
	scanf("%f %f %f", &h, &w, &d);

	if (h < 180 || h > 220 || w < 180 || w > 220 || d < 50 || d > 90) {
		printf("Incorrect data.");
		return;
	}
	else {

		// sm > m
		h = h / 10;
		w = w / 10;
		d = d / 10;

	}

}