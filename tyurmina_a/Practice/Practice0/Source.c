#include <stdio.h>
#include <math.h>
void main ()
{
float x1,y1,x2,y2,r1,r2;
double d;/*d - длина между центрами окружностей*/
printf("Vvedite koordinati chentra i radius 1 okr");
scanf_s ("%f%f%f", &x1, &y1, &r1);
printf("Vvedite koordinati chentra i radius 2 okr");
scanf_s ("%f%f%f", &x2, &y2, &r2);
if ( (r1 == 0) ||  (r2 == 0) )
{
	printf("Oshibka");
	system("pause");
	return;
}
d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
if (d == (r1 + r2))
{
	printf("Kasayutsya vneshne");
	system("pause");
	return;
}
if (r1>r2)
{
   if (d == (r1 - r2))
    {
	   printf("Kasayutsya vnytri");
	   system("pause");
	   return;
    }
   if ((d > (r1 - r2)) && (d < (r1 + r2)))
    {
	   printf("Peresekayutsya");
	   system("pause");
	   return;
    }
   if ((d < (r1 - r2)) && (d > (r1 + r2)))
    {
	   printf("Ne peresekayutsya");
	   system("pause");
	   return;
    }
 }
else
   {
	if (d == (r2 - r1))
	{
		printf("Kasayutsya vnytri");
		system("pause");
		return;
	}
	if ((d > (r2 - r1)) && (d < (r1 + r2)))
	{
		printf("Peresekayutsya");
		system("pause");
		return;
	}
	if ((d < (r2 - r1)) && (d > (r1 + r2)))
	{
		printf("Ne peresekayutsya");
		system("pause");
		return;
	}
   }
}