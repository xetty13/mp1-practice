#include <stdio.h>
#include <math.h>
void main() {
	double a1, b1, a2, b2, r1, r2,x;
	scanf("%lf %lf %lf %lf %lf %lf", a1, b1, r1, a2, b2, r2);
	if ((a1 == a2) && (b1 == b2) && (r1 == r2)) {
		printf("Okruzhnosti sovpadayut");
		return;
	}
	x = sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2));
	if ((x - r2 < r1) || (x - r1 < r2)) {
		printf("Odna Okruzhnost' vhodit v druguyu");
		return;
	}
	else if ((x - r2 == r1) || (x - r1 == r2)) {
		printf("Odna okruzhnost' vnutrnne kasaets'a drugoy");
		return;
	}
	if ()


}

