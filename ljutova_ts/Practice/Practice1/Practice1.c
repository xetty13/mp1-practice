#include <stdio.h>
void main() {
	double V1, V2, V3, m1, m2, m3, M;
	scanf("%lf %lf %lf %lf %lf %lf %lf", &V1, &V2, &V3, &m1, &m2, &m3, &M);
	double l1 = 0.5, l2 = 1.5, l3 = 1;
	scanf("%lf &lf &lf", &l1, &l2, &l3);
	double h, w, d, p1, p2, p3;
	printf("Enter h (From 180 to 200):");
	scanf("%lf", &h);
	printf("Enter w (From 80 to 120):");
	scanf("%lf", &w);
	printf("Enter d (From 50 to 90):");
	scanf("%lf", &d);
	printf("Enter p1:");
	scanf("%lf", &p1);
	printf("Enter p2");
	scanf("%lf", &p2);
	V1 = h*w*l1;
}