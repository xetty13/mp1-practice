#include<stdio.h>
#include<math.h>

void main()
{
	float x1,x2,y1,y2,r1,r2,l;

	scanf("%f%f%f%f%f%f",&x1,&x2,&y1,&y2,&r1,&r2);

	l = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	if(l>r1+r2)
		printf("Circles haven't common points\n");
	else if (l==r1+r2)
		printf("1 points(kasaytsya)\n");
	else if (l<r1+r2)
		printf("2 points (peresekaytsya)\n");
	else if (x1==x2 && y1==y2 && r1==r2)
		printf("Circles sovpadayt");
	else if (x1==x2 && y1==y2 && r1>r2 || r1 < r2)
		printf("Circles kolco");
}