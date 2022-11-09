#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_ARR 10
#define N_CODE 4
#define N_NAME 6

/*
Bread, Milk, Water, Tomato, Pickle, Salt, Pepper, Shugar, Beer, Jagermeister
*/

int i, j, total_cost = 0;

//char codes[N_ARR][N_CODE] = {
//	"0001", "1213", "2424", "3776", "4637", "5180", "6878", "7352", "8545", "9999"
//};

char code0[] = "0001";
char code1[] = "1213";
char code2[] = "2424";
char code3[] = "3776";
char code4[] = "4637";
char code5[] = "5180";
char code6[] = "6878";
char code7[] = "7352";
char code8[] = "8545";
char code9[] = "9999";

char name[N_ARR][N_NAME] = {
	"Bread ", "Milk  ", "Water ", "Tomato", "Pickle", "Salt  ", "Pepper", "Spices", "Beer  ", "Jagerm"
};
int cost[N_ARR] = {
	40, 55, 70, 80, 100, 120, 130, 150, 200, 3000
};
int discount[N_ARR] = {
	5, 10, 15, 20, 22, 25, 30, 35, 40, 45
};
int cost_d[N_ARR] = {
	33, 38, 60, 63, 85, 94, 98, 104, 140, 1650
};
int counters[N_ARR] = { 0 };

int chr_int(char x) {
	int a;
	a = (int)x - 48;
	if (0 <= a && a <= 9)
		return a;
	else
		return -1;
}

/*
int chr_int(char x) {
	switch (x) {
	case '0': {return 0; break; }
	case '1': {return 1; break; }
	case '2': {return 2; break; }
	case '3': {return 3; break; }
	case '4': {return 4; break; }
	case '5': {return 5; break; }
	case '6': {return 6; break; }
	case '7': {return 7; break; }
	case '8': {return 8; break; }
	case '9': {return 9; break; }
	default: return -1;
	}
}*/

int check(char* c) { // 1 - in array; 0 - NOT in array
	if (!strcmp(c, code0) || !strcmp(c, code1) || !strcmp(c, code2) || !strcmp(c, code3) || !strcmp(c, code4) ||
		!strcmp(c, code5) || !strcmp(c, code6) || !strcmp(c, code7) || !strcmp(c, code8) || !strcmp(c, code9))
		return 1;
	return 0;
}

void print_item(int item[]) {
	printf("| ");
	for (i = 0; i < N_NAME; i++)
		printf("%c", name[item[0]][i]);
	printf(" | ");
	printf("%4d | %4d%% | %10d |\n", cost[item[1]], discount[item[2]], cost_d[item[3]]);
	counters[item[0]]++;
	total_cost += cost_d[item[3]];
}

int main() {
	int S, S_d, k, num = 0, flag = 1;
	int item[N_CODE];
	char* inp;

	printf("Welcome to the cash register!\n\n");
	printf("Please scan your items (enter his 4-digit code).\n");
	printf("To finish scanning, enter 0.\n\n");

	printf("| NAME   | COST | DISC. | COST_DISC. |\n");

	
	do {
		inp = (char*)malloc(10);
		gets(inp);
		flag = strcmp(inp, "0");
		if (check(inp)) {
			for (i = 0; i < N_CODE; i++)
				item[i] = chr_int(*(inp + i)); // 0 - id_name, 1 - id_cost, 2 - id_disc, 3 - id_cost_d;
			print_item(item);
		}
		else if (flag)
			printf("There is no such code, try another one.\n");

		free(inp);
	} while (flag);
	

	//The_check:
	printf("\n\n=====================================================================\n");
	printf("|  # | NAME   | COST OF 1 | COST_D OF 1 | COUNT | DISCOUNT |   COST |\n");
	for (i = 0; i < N_ARR; i++)
		if (counters[i] != 0) {
			num++;
			k = counters[i];
			S = cost[i] * k;
			S_d = S - cost_d[i] * k;
			printf("| %2d | ", num);
			for (j = 0; j < N_NAME; j++)
				printf("%c", name[i][j]);
			printf(" | ");
			printf("%9d | %11d | %5d | %8d | %6d |", cost[i], cost_d[i], k, S_d, cost_d[i] * k);
			printf("\n");
		}
	printf("=====================================================================\n");
	printf("Total cost: %d rub.\n", total_cost);
	printf("=====================================================================\n");

	return 0;
}
