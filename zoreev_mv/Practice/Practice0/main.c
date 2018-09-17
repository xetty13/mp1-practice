#include <stdio.h>
#include <math.h>
void main() {
	float x1=0,x2=0,y1=0,y2=0,r1=0,r2=0,R=0;
	scanf("%f%f%f%f%f%f",&x1,&y1,&r1,&x2,&y2,&r2);
	R=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if (R==0) {
		printf("okrujnosti sovpadajut");
		return;
	}
	if ((r1+r2)<R) {
		printf("ne peresekajutsa");
		return;
	}
	if ((r1+r2)==R) {
		printf("Okrujnosti kasautsa vneshnim sposobom");
		return;
	}
	if ((R>r1)&&(R>r2)) {
		printf("Okrujnosti peresekaytsa v dvuh tochkah vneshnim sposobom");
		return;
	}
	if (((R<r1)||(R<r2))&&(((R+r1)>r2)&&((R+r2)>r1))) {
		printf("Okrujnosti peresekaytsa v dvuh tochkah vnutrennim sposobom");
		return;
	}
	if (((R<r1)||(R<r2))&&(((R+r1)==r2)||((R+r2)==r1))) {
		printf("Okrujnosti kasautsa vnutrennim sposobom");
		return;
	}
	if (((R<r1)||(R<r2))&&(((R+r1)<r2)||((R+r2)<r1))) {
		printf("Odna okrujnosti lejit vnutri drugoi");
}
}
