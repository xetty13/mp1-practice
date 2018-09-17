#include <stdio.h>
#include <math.h>
void main() {
    double x1, x2, y1, y2, r1, r2, d;

    printf("Enter the coordinates and radius of the first circle \n");
    scanf_s("%lf %lf %lf",&x1,&y1,&r1);
    printf("Enter the coordinates and radius of the second circle \n");
    scanf_s("%lf %lf %lf", &x2, &y2, &r2);

    d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)* (y1 - y2)); //Расстояние между центрами окружностей

    if ((d > fabs(r1 - r2)) && (d < (r1 + r2)))  printf("Ocrujnosti imeut 2 obshie tochki \n"); 
    if (d < fabs(r1 - r2)) printf("Obshie tochki otsutstvuut - odna ocrujnost lejit v drugoi \n");
    if (d > (r1 + r2)) printf("Obshie tochki otsutstvuut - odna ocrujnost lejit vne drugoi \n");
    if (d == (r1 + r2)) printf("Vneshnee kasanie \n");
    if ((d == (fabs(r1 - r2))) && (r1!=r2)) printf("Vnutrenee kasanie \n");
    if ((d == 0) && (r1 == r2)) printf("Ocrujnosti sovpadaut \n");

    system("pause");
    
}