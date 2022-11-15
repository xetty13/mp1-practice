#include <stdio.h>

#define C_PR 12

int main() {
	char barcodes[C_PR][5] = { "0000", "0001", "0010", "0011", "0100", "1000", "1010", "1011", "1111", "0110", "0111", "0101" };
	char names[C_PR][30] = { "Milk Prostokvashino", "Bread", "Cola 1l", "Sour cream", "Butter", "Chocolate Milka", "Cheese", "Porridge", "Eggs", "Rice", "Sugar 1kg", "baking soda" };
	int priñes[C_PR] = { 80, 40, 110, 80, 107, 120, 170, 50, 55, 60, 59, 250 };
	double disc[C_PR] = { 10.0, 0.0, 5.0, 15.0, 15.0, 20.0, 5.0, 0.0, 5.0, 0.0, 5.0, 15.0 }; // percentage discount
	int hmuch[C_PR] = { 0 };


	while (1) {
		char curr_bar[5], c;
		char code_ch[4] = "CHEK";
		int i, j, flag, ind_pr;
		printf("Enter a barcode of your product\n");
		printf("If you have already scanned all the products, enter: 'CHEK'\n");
		fgets(curr_bar, 5, stdin);
		while ((c = getchar()) != '\n' && c != EOF); // clean up in stream

		flag = 1;
		for (j = 0; j < 4; j++) {
			if (curr_bar[j] != code_ch[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			int i;

			for (i = 0; i < C_PR; i++) {
				if (hmuch[i] != 0)
					printf("Product: %s\tPrice: %d\tDiscount: %d%%\t total price is: %.*lf\n", names[i], priñes[i], (int)disc[i], 2, (priñes[i] * (1 - disc[i] / 100)));
			}

			break;
		}

		for (i = 0; i < C_PR; i++) {
			flag = 1;
			for (j = 0; j < 4; j++) {
				if (curr_bar[j] != barcodes[i][j]) {
					flag = 0;
					break;
				}
			}

			if (flag) {
				hmuch[i] += 1;
				printf("Product: %s\tPrice: %d\tDiscount: %d%%\t total price is: %.*lf\n", names[i], priñes[i], (int)disc[i], 2, (priñes[i] * (1 - disc[i] / 100)));
				break;
			}
		}
	}

	return 0;
}