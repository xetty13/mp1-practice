#include <stdio.h> 
#include <math.h> 

int main() 
{ 
double x1, x2, y1, y2, r1, r2, d; 
scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2); 
d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)); 
scanf("%lf %lf", &r1, &r2); 
if ((d == 0) && (r1==r2)) 
printf("Okruzhnosti sovpadaut"); 
if (d<abs(r1 - r2)) 
printf("Odna okruzhnost lezhit v drugoi"); 
if ((d == abs(r1 - r2)) && (r1!=r2)) 
printf("Odna okruzhnost kasaetsya drugoi vnutrennim obrazom"); 
if (d == abs(r1 + r2)) 
printf("Odna okruzhnost kasaetsya drugoi vnutrennim obrazom"); 
if (d>(r1 + r2)) 
printf("Okruzhnosty ne peresekautsya"); 
if (d<abs(r1 + r2) && d>abs(r1 - r2)) 
printf("Okruzhnosty peresekautsya"); 
}