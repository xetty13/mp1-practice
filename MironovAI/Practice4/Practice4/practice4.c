#include <stdio.h>
#include <string.h>
#include <memory.h>
#define N 10


const char names[N][15] = { "Water", "Chocolate", "Milk", "Bread", "Fries", "Soup", "Tea", "Coffee", "Cookies", "Sugar" };
const char barcodes[N][4] = { "0001","0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010", };
int sales[N] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
int coasts[N] = { 20, 50, 50, 35, 40, 90, 90, 300, 150, 50 };
int cart[N] = { 0 };


void product_information() {
	printf("product_information");
}


int amount_summ() {
	int s = 0;
	for (int i = 0; i < N; i++) {
		s += coasts[i] * sales[i] / 100 * cart[i];
	}
	return s;
}

void removed() {
	printf("Remove");
}

void gen_of_receipt() {
	printf("Gen");
}

void pay() {
	printf("pay");
}


void scanning_funtion() {
	int flag = 1, count;


	while (flag != 0) {
		printf("You always can input 'stop' if u wanna kill it ");


		//Scanning barcode
		char user_code[4];
		printf("Scan your barcode: ");
		scanf("%s", &user_code);
		for (int i = 0; i < 4; i++) printf("%c", user_code[i]);
		//exit 
		if (user_code[0] == 's' && user_code[1] == 't' && user_code[2] == 'o' && user_code[3] == 'p') {
			flag = 0;
			continue;
		}

		//check input barcode
		int product_index = check_user_code(user_code);
		while (product_index == -1) {
			char user_code[4];
			printf("Pls, scan a right barcode: ");
			scanf("%s", &user_code);
			product_index = check_user_code(user_code);
		}

		product_information();
		printf("Input a count you wanna to buy. Input 0 if u dont want to buy it. \n ");
		scanf("%d", &count);

		if (count != 0) {
			cart[product_index] += count;
			printf("Done! %d products '%s' have been added to the cart \n", count, names[product_index]);
			break;

		}
	}

	int s = amount_summ();
	if (s == 0) {
		int id = random_digit();
		printf("You did not choose any product :( Maybe u wanna %s with %d percent a discount \n", names[id], sales[id]);
	}
	else printf("You added to the cart products for %d \n", s);


}





int main() {
	int c = 0, user;

	while (c == 0) {

		printf("Also u can: \n Input 1 for add a products to cart \n Input 2 for know more about product. \n Input 3 for total amount \N Input 4 for generate a receipt \n Input 5 for remove last product from a cart \n Input 6 if u wanna pay \n ");
		scanf("%d", &user);


		//Box office
		if (user == 1) scanning_funtion();
		else if (user == 2) product_information();
		else if (user == 3) amount_summ();
		else if (user == 4) gen_of_receipt();
		else if (user == 5) removed();
		else if (user == 6) {
			pay();
			c = 1;
			break;
		}
		else printf("Choose a operation and write a digit from 1 to 5 pls. \n");



	}
	printf("Have a nice day!");
	return 0;
}




int check_user_code(char user_code[4]) {
	int product_index = -1;
	for (int i = 0; i < N; i++) {
		int f = 0;
		for (int j = 0; j < 4; j++) {
			if (barcodes[i][j] != user_code[j]) {
				f++;
				break;
			}
		}
		if (f == 0) {
			product_index = i;
			break;
		}
	}

	return product_index;
}

int random_digit() {
	int n;

	srand((unsigned int)time(NULL));
	n = rand() % (10);

	return n;
}