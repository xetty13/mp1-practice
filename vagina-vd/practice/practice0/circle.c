#include <stdio.h> 
#include <math.h> 
int main() {
	double x1, x2, y1, y2, r1, r2, d, r_m, r_b, r;
	printf("vvedite koordinaty centra 1-y okruzhnosti");
	scanf_s("%lf %lf", &x1, &y1);
	printf("vvedite radius 1-y okruzhnosti");
	scanf_s("%lf", &r1);
	printf("vvedite koordinaty centra 2-y okruzhnosti");
	scanf_s("%lf %lf", &x2, &y2);
	printf("vvedite radius 2-y okruzhnosti");
	scanf_s("%lf", &r2);
	if ((r1 <= 0) || (r2 <= 0)) {
		printf("Nekorrektny vvod radiusa. Radius - chislo polozhitelnoe!");
		return 0;
	}
	d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (r1 != r2) {
		if (r1 > r2) {
			r_b = r1;
			r_m = r2;
		}
		else {
			r_b = r2;
			r_m = r1;
		}
	}
	else r = r1;
	if ((r1 == r2) && (d == 0)) {
		printf("Okruzhnosti sovpadayut i imeyut beskonechno mnogo obshih tochek");
		return 0;
	}
	if ((d > r1 + r2) || (d < r_b-r_m) && (r1 != r2)) {
		printf("Okruzhnosti ne imeyut obshih tochek");
		return 0;
	}
	if ((d == r1 + r2) || (r1 != r2) && (d == r_b - r_m)) {
		printf("Okruzhnosti imeyut 1 obshuyu tochku");
		return 0;
	}
	if ((d!=0)&&(d < r1 + r2)&&((r1==r2) || (r1 != r2) && (d > r_b - r_m))) {
		printf("Okruzhnosti imeyut 2 obshih tochki");
		return 0;
	}
	
}


