#include <stdio.h>
#include <math.h>
void main() {
	float x1=0,x2=0,y1=0,y2=0,r1=0,r2=0,R=0;
	printf("Please, input parmameters of the first circle, then of the second circle in x,y,r format. Press enter after inputting each parameter\n");
	scanf("%f%f%f%f%f%f",&x1,&y1,&r1,&x2,&y2,&r2);

	if ((r1<0)||(r2<0)) {
		printf("Imposible circle(s)\n");
		return;
	}

	R=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); //Distance between centers of circles

	if ((R==0)&&(r1==r2)) {
		printf("Circles are equal\n");
		return;
	}

	if ((r1+r2)<R) {
		printf("Circles don't intersect, and don't lies one in the other\n");
		return;
	}

	if ((r1+r2)==R) {
		printf("Circles touches outside\n");
		return;
	}

	//From this moment r1+r2>R

	if (((R+r1)>r2)&&(R+r2)>r1) {
		printf("Circles intersect at two points\n");
		return;
	}

	if (((R+r1)==r2)||((R+r2)==r1)) {
		printf("One circle touches another circle inside\n");
		return;
	}
	
	if (((R+r1)<r2)||(R+r2)<r1) {
		printf("One circle lie in anouther");
		return;
	}

	printf("Somthing strange happen, FATAL ERROR");
}
