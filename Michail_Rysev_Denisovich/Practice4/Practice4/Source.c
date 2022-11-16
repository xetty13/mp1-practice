#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char name[10][11] = {"bread", "milk", "juice", "eggs", "soap", "tea", "chocolate", "coffee", "olive oil", "still water"};
int cost[10] = {30, 55, 90, 69, 100, 50, 60, 305, 150, 20};
char barcodes[10][5] = {"0001\0", "0002\0", "0003\0", "0004\0", "0005\0", "0006\0", "0007\0", "0008\0", "0009\0", "0010\0"};
float discounts[10] = {0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5};

int index_lookup(char *basket) {
	for (int i = 0; i < 10; i++) {
		if (strcmp(&(barcodes[i]), basket) == 0) {
			return i;
		}
	}
}

void products() {
	char p = ' ';
	printf("Goods in stock:\n\n");
	printf("product %11c price(rub) %5c discount(%%) %5c barcode\n", p, p, p);
	printf("--------------------------------------------------------------\n");
	printf("bread %13c 30 %13c 5 %15c 0001\n", p, p, p);
	printf("milk %14c 55 %13c 10 %14c 0002\n", p, p, p);
	printf("juice %13c 90 %13c 15 %14c 0003\n", p, p, p);
	printf("eggs %14c 69 %13c 20 %14c 0004\n", p, p, p);
	printf("soap %14c 100 %12c 25 %14c 0005\n", p, p, p);
	printf("tea %15c 50 %13c 30 %14c 0006\n", p, p, p);
	printf("chocolate %9c 60 %13c 35 %14c 0007\n", p, p, p);
	printf("coffee %12c 305 %12c 40 %14c 0008\n", p, p, p);
	printf("olive oil %9c 150 %12c 45 %14c 0009\n", p, p, p);
	printf("still water %7c 20 %13c 50 %14c 0010\n", p, p, p);
	printf("--------------------------------------------------------------\n\n");
}
void scan(char *basket, int count[]) {
	int i = 0;
	printf("Enter 'stop' to stop scaning\n");
	do {
		scanf("%s", &(basket[i * 5]));
		if (strcmp(&basket[i * 5], "stop") != 0) {
			printf("count: ");
			scanf("%d", &count[i]);
			i += 1;
		}
	} while (strcmp(&basket[i * 5], "stop") != 0);
	printf("\n");
}
void print(char *basket, int count[]) {
	int i = 0, ind;
	int sum = 0; 
	float discount_sum = 0;
	printf("Your check\n\n");
	printf("==================================\n");
	while (strcmp(&(basket[i * 5]), "stop") != 0) {
		ind = index_lookup(&(basket[i * 5]));		
		printf("%s %s\n", barcodes[ind], name[ind]);
		printf("count: %d    price: %d\n", count[i], cost[ind]);
		printf("            discount amount: %0.2f\n", count[i] * cost[ind] * discounts[ind]);
		printf("            sum: %0.2f\n", count[i] * cost[ind] * (1 - discounts[ind]));
		printf("----------------------------------\n");
		sum += count[i] * cost[ind];
		discount_sum += count[i] * cost[ind] * discounts[ind];
		i += 1;
	}
	printf("total = %d\n", sum);
	printf("discount amount = %0.2f\n", discount_sum);
	printf("to pay %0.2f\n", sum - discount_sum);
	printf("==================================\n");
	printf("      -= Have a nice day! =-\n");
	printf("==================================\n");
}

int main() {
	char basket[11][5];
	int count[10] = {0};
	
	products();
	scan(&(basket[0][0]), count);
	print(&(basket[0][0]), count);

	return 0;
}