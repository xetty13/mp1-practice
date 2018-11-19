#include <stdio.h>

int main() {
	float DensityDVP = 0.00082f, DensityDSP = 0.0007f, DensityWood = 0.00065f; //  kg/cm3
	float h, w, d, result;
	int NumberOfShelves;
	printf("Enter the height of the wardrobe (from 180 to 220 cm) ");
	scanf("%f", &h);
	printf("\n");
	if (h < 180 || h > 220) return;
	printf("Enter the width of the wardrobe (from 80 to 120 cm) ");
	scanf("%f", &w);
	printf("\n");
	if (w < 80 || w > 120) return;
	printf("Enter the depth of the wardrobe (from 50 to 90) ");
	scanf("%f", &d);
	printf("\n");
	if (d < 50 || d > 90) return;
	NumberOfShelves = h / 40;
	result = (h * w * 1.5) * DensityDVP + (h * w) * DensityWood +
		2 * (h * d * 1.5) * DensityDSP + 2 * (w * d * 1.5) * DensityDSP +
		NumberOfShelves * (w * d * 1.5) * DensityDSP;
	printf("Weight of the wardrobe is %f kg", result);
	return 0;
}