#include <stdio.h>
#include <math.h>
int main()
{
	float x1, x2, y1, y2, r1, r2, s, br, smr;
	scanf("%f %f %f", & x1, & y1, & r1);
	scanf("%f %f %f", &x2, &y2, &r2);
	s = sqrt((x1 - x2)*(x1-x2) + (y1-y2)*(y1 - y2));
	br = r1;
	if (r2 > br) { br = r2; smr = r1; }
	else smr = r2;
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("circumferences are the same");
		return 0;
	}
	if (r1 + r2 < s)
	{
		printf("circumferences doesn't intersect");
	}
	if (r1 + r2 == s)
	{
		printf("circumferences touch");
	}
	if ((r1 + r2 > s) && (s > br))
	{
		printf("circumferences intersect");
	}
	if ((s < br) && (smr < (br - s)))
	{
		printf("one circumference is inside another");
	}
	if ((s < br) && (smr == (br - s)))
	{
		printf("one circumference is inside another and they touch");
	}
	if ((s < br) && (smr > (br - s)))
	{
		printf("one circumference is inside another and they intersect");
	}
	return 0;
}	
