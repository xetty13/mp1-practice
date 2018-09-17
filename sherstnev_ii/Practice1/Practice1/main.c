#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	float x1, y1, x2, y2, r1, r2, t, q;
	setlocale(LC_ALL, "Russian");
	printf("¬ведите x1   ");
	scanf("%f", &x1);
	printf("\n¬ведите y1   ");
	scanf("%f", &y1);
	printf("\n¬ведите x2   ");
	scanf("%f", &x2);
	printf("\n¬ведите y2   ");
	scanf("%f", &y2);
	printf("\n¬ведите r1   ");
	scanf("%f", &r1);
	printf("\n¬ведите r2   ");
	scanf("%f", &r2);
	t=sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1-y2));
	if((x1==x2)&&(y1==y2)&&(r1==r2)) {
		printf("ќкружности совпадают \n");
		return;
	}
	if(t > r1 + r2) {
		printf("ќкружности не дружат \n");
		return;
	}
	if(t == r1 + r2) {
		printf("ќкружности касаютс€ \n");
		return;
	}
	if((r1 > t+r2)||(r2 > t+r1)) {
		printf("ќдна окружность лежит внутри другой \n");
		return;
	}
	if((r1 == t+r2)||(r2 == t+r1)) {
		printf("ќдна окружность лежит внутри другой и касаетс€ ее \n");
		return;
	}
	printf("ќкружности пересекаютс€ \n");
}