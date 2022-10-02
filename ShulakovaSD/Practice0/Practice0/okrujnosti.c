#include<stdio.h>
#include<math.h>
void main()
{
	double x1, x2, y1, y2, r1, r2, d;
printf("Enter first circle characteristics: ");
scanf_s("%lf %lf %lf", &x1, &y1, &r1);
printf("Enter second circle characteristics: ");
scanf_s("%f %f %f", &x2, &y2, &r2);
d = sqrt(x2 * x2 - 2 * x2 * x1 + x1 * x1 + y2 * y2 - 2 * y1 * y2 + y1 * y1);
if (d > (r1 + r2)) printf("Circles don't have common points");
if (d == (r1 + r2)) printf("Circles touch externally");
if (d == fabs(r1 - r2)) printf("Circle2 is inside circle1 with a touch");
if ((d < fabs(r1 - r2)) && (d > 0)) printf("Circle2 is inside circle1 without a touch");
if ((d < (r1 + r2)) && (d > (r1 - r2))) printf("Circles touch at two points");
if ((r1 == r2) && (d == 0)) printf("Circles are equal");
}