#include <stdio.h>
int cabbage[4] = { 1, 1, 1, 1 };
int carrot[4] = { 1, 2, 1, 2 };
int candies[4] = { 2, 3, 1, 1 };
int spaghetti[4] = { 3, 1, 1, 2 };
int zucchini[4] = { 2, 4, 3, 1 };
int cheese[4] = { 2, 3, 1, 4 };
int tomato[4] = { 3, 3, 3, 3 };
int bacon[4] = { 4, 4, 4, 4 };
int lettuce[4] = { 3,4,3,4 };
int chicken[4] = {4, 2, 1, 2};
int muffin[4] = {5,4,3,2};
int pickles[4] = {5, 5, 4, 4};
int products[12] = { 0 };
int barcodes[12] = { 1111, 1212, 2311, 3112, 2431, 2314, 3333, 4444, 3434, 4212, 5432, 5544 };
double prices[12] = { 54.99, 9.99 ,89.99 ,79.99 ,49.99 ,239.99 ,14.99 , 149.99,  29.99,199.99 ,74.99,319.99 };
int discounts[12] = { 19, 23, 45, 48, 33, 15, 19, 25, 37, 7, 40, 39 };
int tmp = 0, recently_added = 0;
double cost = 0, cost_without_discounts = 0;
void introduction()
{
	printf("1 - scan a new item\n");
	printf("2 - get an information about scanned item\n");
	printf("3 - add last scanned item to your groccery check\n");
	printf("4 - print your check\n");
	printf("5 - sum up and show final cost\n");
}
void scan()
{
	int n;
	if (tmp == 0) {
		printf("enter barcode\n");
		scanf("%d", &n);
		for (int i = 0; i < 12; i++) {
			if (barcodes[i] == n) {
				tmp = 2;
				products[i]++;
				recently_added = i;
			}
		}
		if (tmp != 0) {
			printf("beep! Item scanned succesfully!\n");
	}
	else if (tmp == 0) {
			printf("\n");
			printf("Oops, I couldn't find this barcode, please, try again\n");
			scan();
		}
		return 0;
	}
	else if (tmp != 0) {
		printf("looks like an item is already beeing picked. Please, add it to your check first\n");
	}
}
void add_to_check() 
{
	if (tmp == 0) {
		printf("nothing scanned\n");
	}
	else {
		tmp = 0;
		printf("Item was successfully added to your check\n");
	}
}
void info() 
{
	if (tmp != 0) {
		switch (recently_added) {
		case 0:
			printf("\nThis is an average head of an average cabbage\n");
			break;
		case 1:
			printf("\nA carrot. Just a carrot...\n");
			break;
		case 2:
			printf("\nSweet! Some candies!\n");
			break;
		case 3:
			printf("\nVeri spaghetti italiani\n");
			break;
		case 4:
			printf("\nZucchini, it's like a squash, but italian\n");
			break;
		case 5:
			printf("\nCheese, not cheeze\n");
			break;
		case 6:
			printf("\nTomato is like an apple but better\n");
			break;
		case 7:
			printf("\nBacon - cool part of a cool pig\n");
			break;
		case 8:
			printf("\nLettuce - when cabbage is not an option\n");
			break;
		case 9:
			printf("\nChicken... KFC...\n");
			break;
		case 10:
			printf("\nMuffin - Delitious small piece of a cake\n");
			break;
		case 11:
			printf("\nPickles are just forgotten cucumbers in a jar...\n");
			break;
		}
	}
	else {
		printf("nothing scanned\n");
	}
}
void make_check()
{
	cost_without_discounts = 0;
	cost = 0;
	if (tmp == 0) {
		int i;
		printf("\n");
		for (i = 0; i < 50; i++) {
			printf("_");
		}
		printf("\n");
		for (int i = 0; i < 12; i++)
		{
			if (products[i] > 0) {
				printf("   |   ");
				switch (i) {
				case 0:
					printf("cabbage - 54.99");
					break;
				case 1:
					printf("carrot - 9.99");
					break;
				case 2:
					printf("candies - 89.99");
					break;
				case 3:
					printf("spaghetti - 79.99");
					break;
				case 4:
					printf("zucchini - 49.99");
					break;
				case 5:
					printf("cheese - 239.99");
					break;
				case 6:
					printf("tomato - 14.99");
					break;
				case 7:
					printf("bacon - 149.99");
					break;
				case 8:
					printf("lettuce - 29.99");
					break;
				case 9:
					printf("chicken - 199.99");
					break;
				case 10:
					printf("muffin - 74.99");
					break;
				case 11:
					printf("pickles - 319.99");
					break;
				}
				cost_without_discounts += (double)products[i] * prices[i];
				cost += (double)products[i] * prices[i] * (1.0 - (double)discounts[i]/100);
				printf(" - %d", products[i]);
				printf(" - %lf\n", (double)products[i] * prices[i]);
			}
		}
		printf("overall price without discounts: %lf\n", cost_without_discounts);
	}
	else {
		printf("looks like an item is already beeing picked. Please, add it to your check first\n");
	}
}
void final_cost()
{
	if (cost_without_discounts != 0) {
		printf("total price: %lf", cost);
		tmp = 3;
	}
	else { printf("please, create your check first\n"); }
}
void next_move()
{
	char ch;
	printf("choose an action\n");
	do {
		scanf("%c", &ch);
	} while ((ch != '1') && (ch != '2') && (ch != '3') && (ch != '4') && (ch != '5'));
	switch (ch) {
		case '1':
			scan();
			break;
		case '2':
			info();
			break;
		case '3':
			add_to_check();
			break;
		case '4':
			make_check();
			break;
		case '5':
			final_cost();
			break;
		default:
			printf("no such command\n");
	}
}
int main() 
{
	introduction();
	do {
		next_move();
	} while (tmp != 3);
}