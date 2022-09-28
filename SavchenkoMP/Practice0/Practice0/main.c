#include <stdio.h>
#include <math.h>
#include <clocale>

void main() {

	float x1, y1, r1;
	float x2, y2, r2;
	float sqr_x, sqr_y;
	setlocale(LC_CTYPE, "Russian");
	
	// Вводим x1, y1, r1 и x2, y2, r2:
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
	sqr_x = (x1 - x2) * (x1 - x2);
	sqr_y = (y1 - y2) * (x1 - y2);


	if (x1 == x2 && y1 == y2 && r1 == r2) 
		printf("1 Круги дгур на друге");
	if (sqrt(sqr_x + sqr_y) == (r1 + r2))
		printf("2 Круги пересекаются в 1 точке");
	if (sqrt(sqr_x + sqr_y) >= (r1 + r2))
		printf("3 Круги не пересекаются");

}