#include <stdio.h>

void main() {

	float h, w, d; // 180 <= h, w <= 220 sm, 50 <= d <= 90 sm
	float th_DSP = 0.015, th_DVP = 0.005, th_door = 0.01; // m
	float back_wall, side_walls, caps, doors, shelves; // cm
	float q_tree = 900.0, q_DSP = 800.0, q_DVP = 800.0; // kg / m^3
	int n; // amount of shelves

	printf("Input h, w, d: \n");
	printf("(180 <= h, w <= 220 sm, 50 <= d <= 90 sm)\n");
	scanf("%f %f %f", &h, &w, &d);

	if (h < 180 || h > 220 || w < 180 || w > 220 || d < 50 || d > 90) {
		printf("Incorrect data.");
		return;
	}
	else {

		// amount of shelves
		n = h / 40;

		// sm > m
		h = h / 100;
		w = w / 100;
		d = d / 100;

		// kg
		back_wall = q_DVP * h * w * th_DVP;
		side_walls = q_DSP * h * d * th_DSP * 2;
		caps = side_walls;
		doors = q_tree * h * w * th_door;
		shelves = q_DSP * (w - 2 * th_DSP) * (d - th_DVP) * th_DSP * n;

		printf("%f", back_wall + side_walls + caps + doors + shelves);
	}
}