#include <stdio.h>
#include <math.h>

void main() {
	double x1, y1, r1, x2, y2, r2, l;
	int flag = 0;
	printf("Enter center coordinates of circle #1 (with a space between): ");
	scanf("%lf %lf", &x1, &y1);
	printf("\nEnter radius of circle #1: ");
	scanf("%lf", &r1);
	printf("\nEnter center coordinates of circle #2 (with a space between): ");
	scanf("%lf %lf", &x2, &y2);
	printf("\nEnter radius of circle #2: ");
	scanf("%lf", &r2);
	printf("\n");

	if ((r1 <= 0) || (r2 <= 0)) {
		printf("At least one [radius] parameter is incorrect: you must enter a float number exceeding 0. Start again, please.\n");
		return;
	}

	if ((x1 == y1) && (x2 == y2) && (r1 == r2)) {
		printf("Circles match (inf. common points number - their radiuses and center coordinates are equal).\n");
		return;
	}

	if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < r2*r2) {
		printf("Circle #1 is inside circle #2 (no common points).\n");
		return;
	}

	if ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) < r1*r1) {
		printf("Circle #2 is inside circle #1 (no common points).\n");
		return;
	}

	l = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if (l > r1 + r2) printf("Circles does not intersect (no common points).\n");
	else if (l == r1 + r2) printf("Cicles concern outside (1 common point).\n");
	else printf("Circles intersect (2 common points).\n");
}