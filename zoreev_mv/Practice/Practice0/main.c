#include <stdio.h>
#include <math.h>
void main() {
	double x1=0,x2=0,y1=0,y2=0,r1=0,r2=0,R=0;
	printf("Please, input parmameters of the first circle, then of the second circle in x,y,r format.\nPress enter after inputting each parameter\n");
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);

	if ((r1<0)||(r2<0)) {
		printf("Imposible circle(s)\n");
		return;
	}

	R=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); //Distance between centers of circles

	if ((R==0)&&(r1==r2)) {
		printf("Circles are equal\n");
		return;
	}

	if (R>(r1+r2)) { //Warning! It's sometimes work incorrectly with uninteger. For example 0,1.24,0,0,2.24,1 gives this answer but R=1.000000 r1+r2=1.000000. I don't know why this hapening.
		printf("Circles don't intersect, and don't lies one in the other\n");
		return;
	}

	if ((r1+r2)==R) {
		if (r1==0) {
			printf("Point (%lf;%lf) lie on the second circle\n", x1, y1);
			return;
		}
		if (r2 == 0) {
			printf("Point (%lf;%lf) lie on the first circle\n", x2, y2);
			return;
		}
		printf("Circles touches outside\n");
		return;
	}

	//From this moment r1+r2>R

	if (((R+r1)>r2)&&(R+r2)>r1) {
		printf("Circles intersect at two points\n");
		return;
	}

	if (((R+r1)==r2)||((R+r2)==r1)) {
		if (r1>r2)
			printf("The second circle touches the first circle inside\n");
		else printf("The first circle touches the second circle inside\n");
		return;
	}
	
	if (((R+r1)<r2)||(R+r2)<r1) {
		if (r1>r2)
			printf("The second circle lie in the first circle\n");
		else printf("The first circle lie in the second circle\n");
		return;
	}

	printf("Somthing strange happen, FATAL ERROR\n"); //It's usless if program work right, but I can miss something...
}