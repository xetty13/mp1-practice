
#include <stdio.h>
#include <math.h>

int main() {
	float Qdsp, Qdvp, Q, h, w, d, t_zad, t_verh, t_bok, t_dver, t_polki;
	Qdsp = 800;
	Qdvp = 750;
	Q = 640;
	printf("Input h ");
	scanf("%f", h);
	if ((h < 0.18) || (h > 0.22)) {
		printf("Incorrect data,  0.18 <= h <= 0.22 ");
		return 0;
	}
	printf("Input w ");
	scanf("%f", w);
	if ((w < 0.08) || (w > 0.12)) {
		printf("Incorrect data,  0.08 <= w <= 0.12 ");
		return 0;
	}
	printf("Input d ");
	scanf("%f", d);
	if ((d < 0.08) || (d > 0.12)) {
		printf("Incorrect data,  0.05 <= d <= 0.08 ");
		return 0;
	}
	t_zad = 0.0005;
	t_bok = 0.0015;
	t_verh = 0.0015;
	t_dver = 0.001;
	t_pokki = 0.0015;

}