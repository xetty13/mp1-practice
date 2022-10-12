#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
1) ne kasayutsya
2) vneshnee kosanie
3) peresekayutsya
4) vnutrennee kosanie
5) odna okruzhnost' vnutri drugoj
6) okruzhnosti sovpadayut
*/

void main() {
	
	setlocale(LC_ALL, "rus");
	float x1, y1, r1, x2, y2, r2, M, m, dl;
	//printf("Circle 1 (x1, y1, r1) = ");
	//scanf_s("%f %f %f", &x1, &y1, &r1);
	//printf("Circle 2 (x2, y2, r2) = ");
	//scanf_s("%f %f %f", &x2, &y2, &r2);
	setlocale(LC_ALL, "rus");
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);

	if (r1 > r2) {
		M = r1;
		m = r2;
	}
	else {
		M = r2;
		m = r1;
	}

	dl = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (x1 == x2 && y1 == y2 && r1 == r2)
		printf("6"); // okruzhnosti sovpadayut 1 1 1 1 1 1
	else {
		if (dl > (r1 + r2))
			printf("1"); // ne kasayutsya 1 1 1 4 1 1
		else if (dl == (r1 + r2))
			printf("2"); // vneshnee kosanie 1 1 1 3 1 1
		else if ((dl < (r1 + r2)) && (dl > M))
			printf("3"); // peresekayutsya 0 0 2 2 0 1
		else if (dl == (M - m))
			printf("4"); // vnutrennee kosanie 1 1 4 4 1 1
		else if (dl < (M - m))
			printf("5"); // odna okruzhnost' vnutri drugoj 1 1 4 2 1 1
	}



}