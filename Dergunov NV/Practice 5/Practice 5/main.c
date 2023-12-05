#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5
char* barcodes[N] = { "1212", "0101" , "2323" , "2424" , "5454" };
char* names[N] = { "Tea", "Milk", "Bread", "Eggs", "Apples" };
int price[N] = { 150, 100, 105, 100, 120 };
float discout[N] = { 0.15, 0.20, 0.0, 0.25, 0.10 };

int scan(int* amount) {
    char barcode[7] = " ";
    int flag = 0;
    printf("Enter a barcode or write (result) if you want to sum it up: \n");
    while (strcmp(barcodes, "0")) {
        gets(barcode);
        flag = 0;
        if (strcmp(barcode, "0")) {
            for (int i = 0; i < N; i++) {
                if (strcmp(barcodes[i], barcode) == 0) {
                    printf("NAME:%s\nPRICE:%d rubles\nDISCOUNT:%.2f\nEnter a barcode or (result) if u want to exit:\n", names[i], price[i], discout[i]);
                    amount[i] += 1;
                    flag = 1;
                }
                if (strcmp(barcode, "result") == 0) {
                    return 0;
                }
            }
            if (flag == 0) { printf("ya ne nashel barcode\n");  return 1; }
        }
    }
}

void finalcheck(int* amount) {
    float check = 0;
    printf("===Total check===\n");
    for (int i = 0; i < N; i++) {
        if (amount[i] != 0) {
            printf(("%s, price(with discount) - %.2f\n%d(count).\n"), names[i], (price[i] * (1 - (discout[i] / 100))), amount[i]);
        }
        check += (price[i] * (1 - (discout[i] / 100))) * amount[i];
    }
    printf("Total cost - %.2f", check);
}

int main() {
    int count[N] = { 0 };
    int number = 0;
    printf("===CASH===\n");
    int scan(count);
    if (scan(count) == 0) finalcheck(count);
}

