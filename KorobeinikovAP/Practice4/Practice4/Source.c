#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char codes[10][4] = { "1234","2345","3456","4567","5678","6789","7891","8912","9123","9999" };
char names[10][7] = { "salt   ","sugar  ","bread  ", "milk   ","eggs   ","tea    ","cheese ","meat   ","honey  ","oil    " };
int cost[10] = { 50, 60, 40, 80, 80, 50, 200, 300, 150, 75 };
double sale[10] = { 0.1, 0.2, 0.05, 0.05, 0.1, 0.2, 0.04, 0.04, 0.1, 0.2 };


void scan_pr(char* a);
int ind_pr(char* b);
void info_pr(int ind, double* a, double* b);
void f_cheque(int* k, double* a, double* b);


int main() {
	char pr[4];
	int i, flag = 0;
	int ind;
	int counter;
	int sum = 0, total_sum = 0;
	int k_pr[10] = { 0 };
	int total_not_sale, total_sale, total_with_sale;
	double  cost_sale[10] = { 0 };	
	double sale_r[10] = { 0 };
	double total_cost[10] = { 0 };

	for (i = 0; i < 10; i++) {
		cost_sale[i] = cost[i] * (1 - sale[i]);
	}

	for (i = 0; i < 10; i++) {
		sale_r[i] = cost[i]*sale[i];
	}
	
	flag = 1;

	while (flag == 1) {
		printf("Scan the product \n");
		scan_pr(pr);
		ind = ind_pr(pr);
		k_pr[ind] += 1;
		info_pr(ind, sale_r, cost_sale);
		printf("Do you have any more products?  1/0 \n");

		scanf("%d", &counter);
		if (counter == 0)
			flag = 0;
		if (counter == 1)
			continue;
	}

	printf("\n");
	printf("Your cheque: \n");
	for (i = 0; i < 10; i++) {
		total_cost[i] = k_pr[i]*cost_sale[i];
	}

	f_cheque(k_pr, cost_sale, total_cost);

	total_not_sale = 0;
	total_sale = 0;
	total_with_sale = 0;

	for (i = 0; i < 10; i++) {
		total_not_sale += k_pr[i] * cost[i];
		total_sale += k_pr[i] * sale_r[i];
		total_with_sale += k_pr[i] * cost_sale[i];
	}

	printf("Cost without discount = %d \nThe amount of discounts = %d\nCost including discounts = %d", total_not_sale, total_sale, total_with_sale);
	return 0;

}


void scan_pr(char* a) {
	int i;
	char tmp;
	scanf("%c", &tmp);
	if (tmp == '\n') {
		for (i = 0; i < 4; i++) {
			scanf("%c", &a[i]);
		}
	}
	else {
		a[0] = tmp;
		for (i = 1; i < 4; i++) {
			scanf("%c", &a[i]);
		}
	}
}


int ind_pr(char* b) {
	int i, j, flag = 1;
	for (i = 0; i < 10; i++) {
		flag = 1;
		for (j = 0; j < 4; j++) {
			if (codes[i][j] != b[j]) {
				flag = 0;
			}

		}
		if (flag == 1)
			return i;
	}
	printf("Incorrect data ");
	return -1;
}

void info_pr(int ind,double* a, double* b) {
	int i;
	for (i = 0; i <= 6; i++)
		printf("%c"  , names[ind][i]);
	printf("cost = %d   ", cost[ind]);
	printf("sale = %g ", a[ind]);
	printf("total %g \n", b[ind]);
}

void f_cheque(int* k, double* a, double* b) {
	int i, j;
	for (i = 0; i < 10; i++) {
		if (k[i] != 0) {
			for (j = 0; j <= 6; j++)
				printf("%c", names[i][j]);
			printf("cost %g ", a[i]);
			printf("quantity = %d ", k[i]);
			printf("total cost = %g \n", b[i]);
		}
	}
}