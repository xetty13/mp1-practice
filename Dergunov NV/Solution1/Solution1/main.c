#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>

#include "another func.h"
#include "sumf.h"
#include "minusf.h"
#include "dot.h"

int main()
{
    int n;
    double result;
    TVector V1, V2, s, m;
    setlocale(LC_ALL, "Ru");
    printf("Длина V1 = ");
    scanf("%d", &n);
    allocate(&V1, n);
    printf("Длина V2 = ");
    scanf("%d", &n);
    allocate(&V2, n);
    fill(&V1);
    fill(&V2);
    s = sum(&V1, &V2);
    m = minus(&V1, &V2);
    print(&s);
    print(&m);
    result = dot(&V1, &V2);
    printf("Векторное произведение: %lf", result);
    free(V1.x);
    free(V2.x);
    if (s.x != NULL) {
        free(s.x);
    }
    if (m.x != NULL) {
        free(m.x);
    }
}