#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char codes[10][4] = { "1234","2345","3456","4567","5678","6789","7891","8912","9123","9999" };
char names[10][7] = { "salt   ","sugar  ","bread  ", "milk   ","eggs   ","tea    ","cheese ","meat   ","honey  ","oil    " };
int cost[10] = { 50, 60, 40, 80, 80, 50, 200, 300, 150, 75 };
double sale[10] = { 0.1, 0.2, 0.05, 0.05, 0.1, 0.2, 0.04, 0.04, 0.1, 0.2 };
int k_pr[10] = { 0 };


void scan_pr(char* a);
int ind_pr(char* b);
void info_pr(int ind, double* b);


int main() {
	char pr[4];
	int i, flag = 0;
	int ind;
	double  cost_sale[10] = { 0 };

	for (i = 0; i < 10; i++) {
		cost_sale[i] = cost[i] * (1 - sale[i]);
	}


	


	
	
	while (flag == 1) {
		printf("Scan the product \n");
		scan_pr(pr);
		ind = ind_pr(pr);
		printf("%d ", ind);
		k_pr[ind] += 1;
		info_pr(ind, cost_sale);
	}


	
	return 0;

}


void scan_pr(char* a) {
	int i;
	for (i = 0; i <= 3; i++) {
		scanf("%c", &a[i]);
	}
}


int ind_pr(char* b) {
	int i, j, flag;
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
	return - 1;
}

void info_pr(int ind, double* b) {
	int i;
	for (i = 0; i <= 6; i++)
		printf("%c"  , names[ind][i]);
	printf("cost = %d   ", cost[ind]);
	printf("sale = %g ", sale[ind]);
	printf("total %g ", b[ind]);
}



