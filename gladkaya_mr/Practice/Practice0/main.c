#include <stdio.h>
#include <math.h>
#include<locale.h>
 void main() {
 	double x1, y1, r1, x2, y2, r2, o1o2, rs, rr;
	setlocale(LC_ALL, "Russian");
 	printf("Введите координаты центра первой окружности и её радиус\n");
	printf("x1 = ");
	scanf_s("%lf", &x1);
	printf("y1 = ");
	scanf_s("%lf", &y1);
	printf("r1 = ");
	scanf_s("%lf", &r1);
	if (r1 < 0) {
		printf("Радиус должен быть положительным");
		return;
	}
	else {
		printf("Введите координаты центра второй окружности и её радиус\n");
		printf("x2 = ");
		scanf_s("%lf", &x2);
		printf("y2 = ");
		scanf_s("%lf", &y2);
		printf("r2 = ");
		scanf_s("%lf", &r2);
		if (r2 < 0) {
			printf("Радиус должен быть положительным");
			return;
		}
 		else {
			o1o2 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
			rs = r1 + r2;
			rr = abs(r1 - r2);
 			//1 случай
			if ((x1 = x2) && (y1 == y2) && (r1 == r2)) {
				printf("Окружности совпадают");
				return;
			}
			// 2 случай
			if ((rr < o1o2) && (rs > o1o2)) {
				printf("Окружности пересекаются в двух точках");
				return;
			}
			// 3 случай
			if (o1o2 == rs) {
				printf("Внешнее касание окружностей");
				return;
			}
			// 4 случай
			if ((o1o2 == rr) && (r1 != r2)) {
				printf("Внутреннее касание окружностей");
				return;
			}
			//5 случай
			if ((o1o2 < rr) && (o1o2 != 0)) {
				printf("Окружности не пересекаются. Одна находится внутри другой");
				return;
			}
			//6 случай
			if (o1o2 > rs) {
				printf("Окружности не пересекаются. Они расположены на расстоянии друг от друга");
				return;
			}
			//7 случай
			if ((o1o2 == 0) && (r1 != r2)) {
				printf("Это концентрические окружности");
				return;
			}
 		}
	}
	system("pause");
} 
