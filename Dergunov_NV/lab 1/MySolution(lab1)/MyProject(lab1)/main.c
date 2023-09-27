#include <stdio.h>
#include <math.h>
int main() {
    double x1, x2, y1, y2, r1, r2, f;
    printf("Input first round data: ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    if (r1 < 0)
    {
        printf("Incorrect data entered");
        return 0;
    }
    printf("Input second round data: ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    if (r2 < 0)
    {
        printf("Incorrect data entered");
        return 0;
    }
    f = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    if (f == r1 + r2) //1 ����� ������� �������
    {  
        printf("The circles have 1 touch point (outside)");
    }
    if (f > r1 + r2) // ��� ����� �������
    {
        printf("Circles do not have touch points");
    }
    if (x1 == x2 && y1 == y2 && r1 == r2)// ���������� ���������
    {
        printf("The circles are identical");
    }
    if ((sqrt((r1-r2)*(r1-r2))< f) && (f < (r1 + r2)))// ���������� ������������ (2 �����)
        {
            printf("The circles have 2 touch point"); 
        }    
    if (sqrt((r1-r2)*(r1-r2)) == f)// ����� ������� (������)
    {
        printf("The circles have 1 touch point (inside)");
    }
    if ((r1 + f < r2) || (r2 + f < r1)) // ���� ����� ������ ������
    {
        printf("Circles inside each other");
    }
    return 0;
 }