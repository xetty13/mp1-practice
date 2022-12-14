#include "choice.h"
#include <stdio.h>

int choice() {
    int input;
    printf("|-----------------------------------------|\n");
    printf("Selected action:\n");
    printf("1) Merge Sort\n");
    printf("2) Quick Sort\n");
    printf("3) Bubble Sort\n");
    printf("4) Change dir\n");
    printf("5) Exit\n");
    printf("|-----------------------------------------|\n");
    if (scanf("%d", &input) != 1) {
        printf("Enter only numbers...");
        return NULL;
    }
    return input;
}