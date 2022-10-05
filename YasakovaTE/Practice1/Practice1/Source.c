#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	float h, w, d, t_zad, t_front, t_side, t_top, t_door;
	float density_dsp = 800;
	float density_dvp = 750;
	float density_tree = 640;
	printf("Enter the height of the cabinet (from 180 to 220 cm): ");
	scanf("%f", &h);
	if ((h < 180) || (h > 220))
	{
		printf("You entered incorrect data (from 180 to 220 cm).");
		return 0;
	}
	printf("Enter the width of the cabinet: (from 80 to 120 cm): ");
	scanf("%f", &w);
	if ((w < 80) || (w > 120))
	{
		printf("You entered incorrect data (from 80 to 120 cm).");
		return 0;
	}
	printf("Enter the depth of the cabinet: (from 50 to 90 cm): ");
	scanf("%f", &d);
	if ((d < 50) || (d > 90))
	{
		printf("You entered incorrect data (from 50 to 90 cm).");
		return 0;
	}



	

}