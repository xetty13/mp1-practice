#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int arr[100];
	int counter = 0;
	int get_check = 0;
	int grand_total = 0;
	const char* products[10] = { "potatoes","rice","buckwheat","chicken", "fish", "pork", "salad", "juice", "water","tea" };
	int code[10] = { 0000, 1010, 1111, 1212, 1313, 1414, 1515, 1616, 1717, 1818 };
	float price[10] = { 50.00, 60.00, 70.00, 150.00, 200.00, 250.00, 150.00, 100.00, 50.00, 250.00 };
	float discount[10] = { 0.05, 0.10, 0.20, 0.40, 0.10, 0.05, 0.05, 0.15, 0.30, 0.40 };
	int reg[10] = { 0,0,0,0,0,0,0,0,0,0 };

	while (get_check == 0) {
		int tmp = 0, barcode = 0;
		printf("enter product code\n");

		for (int i = 0; i <= 3; i++) {
			scanf_s("%d", &tmp);
			barcode += tmp;
			if (barcode < 999) {
				barcode *= 10;
			}
		}

		arr[counter] = barcode;
		counter++;

		printf("want a check? 1/0\n");
		printf("1 - yes, 0 - no\n");
		scanf_s("%d", &get_check);
	}

	for (int i = 0; i <= counter; i++) {
		for (int j = 0; j <= 10; j++) {
			if (code[j] == arr[i]) {
				reg[j] += 1;
			}
		}
	}

	printf("your check:\n");

	for (int i = 0; i <= 10; i++) {
		if (reg[i] > 0) {
			printf("************************\n");
			int discount_price = price[i] * (1 - discount[i]);
			grand_total = grand_total + discount_price;
			printf("product: %s \n", products[i]);
			printf("price: %f \n", price[i]);
			printf("discount: %f \n", discount[i]);
			printf("discount price: %d \n", discount_price);
			printf("number : %d \n", reg[i]);
		}
	}
	printf("************************\n");
	printf(" grand total: %d\n", grand_total);
	return 0;
}