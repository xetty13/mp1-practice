#include<stdio.h>
#include<math.h>
void main() 
{
	double r1, r2, x1, x2, y1, y2;
	scanf("%fl %fl %fl %fl %fl %fl", &r1, &r2, &x1, &x2, &y1, &y2);
	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
		printf("Совпадают");
		return;
	}
	if (((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>((r1+r2)*(r1+r2)))
	{
		printf("Не пересекаются");
		return;
	}
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))==((r1 + r2)*(r1 + r2))||(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == ((r1 - r2)*(r1 - r2)))) {
		printf("Касаются");
		return;
	}
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < ((r1 + r2)*(r1 + r2))) {
	
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < ((r1 - r2)*(r1 - r2))) {
		printf("Одна внутри другой");
	}
	else printf("Пересекаются");

}