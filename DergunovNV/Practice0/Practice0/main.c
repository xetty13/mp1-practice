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

    if (x1 == x2 && y1 == y2 && r1 == r2)// ���������� ���������
    {
        printf("The circles are identical");
    }
    else if (f == r1 + r2) //1 ����� ������� �������
    {  
        printf("The circles have 1 touch point (outside)");
    }
    else if (f > r1 + r2) // ��� ����� �������
    {
        printf("Circles do not have touch points");
    }
    else if (abs(r1-r2) == f)// ����� ������� (������)
    {
        printf("The circles have 1 touch point (inside)");
    }
    else if ((r1 + f < r2) || (r2 + f < r1)) // ���� ����� ������ ������
    {
        printf("Circles inside each other");
    }
    else // ���������� ������������ (2 �����)
    {
        printf("Circles have 2 to4ki");
    }
    return 0;
 }