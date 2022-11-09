#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char codes[10][4] = { "1234","2345","3456","4567","5678","6789","7891","8912","9123","9999" };
char names[10][20] = { "salt","sugar","bread", "milk","eggs","tea","cheese","meat","honey","oil" };
int cost[10] = { 50, 60, 40, 80, 80, 50, 200, 300, 150, 75 };
int sale[10] = { 0.05, 0.01, 0.1, 0.2, 0.02, 0.3, 0.3, 0.25, 0.08, 0.07 };

void scan_pr(char a[]);



int main() {
	char pr[4] = {0};
	int flag = 0;
	int i;

	printf("Scan the product ");
	scan_pr(pr[0]);
	for (i = 0; i <= 3; i++) {
		print("%c", pr[i]);
	}
	while (flag == 1) {
		



	}
	return 0;

}


void scan_pr(char a[]) {
	int i;
	for (i = 0; i <= 3; i++) {
		scanf("%c", &a[i]);
	}
}



