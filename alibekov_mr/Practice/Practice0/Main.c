#include<stdio.h>
#include<math.h>
void main()
{
	double r1, r2, x1, x2, y1, y2;
	printf("Vvedite: r1, r2, x1, x2, y1, y2\n");
	scanf_s("%lf %lf %lf %lf %lf %lf", &r1, &r2, &x1, &x2, &y1, &y2);
	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
		printf("Sovpadaut\n");
		return;
	}
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) > ((r1 + r2)*(r1 + r2)))
	{
		printf("Ne imeut nichego obshego\n");
		return;
	}
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == ((r1 + r2)*(r1 + r2)) || (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == ((r1 - r2)*(r1 - r2)))) {
		printf("Kasautsya\n");
		return;
	}
	//if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < ((r1 + r2)*(r1 + r2))) {

		if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < ((r1 - r2)*(r1 - r2))) {
			printf("Odna vnutry drugoy\n");
		}
		else printf("Peresekautsya\n");

	//}
}